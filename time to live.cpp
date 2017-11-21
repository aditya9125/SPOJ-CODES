typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#include<bits/stdc++.h>
#include<cmath>
#include<cstdlib> //for qsort
#include<cstdio>
#define rep(x,a,b) for(x=a;x<b;x++)
#define scani(x) scanf("%d",&x)
#define scanfl(x) scanf("%f",&x)
#define scanc(x) scanf("%c",&x)
#define scand(x) scanf("%lf",&x)
#define scanll(x) scanf("%lli",&x)
#define scanl(x) scanf("%ld",&x)
#define scans(x) scanf("%s",x)
#define printi(x) printf("%d\n",x)
#define printl(x) printf("%ld\n",x)
#define printll(x) printf("%lli\n",x)
#define printd(x) printf("%lf\n",x)
#define printfl(x) printf("%f\n",x)
#define printc(x) printf("%c\n",x)
#define prints(x) printf("%s\n",x);
#define sloop(x) loop(i,0,strlen(x)-1)
#define whole(x) x.begin(),x.end()
#define pb push_back
#define newline cout<<"\n"
#define F first
#define S second
inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }
#define SIZE
#define MOD
#define debug
using namespace std;
template<typename type=int> void get_arr(type a[],type n) {for(type i=0;i<n;i++) cin>>a[i];}
template<typename type=int> void show_arr(type a[],type n=1) {for(type i=0;i<n;i++) cout<<a[i]<<" ";}
template<typename type=int> inline type max3(type a,type b,type c){	 return max(max(a,b),c);}

inline void FAST_IO(){ios_base::sync_with_stdio(false);}

vector<vector< int> > adj;

int maxnode,maxpath;

void dfs(int v,int p,int path)
{
	if(path>maxpath){
				maxnode=v;
				maxpath=path;

			}

	assert(v>=0);
	for(int i=0;i<adj[v].size();i++)
	{
		if(adj[v][i]!=p)
		{
			dfs(adj[v][i],v,1+path);
		}
	}

}
int main()
{
		  FAST_IO();
		//freopen("ip.txt","r",stdin);
      //  freopen("op.txt","w",stdout); //uncomment if u want output on op.txt


		//ifstream cin("/home/aditya/Documents/ip");

		int t;

		cin>>t;

		while(t--)
		{



			maxpath=0; maxnode=0;
			int n,u,v;
			cin>>n;


			adj=  vector<vector<int> > (n);

			for(int i=0;i<n-1;i++)
			{
				cin>>u>>v;
				adj[u].pb(v);
				adj[v].pb(u);
			}


			dfs(v,-1,0);

//			cout<<v<<" "<<maxnode<<"\n";
			//maxpath=-1;


			dfs(maxnode,-1,0);

//			cout<<"Final :"<<maxnode<<" "<<maxpath<<"\n";


			ll ans;

			if(maxpath&1){
				ans = (maxpath+1)/2;
			}
			else ans= maxpath/2;

			cout<<ans<<"\n";

		}

//		cout<<maxpath<<"\n";
		//cout<<"maxpath = "<<maxpath<<" maxnode="<<maxnode;

}

