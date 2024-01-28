#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int counter = 0;
  while (n != 0)
  {
    counter++;
    n /= 10;
  }
  cout << "The number of digits is: " << counter;
  return 0;
}

/*
approach 2*/
int count_digits( int n )
{
  int digits = floor(log10(n) + 1);
  return digits;
}
/*
approach 3*/
int count_digits( int n )
{
  string x = to_string(n);
  return x.length();
}
