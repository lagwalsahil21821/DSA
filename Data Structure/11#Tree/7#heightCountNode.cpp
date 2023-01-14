#include<bits/stdc++.h>
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
void preorder(struct node *p){
    if(p){
        cout<<p->data<<' ';
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Inorder(struct node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<' ';
        Inorder(p->rchild);
    }
}

void postorder(struct node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        
        cout<<p->data<<' ';
    }
}
int count(struct node *root){
    if(root) return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}

int height(struct node *root){
    int x=0,y=0;
    if(root == NULL) return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if(x>y)return x+1;
    else return y+1;

}

int main(){
    create();
    cout<<"pre-order traversal: ";
    preorder(root);
    
    cout<<"\nInorder Traversal: ";
    Inorder(root);
    
    cout<<"\nPost-order Traversal: ";
    postorder(root);

    cout<<"\n\n";
    cout<<"Total no. of nodes: ";
    count(root);
    cout<<"\nHeight of tree: ";
    height(root);
}