#include<bits/stdc++.h>
using namespace std;
int main(){
    //declaration
    //1st method
    int a[3][4] = { {1,2,3,4},{2,4,6,8},{1,3,5,7}};
    
    //2nd method
    int *b[3];
    b[0] = new int[4];
    b[1] = new int[4];
    b[2] = new int[4];

    //3rd method
    int **c;
    c = new int*[3];
    c[0] = new int[4];
    c[1] = new int[4];
    c[2] = new int[4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<"\n";
        
    }
    cout<<"\nUsing 2nd method:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<b[i][j]<<' ';
        }
        cout<<"\n";
        
    }

    cout<<"\nUsing 3rd method:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<c[i][j]<<' ';
        }
        cout<<"\n";
        
    }
    

}