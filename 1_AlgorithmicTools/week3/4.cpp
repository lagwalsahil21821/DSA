#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> profit; // profit per click 
    vector<int> clicks; // average no. of clicks
    long long revenue = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        profit.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        clicks.push_back(x);
    }
    sort(profit.begin(), profit.end());
    sort(clicks.begin(), clicks.end());
    for (int i = 0; i < n; i++)
    {
        revenue += ((long long)profit[i]) * clicks[i];      // as when multiply max no. like 10^5 * 10^5 so int will not work in this case so we use long long and make sure you use long long with one of them
    }
    
    cout<<revenue<<"\n";
    
}