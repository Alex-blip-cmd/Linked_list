#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

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
    int i=search_node(&list, 2.5);
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
    //array_t arr=export(&list);
    //printf("Array: %.2f \n", arr.array[0]);
    //printf("Array: %.2f \n", arr.array[1]);
    clock_t start=clock();
    for (uint16_t in=0; i<100; i++) {
        push(&list, 3.0);
    }
    for (uint16_t in=0; i<100; i++) {
        pop(&list, &result);
    }
    clock_t end=clock();
    double erg=(end-start)/CLOCKS_PER_SEC;
    printf("Elapsed: %.2f seconds\n", erg);

    // doublelink

    return 0;
}
