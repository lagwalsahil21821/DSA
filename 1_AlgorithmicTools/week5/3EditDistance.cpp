#include<bits/stdc++.h>
using namespace std;
 
int editDis(string a, string b){
    int n = a.length();
    int m = b.length();
    int arr[n+1][m+1];
    int insertion,del,match,mismatch;
    
    for (int j = 0; j <= m; j++)
    {
        arr[0][j] = j;
    }
    for (int i = 0; i <= n; i++)
    {
        arr[i][0] = i;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            insertion = 1 + arr[i][j-1];
            del = 1+arr[i-1][j];
            match = arr[i-1][j-1];
            mismatch =1 + arr[i-1][j-1];

            if(a[i-1] == b[j-1]) arr[i][j] = min(min(insertion,del),match);
            else arr[i][j] = min(min(insertion,del),mismatch);
        }
        
    }
    
    cout<<"\n";
    return arr[n][m];
    
    
 }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string n,m;
    cin>>n>>m;
    cout<<editDis(n,m);
}