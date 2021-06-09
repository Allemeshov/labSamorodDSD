#include "lab33.h"

void lab33() {
    List list;
    constr_list(list);


    std::ifstream file;
    file.open("text.txt");

    if (!file.is_open()) {
        std::cout << "\nError. Cannot read file \"text.txt\"\n";
        return;
    }

    int n;

    while (!file.eof()) {
        file >> n;
        add(list, n);
    }
    file.close();

    int size = size_list(list);

    print_list(list);
    std::cout << std::endl;

    std::cout << "Enter number: ";
    std::cin >> n;


    for (int i = 0; i < size; i++) {
        if (n <= find_by_index(list, i)->number) {
            add_by_index(list, n, i);
            break;
        }
    }

    print_list(list);
    std::cout << std::endl;

    size = size_list(list);

    for (int i = 0; i < size - 1; i++) {
        if (find_by_index(list, i)->number == find_by_index(list, i + 1)->number) {
            remove_by_index(list, i + 1);
            size--;
        }
    }

    print_list(list);
    std::cout << std::endl;
}


void _free_list(Node *s) {
    s->number = 0;
    s->next = NULL;
}

void free_list(List &l) {
    _free_list(l.head);
    l.head = NULL;
}

void constr_list(List &l) {
    l.head = NULL;
}

bool chk_empty(List l) {
    return (l.head == NULL);
}

void add(List &l, int n) {
    Node *c = new Node();

    c->number = n;
    c->next = NULL;
    if (chk_empty(l))
        l.head = c;
    else
        l.tail->next = c;
    l.tail = c;
}

void remove_first(List &l) {
    Node *p;

    if (l.head) {
        p = l.head;
        l.head = l.head->next;

        _free_list(p);
    }

}

Node *find_by_index(List &l, int index) {
    Node *p = l.head;
    int i = 0;
    while (p != NULL && i < index) {
        p = p->next;
        i++;
    }
    return p;
}

void add_by_index(List &l, int number, int index) {
    if (index == 0) {
        Node *c = new Node();
        c->number = number;

        c->next = l.head;
        l.head = c;
        return;
    }

    Node *p = find_by_index(l, index - 1);
    Node *c = new Node();
    c->number = number;

    if (!p) {
        l.tail->next = c;
        l.tail = c;
    } else {
        c->next = p->next;
        p->next = c;
    }
}

void remove_by_index(List &l, int index) {
    if (index == 0) {
        remove_first(l);
        return;
    }

    Node *p = find_by_index(l, index - 1);

    if (p == NULL || p->next == NULL) return;

    Node *temp = p->next->next;

    if (p->next == l.tail)
        l.tail = p;

    _free_list(p->next);

    p->next = temp;
}

void print_list(List l) {
    while (l.head != NULL) {
        printf("%d ", l.head->number);
        l.head = l.head->next;
    }
}

int size_list(List l) {
    int i = 0;
    while (l.head != NULL) {
        i++;
        l.head = l.head->next;
    }
    return i;
}
