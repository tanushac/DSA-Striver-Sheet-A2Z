/********************Brute Force********************/
#include <iostream>
using namespace std;
string read(int n, vector<int> book, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        { // to eliminate these same pairs, we will start the inner loop from i+1
            if (book[i] + book[j] == target)
                return "YES";
        }
    }
    return "NO";
}
// variant 2(return indices)
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}

/***************Better Approach*****************/
// Using Hashing
#include <bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a = book[i];
        int more = target - a;
        if (mpp.find(more) != mpp.end())
        {
            return "YES";
        }
        mpp[a] = i;
    }
    return "NO";
}
// variant 2
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}
/******************Optimal Approach**************/
/*using 2 pointers, left & right
first sort the array then
one pointer at 0th index and another at last index
calculate sum of these two elements
if sum < target, increment left pointer
if sum > target, decrement right pointer */
#include <bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    int left = 0;
    int right = n - 1;
    sort(book.begin(), book.end());
    while (left < right)
    {
        int sum = book[left] + book[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return "NO";
}
/*This approach will not be optimal for variant 2 which is when we have to return the indices of the elements too
as we would have to use another data structure for storing the elements which will increase space complexity*/
