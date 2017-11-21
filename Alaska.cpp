#include<bits/stdc++.h>
using namespace std;
int main()
{
	//ifstream cin("/home/aditya/Documents/ip");

	while(true)
	{

		int x,y;

		cin>>x;

		if(x==0)
		{
			//cout<<"IMPOSSIBLE\n";

			return 0;
		}

		vector<int> v;

		v.push_back(-200);

		for(int i=1;i<=x;i++)
		{
			cin>>y;
			v.push_back(y);
		}

		sort(v.begin(),v.end());

		bool ans=true;

		for(int i=1;i<=x;i++)
		{
			ans = ans& (v[i]-v[i-1] <=200);
		}

		ans = ans& ( 2*( 1422- v[x])<=200 );

		if(ans) cout<<"POSSIBLE\n";
		else cout<<"IMPOSSIBLE\n";


	}
}
