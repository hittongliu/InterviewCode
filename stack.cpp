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
        p = (int *)malloc(sizeof(int) * 100);
        top = -1;
    }
    ~Stack() {
        free(p);
    }
    void push(int data) {
        p[++top] = data;
    }
    int pop() {
        if (top == 0) {
            printf("wrong no data\n");
            return -1;
        }
        int popdata = p[top--];
        printf("pop: %d\n", popdata);
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

int main() {
    Stack stack,minstack;
    minpush(stack, 6, minstack);
    printf("min:%d\n", minofstack(minstack));
    minpush(stack, 3, minstack);
    printf("min:%d\n", minofstack(minstack));
    minpush(stack, 5, minstack);
    printf("min:%d\n", minofstack(minstack));
    minpush(stack, 2, minstack);
    printf("min:%d\n", minofstack(minstack));
    minpop(stack, minstack);
    printf("min:%d\n", minofstack(minstack));
}