#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;
  vector<int> L;
  vector<int> R;
  L.reserve(n1);
  R.reserve(n2);
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &arr, int left, int right)
{
  if (right > left)
  {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1)
  {
    int n;
    cin >> n;
    if (n == 0)
    {
      return 0;
    }
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
      int inp;
      cin >> inp;
      arr.push_back(inp);
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
      cout << arr[i];
      if (i != n - 1)
      {
        cout << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}

/*
5
3 4 2 1 5
5
2 3 2 3 1
0
*/