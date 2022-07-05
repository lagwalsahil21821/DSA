#include<bits/stdc++.h>
using namespace std;
int DPchange(int money,vector<int> &coin){
    vector<int> minNoCoin(money+1,INT_MAX);
    minNoCoin[0] = 0;
    int NoofCoin;
    for (int i = 1; i <= money; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i >= coin[j] ){
                NoofCoin = minNoCoin[i-coin[j]] + 1;
                if(NoofCoin < minNoCoin[i]) minNoCoin[i] = NoofCoin;
            }
        }
        
    }
    return minNoCoin[money];
    
}
int main(){
    int money;
    cin>>money;
    vector<int> v = {1,3,4};
    cout<<DPchange(money,v)<<"\n";
    
}