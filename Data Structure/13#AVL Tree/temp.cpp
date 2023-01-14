#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] == 0) {
            swap(v[i],v[n-1-count]);
            count++;
        }
    }
    //sort(v.begin(),v.end()-count);
    for(auto x:v) cout<<x<<' ';
    
}