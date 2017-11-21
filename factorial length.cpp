#include<bits/stdc++.h>

using namespace std;

long long findDigits(long long n)
{
    // factorial of -ve number doesn't exists
    if (n < 0)
        return 0;

    // base case
    if (n <= 1)
        return 1;

    // Use Kamenetsky formula to calculate the
    // number of digits
    double x = ((n*log10(n/M_E)+log10(2*M_PI*n)/2.0));

    return floor(x)+1;
}


int main()
{

	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

	int t;

	cin>>t;


	while(t--)
	{

        long long n;
        cin>>n;

		long long  ans = findDigits(n);

		cout<<ans<<"\n";



	}

}
