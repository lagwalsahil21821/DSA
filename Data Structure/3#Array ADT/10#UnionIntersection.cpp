#include<bits/stdc++.h>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr){
    cout<<"\nElements are: ";
    for (int i = 0; i < arr.length; i++)
    {
        cout<<arr.A[i]<<' ';
    }
    
}
struct Array* Merge(struct Array *arr1,struct Array  *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    while(i < arr1->length && j <arr2->length){
        if(arr1->A[i] <arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        else arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->length; i++){
        arr3->A[k++] = arr1->A[i];
    }
    for(; j<arr2->length; j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length+arr2->length;
    arr3->size = 10;
    return arr3;
}

struct Array* Union(struct Array *arr1,struct Array  *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    while(i < arr1->length && j <arr2->length){
        if(arr1->A[i] < arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i]) arr3->A[k++] = arr2->A[j++];
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length; i++){
        arr3->A[k++] = arr1->A[i];
    }
    for(; j<arr2->length; j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
struct Array* Intersection(struct Array *arr1,struct Array  *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    while(i < arr1->length && j <arr2->length){
        if(arr1->A[i] < arr2->A[j]) i++;
        else if(arr2->A[j] < arr1->A[i]) j++;
        else{   // If(arr1->A[i] == arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Diff(struct Array *arr1,struct Array  *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    while(i < arr1->length && j <arr2->length){
        if(arr1->A[i] < arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i]) j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1->length; i++){
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
int main(){
    struct Array arr1 = {{2,9,21,28,35},10,5};
    struct Array arr2 = {{2,9,16,18,28},10,5};
    struct Array *arr3,*arr4,*arr5;
    arr3 = Union(&arr1,&arr2);
    arr4 = Intersection(&arr1,&arr2);
    arr5 = Diff(&arr1,&arr2);
    cout<<"union: ";
    Display(*arr3);
    cout<<"\nIntersection: ";
    Display(*arr4);
    cout<<"\nDiffercene: ";
    Display(*arr5);
    return 0;
}