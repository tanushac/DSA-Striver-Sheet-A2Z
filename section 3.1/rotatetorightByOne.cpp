/************Brute Force***********/
/*Using Vector*/
#include <bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int> &arr, int n)
{
    vector<int> b;
    if (n == 1)
    {
        return arr;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            b.push_back(arr[i]);
        }
        b.push_back(arr[0]);
        return b;
    }
}
/*Using Dummy Array*/
#include <bits/stdc++.h>
using namespace std;
void solve(int arr[], int n)
{
    int temp[n];
    for (int i = 1; i < n; i++)
    {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}
/****************Optimal Solution****************/
/*store element at 0th index in a variable and then shift other elements by one place and then insert the */
#include <bits/stdc++.h>
using namespace std;
void solve(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}