/*
输入n个数，返回第k小的数，最小的数是第0小
https://www.luogu.com.cn/problem/P1923
*/

#include <iostream>

using namespace std;


void swap(int * a, int * b)
{
  int s = *a;
  *a = *b;
  *b = s;
}


/*
交换法:运用了分治的思想，借用快排代码的前半部分
时间复杂度：O(lgn)
*/
int find_k(int a[], int low, int high, int k)
{
    if(low >= high) {
        return a[low];
    }
    int i = low, j = high;
    int result = 0;
    int pivot = a[(low + high) / 2];
    a[(low + high) / 2] = a[low];
    a[low] = pivot;

    while(i < j) {
        while(i < j && a[j] >= pivot) {
            j--;
        }
        while(i < j && a[i] <= pivot) {
            i++;
        }
        if(i < j) {
            swap(&a[i],&a[j]);
        }
    }

    a[low] = a[i];
    a[i] = pivot;

    if(i > k) {
        result = find_k(a, low, i-1, k);
    } else if(i < k) {
        result = find_k(a, i+1, high, k);
    } else {
        result = a[i];
    }
    return result;
}


int main()
{
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  int * a = new int[n];

  for(int i=0;i<n;i++) {
    scanf("%d", a+i);
  }

  printf("%d ",find_k(a,0,n-1,k));

  return 0;
}

