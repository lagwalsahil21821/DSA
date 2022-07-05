#include<bits/stdc++.h>
using namespace std;
//diagonal matrix
int main(){
    int *A,n,ch,x,i,j;
    cout<<"Enter Dimension: ";
    cin>>n;
    A = new int[n];
    do{
        //display menu
        cout<<"1. Create\n2. Get\n3. Set\n4. Display\n";
        cout<<"Enter cHoice: "; cin>>ch;
        switch(ch){
            case 1:
            for (int i = 0; i < n; i++)
            {
                cin>>A[i-1];
            }
            break;
            case 2:
            cout<<"Enter indices: ";
            cin>>i>>j;
            if(i==j) cout<<A[i-1];
            else cout<<"0";
            break;
            
            case 3:
            cout<<"Enter the row and column element: ";
            cin>>i>>j>>x;
            if(i==j) A[i-1] = x;
            break;
            case 4:
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(i == j) cout<<A[i-1]<<' ';
                    else cout<<"0 ";
                }
                cout<<endl;
            }
            default:
            break;
        }
    }while(1);
}