#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &x: v)cin>>x;
    sort(v.begin(),v.end());
    int count = 0;
    bool flag = true;
    for (int i = 0; i < n-1; i++)
    {
        if(v[i] == v[i+1]){
            count++;
        }
        else{ count = 0;}
        if(count>=n/2) {flag = false; break;}
        
    }
    if(!flag) cout<<"1\n";
    else cout<<"0\n";
    
    
}