/*****************Iterative approach************/
#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

/*****************Recursive approach************/
#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, mid + 1, high, target);
    }
    else
    {
        return binarySearch(arr, low, mid - 1, target);
    }
}

int search(vector<int> &nums, int target)
{
    return binarySearch(nums, 0, nums.size() - 1, target);
}
