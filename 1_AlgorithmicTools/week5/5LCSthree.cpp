#include<bits/stdc++.h>
using namespace std;
void threeLCS(vector<int> &a,vector<int> &b,vector<int> &c,int n,int m,int o){
    int arr[n+1][m+1][o+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= o; k++)
            {
                if(i==0 || j==0 || k==0){
                    arr[i][j][k] = 0;
                }
                else if((a[i-1] == b[j-1]) && (a[i-1] == c[k-1])) arr[i][j][k] = 1 + arr[i-1][j-1][k-1];
                else arr[i][j][k] = max(max(arr[i-1][j][k],arr[i][j-1][k]),arr[i][j][k-1]);
            }
            
        }
        
    }
    cout<<arr[n][m][o];
    
    
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,o;
    cin>>n;
    vector<int> a(n);
    for(auto &x: a) cin>>x;
    cin>>m;
    vector<int> b(m);
    for(auto &x : b) cin>>x;
    cin>>o;
    vector<int> c(o);
    for(auto &x: c) cin>>x;
    threeLCS(a,b,c,n,m,o);


}