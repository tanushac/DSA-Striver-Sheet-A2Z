#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==num)
        {
            return i;
        }
        
    }
    return 0;
    
}
int main()
{
    int arr[]={1,2,3,4,5};
    int num = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = linearSearch(n,num,arr[]);
    cout<<val;
    return 0;
}
