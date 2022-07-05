#include<iostream>
using namespace std;
bool isodd(int n){
    return (n & 1) == 1;
}
int main(){
    int n;
    cout<<"Enter a no. to check weather no. is odd or not: ";
    cin>>n;
    cout<<isodd(n);    // if in binary at LSB position, if there is 1 then odd otherwise its even

}