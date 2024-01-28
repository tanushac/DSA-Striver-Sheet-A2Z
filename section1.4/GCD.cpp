
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    int ans;
    for (int i = 1; i <= min(num1, num2); i++)//so that loop doesn't run extra times if num1>num2
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            ans = i;
        }
    }
    cout << "The GCD of the two numbers is " << ans;
}
/*
Euclidean algorithm
gcd(a,b)= gcd(a-b,b)   a>b
repeat unitl one of the numbers==0, the other number will be gcd
or we can also write it as
gcd(a,b) == gcd(a%b,b) until one of the number becomes 0
*/
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (b == 0)
    {
        return a;
    }
    return b;
}
int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << "The GCD of the two numbers is " << gcd(num1, num2);
}
