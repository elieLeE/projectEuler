#include "../libC/src/io/io.h"
#include "../libC/src/vector/vector.h"
#include "../libC/src/macros.h"

static int cmp_str(const void *_str1, const void *_str2)
{
    const char **str1 = (const char **)_str1;
    const char **str2 = (const char **)_str2;

    return strcmp(*str1, *str2);
}

static int read_names(gv_t(string) *names)
{
    FILE *f = NULL;
    char *name;
    char c;
    int name_lenght = 0;

    f = RETHROW_PN(ouv_fichier("names.txt", "r"));

    while ((c = getc(f)) != EOF) {
        if (c == '"' || c == ',') {
            if (name_lenght == 0) {
                continue;
            } else if (fseek(f, - (name_lenght + 1), SEEK_CUR) != 0) {
                logger_error("resetting the pointer in the file has failed\n");
                return -1;
            }

            name = RETHROW_PN(p_calloc(name_lenght + 1));
            if (fgets(name, name_lenght + 1, f) == NULL) {
                logger_error("reading data from the file has failed\n");
            }

            gv_insert_elem_sorted(names, name, cmp_str);

            name_lenght = 0;
        } else {
            name_lenght++;
        }
    }

    fermer_fichier(&f);

   return 0;
}

static unsigned int get_name_val(const char *name)
{
    unsigned int val = 0;

    for (unsigned long i = 0; i < strlen(name); i++) {
        val += (name[i] - 'A' + 1);
    }

    return val;
}

int main(void)
{
    unsigned long res = 0;
    gv_t(string) names;

    gv_init_size(&names, 5000);

    if (read_names(&names) != 0) {
        logger_error("the readling of the file has failed\n");
        return 0;
    }
    gv_for_each_pos(pos, &names) {
        unsigned int name_val = get_name_val(names.tab[pos]);

        res += (name_val * (pos + 1));
    }

    gv_wipe(&names, _p_free);

    printf("%ld\n", res);

    return 0;
}
