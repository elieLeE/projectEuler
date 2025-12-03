#!/bin/bash

# {{{ Variables

COLOR_YELLOW="\x1B[33m"
COLOR_GREEN="\x1B[0;32m"
COLOR_BLUE="\x1B[34m"
COLOR_RED="\x1B[31m"
RESET_COLOR="\x1B[0m"

COMPILATING_ACTION=1
RUNNING_ACTION=2
CLEANING_ACTION=3

all_euler_projects=()

action=
action_str=
project=

USE_VALGRIND=0
VERBOSE=0
CHECK_RESULT=1
STOP_ON_WARNING=0
SKIP_ERRORS=0

ENABLED=1
DISABLED=0

tmp_file="tmp.txt"
tmp_valgrind_file="valgrind_tmp.txt"
expected_result_file="expected_result.txt"
skip_projects_file="skip_projects.txt"

cmd=

# }}}
# {{{ Parsing arguments

display_usage() {
    printf "usage: ./run_project.sh a ACTION [ -p PROJECT ]\n"
}

# NOTE: This requires GNU getopt.  On Mac OS X and FreeBSD, you have to install
# this separately; see below.
TEMP=$(getopt -o mrcvp: \
    --long make,run,clean,verbose,use_valgrind,project:,skip_checking_result,warnings_are_errors,skip_errors,skip_projects:\
    -n 'check_projects' -- "$@")

if [ $? != 0 ] ; then display_usage ; exit 1 ; fi

# Note the quotes around '$TEMP': they are essential!
eval set -- "$TEMP"

while true; do
    case "$1" in
        --make | -m)
            action_str="Compiling"
            action=${COMPILATING_ACTION}
            shift
            ;;
        --clean | -c)
            action_str="Cleaning"
            action=${CLEANING_ACTION}
            shift
            ;;
        --run | -r)
            action_str="Running"
            action=${RUNNING_ACTION}
            shift
            ;;
        --project | -p)
            project=$2
            if [ ! -d $OPTARG ]; then
                printf "${COLOR_RED}$project does not exist\n${RESET_COLOR}"
                exit
            fi
            shift 2
            ;;
        --verbose | -v)
            VERBOSE=${ENABLED}
            shift
            ;;
        --use_valgrind)
            USE_VALGRIND=${ENABLED}
            shift
            ;;
        --skip_checking_result)
            CHECK_RESULT=${DISABLED}
            shift
            ;;
        --warnings_are_errors)
            STOP_ON_WARNING=${ENABLED}
            shift
            ;;
        --skip_errors)
            SKIP_ERRORS=${ENABLED}
            shift
            ;;
        --skip_projects)
            skip_projects_file=$2
            shift 2
            ;;
        *)
            break;
            ;;
    esac
done

if [ ! ${action} ]; then
    display_usage
    exit
fi

if [ ${action} -ne ${RUNNING_ACTION} ]; then
    if [ ${USE_VALGRIND} -eq 1 ]; then
        printf "${COLOR_YELLOW}Valgrind can only be use on running project\n" \
            "{RESET_COLOR}"
    fi
fi

# }}}
# {{{ Executing the command

get_all_folders() {
    local file=$1

    if [ ${project} ]; then
        if [ -f ${project}/${file} ]; then
            all_euler_projects+=(${project})
        else
            printf "${COLOR_RED} file '$1' has not been found in "\
                "${project}\n${RESET_COLOR}"
        fi
    else
        for folder in $(ls -d p*); do
            if [ -f ${folder}/${file} ]; then
                all_euler_projects+=(${folder})
            fi
        done
    fi
}

check_compiling_cmd () {
    if [ ${STOP_ON_WARNING} -eq ${ENABLED} ]; then
        grep -q "warning" ${tmp_file}
        if [ $? -eq 0 ]; then
            if [ ${VERBOSE} -eq ${DISABLED} ]; then
                printf " => "
            fi
            printf "${COLOR_RED}got warning when compiling${RESET_COLOR}"
            return 1
        fi
    fi

    return 0
}

check_running_cmd () {
    local tmp_valgrind_file_path=$1
    local res=0

    if [ ${CHECK_RESULT} -eq ${ENABLED} ]; then
        local expected_result_file_path=${folder}/${expected_result_file}

        if [ ! -f ${expected_result_file_path} ]; then
            printf "\n${COLOR_YELLOW}the file ${folder}/expected_result.txt " \
                "does not exist${RESET_COLOR}\n"
            res=1
        else
            cmp -s ${tmp_file} ${folder}/${expected_result_file}
            if [ $? -eq 1 ]; then
                local expected_result=

                while IFS= read -r line; do
                    expected_result=${line}
                done < "${expected_result_file_path}"

                if [ ${USE_VALGRIND} -eq ${DISABLED} ] || \
                    [ ${VERBOSE} -eq ${DISABLED} ]; then
                    printf " / "
                fi
                printf "${COLOR_RED}expected result: ${expected_result}${RESET_COLOR}"
                printf "${COLOR_RED} -- obtained results: "
                cat ${tmp_file} | tr -d '\n'
                res=1
            fi
        fi
    fi

    if [ ${USE_VALGRIND} -eq ${ENABLED} ]; then
        grep -q "All heap blocks were freed -- no leaks are possible" \
            ${tmp_valgrind_file_path}
        if [ $? -ne 0 ]; then
            if [ ${res} -eq 0 ]; then
                if [ ${VERBOSE} -eq ${DISABLED} ]; then
                    printf " / "
                fi
            else
                printf " + "
            fi
            printf "${COLOR_RED}memory leaks detected${RESET_COLOR}"
            res=1
        fi
        rm ${tmp_valgrind_file_path}
    fi

    return ${res}
}

