
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void isPalindrome(int n)
{
    int m = n;
    int s = 0;
    while (n != 0)
    {
        int r = n % 10;
        s = (s * 10) + r;
        n /= 10;
    }
    if (s == m)
    {
        cout << "Palindrome Number";
    }
    else
    {
        cout << "Not Palindrome Number";
    }
}

int main()
{
    int n;
    cin >> n;
    isPalindrome(n);
    return 0;
}