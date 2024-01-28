/*What is the ceiling of x?
The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x).
From the definitions, we can easily understand that the ceiling of x is basically the lower bound of x. The lower bound algorithm returns the index of x if x is present in the array and otherwise, it returns the index of the smallest element in the array greater than x.
for floor:
If arr[mid] <= x: arr[mid] is a possible answer. So, we will store it and will try to find a larger number that satisfies the same condition. That is why we will remove the left half and try to find the number in the right half.
If arr[mid] > x: The arr[mid] is definitely not the answer and we need a smaller number. So, we will reduce the search space to the left half by removing the right half.
*/
#include <bits/stdc++.h>
using namespace std;
int findFloor(vector<int> &a, int n, int x) {
  int low = 0, high = n - 1;
  int floor = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] <= x) {
      floor = a[mid];
      low = mid + 1;
    }
    else{
      high=mid-1;
    }
  }
  return floor;
}
int findCeil(vector<int> &a, int n, int x){
   int low = 0, high = n - 1;
  int ceil = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] >= x) {
      ceil = a[mid];
      high=mid-1;
    }
    else{
      low = mid + 1;
    }
  }
  return ceil;
}
pair<int, int> getFloorAndCeil(vector<int> a, int n, int x) {
  int f = findFloor(a, n, x);
	int c = findCeil(a, n, x);
	return make_pair(f, c);
}
int main() {
	vector <int> arr = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}