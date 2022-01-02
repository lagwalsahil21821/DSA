#include <bits/stdc++.h>
using namespace std;
long long pisano(long long m)
{
    long long p1 = 0;
    long long p2 = 1;
    long long temp;
    long long modulo = 0;
    for (long long i = 0; i < m * m; i++) // i< m*m
    {
        temp = p1;
        p1 = p2;
        p2 = (temp + p1) % m;
        if (p1 == 0 && p2 == 1)
        {
            modulo = i + 1;
            break;
        }
    }
    return modulo;
}
long long fib(long long n, long long m)
{
    n = n % pisano(m); // new index
    long long first = 0;
    long long second = 1;
    long long temp;
    if (n <= 0)
        return n;

    for (long long i = 0; i < n - 1; i++)
    {
        temp = first;
        first = second;
        second = (temp + first) % m; // % m
    }
    return second % m;
}
int main()
{
    /*
    (this algo didn't work for >10^18)
    long long n;
    long long m;
    cin>>n>>m;
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (long long i = 2; i <= n; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % m;
    }
    cout<<arr[n];
   */

    long long n, m;
    cin >> n >> m;
    cout << fib(n,m);
}