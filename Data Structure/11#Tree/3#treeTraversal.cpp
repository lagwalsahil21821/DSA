#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct node{
    struct node* lchild;
    int data;
    struct node* rchild;
}*root = NULL;

struct que{
    int size;
    int f;
    int r;
    node **q;
};

void Qcreate(struct que *qu,int size){
    qu->size = size;
    qu->f = 0;
    qu->r = 0;
    qu->q = new node*[qu->size];
}
void enqueue(struct que *qu,node* x){
    if( (qu->r + 1)% qu->size == qu->f) cout<<"Queue is full\n";
    else{
        qu->r = (qu->r + 1)%qu->size;
        qu->q[qu->r] = x;
    }
}

node* dequeue(struct que *qu){
    node* x = NULL;
    if(qu->f == qu->r) cout<<"Queue is empty\n";
    else{
        qu->f = (qu->f + 1) % qu->size;
        x = qu->q[qu->f];
    }
    return x;
}

int isEmpty(struct que q){
    return q.f == q.r;
}


void create(){
    int x;
    struct node *p,*t;

    struct que q;
    Qcreate(&q,100);

    cout<<"Enter value for root element: ";
    cin>>x;
    root = new node;
    root->data= x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        cout<<"Enter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){  //left node
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        cout<<"Enter right child "<<p->data<<": ";
        cin>>x;
        if(x!=-1){  //right node
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }

}

void RPreorder(struct node *p){
    if(p){
        cout<<p->data<<' ';
        RPreorder(p->lchild);
        RPreorder(p->rchild);
    }
}

void RInorder(struct node *p){
    if(p){
        RInorder(p->lchild);
        cout<<p->data<<' ';
        RInorder(p->rchild);
    }
}

void RPostorder(struct node *p){
    if(p){
        RPostorder(p->lchild);
        RPostorder(p->rchild);
        
        cout<<p->data<<' ';
    }
}

void itrPreorder(struct node *p){
    stack<node*>stk;
    while(p || !stk.empty()){
        if(p){
            cout<<p->data<<' ';
            stk.emplace(p);
            p = p->lchild;
        }
        else{
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
}

void itrPostorder(struct node *p){
    stack<long int> stk;
    long int temp;
    while(p || !stk.empty()){
        if(p){
            stk.emplace(p);
            p = p->lchild;
        }
        else{
            temp = stk.top();
            stk.pop();
            if(temp > 0){
                stk.emplace(-temp);
                p = ((node*)temp)->rchild;
            }
            else{
                cout<<((node*)temp)->data<<' ';
                p = NULL;
            }
        }
    }
    
}

void itrInorder(struct node *p){
    stack<node*> stk;
    while(p || !stk.empty()){
        if(p){
            stk.emplace(p);
            p = p->lchild;
        }
        else{
            p = stk.top();
            stk.pop();
            cout<<p->data<<' ';
            p = p->rchild;
        }
    }

}
int main(){
    create();
    cout<<"pre-order traversal: ";
    RPreorder(root);
    
    cout<<"\nInorder Traversal: ";
    RInorder(root);
    
    cout<<"\nPost-order Traversal: ";
    RPostorder(root);

    cout<<"\n\n";
    cout<<"***********Iterative Traversal**************\n";
    cout<<"pre-order traversal: ";
    itrPreorder(root);
    
    cout<<"\nInorder Traversal: ";
    itrInorder(root);
    
    cout<<"\nPost-order Traversal: ";
    itrPostorder(root);
}