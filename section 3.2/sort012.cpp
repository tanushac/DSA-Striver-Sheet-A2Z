/************Brute force***********/
// sort the array using any sorting algorithm (merge sort,quick sort etc.)
/************better approach*************/
#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n)
{

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }

    // Replace the places in the original array:
    for (int i = 0; i < cnt0; i++)
        arr[i] = 0; // replacing 0's

    for (int i = cnt0; i < cnt0 + cnt1; i++)
        arr[i] = 1; // replacing 1's

    for (int i = cnt0 + cnt1; i < n; i++)
        arr[i] = 2; // replacing 2's
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
/***********************Optimal Approach*************/
// Dutch National Flag Algorithm
void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
