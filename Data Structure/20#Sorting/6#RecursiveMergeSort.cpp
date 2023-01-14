#include<bits/stdc++.h>
using namespace std;

void merge(int A[],int l,int mid,int r){
    int i,j,k;
    i = l;
    j = mid+1;
    k = l;
    int B[r+1];
    while(i <= mid && j<= r){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    while(i <= mid){
        B[k++] = A[i++];
    }
    while(j <= r){
        B[k++] = A[j++];
    }
    for (int i = l; i <= r; i++)
    {
        A[i] = B[i];
    }
    
}
void mergeSort(int arr[],int l,int r){
    int mid;
    if(l<r){
        mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){
    int n;
    cout<<"A: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    cout<<"Sorted A: ";
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<' ';
    }
    

}

