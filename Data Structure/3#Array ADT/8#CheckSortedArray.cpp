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
    void InsertSort(int x){
        int i = length -1;
        if(length == size)return ;//there is no free space
        while(i>= 0 && A[i] > x){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = x;
        length++;
    }

    //if array is sorted or not
    bool isSorted(){
        for (int i = 0; i < length-1; i++)
        {
            if(A[i] > A[i+1]) return false;
        }
        return true;
    }
    
    void Rearrange(){
        int i,j;
        i = 0;
        j = length -1;
        while(i<j){
            while(A[i] < 0)i++;
            while(A[j] >= 0)j--;
            if(i<j)swap(A[i],A[j]);
        }
    }
    ~Arr(){
        delete[] A;
        cout<<"\nArray Destroyed\n";
    }

};

int main(){
    Arr arr(10);
    arr.create();
    // arr.display();
    // arr.InsertSort(20);
    // cout<<"\n";
    // arr.display();
    // cout<<"\n";
    // cout<<arr.isSorted();
    arr.Rearrange();
    arr.display();
    
}