#include<bits/stdc++.h>
using namespace std;
struct node{
    int coeff;
    int exp;
    struct node *next;
}*poly = NULL;

void create(){
    struct node *t,*last;
    int num;
    cout<<"Enter no. of terms: ";
    cin>>num;
    cout<<"Enter each term with coeff and exp\n";
    for (int i = 0; i < num; i++)
    {
        t = new node;
        cin>>t->coeff>>t->exp;
        t->next = NULL;
        if(poly == NULL){
            poly = last = t;
        }
        else{
            last->next = t;
            last = t;
        }

    }
    
}

long eval(struct node* p,int x){
    long val;
    while(p){
        val += p->coeff * pow(x,p->exp);
        p = p->next;
    }
    return val;
}

void display(struct node *p){
    while(p){
        cout<<p->coeff<<"x"<<p->exp<<"+ ";
        p = p->next;
    }
    cout<<"\n";
}

int main(){
    create();
    display(poly);
    cout<<eval(poly,2);
}