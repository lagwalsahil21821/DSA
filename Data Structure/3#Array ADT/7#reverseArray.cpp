#include<bits/stdc++.h>
using namespace std;
class Arr{
private:
    int *A;
    int size;
    int length;
public:
    Arr(int size){      //constructor
        this->size = size;
        A = new int[size];
    }
    void create(){
        cout<<"Enter no. of elements to be inserted: ";
        cin>>length;
        for (int i = 0; i < length; i++)
        {
            cout << "Array element: " << i << " = " << flush;
            cin>>A[i];
        }
        
    }
    void display(){
        for (int i = 0; i < length; i++)
        {
            cout<<A[i]<<' ';
        }
        
    }
    void reverse(){
        int *B;
        B = new int[length];
        int j;
        for(int i = length-1,j = 0; i>=0; i--,j++ ){
            B[j] = A[i];
        }
        for (int i = 0; i < length; i++)
        {
            A[i] = B[i];
        }
        
    }

    void reverseSwap();

    ~Arr(){
        delete[] A;
        cout<<"\nArray Destroyed\n";
    }

};
void Arr:: reverseSwap(){
    int j;
    for (int i = 0,j= length-1; i < j; i++,j--)
    {
        swap(A[i],A[j]);
    }
}
int main(){
    Arr arr(10);
    arr.create();
    arr.display();
    arr.reverseSwap();
    cout<<"\nArr after reverse: ";
    arr.display();
    arr.reverse();
    cout<<"\nArr after 2nd reverse: ";
    arr.display();
    return 0;
}