#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    //logic
    for (int i = 0; i < n; i++)
    {
        int minindex = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[minindex]) minindex = j;
        }
        swap(arr[i],arr[minindex]);
    }
    

    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}