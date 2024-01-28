/********************Brute Force*****************/
#include <bits/stdc++.h>
using namespace std;
bool linearSearch(vector<int> &a, int num)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    int longest = 1;
    // pick a element and search for its
    // consecutive numbers:
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int cnt = 1;
        // search for consecutive numbers
        // using linear search:
        while (linearSearch(a, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}
/*******************Better Approach********************/
/*We will consider 3 variables,
‘lastSmaller’ →(to store the last included element of the current sequence),
‘cnt’ → (to store the length of the current sequence),
‘longest’ → (to store the maximum length).
Initialize ‘lastSmaller’ with ‘INT_MIN’, ‘cnt’ with 0, and ‘longest’ with 1(as the minimum length of the sequence is 1).*/
/*First, we will sort the entire array.
To begin, we will utilize a loop(say i) to iterate through each element one by one.
For every element, we will check if this can be a part of the current sequence like the following:
If arr[i]-1 == lastSmaller: The last element in our sequence is labeled as ‘lastSmaller’ and the current element ‘arr[i]’ is exactly
‘lastSmaller’+1. It indicates that ‘arr[i]’ is the next consecutive element. To incorporate it into the sequence, we update ‘lastSmaller’
 with the value of ‘arr[i]’ and increment the length of the current sequence, denoted as ‘cnt’, by 1.
If arr[i] == lastSmaller: If the current element, arr[i], matches the last element of the sequence (represented by ‘lastSmaller’), we can
 skip it since we have already included it before.
Otherwise, if lastSmaller != arr[i]: On satisfying this condition, we can conclude that the current element, arr[i] > lastSmaller+1.
It indicates that arr[i] cannot be a part of the current sequence. So, we will start a new sequence from arr[i] by updating ‘lastSmaller’
with the value of arr[i]. And we will set the length of the current sequence(cnt) to 1.
Every time, inside the loop, we will compare ‘cnt’ and ‘longest’ and update ‘longest’ with the maximum value. longest = max(longest, cnt)
Finally, once the iteration is complete, we will have the answer stored in the variable ‘longest’.*/

#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    // sort the array:
    sort(a.begin(), a.end()); // distorting the array
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    // find longest sequence:
    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            // a[i] is the next element of the
            // current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller)
        {
            cnt = 1; // reset the count as it is not consecutive
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}
/*********************Optimal Approach*******************/
/* Instead of searching sequences for every array element as in the brute-force approach, we will focus solely on
finding sequences only for those numbers that can be the starting numbers of the sequences. This targeted approach narrows
down our search and improves efficiency.
We will do this with the help of the Set data structure.

How to identify if a number can be the starting number for a sequence:

First, we will put all the array elements into the set data structure.
If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set,
we will check if x-1 exists inside the set. :
If x-1 exists: This means x cannot be a starting number and we will move on to the next element in the set.
If x-1 does not exist: This means x is a starting number of a sequence. So, for number, x, we will start
finding the consecutive elements.
How to search for consecutive elements for a number, x:

Instead of using linear search, we will use the set data structure itself to search for the elements x+1,
x+2, x+3, and so on.*/
int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;
    // put all the array elements into set:
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    // Find the longest sequence:
    for (auto it : st)
    {
        // if 'it' is a starting number:
        /*It iterates over each element in the set and checks if the previous element (it - 1) is not present in the set.
        If true, it means the current element is the starting point of a consecutive subsequence.*/
        if (st.find(it - 1) == st.end())
        {
            // find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
