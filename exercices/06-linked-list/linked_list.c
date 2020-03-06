#include<stdlib.h>
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

