#include <iostream>


/*
找到最大值，以便得到最大位数
*/
int find_max(int a[], int low, int high)
{
    int m = a[low];
    for(int i=low+1;i<=high;i++) {
        if(a[i] > m) {
            m = a[i];
        }
    }
    return m;
}



int pow(int x, int e)
{
    int t = 1;
    if (e == 0) {
        return 1;
    }
    if (e == 1) {
        return x;
    }
    for (int i = e; i >= 1; i--) {
        t *= x;
    }
    return t;
}


/*
对第i位进行计数排序（最低位是第1位）
*/
void counting_sort(int a[], int low, int high, int i)
{
    int c[10] = {0};    //计数数组
    int bucket[high-low+1]; //辅助数组
    for (int j = low; j <= high; j++) {
        int k = a[j] / pow(10,i-1) % 10;    //得到第i位
        c[k] ++;
    }

    /*很重要*/
    for (int j = low; j < high; j++) {
        c[j+1] += c[j];
    }
    /*必须从后往前遍历*/
    for (int j = high; j >= low; j--) {
        int k = a[j] / pow(10,i-1) % 10;    //得到第i位
        bucket[c[k] - 1] = a[j];
        c[k] --;
    }
    /*复制回原数组*/
    for (int j = low; j<= high; j++) {
        a[j] = bucket[j];
    }
}


void radix_sort(int a[], int low, int high)
{
    int m = find_max(a, low, high);
    int l = 1;//数字最大长度
    int dec = 1;
    while(m / dec > 0) {
        dec *= 10;
        l ++;
    }
    for(int i=1;i<=l;i++) {
        counting_sort(a, low, high, i);
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

    radix_sort(a, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}
