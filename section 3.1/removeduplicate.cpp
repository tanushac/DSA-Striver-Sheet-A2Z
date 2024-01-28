/*********Brute Force***********/
/************Using set*********/
#include <bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    int k = s.size();
    int j = 0;
    for (int x : s)
    {
        arr[j] = x;
        j++;
    }
    return k;
}
int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}
/*********Optimal Solution**********/
/*We can think of using two pointers ‘i’ and ‘j’, 
we move ‘j’ till we don’t get a number arr[j] which is different from arr[i]. 
As we got a unique number we will increase the i pointer and update its value by arr[j]. */
#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;//we have to return size not index
}
