/*
Compute the minimum number of coins needed
to change the given value into coins with denominations
1, 5, and 10.
Input: Integer money.
Output: The minimum number
of coins with denominations 1, 5,
and 10 that changes money.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>x;
    int totalCoin = 0;
    /*
    int arr[] = { 10, 5, 1};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    
    for (int i = 0; i < n; i++)
    {
        int coin = x/arr[i];
        int remain = x % arr[i];
        x = remain;
        totalCoin+= coin;
    }
    */
    totalCoin = x/10 + (x%10)/5 + (x%5)/1;
    cout<<totalCoin;
    
    
}