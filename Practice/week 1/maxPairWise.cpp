#include<iostream>
#include<vector>
using namespace std;
// as input is to 10^5 so when you multiply two numbers then result goes to 10^10 and it not come in the range of int so instead of int use long long
// but Still it shows error of TLE so what to do now 
// just go with another approach
// like multiply max two number.
void maxProd(vector<int> x){
    int n=x.size();
    long long result=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if( ( ( (long long)x[i] ) * x[j]) > result)
            result= ( (long long)x[i] ) *x[j];
        }
    }
    cout<<result<<"\n"; // Max pairwise Product
}

int main(){
    int n;
    cin>>n;
    vector<int> number(n);
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }
    maxProd(number);
    return 0;
    
}