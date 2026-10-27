//
// Created by pimen on 16.09.2026.
//
#include "linkedlist.h"

#include <stddef.h>
#include <stdlib.h>

void push(node_t **head_ref, double data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

bool pop(node_t **head_ref, double *data) {
    if (head_ref == NULL || *head_ref == NULL || data == NULL) {
        return false;
    }
    node_t *temp = *head_ref;
    *data = temp->data;
    *head_ref = temp->next;
    free(temp);
    return true;
}

void insert_node(node_t **head_ref, double data, int index) {
    if (index < 0) {
        return;
    }
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    if (index == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    node_t *current = *head_ref;
    for (uint16_t i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }
    if (current == NULL) {
        free(new_node);
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void insert_at_end(node_t **head_ref, double data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    node_t *current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void clear_list(node_t **head_ref) {
    if (head_ref == NULL || *head_ref == NULL) {
        return;
    }
    node_t *current = *head_ref;
    while (current != NULL) {
        node_t *copy = current->next;
        free(current);
        current = copy;
    }
    *head_ref = NULL;
}

int search_node(node_t **head_ref, double data) {
    node_t *current = *head_ref;
    uint16_t i=0;
    while (current != NULL) {
        if (current->data == data) {
            return i;
        } else {
            current = current->next;
            i++;
        }
    }
    return -1;
}

void delete_at_end(node_t **head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    node_t *current = *head_ref;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void delete_at(node_t **head_ref, double data) {
    if (head_ref == NULL || *head_ref == NULL) {
        return;
    }
    node_t *temp = *head_ref;
    if (temp->data == data) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    node_t *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

array_t export(node_t **head_ref) {
    array_t ret = { .array = NULL, .size = 0, .capacity = 0 };

    if (head_ref == NULL || *head_ref == NULL) {
        return ret;
    }

    uint16_t count = 0;
    node_t *current = *head_ref;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    double *arr = (double *)malloc(count * sizeof(double));
    if (arr == NULL) {
        return ret;
    }
    current = *head_ref;
    for (int i = 0; i < count; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    ret.array = arr;
    ret.size = count;
    ret.capacity = count;
    return ret;
}


