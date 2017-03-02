#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Stack{
public:
    Stack(int length) {
        p = (int *)malloc(sizeof(int) * length);
        top = -1;
    }
    Stack() {
        p = (int *)malloc(sizeof(int) * 5);
        top = -1;
    }
    ~Stack() {
        free(p);
    }
    void push(int data) {
        p[++top] = data;
    }
    int pop() {
        if (top == -1) {
            printf("wrong no data\n");
            return -1;
        }
        int popdata = p[top--];
        // printf("pop: %d\n", popdata);
        return popdata;
    }
    bool isnull() {
        if (top == -1)
            return true;
        else if(top >= 0)
            return false;
    }
    int topdata() {
        return p[top];
    }
private:
    int top;
    int *p;
};

void minpush(Stack &stack, int data, Stack &minstack) {
    stack.push(data);
    if (minstack.isnull()) {
        minstack.push(data);
        return;
    }
    int min = minstack.topdata();
    if (data < min)
        minstack.push(data);
}

void minpop(Stack &stack, Stack &minstack) {
    int data = stack.pop();
    int min = minstack.topdata();
    if (min == data)
        minstack.pop();
}

int minofstack(Stack &minstack) {
    return minstack.topdata();
}

// 利用两个栈实现一个队列
// 栈和队列的主要区别在于元素的次序，一个栈保存的是逆序，再逆序一次，就变成正序了。
// 入栈入newStack，这里保存的是逆序。出栈出oldStack，如果oldStack为空，就把newStack所有元素弹出，放入oldStack。
class Queue{
public:
    void enQueue(int data) {
        newStack.push(data);
    }
    int deQueue() {
        if (oldStack.isnull()) {
            if (newStack.isnull()) {
                printf("no data\n");
                return -1;
            }
            while(!newStack.isnull()) {
                int data = newStack.pop();
                oldStack.push(data);
            }
        }
        int datapop = oldStack.pop();
        printf("pop data: %d\n", datapop);
    }
private:
    Stack newStack;
    Stack oldStack;
};



int main() {
    Queue q1;
    Stack st(1);
    q1.enQueue(1);
    q1.deQueue();
    q1.enQueue(3);
    q1.enQueue(4);
    q1.deQueue();
    q1.enQueue(5);
    q1.deQueue();
    q1.deQueue();
}