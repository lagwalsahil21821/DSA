#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
    int flag;
    for (int i = 0; i < n-1; i++)
    {
        flag = 0;
        for (int j = 0; j < n-1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
        
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
    bubbleSort(arr,n);
    cout<<"Bubble sort: ";
    display(arr,n);
}