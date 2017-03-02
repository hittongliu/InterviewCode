#include <stdlib.h>
#include <stdio.h>


void print(int a[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d\n", a[i]);
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 冒泡排序算法
void bubbleSort(int a[], int length) {
    if (length == 1)
        return;
    int j = length-1;
    while (j != 0) {
        for (int i = 1; i <= j; i++) {
            if (a[i -1] >= a[i]) {
                int temp = a[i-1];
                a[i-1] = a[i];
                a[i] = temp;
            }
        }
        j--;
    }
    for (int i = 0; i < length; i++)
        printf("%d\n", a[i]);
}


// 快速排序算法

int partition(int a[], int low, int high) {
    int privot = a[low];
    while (low < high) {
        while((low < high) && (a[high] >= privot))
            high--;
        swap(&a[low], &a[high]);
        while((low < high) && (a[low] <= privot))
            low++;
        swap(&a[low], &a[high]);
    }
    return low;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int part = partition(a, low, high);
        quickSort(a, low, part -1);
        quickSort(a, part+1, high);
    }
}

// 归并排序，首先不断向下分裂，然后对排好序的两部分进行合并
void Merge(int a[], int low, int middle, int high) {
    int *temp = new int[high - low + 1];
    int i = low; int j = middle;
    while ((i < middle)&&(j <= high)) {
        if (a[i] < a[j])
            *temp = a[i++];
        else
            *temp = a[j++];
        temp++;
    }
    while(i < middle) {
        *temp = a[i];
        i++;temp++;
    }
    while(j <= high) {
        *temp = a[j];
        j++;temp++;
    }
    for (int k = 0; k <= high - low; k++) {
        a[k] = temp[k];
    }
    delete []temp;
}

void Msort(int a[], int low, int high) {
    int middle = (low + high) / 2;
    if (low < high) {
        Msort(a, low, middle-1);
        Msort(a, middle, high);
        Merge(a, low, middle, high);
    }
}



int main() {
    int a[6] = {1,14,6,100,23,15};
    Msort(a, 0, 5);
    print(a, 6);
}