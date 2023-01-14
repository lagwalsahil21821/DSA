#include<bits/stdc++.h>
using namespace std;
void shellSort(int A[],int n){
    for (int gap = n/2; gap > 1; gap/=2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = A[i];
            int j = i-gap;
            while(j>=0 && A[j]> temp){
                A[j+gap] = A[j];
                j -= gap;
            }
            A[j+gap] = temp;

        }
        
    }
    
}

int main(){
    int A[] = {11,13,7,12,16,9,24,5,10,3},n = 10;
    shellSort(A,n);
    for (int i = 0; i < 10; i++)
    {
        cout<<A[i]<<' ';
    }
    cout<<"\n";
    return 0; 
    
}