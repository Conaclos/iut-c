#include <stdlib.h>
#include "linked_list.h"

Cell * list_empty() {
    return NULL;
}

Cell * list_cell(int val, Cell* succ) {
    Cell *res = malloc(sizeof(Cell));
    res->val = val;
    res->succ = succ;
    return res;
}

int list_is_empty(Cell *l) {
    return l == NULL;
}

int list_size(Cell *l) {
    int res = 0;
    while(l != NULL) {
        l = l->succ;
        res++;
    }
    return res;
}

int list_rank_of(Cell *l, int val) {
    int res = 0;
    while(l != NULL) {
        res++;
        if (l->val == val) {
            return res;
        }
        l = l->succ;
    }
    return 0;
}

int * list_to_array(Cell *l) {
    int * res = malloc(sizeof(int) * list_size(l));
    int i = 0;
    while(l != NULL) {
        res[i] = l->val;
        l = l->succ;
        i++;
    }
    return res;
}

Cell * list_add_first(Cell *l, int val) {
    Cell *head = malloc(sizeof(Cell));
    head->val = val;
    head->succ = l;
    return head;
}

Cell * list_add_last(Cell *l, int val) {
    Cell *end = malloc(sizeof(Cell));
    end->val = val;
    end->succ = NULL;
    if (l == NULL) {
        return end;
    }
    else {
        Cell *prev = l;
        Cell *curr = l;
        while(curr != NULL) {
            prev = curr;
            curr = curr->succ;
        }
        prev->succ = end;
        return l;
    }
}

Cell * list_remove_first(Cell *l) {
    if(l == NULL) {
        return NULL;
    }
    else {
        Cell *res = l->succ;
        free(l);
        return res;
    }
}

Cell * list_remove_last(Cell *l) {
    if(l == NULL) {
        return NULL;
    }
    else {
        Cell *prev = l;
        Cell *curr = l;
        while(curr != NULL) {
            prev = curr;
            curr = curr->succ;
        }
        free(prev->succ);
        prev->succ = NULL;
        return l;
    }
}

void list_free(Cell *l) {
    Cell *curr = l;
    Cell *succ;
    while(curr != NULL) {
        succ = curr->succ;
        free(curr);
        curr = succ;
    }
}

