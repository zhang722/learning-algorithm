/*
快速排序
时间复杂度:O(nlgn),极端情况退化到O(n^2)
https://www.luogu.com.cn/problem/P1177
*/

#include <cstdio>

using namespace std;

void swap(int * a, int * b)
{
  int s = *a;
  *a = *b;
  *b = s;
}


/*
刨坑法
*/
//void quick_sort(int a[], int low, int high)
//{
//    if(low >= high) {
//        return;
//    }
//    int i = low, j = high;
//    int pivot = a[(low + high) / 2];
//    a[(low + high) / 2] = a[low];
//    a[low] = pivot;
//
//    while(i < j) {
//        while(i < j && a[j] >= pivot) { //指针继续有两个条件：没有相遇且不需要移动数据
//            j--;
//        }
//        if(i < j) { //确保指针停下是因为需要移动数据而不是相遇
//            a[i++] = a[j];
//        }
//
//        while(i < j && a[i] <= pivot) {
//            i++;
//        }
//        if(i < j) {
//            a[j--] = a[i];
//        }
//    }
//    a[i] = pivot;
//    quick_sort(a, low, i-1);
//    quick_sort(a, i+1, high);
//}




/*
交换法
*/
//void quick_sort(int a[], int low, int high)
//{
//    if(low >= high) {
//        return;
//    }
//    int i = low, j = high;
//    int pivot = a[(low + high) / 2];
//    a[(low + high) / 2] = a[low];
//    a[low] = pivot;
//
//    while(i < j) {
//        while(i < j && a[j] >= pivot) {
//            j--;
//        }
//        while(i < j && a[i] <= pivot) {
//            i++;
//        }
//        if(i < j) {
//            swap(&a[i],&a[j]);
//        }
//    }
//
//    a[low] = a[i];
//    a[i] = pivot;
//    quick_sort(a, low, i-1);
//    quick_sort(a, i+1, high);
//}

/*
三向切分法
*/
void quick_sort(int a[], int low, int high)
{
    if(low >= high) {
        return;
    }
    int lt = low;
    int gt = high;
    int i = low + 1;

    int pivot = a[(low + high) / 2];
    a[(low + high) / 2] = a[low];
    a[low] = pivot;

    while(i <= gt) {
        if(a[i] < pivot) {
            swap(&a[i], &a[lt]);
            lt++;
            i++;
        } else if(a[i] > pivot) {
            swap(&a[i], &a[gt]);
            gt--;
        } else {
            i++;
        }
    }
    quick_sort(a, low, lt-1);
    quick_sort(a, gt+1, high);
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

  quick_sort(a, 0, n-1);

  for (int i = 0; i < n; i++)
  {
    printf("%d ",a[i]);
  }
  return 0;
}

