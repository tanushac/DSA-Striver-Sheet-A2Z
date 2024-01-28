/**********Brute Force*************/
#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> a)
{
    // temporary array:
    vector<int> temp;
    // copy non-zero elements
    // from original -> temp array:
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    // copy elements from temp
    // fill first nz fields of
    // original array:
    for (int i = 0; i < nz; i++)
    {
        a[i] = temp[i];
    }

    // fill rest of the cells with 0:
    for (int i = nz; i < n; i++)
    {
        a[i] = 0;
    }
    return a;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}
/*****************Optimal Solution**********/
// using 2 pointers
/*we will swap non zero numbers with zero
j will always point to a zero(slow pointer)
i-> fast pointer*/
#include <bits/stdc++.h>
vector<int> moveZeros(int n, vector<int> a) {
    int j=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return a;//no non-zero numbers
    for(int i=j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }
    return a;
}
