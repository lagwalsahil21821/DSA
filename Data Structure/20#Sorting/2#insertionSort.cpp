#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int j = i-1;
        while(j > -1 && arr[j] > x){
            arr[j+1] =  arr[j];
            j--;
        }
        arr[j+1] = x;
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
    insertionSort(arr,n);
    cout<<"Insertion sort: ";
    display(arr,n);
}