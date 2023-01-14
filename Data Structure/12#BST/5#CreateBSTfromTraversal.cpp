#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *lchild,*rchild;
}*root = NULL;

void preTrav(int *pre,int n){
    struct node *t,*p = root;
    stack<node*> stk;   // to store addresses of node
    root = new node;
    root->data = pre[0];
    root->lchild = root->rchild = NULL;
    p = root;
    int i = 1;
    while(i < n){
        if(pre[i] < p->data){
            t = new node;
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else{
            
            if(pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data){
                t = new node;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else{
                p = stk.top();
                stk.pop();
            }
        }
    }
}

void Inorder(struct node* t){
    if(t){
        Inorder(t->lchild);
        cout<<t->data<<' ';
        Inorder(t->rchild);
    }
}

int main(){
    int pre[] = {30,20,10,15,25,40,50,45};
    int size = sizeof(pre)/sizeof(pre[0]);
    preTrav(pre,size);
    Inorder(root);
}