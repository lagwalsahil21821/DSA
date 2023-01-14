#include<bits/stdc++.h>
using namespace std;
class stk{
private: 
    int size;
    int top;
    int* st;
public:
    stk(int size){
        this->size = size;
        top = -1;
        st = new int[size];
    }
    ~stk();
    void push(int x);
    int pop();
    int peek(int index);
    int stackTop();
    int isFull();
    int isEmpty();
    void display();
};
stk::~stk(){
    delete[] st;
}
void stk::push(int x){
    if(isFull()) cout<<"overFlow\n";
    else{
        top++;
        st[top] = x;
    }
}
int stk::pop(){
    int x = -1;
    if(isEmpty()) cout<<"UnderFlow\n";
    else{
        x = st[top];
        top--;
    }
    return x;
}
int stk::peek(int index){
    int x = -1;
    if(top - index + 1 < 0 || top-index+1 ==size) cout<<"invalid position\n";
    else{
        x = st[top-index+1];
    }
    return x;
}
int stk::stackTop(){
    if(top == -1) return -1;
    else{
        return st[top];
    }
}
int stk:: isEmpty(){
    if(top == -1) return 1;
    else return 0;
}
int stk::isFull(){
    if(top == size-1) return 1;
    else return 0;
}
void stk::display(){
    for (int i = top; i >= 0; i--)
    {
        cout<<st[i]<<" | "<<endl;
    }
    cout<<endl;
    
}

int main(){
    stk s(10);
    s.push(10);
    s.push(1);
    s.push(0);
    s.push(20);
    s.push(30);

    cout << "Stack full: " << s.isFull() << endl;
 
    // Display stack;
    cout << "Stack: " << flush;
    s.display();
 
    // Peek
    cout << "Peek at 0th: " << s.peek(0) << endl;
    cout << "Peek at 3rd: " << s.peek(3) << endl;
    cout << "Peek at 10th: " << s.peek(10) << endl;
 
    // Top element
    cout << "Top element: " << s.stackTop() << endl;
 
    s.pop();
 
    cout << "Stack empty: " << s.isEmpty() << endl;
 
    return 0;
}