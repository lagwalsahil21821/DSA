#include<bits/stdc++.h>
using namespace std;
// Dutch national flag algo for 3 partition
pair<int,int> partition(vector<int>&v ,int l,int r){    // l  = starting index  , r = end index
    int mid = l;
    int pivot = v[r];

    while(mid <= r){
        if(v[mid] < pivot) {
            swap(v[mid],v[l]);
            ++l; ++mid;
        }
        else if(v[mid] == pivot){
            ++mid;
        }else{
            swap(v[mid],v[r]);
            --r;
        }
    }

    // v[l ... mid-1] contains all occurences of a pivot
    return make_pair(l-1,r);
}

void QuickSortEqualElements(vector<int> &v,int l,int r){
    if(l >= r) return;

    int pivot = l + rand() % (r-l+1);   // pick random value
    swap(v[r],v[pivot]);

    // three region implementation
    pair<int,int>p = partition(v,l,r);

    QuickSortEqualElements(v,l,p.first);
    QuickSortEqualElements(v,p.second,r);     // as recursive call take O(n) space comlexity so in case of 
                                                 // all equal elements partition occur 0 and n elements so worst 
                                                 // space comlexity in this region is O(n)
    
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x: v) cin>>x;
    QuickSortEqualElements(v,0,v.size() - 1);
    for (size_t i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<' ';
    }
    
}