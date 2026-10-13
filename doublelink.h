//
// Created by pimen on 13.10.2026.
//

#ifndef UNTITLED_DOUBLELINK_H
#define UNTITLED_DOUBLELINK_H
#include <stdbool.h>

typedef struct dnode {
    struct dnode *prev;
    double data;
    struct dnode *next;
} dnode_t;

void dpush(dnode_t **head_ref, double data);
bool dpop(dnode_t **head_ref, double *data);
void dclear_list(dnode_t **head_ref);
void dinsert_node(dnode_t **head_ref, double data, int index);

#endif //UNTITLED_DOUBLELINK_H
