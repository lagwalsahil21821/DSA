#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int count = 0;
        int i = 0; int j = n-1;
        while(i < j){
            if(a[i] + a[j] == k){ count++; break;}
            else if(a[i] + a[j] > k) j--;
            else i++;
        }
        if(count != 0) cout<<"Yes\n";
        else cout<<"No\n";
        
    }
}