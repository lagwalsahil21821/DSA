#include<iostream>
using namespace std;

int gcd(int a,int b){
    
    if(b == 0)
        return a;
    int _a = a%b ;  //remainder of a/b
    return gcd(b,_a);   
}

int main(){
    int u,v;
    cin>>u>>v;  //taking two no. as input
    cout<<gcd(u,v);
    return 0;
}
//eg: 
// gcd(3918848, 1653264) = 61232