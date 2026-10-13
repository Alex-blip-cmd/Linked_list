//...
#include "doublelink.h"
#include <stdlib.h>

void dpush(dnode_t **head_ref, double data) {
    dnode_t *new_node = (dnode_t *)malloc(sizeof(dnode_t));
    if (new_node == NULL) {
        return;
    }
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

bool dpop(dnode_t **head_ref, double *data) {
    if (head_ref == NULL || *head_ref == NULL || data == NULL) {
        return false;
    }
    dnode_t *temp = *head_ref;
    *data = temp->data;
    *head_ref = temp->next;
    if (*head_ref != NULL) {
        (*head_ref)->prev = NULL;
    }
    free(temp);
    return true;
}

void dclear_list(dnode_t **head_ref) {
    if (head_ref == NULL || *head_ref == NULL) {
        return;
    }
    dnode_t *current = *head_ref;
    while (current != NULL) {
        dnode_t *copy = current->next;
        free(current);
        current = copy;
    }
    *head_ref = NULL;
}
