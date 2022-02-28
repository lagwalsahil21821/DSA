#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s,p;
    cin>>s>>p;
    long long arr[s][2];
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            cin>>arr[i][j];
        }
    }

    long long v[p];
    for(auto &x: v) cin>>x;
    

    for (int i = 0; i <p; i++)
    {
        int count = 0;
        for (int j = 1; j <= s; j++)
        {
            long long a,b;
            a = arr[j][1];
            b = arr[j][2];
            if(v[i]<=b && v[i]>=a) count++;
        }
        cout<<count<<" ";
    }
    
    
    
}