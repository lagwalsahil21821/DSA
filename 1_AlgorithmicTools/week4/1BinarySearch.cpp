#include<bits/stdc++.h>
using namespace std;
int binary_search(int a[],int l, int r, int k){
    if(r < l) return -1;
    int m = (l+r)/2;
    if(a[m] == k) return m;

    else if(k < a[m]) return binary_search(a,l,m-1,k);
    else if(k > a[m]) return binary_search(a,m+1,r,k);
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int b[k];
    for (int i = 0; i < k; i++)
    {
        cin>>b[i];
    }
    int l = 0;
    int r = n - 1;
    
    
    for (int i = 0; i < k; i++)
    {
        cout<<binary_search(a,l,r,b[i])<<" ";
        
        
    }
    
}