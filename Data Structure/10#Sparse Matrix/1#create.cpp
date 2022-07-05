#include<bits/stdc++.h>
using namespace std;
struct element{
    int i;  //row
    int j;  //column
    int x;  //value
};

struct sparse{
    int m;  //no. of rows
    int n;  // no of columns
    int num; // no. of non zero elements
    struct element *e;
};
void create(struct sparse *s){
    cout<<"Enter Dimensions: ";
    cin>>s->m>>s->n;
    cout<<"Enter the no. of non-zero elements: ";
    cin>>s->num;
    s->e = new element[s->num];
    cout<<"Enter all Elements: \n";
    for (int i = 0; i < s->num; i++)
    {
        cin>>s->e[i].i>>s->e[i].j>>s->e[i].x;
    }
    
}

void display(struct sparse s){
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if(i == s.e[k].i && j == s.e[k].j)
                cout<<s.e[k++].x<<' ';
            else cout<<"0 ";
        }
        cout<<"\n";
        
    }
    
}

int main(){
    struct sparse s;
    create(&s);
    display(s);
    return 0;
}