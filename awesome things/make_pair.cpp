#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
 
int main()
{ 
    vector<pair<ll,ll>> v;
    f(0,3){
        ll a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<v.at(i).first<<" "<<v.at(i).second<<"\n";
    }
    // { {1,2}, {3,4}, {5,6}}
    //     1       2       3
}

    