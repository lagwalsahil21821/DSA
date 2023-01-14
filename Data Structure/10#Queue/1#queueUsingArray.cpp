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
    qu->f = -1;
    qu->r = -1;
    qu->q = new int[qu->size];
}
void enqueue(struct que *qu,int x){
    if(qu->r == qu->size - 1) cout<<"overflow\n";
    else{
        qu->r++;
        qu->q[qu->r] = x;
    }
}

int dequeue(struct que *qu){
    int x = -1;
    if(qu->f == qu->r) cout<<"Underflow\n";
    else{
        qu->f++;
        x = qu->q[qu->f];
    }
    return x;
}

void display(struct que qu){
    for (int i = qu.f+1; i <= qu.r; i++)
    {
        cout<<qu.q[i]<<' ';
    }
    cout<<"\n";
    
}

int main(){
    struct que q;
    create(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    cout<<"dequeue element is: "<<dequeue(&q)<<"\n";
    display(q);
}


