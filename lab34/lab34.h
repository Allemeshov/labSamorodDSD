#ifndef SAMORODLABDSD_LAB34_H
#define SAMORODLABDSD_LAB34_H

#include <stdio.h>
#include <malloc/malloc.h>
#include <string.h>
#include <iostream>


void lab34();


struct node {
    int number;
    node *next;
};

struct list {
    node *head = NULL;
    node *tail = NULL;
    int size = 0;
};

void free(node *n);

void constr_list(list &l);

bool chk_empty(list l);

void add(list &l, int n);

void remove_first(list &l);

node *find_by_index(list &l, int index);

void add_by_index(list &l, int number, int index);

void remove_by_index(list &l, int index);

void print_list(list l);

int size_list(list l);

void free_list(list &l);

#endif //SAMORODLABDSD_LAB34_H
