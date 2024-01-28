/**********************Brute Force****************/
/************Using flag variable**********/
#include <bits/stdc++.h>
int isSorted(int n, vector<int> a)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] <= a[i + 1])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/**************directly returning false or true************/
#include <bits/stdc++.h>

using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                return false;
        }
    }

    return true;
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    bool ans = isSorted(arr, n);
    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
/***********************Optimal Solution********************/
#include <bits/stdc++.h>
bool isSort(int n, vector<int> a)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            return false;
        }
    }
    return true;
}
