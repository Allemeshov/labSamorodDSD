#include "lab30.h"

void lab30() {
    StackA stack;

    std::string number;

    std::cout << "Введите число: ";
    std::cin >> number;

    int length = -1;
    while (number[length + 1] != '\0') {
        ++length;
    }
    ++length;

    InitStack(&stack, length);

    for (int i = 0; i < length; ++i) {
        if (!Push(&stack, number[i])) {
            std::cout << "Push error\n";
            return;
        }
    }

    std::cout << "\nReversed number: ";
    for (int i = 0; i < length; ++i) {
        std::cout << Pop(&stack);
    }
    std::cout << std::endl;

    Destruct(&stack);
    return;
}


void InitStack(StackA *s, int l) { // инициализация стека из l элементов
    s->A = (char *) malloc(sizeof(char) * l);
    if (s->A) {
        s->l = l;
    } else
        s->l = -1;
    s->top = -1;
}

void PrintStack(StackA const *s) { // вывод элементов стека
    int i;
    for (i = 0; i <= s->top; i++)
        printf("%-7.3lf ", (s->A)[i]);
}

void Destruct(StackA *s) { // уничтожение стека
    if (s->A) free(s->A);
    s->l = -1;
    s->top = -1;
}

int Push(StackA *s, char v) { // добавление элемента в стек
    if (s->top >= s->l - 1) return 0;
    s->top++;
    s->A[s->top] = v;
    return 1;
}

char Pop(StackA *s) { // достать элемент
    if (s->top >= 0)
        return s->A[s->top--];
    else return 1e300;
}

double Peek(StackA const *s) { // просмотреть верхний элемент без удаления
    if (s->top >= 0)
        return s->A[s->top];
    else return 1e300;
}

void Clear(StackA *s) { //очистка стека
    s->top = -1;
}

int IsEmptyStack(StackA const *s) { // проверка стека на наличие элементов
    if (s->top < 0) return 1;
    else return 0;
}
