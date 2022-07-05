#include <bits/stdc++.h>
using namespace std;

int main()
{
    int refill = 0;
    int a = 0;
    int maxfuel;
   
    int dest;
    cin >> dest;
    int l;
    cin>>l;
    int currentfuel = l;
    int arr[10];
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    int n;
    cin>>n;
    while(currentfuel <= n)
    if (currentfuel < 0)
    {
        cout << "impossible";
        a++;
    }
    for (int i = 0; i < 6; i++)
    {
        if (currentfuel <= arr[i + 1] - arr[i])
        {
            currentfuel = l;
            refill++;
        }

        else
        {
            currentfuel = currentfuel - arr[i + 1] - arr[i];
        }
    }
    cout<< refill;
}