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

    int BinarySearch(int key){
        int l,r,mid;
        l = 0;
        r = length - 1;
        while(l <= r){
            mid = (l+r)/2;
            if(key == A[mid]) return mid;
            else if(key < A[mid]) r = mid -1;
            else l = mid + 1;
        }
        return -1;
    }

    int RBS(int key,int l ,int r){
        int mid;
        if(r < l) return -1;
        mid = (l+r)/2;
        if(key == A[mid]) return mid;
        else if(key < A[mid]) return RBS(key,l,mid-1);
        else return RBS(key,mid+1,r);
        //if not found
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
    cout<<"\nfound at index: "<<arr.BinarySearch(4)<<"\n";
    cout<<"\nfound at index: "<<arr.RBS(2,0,10)<<"\n";
    cout<<"\nfound at index: "<<arr.RBS(10,0,10)<<"\n";
    cout<<"Array: ";
    arr.display();
    return 0;
}