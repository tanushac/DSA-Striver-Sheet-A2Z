/*What is Upper Bound?
The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.
The upper bound is the smallest index, ind, where arr[ind] > x.
But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. The main difference between the lower and upper bound is in the condition. For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.*/
/************BRUTE FORCE APPROACH************/
// linear search
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            // lower bound found:
            return i;
        }
    }
    return n;
}
/*******************OPTIMAL APPROACH***************/
#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &arr, int x, int n){
  int low = 0;
  int high = n - 1;
  int ans = n;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] > x) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

