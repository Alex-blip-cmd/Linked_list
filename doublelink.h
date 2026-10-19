//
// Created by pimen on 13.10.2026.
//

#ifndef UNTITLED_DOUBLELINK_H
#define UNTITLED_DOUBLELINK_H
#include <stdbool.h>
#include <stdint.h>

typedef struct dnode {
    struct dnode *prev;
    double data;
    struct dnode *next;
} dnode_t;
typedef struct darray {
    double *array;
    uint16_t size;
    uint16_t capacity;
} darray_t;

void dpush(dnode_t **head_ref, double data);
bool dpop(dnode_t **head_ref, double *data);
void dclear_list(dnode_t **head_ref);
void dinsert_node(dnode_t **head_ref, double data, int index);
void dinsert_at_end(dnode_t **head_ref, double data);
uint16_t dsearch_node(dnode_t **head_ref, double data);
void ddelete_at(dnode_t **head_ref, double data);
void ddelete_at_end(dnode_t **head_ref);
darray_t dexport(dnode_t **head_ref);

#endif //UNTITLED_DOUBLELINK_H
