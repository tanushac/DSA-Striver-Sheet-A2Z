/*the first occurrence of the element = lb(the index returned by lower bound)
and the last occurrence = (ub-1)(ub = the index returned by upper bound).

There are some edge cases.

Edge Case 1: If the element is not present in the array.

If the target number is not present in the array, the lower bound will return the index of the nearest greater element. So, in the code, we have to check the following:
If arr[lb] != k: The element is not present in the array and so, there will be no first or last occurrences. So, we will return -1.
Edge Case 2: If the element is not present in the array and all the array elements are smaller than the target number.*/

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int lowerBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int lb = lowerBound(arr, n, k);
    if (lb == n || arr[lb] != k) return { -1, -1};
    int ub = upperBound(arr, n, k);
    return {lb, ub - 1};
}


int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}
