/*********************Brute Force******************/
/* 1.Generate all permutations
2.Search the given array
3.Return the next permutation
permutations can be generated by recursion*/

/****************Better Approach****************/
/*C++ provides an in-built function called next_permutation() which directly returns the
lexicographically next greater permutation of the input.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// int main()
// {
//     int arr[] = {1, 3, 2};
//     next_permutation(arr, arr + 3); // using in-built function of C++
//     cout << arr[0] << " " << arr[1] << " " << arr[2];
//     return 0;
// }
vector<int> nextGreaterPermutation(vector<int> &A)
{
    next_permutation(A.begin(), A.end());
    return A;
}

/**********************Optimal Solution******************/
// find the first adacent pair from right side where left is smaller than right
// if you dont find such a pair, reverse the whole array
// swap the left element in the pair with the smallest element greater than that to its right
// then reverse the sub array from the point of swap(after the left element in the pair) till the end

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size();
    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            // index i is the break point
            ind = i;
            break;
        }
    }
    // If break point does not exist:
    if (ind == -1)
    {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }
    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--)
    {
        if (A[i] > A[ind])
        {
            swap(A[i], A[ind]);
            break;
        }
    }
    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());
    return A;
}
