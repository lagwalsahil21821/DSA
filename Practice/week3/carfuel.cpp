#include <bits/stdc++.h>
using namespace std;
int minRefill(int arr[], int n, int d)
{
    int numRefill = 0;
    int currentRef = 0;
    while (currentRef <= n)
    {
        int lastRefill = currentRef;
        while ((currentRef <= n) && (arr[currentRef + 1] - arr[currentRef] <= d))
        {
            currentRef++;
        }
        if (currentRef = lastRefill)
        {
            cout << "IMPOSSIBLE";
        }else
        if (currentRef <= n)
        {
            numRefill++;
        }
    }
    return numRefill;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int d;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> d; // fuel tank capacity
    cout << minRefill(arr, n, d);
}