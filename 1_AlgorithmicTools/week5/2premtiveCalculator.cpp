#include <bits/stdc++.h>
using namespace std;

int pCal(int n, vector<int> &operation)
{

    operation[0] = 0;
    operation[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0 && i % 3 == 0)
        {
            operation[i] = min(min(operation[i / 2], operation[i / 3]), operation[i - 1]) + 1;
        }
        else if (i % 2 == 0)
        {
            operation[i] = min(operation[i / 2], operation[i - 1]) + 1;
        }
        else if (i % 3 == 0)
        {
            operation[i] = min(operation[i / 3], operation[i - 1]) + 1;
        }
        else
        {
            operation[i] = operation[i - 1] + 1;
        }
    }
    return operation[n];
}

void seq(vector<int> &operation, vector<int> &s,int n)
{
    
    while(n >= 1){
        if(n%2 == 0 && n%3 == 0){
            s.push_back(n);
            if(operation[n/3] <= operation[n/2]){
                if(operation[n/3] < operation[n-1]) n /= 3;
                else n--;
            }else{
                if(operation[n/2] < operation[n-1]) n /= 2;
                else n--;
            }
        }
        else if(n%3 == 0){
            s.push_back(n);
            if(operation[n/3] <= operation[n-1]) n/= 3;
            else n--;

        }else if(n%2 == 0){
            s.push_back(n);
            if(operation[n/2] <= operation[n-1]) n /= 2;
            else n--;
            
        }else{
            s.push_back(n);
            n--;

        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> operation(n + 1, INT_MAX);
    operation.push_back(0);
    cout << pCal(n, operation) << "\n";
    vector<int> sequence;
    int temp = operation[n];

    seq(operation, sequence,n);

    reverse(sequence.begin(),sequence.end());
    for(auto x: sequence) cout<<x<<' ';
    
    
    cout<<"\n";
}