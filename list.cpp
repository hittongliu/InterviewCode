#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node * next;
}ListNode;

void deleteDuplate(ListNode *node){
    ListNode *current = node;
    while(current) {
        int currentData = current->data;
        ListNode *pCurrent = current;
        while(pCurrent->next) {
            if (pCurrent->next->data == currentData) {
                printf("del\n");
                ListNode *delNode = pCurrent->next;
                if (pCurrent->next->next)
                    pCurrent->next = pCurrent->next->next;
                else
                    pCurrent->next = NULL;
                free(delNode);
            } else {
                pCurrent = pCurrent->next;
            }
        }
        current = current->next;
    }
}

ListNode* nthTolast(ListNode *head, int k) {
    ListNode *knode = head;
    for(int i = 0; i < k; i++) {
        if (!knode->next) {
            printf("node numbers not have k\n");
            return NULL;
        }
        knode = knode->next;
    }
    printf("List to k knode:%d\n", knode->data);
    while(knode->next){
        knode = knode->next;
        head = head->next;
    }
    printf("List to k last:%d\n", head->data);
    return head;
}

void printList(ListNode *head) {
    while(head) {
        printf("head: %d\n", head->data);
        head = head->next;
    }
    printf("printf over\n");
}

int main() {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 2;
    int nodeNum = 10;
    ListNode *p = head;
    for (int i = 1; i < 10; i++) {
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        temp->data = i ;
        p->next = temp;
        p = p->next;
    }
    nthTolast(head, 11);
}