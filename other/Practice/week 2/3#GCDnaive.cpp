#include<iostream>
using namespace std;

int gcd(int a,int b){
    int best = 0;
    for (int i = 1; i < a+b; i++)
    {
        if( (a%i == 0) && (b%i == 0) ){
            best = i;
        }
    }
    return best;
    
}
int main(){
    int a,b;
    cout<<"Enter no. : ";
    cin>>a>>b;
    cout<<gcd(a,b);
}