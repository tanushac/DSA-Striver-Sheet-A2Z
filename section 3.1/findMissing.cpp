/********************Brute Force***************/
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a, int N)
{

    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++)
    {

        // flag variable to check
        // if an element exists
        int flag = 0;

        // Search the element using linear search:
        for (int j = 0; j < N - 1; j++)
        {
            if (a[j] == i)
            {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        // i.e flag == 0:

        if (flag == 0)
            return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}
/**************Better Approach (using Hashing):****************/
/*The range of the number is 1 to N. So, we need a hash array of size N+1
(as we want to store the frequency of N as well).
Now, for each element in the given array, we will store the frequency in the hash array.
After that, for each number between 1 to N, we will check the frequencies.
And for any number, if the frequency is 0, we will return it.*/
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a, int N)
{

    int hash[N + 1] = {0}; // hash array, initialising with zeroes

    // storing the frequencies:
    for (int i = 0; i < N - 1; i++)
        hash[a[i]] = 1;

    // checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}
/************************Optimal Approach 1******************************/
/*We know the sum of n natural numbers, we will subtract the sum of all elements of array from 
the sum of natural numbers, this will give us the missing number.*/

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}
/************************Optimal Approach 2******************************/
/*Among the optimal approaches, the XOR approach is slightly better than the
summation one because the term (N * (N+1))/2 used in the summation method cannot
be stored in an integer if the value of N is big (like 105). In that case, we have to use some bigger data types.
But we will face no issues like this while using the XOR approach.

Two important properties of XOR are the following:
XOR of two same numbers is always 0 i.e. a ^ a = 0. ← Property 1.
XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ← Property 2
all the numbers except the missing number will form a pair and each pair will result in 0 according to the XOR property.
The result will be = 0 ^ (missing number) = missing number (according to property 2).

So, if we perform the XOR of the numbers 1 to N with the XOR of the array elements, we will be left with the missing number.*/
int missingNumber(vector<int>&a, int N) {
    int xor1,xor2;
    xor2=0;
    xor1=0;
    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1=xor1^N;//XOR up to [1...N]
    return xor1^xor2;
}