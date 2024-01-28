
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void ifarmstrong(int num, int counter)
{

    int sum = 0;
    int n = num;
    while (num != 0)
    {
        int r = num % 10;
        sum += pow(r, counter);
        num /= 10;
    }
    if (sum == n)
    {
        cout << "Yes, it is an Armstrong Number." << endl;
    }
    else
    {
        cout << "No, it is not an Armstrong Number." << endl;
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int m = n;
    int counter = 0;
    while (n != 0)
    {
        counter++;
        n /= 10;
    }
    ifarmstrong(m, counter);
    return 0;
}
