#include<bits/stdc++.h>
using namespace std;
int findMax(int A[],int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(A[i] > maxi)maxi = A[i];
    }
    return maxi;
}

void countSort(int A[],int n){
    int *C;
    int max;
    max = findMax(A,n);
    C = new int[max+1];
    for (int i = 0; i < n; i++)
    {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        C[A[i]]++;
    }

    int j = 0;  // on A[0]
    int i = 0;  // on C[0]
    while(i < max+1){
        if(C[i] > 0){
            A[j++] = i;
            C[i]--;
        }
        else i++;
    }
    delete []C; //delete heap memory
}

int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    
    countSort(A,n);
    cout<<"Count Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<' ';
    }
    
}