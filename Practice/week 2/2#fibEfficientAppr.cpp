// Efficient approach for f(100) it will take only approx 202 lines of code
// as  T(n) = 2*n +2;


#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n; //  to calculate the fibbnacci no. at that position
    long long arr[n];
    long long *ptr = arr;     // ptr stores the address of arr[0]

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        *(ptr+i) = *(ptr + i -1) + *(ptr + i -2);
    }
    cout<<*(ptr + n)<<endl;
    return 0;
}

/*
without pointer

int main(){
    int n;
    cin>>n;
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2 ;i <=n ; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout<<arr[n];
    return 0 ;
}

*/