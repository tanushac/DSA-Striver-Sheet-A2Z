/********************Brute force****************/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &arr)
{
    int maxPro = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
    }
    return maxPro;
}
/************************Optimal Approach*************/
/*We will linearly travel the array. We can maintain a minimum from the start of the array and compare it
with every element of the array, if it is greater than the minimum then take the difference and maintain it
in max, otherwise update the minimum.*/
#include <bits/stdc++.h>
using namespace std;
int maxProfit2(vector<int> &arr)
{
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    return maxPro;
}