#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5] = {2,3,4,5,6};
    int *p;
    p = new int[5];
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 9;
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for (int i = 0; i < 5; i++)
    {
        cout<<p[i]<<' ';
    }
    
    return 0;
}