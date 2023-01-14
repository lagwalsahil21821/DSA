#include<bits/stdc++.h>
using namespace std;

void insert(int arr[],int n){
    int i = n;
    int temp = arr[n];
    while(i>0 && temp > arr[i%2 == 0 ? (i/2)-1 : i/2]){
        arr[i] = arr[i%2==0 ? (i/2)-1 : i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;
    }
    arr[i] = temp;
}

//stl based
void Insert(vector<int>& vec, int key){
    // Insert key at the end
    auto i = vec.size();
    vec.emplace_back(key);
 
    // Rearrange elements: Indices are not DRY :-(
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2]){
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    vec[i] = key;
}


template <class T>
void print(T& vec, int n){
    cout<<"Max Heap: ["<<flush;
    for (int i = 0; i < n; i++)
    {
        cout<<vec[i]<<flush;
        if(i < n-1){
            cout<<", "<<flush;
        }
    }
    
    cout<<"]"<<endl;
    
}

int main(){
    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    insert(a, 9);
    print(a,sizeof(a)/sizeof(a[0]));
    cout<<endl;

    // STL based
    vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    print(v, v.size());
    v.reserve(15);  // Reserve space for 15 elements
 
    Insert(v, 50);
    print(v, v.size());

}