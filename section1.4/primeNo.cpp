#include <iostream>
using namespace std;
void isprime(int n)
{
    int flag = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not a prime number." << endl;
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    isprime(n);
    return 0;
}
/*
use square root of n instead of < n
This is more efficient because factors of a number, if they exist, will always be less than or equal to its square root.*/
#include <iostream>
using namespace std;
void isprime(int n)
{
    int flag = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not a prime number." << endl;
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    isprime(n);
    return 0;
}