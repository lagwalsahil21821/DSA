#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n){
    int j,k;
    for (int i = 0; i < n-1; i++)
    {
        for (k = j = i; j < n; j++)
        {
            if(arr[j] < arr[k]){
                k = j;
            }
            
        }
        swap(arr[i],arr[k]);
    }
}
void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<' ';
    }
    
}
int main(){
    int arr[] = {10,40,5,15,45,67,45,33};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    cout<<"Selection sort: ";
    display(arr,n);
}