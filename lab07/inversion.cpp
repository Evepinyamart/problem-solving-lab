#include <bits/stdc++.h>
using namespace std;

long long merge(vector<long long> &arr, long long left, long long mid, long long right, long long &countInv)
{
  long long n1 = mid - left + 1;
  long long n2 = right - mid;
  vector<long long> L(n1);
  vector<long long> R(n2);
  for (long long i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (long long j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  long long i = 0, j = 0, k = left;
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
      countInv += n1 - i;
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
  return countInv;
}

long long mergeSort(vector<long long> &arr, long long left, long long right, long long &countInv)
{
  if (right > left)
  {
    long long mid = (left + right) / 2;
    mergeSort(arr, left, mid, countInv);
    mergeSort(arr, mid + 1, right, countInv);

    merge(arr, left, mid, right, countInv);
  }
  return countInv;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> arr;
  for (int i = 0; i < n; i++)
  {
    long long inp;
    cin >> inp;
    arr.push_back(inp);
  }
  long long countInv = 0;
  mergeSort(arr, 0, n - 1, countInv);
  cout << countInv;
  return 0;
}