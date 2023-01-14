#include<bits/stdc++.h>
using namespace std;
class que{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    que(){front = rear = -1; size = 10; Q = new int[size];}
    que(int size){
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};
void que::enqueue(int x){
    if(rear == size -1) cout<<"Queue full\n";
    else{
        rear++;
        Q[rear] = x;
    }
}
int que::dequeue(){
    int x = -1;
    if(front == rear) cout<<"Queue is empty\n";
    else{
        front++;
        x = Q[front];
    }
    return x;
}
void que::display(){
    for (int i = front+1; i <= rear; i++)
    {
        cout<<Q[i]<<' ';
    }
    cout<<"\n";
}

int main(){
    que q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    cout<<"\n"<<q.dequeue()<<"\n";
    q.display();

}