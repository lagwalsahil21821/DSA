#include<bits/stdc++.h>
using namespace std;

pair<int,int> Partition(int A[],int l, int h){
    int i = l;  //treat i as mid
    int pivot = A[h];
    while(i <= h){
        if(A[i] < pivot){
            swap(A[i],A[l]);
            ++l; ++i;
        }
        else if(A[i] == pivot){
            ++i;
        }
        else{
            swap(A[i],A[h]);
            --h;
        }
    }
    return make_pair(l-1,h);
}

void QuickSort(int A[],int l,int h){
    if(l >= h) return;
    int pivot = l + rand()%(h-l+1);
    swap(A[h],A[pivot]);

    // three region implementation
    pair<int,int>p = Partition(A,l,h);
    QuickSort(A,l,p.first);
    QuickSort(A,p.second,h);    // as recursive call take O(n) space comlexity so in case of 
                                // all equal elements partition occur 0 and n elements so worst 
                                // space comlexity in this region is O(n)
    
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
    int l = 0;
    QuickSort(arr,l,n-1);
    cout<<"Quick sort: ";
    display(arr,n);
}