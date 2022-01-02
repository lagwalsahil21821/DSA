#include <bits/stdc++.h>
using namespace std;
int main()
{
    int items, bagCapacity;
    double loot = 0;
    cin >> items >> bagCapacity;
    int value[items], wt[items];
    vector<double> valuePerUnit;
    for (int i = 0; i < items; i++)
    {
        cin >> value[i] >> wt[i];
        valuePerUnit.push_back((double)value[i] / wt[i]);   //store it in decimal to use double
    }

    //imp part 
    // store previous index after sorting
    vector<size_t> idx(valuePerUnit.size());    //size_t is like unsigned int 
    iota(idx.begin(), idx.end(), 0);

    stable_sort(idx.begin(), idx.end(), [valuePerUnit](size_t i1, size_t i2){
        return valuePerUnit[i1] < valuePerUnit[i2];
    });
    
    
    reverse(idx.begin(),idx.end());     //reverse so vector sort in decending order
    
    
    for (size_t i = 0 ; i < idx.size(); i++)
    {
        int x = idx[i];
        int a = min(bagCapacity, wt[x]);
        loot += valuePerUnit[x] * (double)a;
        bagCapacity = bagCapacity - a;
        wt[x] -= a;
        
    }
    
    
    cout<<fixed<<setprecision(4)<<loot; // to print output upto four digit after decimal
    
 
}