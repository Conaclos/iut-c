#include <assert.h>
#include <stdlib.h>

#include "linked_list.h"

void test_list_empty() {
    Cell *l1 = list_empty();

    assert(list_is_empty(l1));
}

void test_list_size() {
    Cell *l1 = list_cell(5, list_cell(8, list_empty()));
    Cell *l2 = l1->succ;

    assert(list_size(list_empty()) == 0);
    assert(list_size(l2) == 1);
    assert(list_size(l1) == 2);

    list_free(l1);
}

void test_list_rank_of() {
    Cell *l1 = list_cell(5, list_cell(8, list_empty()));
    Cell *l2 = l1->succ;

    assert(list_rank_of(list_empty(), 5) == 0);
    assert(list_rank_of(l2, 5) == 0);
    assert(list_rank_of(l2, 8) == 1);
    assert(list_rank_of(l1, 8) == 2);
    assert(list_rank_of(l1, 5) == 1);

    list_free(l1);
}

void test_list_add_first() {
    Cell *l1 = list_empty();
    Cell *l2;
    Cell *l3;

    l2 = list_add_first(l1, 5);
    assert(l2 != list_empty());
    assert(l2->val == 5);
    assert(l2->succ == list_empty());

    l3 = list_add_first(l2, 8);
    assert(l3 != list_empty());
    assert(l3->val == 8);
    assert(l3->succ != list_empty());
    assert(l3->succ->val == 5);
    assert(l3->succ->succ == list_empty());

    list_free(l3);
}

void test_list_add_last() {
    Cell *l1 = list_empty();
    Cell *l2;
    Cell *l3;

    l2 = list_add_last(l1, 5);
    assert(l2 != list_empty());
    assert(l2->val == 5);
    assert(l2->succ == list_empty());

    l3 = list_add_last(l2, 8);
    assert(l3 != list_empty());
    assert(l3->val == 5);
    assert(l3->succ != list_empty());
    assert(l3->succ->val == 8);
    assert(l3->succ->succ == list_empty());

    list_free(l3);
}

void test_list_remove_first() {
    Cell *l1 = list_cell(5, list_cell(8, list_empty()));
    Cell *l2;

    l2 = list_remove_first(l1);
    assert(l2->val == 8);
    assert(l2->succ == list_empty());

    list_free(l2);
}

void test_list_remove_last() {
    Cell *l1 = list_cell(5, list_cell(8, list_empty()));
    Cell *l2;

    l2 = list_remove_last(l1);
    assert(l2->val == 5);
    assert(l2->succ == list_empty());

    list_free(l2);
}

int main() {
    test_list_empty();
    test_list_size();
    test_list_rank_of();
    test_list_add_first();
    test_list_add_last();
    test_list_remove_first();
    return 0;
}

