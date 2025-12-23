#include <stdio.h>

#include "../libC/src/vector/vector.h"
#include "../libC/src/mem/mem.h"

/* To resolve this problem, I have decided to create a tree. The top node is
 * the one associated to power = 1. Then, for the previous levels, the new
 * node corresponding to the newt power are created (only the level greater
 * or equal than power / 2 are taken in account. So, if we want to create the
 * nodes of the power '10', the nodes from the powers 5 to 9 will be taken in
 * account.
 * It is important to notice that we will not create a single node foe the
 * power '4' (for example). We will create as much node as necessaries for all
 * the path leading to the powers '4'.
 * Indeed, for The four level, we will have that:
 *                      1
 *                      |
 *                      2
 *                     / \
 *                    3   \
 *                    |    \
 *                    4     4
 * So, we have two path that can leading to 4. But, this two paths does not
 * have the same cost and does not let create the same next nodes. For example,
 * the path that does not go by the power 3 can not create the power '7'.
 *
 * The fact of creating all the paths leading to a node has two consequences:
 * - the number of node necessaries for a power will increase exponentially.
 * - some paths are just useless.
 *
 * It is easy to see that the number will increase exponentially. More power
 * means more paths, and more paths on the previous levels means more new
 * nodes and so more paths...
 * But, the path adding just a single power of the previous node is useless
 * from the power '4'.
 * So, in order to limit the nodes number created, once all the nodes have been
 * created for a power, these ones will be sorted. Then, when the time of
 * creating the next nodes has come, we will limit the best previous paths to
 * the 1000 first ones (arbitrarily, but it works).
 */

#define MAX_POWER 200 + 1
#define MAX_PATH 2 * (MAX_POWER)

struct node_power_t;

typedef struct node_power_t {
    unsigned int current_power;
    int path_len;
    struct node_power_t *parent;
} node_power_t;

generic_vector_t(nodes_power, node_power_t);

static int cmp_node_power(const void *_n1, const void *_n2)
{
    const node_power_t *n1 = _n1;
    const node_power_t *n2 = _n2;

    return n1->path_len - n2->path_len;
}

/* determine if the path has seen the power 'N'. If yes, the link can be
 * created */
static inline bool
has_path_encounter_power(const node_power_t *power_node, unsigned int power)
{
    if (power == 1 || power == 2 || power_node->current_power == power) {
        return true;
    }

    if (power > power_node->current_power) {
        return false;
    }

    return has_path_encounter_power(power_node->parent, power);
}

static void
create_nodes_for_power_n(gv_t(nodes_power) current_nodes[MAX_POWER],
                         unsigned int current_power)
{
    unsigned int min_power_parents_nodes;

    if (current_power % 2 == 0) {
        min_power_parents_nodes = current_power / 2;
    } else {
        min_power_parents_nodes = (current_power / 2) + 1;
    }

    for (unsigned int i = min_power_parents_nodes; i < current_power; i++) {
        unsigned power_searched = current_power - i;
        const gv_t(nodes_power) *parent_nodes = &current_nodes[i];
        int max_node_to_create;

        if (parent_nodes->len < 1000) {
             max_node_to_create = parent_nodes->len;
        } else {
            max_node_to_create = parent_nodes->len / 10;
        }

        for (int j = 0; j < max_node_to_create; j++) {
            node_power_t *parent_node = &parent_nodes->tab[j];

            if (has_path_encounter_power(parent_node, power_searched)) {
                node_power_t *new_node;

                new_node = gv_grow1(&current_nodes[current_power]);
                new_node->current_power = current_power;
                new_node->path_len = parent_node->path_len + 1;
                new_node->parent = parent_node;
            }
        }
    }
}

int main()
{
    gv_t(nodes_power) nodes_power[MAX_POWER];
    node_power_t *first_node;
    unsigned int res = 0;

    p_clear(nodes_power, MAX_POWER);
    for (int i = 0; i < MAX_POWER; i++) {
        gv_init(&nodes_power[i]);
    }

    first_node = gv_grow1(&nodes_power[1]);
    first_node->path_len = 0;
    first_node->current_power = 1;
    first_node->parent = NULL;

    for (unsigned i = 2; i < MAX_POWER; i++) {
        create_nodes_for_power_n(nodes_power, i);
        gv_sort(&nodes_power[i], cmp_node_power);
        res += nodes_power[i].tab[0].path_len;
    }

    for (int i = 0; i < MAX_POWER; i++) {
        gv_wipe(&nodes_power[i], NULL);
    }

    printf("%d\n", res);

    return 0;
}
