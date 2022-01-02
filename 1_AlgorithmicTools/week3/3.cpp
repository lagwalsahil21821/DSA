#include<bits/stdc++.h>
using namespace std;

int minRefill(int n, vector<int> &station , int maxFuel){
    int numRefill = 0;
    int currentPos = 0;
    while(currentPos <= n){
        int lastPos = currentPos;
        while( (currentPos <= n) && ((station[currentPos +1] - station[lastPos]) <= maxFuel)){
            currentPos++;
        }
        if(currentPos == lastPos)
        return -1;
        
        if(currentPos <= n) {
            numRefill++;
        }
        
    }
    return numRefill;
}

int main(){
    int distance, maxFuel;
    cin>>distance;
    cin>>maxFuel;
    int n;
    cin>>n;
    vector<int> station;
    station.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        station.push_back(x);
    }
    station.push_back(distance);


    cout<<minRefill(n,station,maxFuel);
    
    
}