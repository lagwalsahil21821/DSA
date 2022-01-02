#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    
    int r;
    vector<int>temp;
    for (int i = 0; i < n; i++)
    {
        int q = 100;
        int best = vec[i];
        while(q>=10){
            q = best/10;
            r = best % 10;
            
            best = q;
        }
        temp.push_back(r);
        

    }
    //imp part 
    // store previous index after sorting
    vector<size_t> idx(temp.size());    //size_t is like unsigned int 
    iota(idx.begin(), idx.end(), 0);

    stable_sort(idx.begin(), idx.end(), [temp](size_t i1, size_t i2){
        return temp[i1] < temp[i2];
    });

    reverse(idx.begin(),idx.end());

    for (int i = 0; i < n; i++)
    {
        int x = idx[i];
        cout<<vec[x];
    }
    
    
}