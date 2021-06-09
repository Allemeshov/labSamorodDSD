#include "lab34.h"


void lab34() {
    list list;
    int n;
    int c;
    int temp;

    std::cout << "Input number count: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Input number of card[" << i << "]: ";
        std::cin >> temp;
        add(list, temp);
    }

    print_list(list);

    std::cout << "Input how many time to process: ";
    std::cin >> c;

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n; j++) {
            if (find_by_index(list, j)->number % 5 == 0) {
                remove_by_index(list, j);
                add_by_index(list, rand() % 10, j);
            }
        }
    }

    print_list(list);
}


void free(node *n) {
    n->next = NULL;
}

void _free_list(list &l, node *s) {
    while (s->next != l.head)
        _free_list(l, s->next);

    free(s);
}

void free_list(list &l) {
    _free_list(l, l.head);
    l.tail = l.head = NULL;
}

void constr_list(list &l) {
    l.head = NULL;
    l.tail = NULL;
}

bool chk_empty(list l) {
    return (l.head == NULL);
}

void add(list &l, int n) {
    l.size++;

    node *temp = new node;

    temp->next = l.head;
    temp->number = n;
    if (l.head != NULL) {
        l.tail->next = temp;
        l.tail = temp;
    } else l.head = l.tail = temp;
}

void remove_first(list &l) {
    if (!l.head) return;

    node *p = NULL;

    if (l.head == l.tail) {
        p = l.head;
        l.head = l.tail = NULL;;
    }
    if (l.head) {
        p = l.head;
        l.head = l.head->next;
        l.tail->next = l.head;
    }

    l.size--;
    free(p);
}

node *find_by_index(list &l, int index) {
    if (l.size < index) return NULL;

    node *p = l.head;
    int i = 0;
    while (p != NULL && i < index) {
        p = p->next;
        i++;
    }
    return p;
}

void add_by_index(list &l, int number, int index) {
    if (index >= l.size) {
        add(l, number);
        return;
    }

    node *c = new node();
    c->number = number;

    if (index == 0) {
        l.tail->next = c;
        c->next = l.head;
        l.tail = c;
        return;
    }

    node *p = find_by_index(l, index - 1);

    c->next = p->next;
    p->next = c;
}

void remove_by_index(list &l, int index) {
    if (index == 0) {
        remove_first(l);
        return;
    }

    node *p = find_by_index(l, index - 1);

    if (p == NULL) return;

    node *temp = p->next->next;

    if (p->next == l.tail)
        l.tail = p;

    free(p->next);

    p->next = temp;
}

void print_list(list l) {
    node *tempHead = l.head;

    int temp = l.size;
    while (temp != 0) {
        printf("%d ", tempHead->number);
        tempHead = tempHead->next;
        temp--;
    }

    std::cout << std::endl;
}

int size_list(list l) {
    return l.size;
}

