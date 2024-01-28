/**********Optimal Approach**************/
// using XOR
#include <vector>
#include <iostream>
using namespace std;
int getSingleElement(vector<int> &arr)
{
    int xor1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}
/*******************Brute Force****************/
#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr)
{
    // Size of the array:
    int n = arr.size();

    // Run a loop for selecting elements:
    for (int i = 0; i < n; i++)
    {
        int num = arr[i]; // selected element
        int cnt = 0;

        // find the occurrence using linear search:
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1)
            return num;
    }

    // This line will never execute
    // if the array contains a single element.
    return -1;
}
/************Better Approach 1***************/
/*hashing can be done in two different ways and they are the following:

Array hashing(not applicable if the array contains negatives or very large numbers)
Hashing using the map data structure*/
/*Now, using array hashing it is difficult to hash the elements of the array if it
contains negative numbers or a very large number. So to avoid these problems,
 we will be using the map data structure to hash the array elements.*/

#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr)
{

    // size of the array:
    int n = arr.size();

    // Find the maximum element:
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    // Declare hash array of size maxi+1
    // And hash the given array:
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // Find the single element and return the answer:
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
            return arr[i];
    }

    // This line will never execute
    // if the array contains a single element.
    return -1;
}

/************Better Approach 2***************/
// Hashing using the map data structure
#include <bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> &arr)
{
    int n = arr.size();
    // Declare the hashmap.
    // And hash the given array:
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    // Find the single element and return the answer:
    for (auto it : mpp)
    {
        if (it.second == 1)
            return it.first;
    }
    // This line will never execute
    // if the array contains a single element.
    return -1;
}