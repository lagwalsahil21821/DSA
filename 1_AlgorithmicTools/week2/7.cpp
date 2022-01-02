#include<bits/stdc++.h>
using namespace std;
int sum(int y,int x){
    long long first = 0;
    long long second = 1;
    long long temp ;
    int sum = 0;
    if(x<=1)
    return x;
    for (int i = 0; i <= x; i++)
    {
        if(i>=y){
            sum = (sum + first) % 10;
        }
        temp = first;
        first = second;
        second = (temp + first)% 10;
        
    }
    return sum;
}
int main(){
    long long m,n;
    cin>>m>>n;
    long long a = n/60 + 1;
    long long b = n%60;
    long long c = m%60;
    long long d = m/60;
    long long result;
    
    result = ( ( sum(0,b) ) + ((a-1)*sum(0,60)) + sum(c,60) )%10;
    cout<<result;
}