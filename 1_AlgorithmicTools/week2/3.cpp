// program to find gcd

#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){ 
      
    if(b == 0)
    return a;
    int r = a%b;
    gcd(b,r);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;

}