run_cmd () {
    local folder=$1
    local cmd_res=0
    local answer=
    local tmp_valgrind_file_path=

    tmp_valgrind_file_path=${folder}/${tmp_valgrind_file}

    # "()" lets me run these commands is a sub-shell
    (cd ${folder}; ${cmd[@]}) > ${tmp_file} 2>&1
    cmd_res=$?

    if [ ${action} -eq ${RUNNING_ACTION} ]; then
        while IFS= read -r line; do
            answer=${line}
        done < "${tmp_file}"
        printf " ${answer}"
    fi

    if [ ${VERBOSE} -eq ${ENABLED} ]; then
        if [ ${action} -eq ${RUNNING_ACTION} ]; then
            if [ ${USE_VALGRIND} -eq ${ENABLED} ]; then
                printf "\n"
                cat ${tmp_valgrind_file_path}
            fi
        else
            printf "\n"
            cat ${tmp_file}
        fi
    fi

    if [ ${cmd_res} != 0 ]; then
        return 1
    fi

    if [ ${action} -eq ${COMPILATING_ACTION} ]; then
        check_compiling_cmd
        return $?
    elif [ ${action} -eq ${RUNNING_ACTION} ]; then
        check_running_cmd ${tmp_valgrind_file_path}
        return $?
    fi

    return ${res}
}

run_cmd_on_projects() {
    local projects_to_skip=()

    if [ ${action} -eq ${RUNNING_ACTION} ]; then
        if [ ${skip_projects_file} ]; then
            while IFS= read -r line; do
                projects_to_skip+=(${line})
            done < "${skip_projects_file}"
        fi
    fi

    for ((idx = 0; idx < ${#all_euler_projects[@]}; idx++)) do
        local folder=${all_euler_projects[${idx}]}
        local res=

        if [ ${VERBOSE} -eq ${ENABLED} ] && [ ${idx} -gt 0 ]; then
            if [ ${action} -ne ${RUNNING_ACTION} ] || [ ${USE_VALGRIND} -eq ${ENABLED} ]
            then
                printf "\n"
            fi
        fi

        printf "${COLOR_BLUE}${action_str} ${folder}${RESET_COLOR}"

        for project_to_skip in ${projects_to_skip[@]}; do
            if [ ${folder} = ${project_to_skip} ]; then
                printf " => ${COLOR_YELLOW}SKIP\n"
                continue 2
            fi
        done

        run_cmd ${folder};
        res=$?

        if [ ${action} -eq ${RUNNING_ACTION} ]; then
            if [ ${VERBOSE} -eq ${DISABLED} ] || \
                [ ${USE_VALGRIND} -eq ${DISABLED} ] || \
                [ ${res} -ne 0 ]; then
                printf " => "
            fi
        elif [ ${VERBOSE} -eq ${DISABLED} ]; then
            printf " => "
        fi

        if [ ${res} != 0 ]; then
            printf "${COLOR_RED}ECHEC${RESET_COLOR}\n"
            if [ ${SKIP_ERRORS} -eq 0 ]; then
                break
            fi
        else
            printf "${COLOR_GREEN}SUCCES${RESET_COLOR}\n"
        fi

    done
}

compile_projets() {
    cmd=(make all)

    get_all_folders Makefile
    run_cmd_on_projects
}

run_projets() {
    if [ ${USE_VALGRIND} == 1 ]; then
        cmd=(valgrind --log-file=${tmp_valgrind_file} ./prog)
    else
        cmd=(./prog)
    fi

    get_all_folders prog
    run_cmd_on_projects
}

clean_projects() {
    cmd=(make clean)

    get_all_folders Makefile
    run_cmd_on_projects

}

# }}}

if [ ${action} -eq ${COMPILATING_ACTION} ]; then
    compile_projets
elif [ ${action} -eq ${RUNNING_ACTION} ]; then
    run_projets
elif [ ${action} -eq ${CLEANING_ACTION} ]; then
    clean_projects
fi

if [ -f ${tmp_file} ]; then
    rm ${tmp_file}
fi
