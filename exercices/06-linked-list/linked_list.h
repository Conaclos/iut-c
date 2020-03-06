
typedef struct cell {
    int val;
    struct cell *succ;
} Cell;


/**
 * @return an empty list
 */
Cell * list_empty();

/**
 * @return new cell such that val is its value and succ its successor cell.
 */
Cell * list_cell(int val, Cell* succ);

/**
 * @param l list to test
 * @return is l an empty list?
 */
int list_is_empty(Cell *l);

/**
 * @param l list
 * @return size of the list l.
 */
int list_size(Cell *l);

/**
 * @param l
 * @return array representation of l.
 */
int * list_to_array(Cell *l);

/**
 * @param l
 * @param val
 * @return rank of val in l. 0 if the item is absent.
 */
int list_rank_of(Cell *l, int val);

/**
 * @param l
 * @return list such that val is the first value.
 *  The new cell is allocated on the heap.
 */
Cell * list_add_first(Cell *l, int val);

/**
 * @param l
 * @return list such that val is the last item.
 *  The new cell is allocated on the heap.
 */
Cell * list_add_last(Cell *l, int val);

/**
 * @param l list allocated on the heap
 * @return list where the first item of l is absent.
 */
Cell * list_remove_first(Cell *l);

/**
 * @param l list allocated on the heap
 * @return list where the last item of l is absent.
 *  The last item is freed.
 */
Cell * list_remove_last(Cell *l);

/**
 * Free heap memory
 *
 * @param list allocated on the heap
 */
void list_free(Cell *l);

