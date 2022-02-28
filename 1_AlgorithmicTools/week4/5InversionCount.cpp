#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>&v, int l,int mid,int r){
    int n = v.size();
    int i = l;
    int j = mid+1;
    int k = l;
    int count = 0;
    vector<int> res(n);
    while(i <= mid && j <= r){
        if(v[i] <= v[j]){
            res[k] = v[i];
            
            i++; 
        }else{
            res[k] = v[j];
            j++; 
            count += mid - i + 1;
        }
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
    
    return count;
    
}
int mergeSort(vector<int> &v,int l,int r){
    int inversion = 0;
    if(l<r){
        int mid = (l+r)/2;
        inversion += mergeSort(v,l,mid);
        inversion += mergeSort(v,mid+1,r);
        inversion += merge(v,l,mid,r);
        
    }
    return inversion;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    cout<<mergeSort(v,0,n-1)<<"\n";
    
    
}