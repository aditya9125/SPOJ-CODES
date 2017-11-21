#include<bits/stdc++.h>

using namespace std;

int main()
{

	int t;

	cin>>t;

	while(t--){

    int n,k,t,f;

    cin>>n>>k>>t>>f;

    assert(f>=n);


	long long ans= (f-n)/(k-1) + 1LL*f;

	cout<<ans<<'\n';

	}

}
