/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 04 – Dynamic Structures
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : Imam Azkaziyan Ahmad (13224058)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program untuk mengelola Gerbong Kargo Campuran 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDX_UNDEF -1


// struct
typedef struct Node{
    int data;
    struct Node *next;
} Node;


// fungsi membuat node baru
Node *createNode(int val) {
    Node *temp = NULL;
    temp = (Node *) malloc(sizeof(Node));

    temp->data = val;
    temp->next = NULL;

    return temp;
}

// fungsi push ke akhir node
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

// fungsi push ke awal node
void pushFront(Node **l, int val) {
    Node *newNode = createNode(val);

    newNode->next = *l;
    *l = newNode;
}

// fungsi find nilai x
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

// fungsi delete nilai x
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

// fungsi display kee terminal
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

// fungsi memproses perintah
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

// fungsi hapus memory
void freeList(Node **l) {
    Node *temp = NULL;
    temp = *l;
    while (*l != NULL) {
        temp = *l;
        *l = (*l)->next;
        free(temp);
    }
    *l = NULL;
}

// fungsi utama
int main() {
    Node *head = NULL;
    int N = 0;
    scanf("%d", &N);

    process(&head, N);
    display(head);

    freeList(&head);

    return 0;
}