//Compute the last digit of sum of square of fibonacci no.

#include<bits/stdc++.h>
using namespace std;
int square(int x){
    long long first = 0;
    long long second =1;
    long long temp;
    int square,sum=1;
    if(x<=1)
    return x;
    for (int i = 0; i < x-1; i++)
    {
        temp = first;
        first = second;
        second = (temp + first) % 10;
        square = (second * second)% 10;
        sum = (sum + square ) % 10;
    }
    return sum;
}
int main(){
    long long n;
    cin>>n;
    long long a = n/60;  //cycle period is 60
    long long b = n%60;
    cout<< ( (a*square(60)) + square(b) )%10;
    
}