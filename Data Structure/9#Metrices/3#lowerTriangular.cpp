#include<bits/stdc++.h>
using namespace std;
struct matrix{
    int *A;
    int n;
};
void Set(struct matrix *m,int i ,int j ,int x){
    if(i>=j) m->A[i*(i-1)/2 + (j-1)] = x;   //for column major
                                            // m->A[m.n*(j-1)*j-2)*(j-1)/2+i-j];
}
int Get(struct matrix m,int i,int j){
    if(i>=j) return m.A[i*(i-1)/2 + (j-1)];
    else return 0;

}
void display(struct matrix m){
    int i,j;
    for(int i = 1; i<= m.n;i++){
        for (int j = 1; j <= m.n; j++)
        {
            if(i>=j) cout<<m.A[i*(i-1)/2 + (j-1)]<<' ';
        
            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
}
int main(){
    struct matrix m;
    int x;
    printf("Enter the dimensions: ");
    scanf("%d",&m.n);
    m.A = (int *)malloc(m.n*(m.n+1)/2*sizeof(int));
    printf("Enter all elements:\n");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            scanf("%d",&x);
            Set(&m,i,j,x);
        }
    }
    cout<<"\n";
    display(m);
    
    return 0;
}