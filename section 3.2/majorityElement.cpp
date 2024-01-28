/*******************Brute Force****************/
// count each element in the array using 2 loops and whichever one's count is > n/2, return that element.
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // counting the frequency of v[i]
            if (v[j] == v[i])
            {
                cnt++;
            }
        }
        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }
    return -1;
}
/******************Better Approach**************************/
// Hashing
// map(element,count)
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> v)
{
    map<int, int> mpp;
    // storing the elements with its occurence:
    for (int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;
    }
    // searching for the majority element:
    for (auto it : mpp)
    {
        if (it.second > (v.size()) / 2)
        {
            return it.first;
        }
    }
    return -1;
}
/******************** Optimal Approach ******************/
// Moore’s Voting Algorithm:
/*If the array contains a majority element, its occurrence must be greater than the floor(N/2). Now, we can say 
that the count of minority elements and majority elements is equal up to a certain point in the array. So when we 
traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 

After traversing the whole array, we will check the element stored in the variable. If the question states that the 
array must contain a majority element, the stored element will be that one but if the question does not state so, 
then we need to check if the stored element is the majority element or not. If not, then the array does not contain 
any majority element.*/
/*But if in this array, the last two elements were 3, then the Element variable would have stored 3 instead of 2. 
For that, we need to check if the Element is the majority element by traversing the array once more. But if the 
question guarantees that the given array contains a majority element, then we can bet the Element will store the majority one.*/
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int el;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            el = nums[i];
        }
        else if (nums[i] == el)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int count2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el)
        {
            count2++;
        }
    }
    if (count2 > nums.size() / 2)
    {
        return el;
    }
    return -1;
}
