//
// Created by pimen on 16.09.2026.
//

#ifndef UNTITLED_LINKED_LIST_H
#define UNTITLED_LINKED_LIST_H
#include <limits.h>
#include <stdbool.h>

typedef struct node {
	double data;
	struct node *next;
	} node_t;

typedef struct array {
	double array[INT_MAX];
} array_t;

void push(node_t **head_ref, double data);
bool pop(node_t **head_ref, double *data);
void insert_node(node_t **head_ref, double data, int index);
void insert_at_end(node_t **head_ref, double data);
void clear_list(node_t **head_ref);
double search_node(node_t **head_ref, double data);
void delete_at_end(node_t **head_ref);
array_t export(node_t **head_ref);

#endif //UNTITLED_LINKED_LIST_H
