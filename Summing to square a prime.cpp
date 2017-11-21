
///Status : AC
///Remark :
typedef long long ll;
#include<bits/stdc++.h>

#define nl ("\n")
#define newl cout<<nl
#define FILL(A,value) memset(A,value,sizeof(A))
#define FILL_MAT(x,rrrr,cccc,value) for(int iiii=0;iiii<rrrr;iiii++){for(int jjjj=0;jjjj<cccc;jjjj++) x[iiii][jjjj]=value;}


#define whole(x) x.begin(),x.end()
#define pb push_back
#define F first
#define S second
//}END MACROS

using namespace std;
inline void FAST_IO(){ios_base::sync_with_stdio(false);}

vector<vector<vector<ll> > > cache;

int flag =0;

ll ways(int n,int f,int k)
{

	if(n==0) return 1;

	if(f>n) return 0;

	if(cache[n][f][k]!=-1){
		//flag=1;
		return cache[n][f][k];
	}

	ll ans = 0;

	for(int s= f; s<= min(n,k);s++)
	{

		ans = ans + ways(n-s,s,k);
	}

	return cache[n][f][k]=ans;

}


const int N= 8000;

int isprime[8000];

void gp(void)
{
	for(int i=0;i<8000;i++) isprime[i]=1;

	for(int i=2;i*i<N;i++)
	{
	    if(isprime[i]){
			for(int j=2*i;j<N;j+=i) isprime[j]=0;
		}
	}
}

vector<int> values;

void func(void)
{
	for(int i=1;i<=90;i++)
	{

		for(int j=i;j<=90;j++){

			ll aux = i*i + j*j;

			if(aux>7994) break;

			if(isprime[aux]) values.pb(aux);
		}
	}
}


int main()
{

	FAST_IO();




	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif
	//ofstream cout("/home/aditya/Documents/op");



		gp();

		func();

		sort(whole(values));




		//for(auto item:values) cout<<item<<" "; newl;

		cache = vector< vector< vector<ll> > >(7996, vector< vector<ll> >(4, vector<ll>(4,-1)) );



		int t;	cin>>t;while(t--){


			int n,k;
			cin>>n>>k;



			int x = values[n-1];

			//cout<<x<<" "<<k<<nl;
			ll ans = ways(x,1,k);
			cout<<ans<<nl;


		}



}




