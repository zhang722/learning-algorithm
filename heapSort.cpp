#include <iostream>

void swap(int a[], int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

/*
堆i节点最大化
*/
void max_heapify(int a[], int len, int i)
{
    if(len <= 1) {
        return;
    }
    int l = i * 2;  //左子节点在堆中的位置
    int r = i * 2 + 1;  //右子节点在堆中的位置
    int m = i;  //i及其子节点中的最大节点的位置
    if(l <= len && a[l-1] > a[m-1]) {
        m = l;
    }
    if(r <= len && a[r-1] > a[m-1]) {
        m = r;
    }
    if(m != i) {
        swap(a, i-1, m-1);
        max_heapify(a, len, m);
    }
}


/*
初始化最大堆
*/
void heap_init(int a[], int len)
{
    for(int i=len/2; i>0; i--) {
        max_heapify(a, len, i);
    }
}



void heap_sort(int a[], int low, int high)
{
    int s = high - low + 1;
    heap_init(a, s);
    while(s >= 2) {
        swap(a, 0, s-1);
        s -= 1;
        max_heapify(a, s, 1);
    }
}

void main()
{
    int n;
    scanf("%d", &n);
    int * a = new int[n];

    for(int i=0;i<n;i++) {
        scanf("%d", a+i);
    }

    heap_sort(a, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}
