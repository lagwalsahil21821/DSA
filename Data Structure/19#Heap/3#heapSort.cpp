// first create heap
// delete element from heap 
// store it in last vacant place 

#include<bits/stdc++.h>
using namespace std;

void insert(int H[],int n){
    int i = n;
    int temp = H[i];
    while(i>1 && temp > H[i%2 == 0 ? (i/2)-1 : i/2]){
        H[i] = H[i%2 == 0 ? (i/2)-1 : i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;

    }
    H[i] = temp;
}

int Delete(int A[], int n){
    int i,j,x,val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1; j = i*2;
    
    while(j < n-1){
        if(A[j+1] > A[j]) j++;
        if(A[j] > A[i]){
            swap(A[i],A[j]);
            i = j;
            j = 2*j;
        }
        else break;
    }

    return val;
}

int main(){
    int H[] = {0,10,20,30,25,5,40,35};
    
    for (int i = 2; i <= 7; i++)
        insert(H,i);

    for (int i = 7; i > 1; i--)
    {
        Delete(H,i);
    }
    cout<<"Heap Sort: ";
    for (int i = 1; i <= 7; i++)
    {
        cout<<H[i]<<' ';
    }
    
    
    return 0;
}