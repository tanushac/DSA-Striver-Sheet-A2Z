/********************Brute Force****************/
/*How to generate all possible subarrays?
We will select all possible starting indices(say i) and all possible ending indices(say j) to generate all
possible subarrays. The possible starting indices i.e. i can vary from index 0 to index n-1(i.e. The last index).
For every index i, the possible ending index j can vary from i to n-1.

We will check the sum of every possible subarray and consider the one with the sum k and the maximum length among
them. To get every possible subarray sum, we will be using three nested loops. The first loops(say i and j) will
iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the
subarray range will be from index i to index j. Using another loop we will get the sum of the elements of the
subarray [i…..j]. Among all the subarrays with sum k, we will consider the one with the maximum length.

Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its
elements using another loop.*/
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.
    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        for (int j = i; j < n; j++)
        { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K1 = i; K1 <= j; K1++)
            {
                s += a[K1];
            }
            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
/**************************Better Approach 1*************************/
/*We can remove the third nested loop
Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j]
If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the
current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].*/
#include <bits/stdc++.h>
using namespace std;
int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {                    // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++)
        { // ending index
            // add the current element to the subarray a[i...j-1]:
            s += a[j];
            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
/**************************Better Approach 2(Using Hashing): *************************/

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size();

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // calculate the prefix sum till index i:
        sum += a[i];
        // if the sum = k, update the maxLen:
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        // Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
/********************************Optimal Solution****************************/
/*We are using two pointers i.e. left and right. The left pointer denotes the starting index of the subarray
and the right pointer denotes the ending index. Now as we want the longest subarray, we will move the right
pointer in a forward direction every time adding the element i.e. a[right] to the sum. But when the sum of
the subarray crosses k, we will move the left pointer in the forward direction as well to shrink the size of
the subarray as well as to decrease the sum. Thus, we will consider the length of the subarray whenever the
sum becomes equal to k.*/
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &a, long long k)
{
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n)
    {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward the right pointer:
        right++;
        if (right < n)
            sum += a[right];
    }

    return maxLen;
}
