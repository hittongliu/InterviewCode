#include <stdio.h>
#include <stdlib.h>

/*
判断数组中是否存在出现次数大于一半的数。
删掉任意两个不同的数，成对的删掉
*/

bool printHalfMajor(int a[], int length) {
    int cands;
    int times = 0;
    // 第一次遍历，想象假设某个数的出现次数超过一半了，那么最后一定会被保留下来。
    // times++相当于碰到了相同的数，保留出现次数。然后碰到不同的数，就time--，
    // 表示牺牲掉一个cands删掉与之不同的数。
    for(int i = 0; i < length; i++) {
        if (times == 0) {
            cands = a[i];
        }
        if (cands == a[i])
            times ++;
        if (cands != a[i])
            times--;
    }
    int halflength = 0;
    // 第二次遍历为了确保这个数真的是对的。因为1，2，3也会被保留下来3。
    for(int i = 0; i < length; i++) {
        if (a[i] == cands)
            halflength++;
    }
    if (halflength > (length /2.0)) {
        printf("most number:%d\n", cands);
        return true;
    } else {
        printf("次数不超过一半\n");
        return false;
    }
}

/*
需要排序的最短子数组的长度。
例如a = [1,3,2,4,5,6,4,7,9],需要排序[3,2,4,5,6,4]
思考一下3和4两个端点的选取。
3这个点是因为它比右侧序列的最小值还要大。
4是因为比左侧序列的最大值还要小。
 */

void getMinLength(int a[], int length) {
    int leftIndex = -1;
    int min = a[length - 1];
    // 其实这里保证了两点，首先leftIndex之前的序列肯定是升序的，而且leftIndex-1肯定比后面序列的最小值还要小。
    for(int i = length - 2;i >= 0; i--) {
        if(a[i] < min)
            min = a[i];
        if (a[i] > min)
            leftIndex = i;
    }
    int rightIndex = length;
    int max = a[0];
    for (int i = 1; i < length; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < max)
            rightIndex = i;
    }
    printf("leftIndex:%d\n", leftIndex);
    printf("rightIndex:%d\n", rightIndex);
}

int main()
{
    int a[9] = {1,3,2,4,5,6,4,7,9};
    getMinLength(a,9);
}

