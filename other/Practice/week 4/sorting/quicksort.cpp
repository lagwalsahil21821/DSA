//randomized Quick Sort
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&v , int l,int r){
    int x = v[l];   // pivot
    int j = l;
    for (int i = l+1; i <= r; i++)
    {
        if(v[i] <= x){
            j++;
            swap(v[i],v[j]);
        }
    }
    swap(v[l],v[j]);
    return j;
}

void quicksort(vector<int> &v,int l,int r){
    if (l >= r) return;

    int pivot = l + rand() % (r - l + 1);
    swap(v[l],v[pivot]);
    int m = partition(v,l,r);
    quicksort(v,l,m-1);
    quicksort(v,m+1,r);
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int n;
    cin>>n; // no. of elements in sequence
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int l = 0;
    int r = v.size() - 1;
    quicksort(v,l,r);
    for (size_t i = 0; i < v.size(); i++)   // size_t     unsigned datatype
    {
        cout<< v[i]<<' ';
    }
    

}