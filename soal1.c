#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDX_UNDEF -1

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *createNode(int val) {
    Node *temp = NULL;
    temp = (Node *) malloc(sizeof(Node));

    temp->data = val;
    temp->next = NULL;

    return temp;
}

void pushBack(Node **l, int val) {
    Node *newNode = createNode(val);

    if (*l == NULL) {
        *l = newNode;
    }
    else {
        Node *temp = *l;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void pushFront(Node **l, int val) {
    Node *newNode = createNode(val);

    newNode->next = *l;
    *l = newNode;
}

int find(Node **l, int val) {

    int idx = 0;
    Node *temp = *l;

    while (temp != NULL) {
        if (temp->data == val) {
            return idx;
        }
        temp = temp->next;
        idx++;
    }

    return IDX_UNDEF;
}

void delete(Node **l, int val) {
    Node *temp = *l;
    Node *prev = NULL;

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL) {
        *l = temp->next;
    } else {
        prev->next = temp->next;
    }
}

void display(Node *l) {
    Node *temp = l;
    printf("LIST");
    if (temp != NULL) printf(" ");
    else {
        printf(" EMPTY");
        return;
    }
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL) printf(" ");
    }
}

void process(Node **l, int N) {
    int command = 0, val = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &command, &val);

        switch (command)
        {
        case 1:
            pushFront(l, val);
            break;
        
        case 2:
            pushBack(l, val);
            break;
        
        case 3:
            delete(l, val);
            break;

        case 4:
            int idx = find(l, val);
            if (idx != IDX_UNDEF) printf("FOUND %d\n", idx);
            else printf("NOT FOUND\n");
        
        default:
            break;
        }
    }
}

int main() {
    Node *head = NULL;
    int N = 0;
    scanf("%d", &N);

    process(&head, N);
    display(head);

    return 0;
}