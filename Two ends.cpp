#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > dp;
vector<int> v;


int n;

void solve(void)
{

    for(int len=4;len<=n;len+=2)
    {

		for(int i=0;i+len<=n;i++)
		{
			int j=i+len-1;

            int ans1,ans2;
			assert(i+2<n and j-2>=0);
            if(v[i+1]>=v[j]) ans1=v[i]+dp[i+2][j];
            else ans1=v[i]+dp[i+1][j-1];

            if(v[i]>=v[j-1]) ans2=v[j]+dp[i+1][j-1];
            else ans2=v[j]+dp[i][j-2];

            dp[i][j]=max(ans1,ans2);
		}
	}

}

int main()
{

	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

	int m=1;
	while(true)
	{

		cin>>n;

		if(n==0) break;



		assert(!(n&1));

		v= vector<int>(n);

		dp= vector<vector<int> >(n,vector<int>(n,0));

		int sum=0;
		for(int i=0;i<n;i++)
		{

			cin>>v[i];
			sum+=v[i];
		}

		for(int i=0;i+2<=n;i++) dp[i][i+1]= max(v[i],v[i+1]);


		solve();

		int A=dp[0][n-1];
		int B= sum-A;

		//cout<<"for n= "<<n<<" ans is:\n";
		cout<<"In game "<<m<<", the greedy strategy might lose by as many as "<<A-B<<" points.\n";
		m++;
	}
	//cout<<"Program ran for all cases\n";
}
