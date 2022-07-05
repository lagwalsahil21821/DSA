#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &v,int l,int mid,int r)
{
    int n = v.size();   // l - r + 1
    int i = l;      // store index
    int j = mid + 1;
    int k = l;  //indexing of resultant array 
    vector<int>res(n);
    while(i<=mid && j<=r){
        if(v[i] <= v[j]) {res[k] = v[i]; i++; }
        else {res[k] = v[j]; j++;}
        k++;
    }
    if(i > mid){
        while(j <= r){
            res[k] = v[j];
            j++; k++;
        }
    }else{
        while(i<= mid){
            res[k] = v[i];
            i++; k++;
        }
    }
    for (int k = l; k <= r; k++)
    {
        v[k] = res[k];
    }
    
}
void mergeSort(vector<int> &v, int l, int r)
{
    
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        merge(v,l,mid,r);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    mergeSort(v,0,n-1);
    for(auto &x: v) cout<<x<<" ";
}