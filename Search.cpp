#include <stdio.h>
#define KeyType int

typedef struct DataType {
    int key;
}DataType;

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, * LinkList;//单链表

int seqSearch (DataType array[], int length, KeyType key) {
    for (int i = 0; i < length; i++) {
        if (array[i].key == key) {
            return i;
        }
    }
    return -1;
}

int biSearch (DataType array[], int length, KeyType key) {
    int low = 0;
    int high = length - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid].key == key) {
            return mid;
        }
        else if (array[mid].key < key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int hashSearch (int array[], int key) {
    int x = key % 11;//11为散列表长度
    if (array[x] == key) {
        return x;
    }
    else {
        for (int i = 1;i <= 3;i++) {
            int y = x + i;
            //int y = x + i * i;
            if (array[y] == key) {
                return y;
            }
            // int y = x - i * i;
            // if (array[y] == key) {
            //     return y;
            // }
        }
        return -1;
    }
}

int hashSearch (LinkList array[], int length, int key) {
    int x = key % length;
    LNode* p = array[x]->next;
    while (p != NULL) {
        if (p->data == key) {
            return x;
        }
        p = p->next;
    }
    return -1;
}
