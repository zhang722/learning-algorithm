/*
计数排序
时间复杂度:O(n)
https://www.luogu.com.cn/problem/P1271
*/

#include <iostream>
#include <cstring>
using namespace std;

void counting_sort(int * arr, int len);

int main()
{
  int * a = new int[5]; 
  a[0] = 11;
  a[1] = 13;
  a[2] = 12;
  a[3] = 12;
  a[4] = 11;
  counting_sort(a, 5);
  for(int i=0;i<5;i++) {
    cout << a[i] <<' ';
  }
  return 0;
}

/*
6
13 312 321 342 654 65
*/

void counting_sort(int * arr, int len) 
{
  int max = 0, min = 0;

  for(int i=0;i<len;i++) {
    if(max < arr[i]) {
      max = arr[i];
    }
    if(min > arr[i]) {
      min = arr[i];
    }
  }
  int range = max - min + 1;
  int * count = new int[range];

  for(int m=0;m<range;m++) {
    count[m] = 0;
  }

  for(int i=0;i<len;i++) {
    count[arr[i] - min] ++;
  }
  int index = 0;
  for(int i=0;i<range;i++) {
    while(count[i]>0) {
      arr[index++] = min + i;
      count[i]--;
    }
  }
  
}


