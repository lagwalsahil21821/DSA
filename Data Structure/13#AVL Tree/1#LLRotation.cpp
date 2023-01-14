#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    int height;  // for maintaining balance factor
    node* lchild,*rchild;
}*root = NULL;

int nodeHeight(struct node *p){
    int hl,hr;
    hl = p && p->lchild? p->lchild->height:0;
    hr = p && p->rchild? p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct node *p){
    int hl,hr;
    hl = p && p->lchild? p->lchild->height:0;
    hr = p && p->rchild? p->rchild->height:0;
    return hl-hr;
}

struct node* LLRotation(struct node *p){
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeHeight(p);
    pl->height=nodeHeight(pl);

    if(root == p) root = pl;

    return pl;
}

struct node* LRRotation(struct node *p){
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height - nodeHeight(plr);

    if(root == p) root = plr;

    return plr;
}

struct node* RRRotation(struct node *p){
    return NULL;
}

struct node* RLRotation(struct node *p){
    return NULL;
}


struct node* RInsert(struct node *p ,int key){
    struct node *t = NULL;
    if(p == NULL){
        t = new node;
        t->data = key;
        t->height = 1;  //starting height from 1 not 0
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data) p->lchild = RInsert(p->lchild,key);
    else if(key > p->data) p->rchild = RInsert(p->rchild,key);
    
    p->height = nodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1){
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

void inorder(struct node* p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<' ';
        inorder(p->rchild);
    }
}
int main(){
    root = RInsert(root,10);
    RInsert(root,5);
    RInsert(root,7);
    LRRotation(root);
    return 0;
}

