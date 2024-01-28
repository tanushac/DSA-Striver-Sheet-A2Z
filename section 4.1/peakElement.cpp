/*If arr[i] > arr[i-1]: we are in the left half.
If arr[i] > arr[i+1]: we are in the right half.
How to eliminate the halves accordingly:

If we are in the left half of the peak element, we have to eliminate this left half (i.e.    
low = mid+1). Because our peak element appears somewhere on the right side.
If we are in the right half of the peak element, we have to eliminate this right half (i.e.     high = mid-1). Because our peak element appears somewhere on the left side.
If an index is a common point where a decreasing sequence ends and an increasing sequence begins, we can actually eliminate either the left or right half. Because both halves of such an index contain a peak. 

So, we decide to merge this case with the condition If arr[i+1] < arr[i]. You can choose otherwise as well.*/
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        //increasing curve
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        //decreasing curve
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << " and the peak value is: "<<arr[ans]<<"\n";
    return 0;
}
