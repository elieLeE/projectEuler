#include <stdio.h>

#include "../libC/src/logger/logger.h"

typedef enum day_t {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THIRDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} day_t;

typedef enum month_t {
    JANUARY,
    FEBRUAY,
    MARS,
    APRIL,
    MAI,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} month_t;

typedef struct date_t {
    int day_number;
    day_t day;
    month_t month;
    int year;
} date_t;


static int cmp_date(const date_t *d1, const date_t *d2)
{
    if (d1->year != d2->year) {
        return d1->year - d2->year;
    }
    if (d1->month != d2->month) {
        return d1->month - d2->month;
    }
    return d1->day_number - d2->day_number;
}

static int get_first_day_number_month_move(const date_t *date)
{
    switch (date->month) {
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 2;

        case JANUARY:
        case MARS:
        case MAI:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return 3;

        case FEBRUAY:
            if (date->year % 4 == 0 &&
                (date->year % 100 != 0 || date->year % 400 == 0))
            {
                return 1;
            }
            return 0;
    }

    logger_fatal("invalid month: %d\n", date->month);
    return -1;
}

static void go_to_next_month(date_t *date)
{
    date->day = (date->day + get_first_day_number_month_move(date)) % 7;
    date->month = (date->month + 1) % 12;

    if (date->month == JANUARY) {
        date->year++;
    }
}

int main()
{
    int saturday_count = 0;
    date_t date = {.day_number = 1, .day = TUESDAY, .month = JANUARY,
        .year = 1901};
    date_t last_date = {.day_number = 31, .day = MONDAY, .month = DECEMBER,
        .year = 2000};

    while (cmp_date(&date, &last_date) < 0) {
        go_to_next_month(&date);

        if (date.day == SATURDAY) {
            saturday_count++;
        }
    }

    printf("%d\n", saturday_count);

    return 0;
}
