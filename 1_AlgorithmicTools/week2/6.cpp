// last digit of sum of fibbonacci series like
// if n = 3 then (f0 + f1 + f2 + f3) mod 10

#include <bits/stdc++.h>
using namespace std;
int sum(int x){
    int first = 0;
    int second = 1;
    int temp;
    int sum = 1;
    if(x<=1)
    return x;
    for (int i = 0; i < x-1; i++)
    {
        temp = first;
        first = second;
        second = (first + temp) % 10;
        sum = (sum + second) % 10;
    }
    return sum;
}
int main()
{
    /*(Can't work for n>10^18)
    array didn't work after 10^9

    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    arr[0] = 0;
    arr[1] = 1;
    for (int  i = 2; i <= n; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % 10;
    }
    for (int i = 0; i <= n; i++)
    {
        sum+= arr[i];
    }
    cout<<(sum % 10);
    */

   /* 2nd approach
   it work for n>10^9
   but TLE occurs here

    long long n;
    cin >> n;
    long long first = 0;
    long long second = 1;
    long long temp;
    long long sum = 1;
    if (n <= 1)
    {
        cout << n;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            temp = first;
            first = second;
            second = (first + temp) % 10;
            sum = (sum + second) % 10;
        }
    
        cout << sum;
    }
    */

    // so now i will go with formula/pattern
    // as unit digit repeat after every 60 digit means cycle period of unit digit of mod 10 is 60
    long long n;
    cin>>n;
    long long a = n/60; // multiply factor
    long long b = n % 60; // remainder factor
    
    
    int sum60 = sum(60);
    int sumRemain = sum(b);
    
    cout<< ((sum60 * a) + sumRemain)%10;

    
    

}