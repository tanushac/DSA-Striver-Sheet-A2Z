/*********************Brute Force******************/
#include <bits/stdc++.h>
using namespace std;
vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        // Checking whether a[i] is greater than all
        // the elements in its right side
        for (int j = i + 1; j < n; j++)
        {

            if (a[j] >= a[i])
            {
                // If any element found is greater than current leader
                // curr element is not the leader.
                leader = false;
                break;
            }
        }
        // Push all the leaders in ans array.
        if (leader)
        {
            ans.push_back(a[i]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

/*******************Optimal Solution********************/
/*First, we’ll start the traversal from the right. Then, we move toward the left. Whenever we encounter a new element, we check with the greatest element obtained so far.
If the current element is greater than the greatest so far, then the current element is one of the leaders and we update the greatest element.*/
#include <bits/stdc++.h>
using namespace std;
vector<int> printLeaders(int arr[], int n)
{
    vector<int> ans;
    // Last element of an array is always a leader,
    // push into ans array.
    int max = arr[n - 1];
    ans.push_back(arr[n - 1]);
    // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > max)
        {
            ans.push_back(arr[i]);
            max = arr[i];
        }
    return ans;
}
