
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void Reversen(int n)
{
    int s = 0;
    while (n != 0)
    {
        int r = n % 10;
        s = (s * 10) + r;
        n /= 10;
    }
    cout << "Reversed number is: " << s;
}

int main()
{
    int n;
    cin >> n;
    Reversen(n);
    return 0;
}