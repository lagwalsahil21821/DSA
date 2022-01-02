#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,8,5,4,1,2,8};
    int a=arr[0];
    int size=sizeof(arr)/sizeof(arr[0]);
    for (int i = 1; i < size; i++)
    {
        a ^= arr[i];
    }
    if(a == 0){
        cout<<"Every element in array is repeating";
    }else
    {
    
        cout<<"Non repeating element in array is: "<<a;
    }
}