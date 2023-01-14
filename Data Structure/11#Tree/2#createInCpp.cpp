#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node *lchild;
    int data;
    node *rchild;
};

class CircularQueue{
private:
    int size;
    int front;
    int rear;
    node **Q;
public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isFull();
    bool isEmpty();
    void enqueue(node* x);
    node* dequeue();
    void display();
};
 
CircularQueue::CircularQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new node*[size];
}
 
CircularQueue::~CircularQueue() {
    delete [] Q;
}
 
bool CircularQueue::isEmpty() {
    return front==rear;
}
 
bool CircularQueue::isFull() {
    if ((rear + 1) % size == front){
        return true;
    }
    return false;
}
 
void CircularQueue::enqueue(node* x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}
 
node* CircularQueue::dequeue() {
    node* x = NULL;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}


class Tree{
    //if root is private then create dummy function bcz it's not possible to call this node in main 
    node *root;
public:
    Tree(){root = NULL;}
    void createTree();

    void Preorder(){Preorder(root);} //dumy function
    void Preorder(node *p);

    void Postorder(){Postorder(root);}
    void Postorder(node *p);

    void Inorder(){Inorder(root);}
    void Inorder(node *p);

    void Levelorder(){Levelorder(root);}
    void Levelorder(node *p);

    int Height(){Height(root);}
    int Height(node *p);
};
void Tree::createTree(){
    int x;
    node *p,*t;

    CircularQueue q(100);

    cout<<"Enter value for root element: ";
    cin>>x;
    root = new node;
    root->data= x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        cout<<"Enter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){  //left node
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout<<"Enter right child "<<p->data<<": ";
        cin>>x;
        if(x!=-1){  //right node
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(node *p){
     if(p){
        cout<<p->data<<' ';
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<' ';
        Inorder(p->rchild);
    }
}

void Tree::Postorder(node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        
        cout<<p->data<<' ';
    }
}

void Tree::Levelorder(node *root){
    CircularQueue q(100);
    cout<<root->data<<' ';
    q.enqueue(root);
    while(!q.isEmpty()){
        root= q.dequeue();
        if(root->lchild){
            cout<<root->lchild->data<<' ';
            q.enqueue(root->lchild);
        }
        if(root->rchild){
            cout<<root->rchild->data<<' ';
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(node *root){
    int x = 0,y= 0;
    if(root == 0) return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(x>y) return x;
    else return y;
}

int main(){
    Tree t;
    t.createTree();
    cout<<"\npreorder Traversal: ";
    t.Preorder();
    cout<<"\nInorder Traversal: ";
    t.Inorder();
    cout<<"\nPostorder Traversal: ";
    t.Postorder();
    cout<<"\nLevel Traversal: ";
    t.Levelorder();
    cout<<"\nHeight of Tree: ";
    cout<<t.Height();
    
}
