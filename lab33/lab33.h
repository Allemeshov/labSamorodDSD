#ifndef SAMORODLABDSD_LAB33_H
#define SAMORODLABDSD_LAB33_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <vector>


void lab33();


struct Node {

    std::string number; // данные
    Node *next; // ссылка на следующий элемент
};

struct List {
    Node *head; // ссылка на начало
    Node *tail; // ссылка на конец
};

void constr_list(List &l);

bool chk_empty(List l);

void add(List &l, std::string n);

void remove_first(List &l);

Node *find_by_index(List &l, int index);

void add_by_index(List &l, std::string number, int index);

void remove_by_index(List &l, int index);

void print_list(List l);

int size_list(List l);

void free_list(List &l);

#endif //SAMORODLABDSD_LAB33_H
