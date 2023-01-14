#include<bits/stdc++.h>
using namespace std;
class element{
public:
    int i;
    int j;
    int x;
};
class sparse{
private:
    int m;
    int n;
    int num;
    element *e;
public:
    sparse(int m,int n,int num){
        this->m  = m;
        this->n = n;
        this->num = num;
        e = new element[this->num];
    }
    ~sparse(){
        delete []e;
    }

    sparse operator+(sparse &s);
    friend istream & operator>>(istream &is,sparse &s);
    friend ostream & operator<<(ostream &os,sparse &s);
    
};

sparse sparse::operator+(sparse &s){
    int i,j,k;
    if(m!=s.m || n!=s.n) return sparse(0,0,0);
    sparse *sum = new sparse(m,n,num+s.num);
    i = j= k = 0;
    while(i<num && j<s.num){
        if(e[i].j <s.e[j].j) sum->e[k++] = e[i++];
        else if(e[i].j > s.e[j].j) sum->e[k++] = s.e[j++];
        else{
            if(e[i].i <s.e[j].i) sum->e[k++] = e[i++];
            else if(e[i].i > s.e[j].i) sum->e[k++] = s.e[j++];
            else{
                sum->e[k] = e[i];
                sum->e[k++].x = e[i++].x +s.e[j++].x;
            }
        }
    }
    for(;i<num; i++)sum->e[k++] = e[i];
    for(;i<s.num;i++)sum->e[k++]=s.e[j];
    sum->num = k;
    return *sum;
}

istream & operator>>(istream &is,sparse &s){
    cout<<"Enter non zero elements:\n ";
    for (int i = 0; i < s.num; i++)
    {
        cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
    }
    return is;
}
ostream & operator<<(ostream &os,sparse &s){
    int k =0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if(s.e[k].i == i && s.e[k].j==j){
                cout<<s.e[k++].x<<' ';
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}


int main(){
    sparse s1(5,5,5);
    sparse s2(5,5,5);
    cin>>s1;
    cin>>s2;
    sparse sum = s1+s2;
    cout<<"First matrix: \n"<<s1;
    cout<<"\nSecond Matrix: \n"<<s2;
    cout<<"\nsum matrix: \n"<<sum;
    return 0;
}