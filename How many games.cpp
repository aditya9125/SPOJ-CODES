#include<bits/stdc++.h>

using namespace std;


int main()
{
			ifstream cin("/home/aditya/Documents/ip");

    int t;
    cin>>t;

    while(t--)
    {
        string inp;


		cin>>inp;

		bool flag=false;

		long long x=0,dd=0;

		for(int i=0;i<inp.size();i++)
		{
            if(inp[i]!='.')
				x= x*10 + (inp[i]-'0');
			else flag=true;


			dd = dd+ flag;
		}

		if(!flag) dd=1;

        long long a=x,b=pow(10,dd-1);


		//cout<<a<<" "<<b<<"\n";



        long long ans = b/__gcd(a,b);

        cout<< ans<<"\n";
    }
}
