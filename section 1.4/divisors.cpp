
#include <iostream>
using namespace std;

void divisor(int num)
{
    cout << "Divisiors of " << num << " are: " << endl;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    divisor(n);
    return 0;
}
/*Second Approach*/

#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

void printDivisorsOptimal(int n){

    cout<<"The Divisors of "<<n<<" are:"<<endl;
    for(int i = 1; i <= sqrt(n); i++)
        if(n % i == 0){
            cout << i << " ";
            if(i != n/i) cout << n/i << " ";
        }

    cout << "\n";
}

int main(){
    int n;
    cin >> n;
    printDivisorsOptimal(n);
        return 0;
}

