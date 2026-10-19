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
    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }
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

void dinsert_node(dnode_t **head_ref, double data, int index) {
    if (index < 0) {
        return;
    }
    if (index == 0) {
        dpush(head_ref, data);
        return;
    }
    dnode_t *current = *head_ref;
    for (uint16_t i = 0; current != NULL && i < index; i++) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    dnode_t *new_node = (dnode_t *)malloc(sizeof(dnode_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = current;
    new_node->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = new_node;
    }
    current->prev = new_node;
}

void dinsert_at_end(dnode_t **head_ref, double data) {
    dnode_t *new_node = (dnode_t *)malloc(sizeof(dnode_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    dnode_t *current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

uint16_t dsearch_node(dnode_t **head_ref, double data) {
    if (head_ref == NULL) {
        return -1;
    }
    dnode_t *current = *head_ref;
    uint16_t i = 0;
    while (current != NULL) {
        if (current->data == data) {
            return i;
        }
        current = current->next;
        i++;
    }
    return -1;
}

void ddelete_at(dnode_t **head_ref, double data) {
    if (head_ref == NULL || *head_ref == NULL) {
        return;
    }
    dnode_t *current = *head_ref;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head_ref = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

void ddelete_at_end(dnode_t **head_ref) {
    if (head_ref == NULL || *head_ref == NULL) {
        return;
    }
    dnode_t *current = *head_ref;
    if (current->next == NULL) {
        free(current);
        *head_ref = NULL;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}

darray_t dexport(dnode_t **head_ref) {
    darray_t ret = { .array = NULL, .size = 0, .capacity = 0 };
    if (head_ref == NULL || *head_ref == NULL) {
        return ret;
    }
    uint16_t count = 0;
    dnode_t *current = *head_ref;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    double *arr = (double *)malloc(count * sizeof(double));
    if (arr == NULL) {
        return ret;
    }
    current = *head_ref;
    for (uint16_t i = 0; i < count; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    ret.array = arr;
    ret.size = count;
    ret.capacity = count;
    return ret;
}
