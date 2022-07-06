#include "LinkList.cpp"

void delete_equal(LNode* h) {
    LNode* p = h->next;
    while (p && p->next) {
        if (p->data == p->next->data) {
            LNode* q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

int main() {
    LNode* h = (LNode*)malloc(sizeof(LNode));
    h->next = NULL;
    int arr[10] = {0, 1, 2, 2, 2, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++) {
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data = arr[i];
        s->next = h->next;
        h->next = s;
    }
    delete_equal(h);
    LNode* p = h->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}
