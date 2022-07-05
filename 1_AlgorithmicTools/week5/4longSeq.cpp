#include<bits/stdc++.h>
using namespace std;
void lcs(vector<int> &a, vector<int> &b,int n,int m){
    int arr[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        arr[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        arr[0][i] = 0;
    }
    
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1]) arr[i][j] = 1 + arr[i-1][j-1];
            else arr[i][j] = max(arr[i-1][j] ,arr[i][j-1]);
         
        }
        
    }
    cout<<arr[n][m];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n;
    vector<int> a(n);
    for(auto &x: a) cin>>x;
    cin>>m;
    vector<int> b(m);
    for(auto &x: b) cin>>x;
    lcs(a,b,n,m);

}
