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

    void append(int x){
        if(length < size){
            A[length] = x;
            length++;
        }
    }

    void insert(int index,int x){
        if(index >= 0 && index <=length){
            for (int i = length ; i > index; i--)
            {
                A[i] = A[i-1];
            }
            A[index] = x;
            length++;
            
            
        }
    }

    void deletion(int index){
        if(index >= 0 && index < length){
            for (int i = index; i < length -1 ; i++)
            {
                A[i] = A[i+1];
            }
            length--;
        }
    }

    int linearSearch(int key){
        for (int i = 0; i < length; i++)
        {
            if(key == A[i])
            {
                swap(A[i],A[i-1]);
                return i;
            }
        }
        return -1;
    }
    ~Arr(){
        delete[] A;
        cout<<"\nArray Destroyed\n";
    }

};
int main(){
    Arr arr(10);
    arr.create();
    arr.display();
    cout<<"\nfound at index: "<<arr.linearSearch(4)<<"\n";
    cout<<"Array: ";
    arr.display();
    return 0;
}