#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "doublelink.h"
#include "linkedlist.h"

int main(void) {
    node_t *list = NULL;
    push(&list, 1.0);
    push(&list, 2.5);
    insert_node(&list, 3.0,1);
    double result;
    bool t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    push(&list, 30.0);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    push(&list, 10.0);
    push(&list, 11.0);
    insert_at_end(&list, 2.5);
    uint16_t i=search_node(&list, 2.5);
    printf("index: %i\n", i);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    push(&list, 3.0);
    push(&list, 4.0);
    push(&list, 5.0);
    push(&list, 6.0);
    push(&list, 7.0);
    push(&list, 8.0);
    delete_at_end(&list);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    push(&list, 3.0);
    push(&list, 4.0);
    push(&list, 5.0);
    push(&list, 6.0);
    push(&list, 7.0);
    push(&list, 8.0);
    clear_list(&list);
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    push(&list, 3.0);
    push(&list, 4.0);
    push(&list, 5.0);
    push(&list, 6.0);
    push(&list, 7.0);
    push(&list, 8.0);
    array_t arr=export(&list);
    printf("Array: %.2f \n", arr.array[0]);
    printf("Array: %.2f \n", arr.array[1]);
    clock_t start=clock();
    // 100millionen
    for (int in=0; in<100000000; in++) {
        push(&list, 3.0);
    }
    for (int in=0; in<100000000; in++) {
        pop(&list, &result);
    }
    clock_t end=clock();
    double erg=(end-start)/CLOCKS_PER_SEC;
    printf("Elapsed: %f seconds\n", erg);

    // doublelink

    dnode_t *dlist = NULL;
    dpush(&dlist, 1.0);
    dpush(&dlist, 2.5);
    dinsert_node(&dlist, 3.0,1);
    result=0;
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    dpush(&dlist, 30.0);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    dpush(&dlist, 10.0);
    dpush(&dlist, 11.0);
    dinsert_at_end(&dlist, 2.5);
    i=dsearch_node(&dlist, 2.5);
    printf("index: %i\n", i);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    dpush(&dlist, 3.0);
    dpush(&dlist, 4.0);
    dpush(&dlist, 5.0);
    dpush(&dlist, 6.0);
    dpush(&dlist, 7.0);
    dpush(&dlist, 8.0);
    ddelete_at_end(&dlist);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    dpush(&dlist, 3.0);
    dpush(&dlist, 4.0);
    dpush(&dlist, 5.0);
    dpush(&dlist, 6.0);
    dpush(&dlist, 7.0);
    dpush(&dlist, 8.0);
    dclear_list(&dlist);
    t=dpop(&dlist, &result);
    printf("Popped: %.2f %d\n", result, t);
    dpush(&dlist, 3.0);
    dpush(&dlist, 4.0);
    dpush(&dlist, 5.0);
    dpush(&dlist, 6.0);
    dpush(&dlist, 7.0);
    dpush(&dlist, 8.0);
    darray_t darr=dexport(&dlist);
    printf("Array: %.2f \n", darr.array[0]);
    printf("Array: %.2f \n", darr.array[1]);
    start=clock();
    // 100millionen
    for (int in=0; in<100000000; in++) {
        dpush(&dlist, 3.0);
    }
    for (int in=0; in<100000000; in++) {
        dpop(&dlist, &result);
    }
    end=clock();
    erg=(end-start)/CLOCKS_PER_SEC;
    printf("Elapsed: %f seconds\n", erg);

    return 0;
}
