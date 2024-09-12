#include <iostream>
#include <algorithm>
using namespace std;

long long answer = 0;
int pivot_index = 0;

int binary_search(int A[],int low, int high, int key, int len)
 {
  while (low <= high) {
    int mid = low + ((high - low) / 2);

    if (A[mid] == key) {
      return mid;
    }

    if (key < A[mid]) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return -1;
}


void quickSort_count(int arr[], int low, int high, int pivot_list[], int n)
{
    if (low < high && pivot_index < n)
    {
        answer += high - low;

        int pi =  binary_search(arr, low, high, pivot_list[pivot_index], n);

        pivot_index++;


        quickSort_count(arr, low, pi - 1,  pivot_list , n);
        quickSort_count(arr, pi + 1, high, pivot_list, n);


    }
    else if(high == low && pivot_index < n)
    {
        pivot_index++;
    }
}


int main()
{
    int n;
    cin >> n;

    int base[n];
    int pivots_list[n];
    int input;

    for(int i = 0; i < n; i++)
    {
        cin >> input;

        base[i] = input;
    }

    for(int i = 0; i < n; i++)
    {
        cin >> input;

        pivots_list[i] = input;
    }


     int s = sizeof(base) / sizeof(base[0]);

     sort(base, base + s);


     quickSort_count(base, 0, n - 1, pivots_list, n);

     cout << answer;

    return 0;
}
