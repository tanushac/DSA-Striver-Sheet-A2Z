/*************** BRUTE FORCE APPROACH *****************/
#include <bits/stdc++.h>
using namespace std;
int maxLength(vector<int> &v)
{
    int n = v.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        long long s = 0;
        for (int j = i; j < n; j++)
        {
            s += v[j];
            if (s == 0)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
int main()
{
    vector<int> A = {6, -2, 2, -8, 1, 7, 4, -10};
    sort(A.begin(), A.end());
    for (auto it : A)
    {
        cout << it << " ";
    }
    int ans = maxLength(A);
    cout << ans;
    return 0;
}
/*************** OPTIMAL APPROACH ****************/
#include <bits/stdc++.h>
int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maxi;
}
