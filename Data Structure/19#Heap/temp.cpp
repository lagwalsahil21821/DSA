#include<bits/stdc++.h>
using namespace std;

 
int maxProduct(vector<int>& nums) {
    
    int n = nums.size();
    vector<int> vec(n);
    for(int i = 0; i<n; i++)
    {
        int j = i;
        int temp = nums[j];
        while(j>0 && temp > vec[j%2 == 0 ? (j/2)-1 : j/2])
        {
            vec[j] = vec[j%2 == 0 ? (j/2-1) : j/2];
            j = j%2==0 ? (j/2)-1 : j/2;
        }
        vec[j] = temp;
    }
    //now find max of b/w 2nd and 3rd place
    int imp;
    if(vec[1]> vec[2]) imp = vec[1];
    else imp = vec[2];
    
    return imp*vec[0];
    
    
    
    
}

int main()
{
    vector<int> b = {10, 20, 30, 25, 5, 40, 35};
    cout<<maxProduct(b);
    
}