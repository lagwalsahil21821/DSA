#include<bits/stdc++.h>
using namespace std;
class diagonal{
private:
    int n;
    int *A;
public:
    diagonal(int n){
        this->n = n;
        A = new int[n];
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~diagonal(){
        delete []A;
    }
};
void diagonal:: set(int i,int j ,int x){
    if(i == j) A[i-1] = x;
}
int diagonal::get(int i,int j){
    if(i == j) return A[i-1];
    else return 0;
}
void diagonal:: display(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j) cout<<A[i]<<' ';
            else cout<<"0 ";
        }
        cout<<endl;
    }
    
}


int main(){
    int n;
    cout<<"Enter Dimension: ";
    cin>>n;
    diagonal M(n);
    int x;
    cout<<"Enter all elements: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>x;
            M.set(i,j,x);
        }
        
    }
    M.display();
    return 0;
}