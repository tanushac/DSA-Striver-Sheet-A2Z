/* Consequently, the previous approach will not work when arr[low] = arr[mid] = arr[high].

How to handle the edge case arr[low] = arr[mid] = arr[high]:

In the algorithm, we first check if arr[mid] is the target before identifying the sorted half. If arr[mid] is not our target, we encounter this edge case. In this scenario, since arr[mid] = arr[low] = arr[high], it means that neither arr[low] nor arr[high] can be the target. To handle this edge case, we simply remove arr[low] and arr[high] from our search space, without affecting the original algorithm. 

To eliminate elements arr[low] and arr[high], we can achieve this by simply incrementing the low pointer and decrementing the high pointer by one step. We will continue this process until the condition arr[low] = arr[mid] = arr[high] is no longer satisfied.*/

#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}
