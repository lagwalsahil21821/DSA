// too slow algorithm
// calculate same thing many times

#include<iostream>
using namespace std;
long long FibRec(int n){
    if(n<=1){
        return n;
    }
    else {
        return FibRec(n-1) + FibRec(n-2);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<FibRec(n);
    return 0;
}