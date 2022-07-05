#include<bits/stdc++.h>
using namespace std;
class ltm{
private:
    int n;
    int *A;
public:
    ltm(int n){
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~ltm(){
        delete []A;
    }
};

void ltm:: set(int i,int j ,int x){
    if(i >= j) A[i*(i-1)/2 + (i-j)] = x;
}
int ltm::get(int i,int j){
    if(i >= j) return A[i*(i-1)/2 + (i-j)];
    else return 0;
}
void ltm:: display(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i >= j) cout<<A[i*(i-1)/2 + (i-j)]<<' ';
            else cout<<"0 ";
        }
        cout<<endl;
    }
    
}
int main(){
    int n;
    cout<<"Enter Dimension: ";
    cin>>n;
    ltm M(n);
    int x;
    cout<<"Enter all elements: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>x;
            M.set(i,j,x);
        }
        
    }
    M.display();
    return 0;
}