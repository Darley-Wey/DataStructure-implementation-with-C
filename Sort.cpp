#include <stdio.h>
#include <algorithm>
#define KeyType int

typedef struct DataType {
    int key;
} DataType;

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;  //单链表

;

void creatData(DataType array[], int key[], int length) {
    for (int i = 0; i < length; i++) {
        array[i].key = key[i];
    }
}

void printData(DataType array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d,", array[i].key);
    }
    printf("\n");
}

void insertSort(DataType array[], int length) {
    int i, j;
    for (i = 2; i <= length; i++) {
        if (array[i].key < array[i - 1].key) {
            array[0] = array[i];  //找出一个较小值
            for (j = i - 1; array[0].key < array[j].key; --j) {
                array[j + 1] = array[j];  //寻找插入位置并整体移动
            }
            array[j + 1] = array[0];  //插入
        }
    }
}

void biInsertSort(DataType array[], int length) {
    int mid, low, high;
    for (int i = 2; i <= length;
         i++) {  //数组0号位无数据，从第2位与第1位比较开始
        array[0] = array[i];
        low = 1;
        high = i - 1;
        while (low <= high) {  //二分查找
            mid = (low + high) / 2;
            if (array[0].key < array[mid].key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= high + 1; j--) {  //整体移动
            array[j + 1] = array[j];
        }
        array[high + 1] = array[0];  //插入
    }
}
//未考察
void shellSort(DataType array[], int length) {
    int i, j, delta;
    for (delta = length / 2; delta >= 1; delta = delta / 2) {  //设定delta
        for (i = delta + 1; i <= length; i++) {                //分组遍历
            if (array[i].key < array[i - delta].key) {  //直接插入排序
                array[0] = array[i];                    //存储当前元素
                for (j = i - delta; j > 0 && array[0].key < array[j].key;
                     j -= delta) {  //分组比较
                    array[j + delta] = array[j];
                }
                array[j + delta] = array[0];  //插入
            }
        }
    }
}
void bubbleSort(DataType array[], int length) {
    int flag;
    DataType temp;
    for (int i = 1; i < length; i++) {
        flag = 0;                                //交换标志
        for (int j = 1; j <= length - i; j++) {  //尾部i个已有序
            if (array[j].key > array[j + 1].key) {  //大值向后交换，直至最后
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            return;
        }
    }
}
void quickSort(DataType array[], int low, int high) {
    if (low >= high)
        return;
    int i = low, j = high;
    DataType temp = array[i];
    while (i < j) {
        while (i < j && temp.key <= array[j].key) {
            j--;  //后找小
        }
        array[i] = array[j];  //移至前
        while (i < j && temp.key >= array[i].key) {
            i++;  //前找大
        }
        array[j] = array[i];  //移植后
    }
    array[i] = temp;                //基准元素归位
    quickSort(array, low, i - 1);   //递归枢纽前半部分
    quickSort(array, i + 1, high);  //递归枢纽后半部分
}

void hoareQuickSort(DataType array[], int low, int high) {
    if (low >= high)
        return;
    int i = low - 1, j = high + 1;
    DataType temp = array[low];
    while (i < j) {
        while (temp.key < array[--j].key)
            ;  //后找小
        while (temp.key > array[++i].key)
            ;  //前找大
        if (i < j)
            std::swap(array[i], array[j]);  //移植后
    }
    quickSort(array, low, j);       //递归枢纽前半部分
    quickSort(array, j + 1, high);  //递归枢纽后半部分
}

//znc20
void selectSort(DataType array[], int length) {
    DataType temp;
    int small;
    for (int i = 0; i < length - 1; i++) {
        small = i;
        for (int j = i + 1; j < length;
             j++) {  //头部i个元素已有序，寻找最小元素的位置
            if (array[j].key < array[small].key) {
                small = j;
            }
        }
        if (small != i) {  //最小元素移至i，i+1
            temp = array[i];
            array[i] = array[small];
            array[small] = temp;
        }
    }
}
int main() {
    int key[] = {0, 56, 34, 67, 89, 56, 23, 45, 78, 12};
    const int length = sizeof(key) / sizeof(int);
    DataType array[length];
    creatData(array, key, length);
    printData(array, length);
    // shellSort (array, length - 1);
    // bubbleSort (array, length-1);
    hoareQuickSort(array, 1, length - 1);
    // quickSort(array, 0, length - 1);
    //selectSort (array, length);
    printData(array, length);
}
