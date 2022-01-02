#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>x;
    int totalCoin = 0;
    totalCoin = x/10 + (x%10)/5 + (x%5)/1;
    cout<<totalCoin;
    
    
}