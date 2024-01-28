// Maximum possible subarray with highest sum in the array
/*****************Brute Force***************/
/*Generate all possible subarrays and calcuate their sum
then find maximum of max and sum to find the largest sum*/
#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum0(int arr[], int n)
{
    int maxi = INT_MIN; // maximum sum
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // subarray = arr[i.....j]
            int sum = 0;
            // add all the elements of subarray:
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum0(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
/*************Better Approach****************/
/*f we carefully observe, we can notice that to get the sum of the current subarray we just need to add
the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].
Assume previous subarray = arr[i……j-1]
current subarray = arr[i…..j]
Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]
This is how we can remove the third loop and while moving j pointer, we can calculate the sum.*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum1(int arr[], int n)
{
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            // current subarray = arr[i.....j]
            // add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];
            maxi = max(maxi, sum); // getting the maximum
        }
    }
    return maxi;
}
/************Optimal Approach**************/
/*The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less
than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot
be a part of the subarray with maximum sum.

Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum
variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to
consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.
Thus we can solve this problem with a single loop.*/

/*If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.

Note: In some cases, the question might say to consider the sum of the empty subarray while solving this
problem. So, in these cases, before returning the answer we will compare the maximum subarray sum calculated
with 0(i.e. The sum of an empty subarray is 0). And after that, we will return the maximum one.
For e.g. if the given array is {-1, -4, -5}, the answer will be 0 instead of -1 in this case. */
#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum2(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }
    // To consider the sum of the empty subarray
    // uncomment the following check:
    // if (maxi < 0) maxi = 0;
    return maxi;
}
/*******Follow-up question*******/
// There might be more than one subarray with the maximum sum. We need to print any of them.
/*If we carefully observe our algorithm, we can notice that the subarray always starts at the particular index where the sum variable is equal to 0, and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi).

So, we will keep a track of the starting index inside the loop using a start variable.
We will take two variables ansStart and ansEnd initialized with -1. And when the sum crosses the maximum sum, we will set ansStart to the start variable and ansEnd to the current index i.e. i*/

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum3(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
    // To consider the sum of the empty subarray
    // uncomment the following check:
    // if (maxi < 0) maxi = 0;

    return maxi;
}
