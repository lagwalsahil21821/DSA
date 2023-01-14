#include<bits/stdc++.h>
using namespace std;
struct que{
    int size;
    int f;
    int r;
    int *q;
};
void create(struct que *qu){
    cout<<"Enter the size: "; cin>>qu->size;
    qu->f = 0;
    qu->r = 0;
    qu->q = new int[qu->size];
}
void enqueue(struct que *qu,int x){
    if( (qu->r + 1)% qu->size == qu->f) cout<<"Queue is full\n";
    else{
        qu->r = (qu->r + 1)%qu->size;
        qu->q[qu->r] = x;
    }
}

int dequeue(struct que *qu){
    int x = -1;
    if(qu->f == qu->r) cout<<"Queue is empty\n";
    else{
        qu->f = (qu->f + 1) % qu->size;
        x = qu->q[qu->f];
    }
    return x;
}

void display(struct que qu){
    int i = qu.f + 1;
    do{
        cout<<qu.q[i]<<' ';
        i = (i+1)%qu.size;

    }while(i!=(qu.r + 1)%qu.size);
    cout<<"\n";
}

int main(){
    struct que q;
    create(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    cout<<"dequeue element is: "<<dequeue(&q)<<"\n";
    enqueue(&q,30);
    enqueue(&q,40);
    cout<<"dequeue element is: "<<dequeue(&q)<<"\n";
    enqueue(&q,50);
    
    display(q);
}


