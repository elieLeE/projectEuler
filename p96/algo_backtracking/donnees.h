#ifndef _DONNEES_H_
#define _DONNEES_H_

#define MODE 1

#define NBRE_LIGNE 9
#define NBRE_COL 9
#define NBRE_VAL_POSS 9

typedef struct liste_elem *liste_elem;
typedef struct liste_elem_imp *liste_elem_imp;
typedef struct liste_val_poss *liste_val_poss;
typedef struct S_elem S_elem;
typedef struct S_pos S_pos;

struct S_pos{
    char lig, col;
};

#if MODE
struct liste_elem_imp{
    char *val;
    struct S_pos pos;	//pour debugger
    struct liste_elem_imp *suiv;
};

struct liste_val_poss{
    char val;
    struct liste_val_poss *suiv;
};
#endif

struct S_elem{
    char *val;
    struct S_pos pos;	//pour debugger
#if MODE
    struct liste_val_poss *pos_val_poss;
    struct liste_val_poss *l_val_poss;
    struct liste_elem_imp *l_elem_imp;
#else 
    char val_poss[9];
    char* elem_imp[27];
    int nbre_elem_imp;
    int pos_tab_val_poss;
    int nbre_val_poss;
#endif
};

#if MODE
struct liste_elem{
    struct S_elem S_el;
    struct liste_elem *suiv, *prec;
};
#endif

#if !MODE
struct tab_elem{
    int nbre_elem;
    S_elem elem[81];
}
#endif

#endif
