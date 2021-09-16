#include <iostream>


/*
这种实现有改进的地方
*/
//void insert_sort(int a[], int low, int high)
//{
//    int pivot = 0;
//    for(int i=low;i<high;i++) {
//        int j = i;
//        while(j >= 0 && a[i+1] < a[j]) {
//            j--;
//        }
//        pivot = a[i+1];
//        /*从后往前依次移动*/
//        for(int k=i;k>=j+1;k--) {
//            a[k+1] = a[k];
//        }
//        a[j+1] = pivot;
//    }
//}

/*
改进后
*/
// void insert_sort(int a[], int low, int high)
// {
//     if(low >= high) {
//         return;
//     }
//     for(int i=low;i<=high;i++) {
//         int j = i;
//         int pivot = a[j];
//         while(j-1 >= low && a[j-1] > pivot) {
//             a[j] = a[j-1];
//             j -= 1;
//         }
//         a[j] = pivot;
//     }
// }

void swap(int *a, int *b)
{
    int s = *a;
    *a = *b;
    *b = s;
}

void insert_sort(int a[], int low, int high)
{
    if(low >= high) {
        return;
    }
    for(int i=low;i<high;i++) {
        for(int j=i+1;j>low;j--) {
            if(a[j] < a[j-1]) {
                swap(&a[j], &a[j-1]);
            }
        }

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

    insert_sort(a, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
