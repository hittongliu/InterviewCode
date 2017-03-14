#include <stdlib.h>
#include <stdio.h>

typedef struct List{
    List *next;
    
    int data;
}ListNode;

/* 删除重复的节点
两个指针Current和pCurrent，一个遍历所有的节点。
pCurrent从Current节点开始遍历，删除所有与之重复的元素。
*/
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

/* 打印倒数第K个节点。
可以定义一个指针，先走k步。
然后头指针和该指针同时往后走，该指针走到结尾的时候，头指针就走到倒数第K个位置。
*/

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

/* 删除第K个节点（其他节点不能访问）：
采用替换的策略。
第K个节点的值替换为下一个节点的数值。然后删掉下一个节点。
注意有缺点：如果是尾部节点，无法操作。
*/
void deletNodeK(ListNode *nodeK) {
    if (nodeK == NULL)
        return;
    ListNode *next = nodeK->next;
    if (next == NULL)
        return;
    nodeK->data = next->data;
    nodeK->next = next->next;
    free(next);
}

void listadd(ListNode *a, ListNode *b, int val, ListNode *result) {
    if ((a == NULL) && (b == NULL) && (val == 0))
        return ;
    ListNode *p = new ListNode;
    int value = val;
    if ( a != NULL) {
        value += a->data;
    }
    if (b != NULL)
        value += b->data;
    p->data = value % 10;
    result->next = p;
    listadd(a ? a->next:NULL, b?b->next:NULL, value >= 10?1:0, p);
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
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));p->data = 0;
    ListNode *head1 = p;
    for (int i = 1; i < 4; i++) {
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        temp->data = i ;
        p->next = temp;
        p = p->next;
    }

    ListNode *p2 = (ListNode *)malloc(sizeof(ListNode));p2->data = 0;
    ListNode *head2 = p2;
    for (int i = 1; i < 5; i++) {
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        temp->data = i * 2 ;
        p2->next = temp;
        p2 = p2->next;
    }

    listadd(head1, head2, 0, head);
    printList(head);
}
