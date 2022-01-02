// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the nth Fibonacci number
long long fib(long long n)
{
	double phi = (1 + sqrt(5)) / 2;
	return round(pow(phi, n) / sqrt(5));
}

// Function to return the required sum
long long calculateSum(long long l, long long r)
{

	// Using our deduced result
	long long sum = fib(r + 2) - fib(l + 1);
	return sum;
}

// Driver code
int main()
{
	long long l,r;
	cin>>l>>r;
	cout << calculateSum(l, r);

	return 0;
}
