#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = 0;
    int k;
    
    for (int i = 1; i <= n; i++)
    {
        sum+=i;
        if(n == 1){
            k = 1;
            break;
        }else
        if(sum > n){
            k = i-1;
            break;
        }
    }
    cout<<k<<"\n";
    for (int i = 1; i < k; i++)
    {
        cout<<i<<" ";
    }
    //only thing is to find last digit of sequence
    int temp = ((k-1)*(k))/2;
    cout<<(n - temp)<<"\n";    // as we know   [sum of all term except last term + last term = given value]
    
    

    
}