#include <stdio.h>
#include <stdint.h>
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
    double i=search_node(&list, 2.5);
    printf("index: %.0f\n", i);
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
    clear_list(&list);
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
    t=pop(&list, &result);
    printf("Popped: %.2f %d\n", result, t);
    return 0;
}
