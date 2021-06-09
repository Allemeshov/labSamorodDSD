#ifndef SAMORODLABDSD_LAB30_H
#define SAMORODLABDSD_LAB30_H

#ifndef LAB_30_STACK_H
#define LAB_30_STACK_H

#include <iostream>

void lab30();

typedef struct {
    char *A;
    int l;
    int top;
} StackA;

int Push(StackA *s, char v);

char Pop(StackA *s);

double Peek(StackA const *s);

int IsEmptyStack(StackA const *s);

void Clear(StackA *s);

void InitStack(StackA *s, int l);

void PrintStack(StackA const *s);

void Destruct(StackA *s);

#endif //LAB_30_STACK_H


#endif //SAMORODLABDSD_LAB30_H
