#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>number(n);
    for (int i = 0; i < n; i++)
    {
        cin>>number[i];
    }
    sort( number.begin(),number.end() );
    cout<<( ( (long long)number[n-1] ) * number[n-2]);
    
    
    return 0;
}