#include "../libC/src/io/io.h"
#include "../libC/src/vector/vector.h"
#include "../libC/src/macros.h"

generic_vector_t(triangle_paths, gv_t(uint64));

static int read_triangle(gv_t(triangle_paths) *triangle_paths)
{
    FILE *f;
    int c, val;
    int max_nber_current_line = 1;
    int current_idx_line = 0;
    int nber_count = 0;
    gv_t(uint64) *current_line;

    f = ouv_fichier("data.txt", "r");
    if (f == NULL) {
        return -1;
    }

    current_line = gv_grow1(triangle_paths);
    gv_init(current_line);

    while ((c = fscanf(f, "%d", &val)) != EOF) {
        if (nber_count == max_nber_current_line) {
            current_idx_line++;
            current_line = gv_grow1(triangle_paths);
            gv_init(current_line);
            max_nber_current_line++;
            nber_count = 0;
        }
        gv_add(current_line, val);
        nber_count++;
    }

   fermer_fichier(&f);

   return 0;
}

int main(void)
{
    unsigned long max_path = 0;
    gv_t(triangle_paths) triangle_paths;
    gv_t(uint64) *last_line;

    gv_init(&triangle_paths);

    if (read_triangle(&triangle_paths) < 0) {
        logger_fatal("reading of the data has failed\n");
    }

    for (long i = 1; i < triangle_paths.len; i++) {
        gv_t(uint64) *previous_line = &(triangle_paths.tab[i - 1]);
        gv_t(uint64) *current_line = &(triangle_paths.tab[i]);

        current_line->tab[0] += previous_line->tab[0];
        current_line->tab[current_line->len - 1] +=
            previous_line->tab[previous_line->len - 1];

        for (long j = 1; j < current_line->len - 1; j++) {
            uint16_t tmp;

            tmp = MAX(previous_line->tab[j-1], previous_line->tab[j]);
            current_line->tab[j] += tmp;
        }
    }

    last_line = &(triangle_paths.tab[triangle_paths.len - 1]);
    gv_for_each_pos(pos, last_line) {
        max_path = MAX(max_path, last_line->tab[pos]);
    }
    printf("%ld\n", max_path);

    gv_for_each_pos(pos, &triangle_paths) {
        gv_wipe(&(triangle_paths.tab[pos]), NULL);
    }
    gv_wipe(&triangle_paths, NULL);

    return 0;
}
