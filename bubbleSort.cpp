#include <iostream>
using namespace std;

void swap(int * a, int * b)
{
    int s = *a;
    *a = *b;
    *b = s;
}


void bubble_sort(int a[], int len)
{
    for(int i=len-1;i>=0;i--) {
        for(int j=0;j<i;j++) {
            if(a[j+1] < a[j]) {
                swap(&a[j+1], &a[j]);
            }
        }
    }
}


/*
输入格式：
5
2 1 3 6 3
*/ 
int main()
{
    int n;
    scanf("%d", &n);
    int * a = new int[n];

    for(int i=0;i<n;i++) {
        scanf("%d", a+i);
    }
    bubble_sort(a, n);

    for(int i=0;i<n;i++) {
        printf("%d", a[i]);
    }
    return 0;
}
