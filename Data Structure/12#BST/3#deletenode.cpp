#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* lchild,*rchild;
}*root = NULL;

void insert(int key){
    struct node *t = root;
    struct node *r,*p;

    if(root == NULL){
        p = new node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while(t!=NULL){
        r = t;
        if(key < t->data) t = t->lchild;
        else if(key > t->data) t= t->rchild;
        else return;
    }

    p = new node;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(key < r->data) r->lchild = p;
    else r->rchild = p;

}

void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<' ';
        inorder(p->rchild);
    }
}

struct node* BS(int key){
    struct node *p = root;
    while(p!=NULL){
        if(key == p->data) return p;
        else if(key < p->data) p = p->lchild;
        else p = p->rchild;
    }
    return NULL;
}

struct node* Rinsert(struct node *p,int key){
    struct node *t;
    if(p== NULL){
        t = new node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data) p->lchild = Rinsert(p->lchild,key);
    else if(key > p->data) p->rchild = Rinsert(p->rchild,key);

    return p;
}

int Height(struct node *p){
    int x,y;
    if(p == NULL) return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y?x+1:y+1;
}

struct node* InPre(struct node *p){
    while(p && p->rchild != NULL)
        p = p->rchild;
    return p;
}
struct node* InSuc(struct node *p){
    while(p && p->lchild != NULL)
        p = p->lchild;
    return p;
}
struct node* Delete(struct node *p,int key){
    struct node* q;
    if(p == NULL) return NULL;
    if(p->lchild == NULL && p->rchild == NULL){
        if(p == root) root = NULL;
        free(p);
        return NULL;
    }

    if(key < p->data) p->lchild = Delete(p->lchild,key);
    else if(key > p->data)p->rchild = Delete(p->rchild,key);
    else{
        if(Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }
        else{
            q = InPre(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main(){
    struct node *temp;
    root = Rinsert(root,50);
    Rinsert(root,10);
    Rinsert(root,40);
    Rinsert(root,20);
    Rinsert(root,30);

    Delete(root,50);

    inorder(root);  //gives sorted order of elements
    cout<<"\n";

    temp = BS(20);
    if(temp!=NULL) cout<<"Element "<<temp->data<<" is found\n";
    else cout<<"Element not found\n";


    return 0;
}