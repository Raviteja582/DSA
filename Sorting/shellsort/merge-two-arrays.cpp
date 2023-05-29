#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?page=1&status[]=solved&category[]=Sorting&sortBy=submissions

class Solution {
public:
// Function to merge the arrays.
#define ll long long
  ll find_gap(ll gap) {
    if (gap <= 1)
      return 0;

    // return ceil of the gap
    return (gap / 2) + (gap % 2);
  }
  void merge(long long arr1[], long long arr2[], int n, int m) {
    ll gap = n + m;
    for (gap = find_gap(gap); gap > 0; gap = find_gap(gap)) {
      int i, j;
      for (i = 0; (i + gap) < n; i++) {
        if (arr1[i] > arr1[i + gap]) {
          swap(arr1[i], arr1[i + gap]);
        }
      }

      for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++) {
        if (arr1[i] > arr2[j]) {
          int tmp = arr2[j];
          arr2[j] = arr1[i];
          arr1[i] = tmp;
        }
      }

      if (j < m) {
        for (j = 0; (j + gap) < m; j++) {
          if (arr2[j] > arr2[j + gap]) {
            swap(arr2[j], arr2[j + gap]);
          }
        }
      }
    }
  }
};

int main() { return 0; }