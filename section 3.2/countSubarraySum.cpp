/*******************Brute Force*******************/
#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the given array.
    int cnt = 0;        // Number of subarrays:

    for (int i = 0; i < n; i++)
    { // starting index i
        for (int j = i; j < n; j++)
        { // ending index j

            // calculate the sum of subarray [i...j]
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += arr[K];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
/***********************Better Approach*****************/
// removing third loop
#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the given array.
    int cnt = 0;        // Number of subarrays:

    for (int i = 0; i < n; i++)
    { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++)
        { // ending index j
            // calculate the sum of subarray [i...j]
            // sum of [i..j-1] + arr[j]
            sum += arr[j];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}
/********************Optimal Solution***************/
// uses concept of prefix sum also used in longest subarray with sum k
#include <bits/stdc++.h>
using namespace std;
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the given array.
    map<int, int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map. since an element by itself can be a subarray with the given sum.
    for (int i = 0; i < n; i++)
    {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];
        /*This line adds the count of subarrays whose sum is equal to k by looking up the value
        associated with remove in the mpp map. The map stores the frequency of prefix sums encountered so far*/

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
        /*This line updates the count of the current preSum in the map. It keeps track of how many times a
        particular prefix sum has been encountered.*/
    }
    return cnt;
}
/*The key is a prefix sum, and the value is the count of occurrences of that particular prefix sum in the array processed so far.*/
/*int remove = preSum - k;: This line calculates the value remove, which represents the difference between the current prefix sum preSum and the target sum k. It signifies the value that needs to be removed from the cumulative sum to achieve the desired sum.

cnt += mpp[remove];: This line updates the variable cnt, which is used to store the count of subarrays with the given sum k. It adds the value associated with the key remove in the map mpp to the current value of cnt.

If remove exists as a key in mpp, it means that there are subarrays whose sum is equal to the target sum (k) by removing the value remove from the cumulative sum. The count of such subarrays is stored as the value corresponding to the key remove in the map.

If remove is not present as a key in mpp, its associated value is considered as 0 (zero). This is because if there are no occurrences of remove in the prefix sums encountered so far, it implies that there are no subarrays with the sum equal to the target sum by removing remove.*/
