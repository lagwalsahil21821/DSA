#include<bits/stdc++.h>
using namespace std;
class node{
public:
    char data;
    node* next;
};

class stk{
private:
    node* top;
public:
    stk();
    ~stk();
    void push(char x);
    char pop();
    void display();
    char peek(int index);
    int isEmpty();
    int isFull();
    char stackTop();
};
stk::stk(){top = nullptr;}
stk::~stk(){
    node *p = top;
    while(top){
        top = top->next;
        delete p;
        p = top;
    }
}
void stk::push(char x){
    node* t = new node;
    if(t==NULL) cout<<"Stack overflow\n";
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}
char stk:: pop(){
    int x = -1;
    node* t;
    if(top == NULL) cout<<"Stack Underflow!\n";
    else{
        t = top;
        x = top->data;
        top = top->next;
        delete t;
    }
    return x;
}
int stk::isFull(){
    node *t = new node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int stk::isEmpty(){
    return top ? 0 : 1;
}

char stk:: stackTop(){
    if(top) return top->data;
    return -1;
}

char stk::peek(int index){
    if(isEmpty())return -1;
    else{
        node *p = top;
        for (int i = 0;p && i<index-1; i++)
        {
            p = p->next;
        }
        if(p){
            return p->data;
        }else{
            return -1;
        }
        
    }

}

int isBalanced(char* exp){
    stk s;
 
    for (int i=0; i<strlen(exp); i++){
        if (exp[i] == '('){
            s.push(exp[i]);
        } else if (exp[i] == ')'){
            if (s.isEmpty()){
                return false;
            } else {
                s.pop();
            }
        }
    }
    return s.isEmpty() ? true : false;
}
 
 
int main() {
 
    char E[] = "((a+b)*(c-d))";
    cout << isBalanced(E) << endl;
 
    char F[] = "((a+b)*(c-d)))";
    cout << isBalanced(F) << endl;
 
    char G[] = "(((a+b)*(c-d))";
    cout << isBalanced(G) << endl;
 
    return 0;
 
}