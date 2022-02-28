#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> &v,int l,int r,int k){
    if(r < l) return -1;
    int mid = (l+r)/2;
    if(v[mid] == k){
        
        while(v[mid] == k){
            if(v[mid] != v[mid-1]){ return mid; break;}
            mid--;
        }
    }
    else if(k < v[mid])
        return binary_search(v,l,mid-1,k);
    else if(k > v[mid])
        return binary_search(v,mid+1,r,k);
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &x: v) cin>>x;
    int k;
    cin>>k;
    vector<int>b(k);
    for(auto &x: b)cin>>x;
    int r  = n - 1;
    for (int i = 0; i < k; i++)
    {
        cout<<binary_search(v,0,r,b[i])<<' ';
    }
    
}