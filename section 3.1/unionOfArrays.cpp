/*
Use a Single map to find the frequencies of elements in arr1 and arr2.
As we are using only a single map the common element in arr1 and arr2 are
treated as a single element for finding frequency, so there would be no duplicates.

Why not unordered_map?
In unordered_map the keys are stored in random order, while in the map the
keys are stored in sorted order (ascending order by default). As we require elements
of the union to be in ascending order, using a map is preferable.

We can also use unordered_map, but after finding the union of arr1 and arr2, we need to sort the
union vector to get the elements of the union in sorted order.*/

#include <bits/stdc++.h>

using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    map<int, int> freq; // A map is used to store the frequency of each element in the combined arrays.
    vector<int> Union;  // This vector will store the union of the arrays.
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;
    // For example, if arr1 is {1, 2, 3, 3, 4}, after this loop, the freq map would be {1:1, 2:1, 3:2, 4:1}, indicating that 1 occurs once, 2 occurs once, 3 occurs twice, and 4 occurs once in arr1.

    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;
    // if arr2 is {2, 3, 3, 4, 5}, after this loop, the freq map would be {1:1, 2:2, 3:3, 4:2, 5:1}, indicating the frequencies of each element in the combined set of arr1 and arr2.

    for (auto &it : freq)
        Union.push_back(it.first); // This loop iterates through the elements in the frequency map and adds
    // each unique element to the Union vector. The use of it.first ensures that only the unique elements are added.

    return Union;
}
int main()
{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}
/*So using a set we can find the distinct elements because the set does not hold any duplicates. Hence we can find the union of arr1 and arr2.

Why not unordered_set?
In unordered_set the elements are stored in random order, while in a set the keys are stored in sorted order (ascending order by default). As we require elements of the union to be in ascending order, using a set is preferable.

We can also use unordered_set, but after finding the union of arr1 and arr2, we need to sort the union vector to get the elements of the union in sorted order.*/

#include <bits/stdc++.h>

using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    vector<int> Union;
    for (int i = 0; i < n; i++)
        s.insert(arr1[i]);
    for (int i = 0; i < m; i++)
        s.insert(arr2[i]);
    for (auto &it : s)
        Union.push_back(it);
    return Union;
}

int main()

{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}
/************************************* OPTIMAL SOLUTION *****************************************/
// Two pointer method
#include <bits/stdc++.h>
vector<int> sortedArray(vector<int> a, vector<int> b)
{
    vector<int> unionArr;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i]) // if union is empty then simply insert element || check if last element in union is not the same as one we are inserting
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else // if b[j]>a[i]
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < n1)//if any element left in arr1
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)//if any element left in arr2
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}
