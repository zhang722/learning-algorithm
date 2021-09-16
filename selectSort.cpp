#include <iostream>

void swap(int *a, int *b)
{
    int s = *a;
    *a = *b;
    *b = s;
}
/*
选择排序
1 不稳定，因为总是在所有相等项中选择最后一个，和前面交换
2 时间复杂度O(n^2)
3 空间复杂度O(1)
*/
void select_sort(int a[], int low, int high)
{
    if(low >= high) {
        return;
    }
    for(int i=low;i<high;i++) {
        int k = i;
        for(int j=i;j<=high;j++) {
            if(a[j] < a[k]) {
                k = j;
            }
        }
        swap(&a[k], &a[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int * a = new int[n];

    for(int i=0;i<n;i++) {
        scanf("%d", a+i);
    }

    select_sort(a, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
