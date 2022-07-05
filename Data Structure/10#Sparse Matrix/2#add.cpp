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

struct sparse * add(struct sparse *s1,struct sparse *s2){
    struct sparse *sum;
    int i,j,k;
    i = j = k = 0;
    sum = new sparse;
    sum->e = new element[s1->num+s2->num];
    while(i<s1->num && j<s2->num){
        if(s1->e[i].i < s2->e[j].i) sum ->e[k++] = s1->e[i++];
        else if(s1->e[i].i > s2->e[j].i) sum ->e[k++] = s2->e[j++];
        else{
            if(s1->e[i].j < s2->e[j].j) sum ->e[k++] = s1->e[i++];
            else if(s1->e[i].j > s2->e[j].j) sum ->e[k++] = s2->e[j++];
            else{
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for(;i<s1->num;i++){
        sum->e[k++] = s1->e[i];
    }
    for(; j<s2->num; i++){
        sum->e[k++] = s2->e[j];
    }
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    return sum;
}

int main(){
    struct sparse s1,s2,*s3;
    create(&s1);
    create(&s2);
    s3 = add(&s1,&s2);
    cout<<"First matrix\n\n";
    display(s1);
    cout<<"second matrix\n\n";
    display(s2);
    cout<<"sum matrix\n\n";
    display(*s3);
    return 0;
}