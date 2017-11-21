typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#include<bits/stdc++.h>
#include<cmath>
#include<cstdlib> //for qsort
#include<cstdio>

#define rep(x,a,b) for(x=a;x<b;x++)
#define reptill(x,a,b) for(x=a;x<=b;x++)

#define scani(x) scanf("%d",&x)
#define scan2i(x,y) scanf("%d %d",&x,&y)
#define scan3i(x,y,z) scanf("%d %d %d",&x,&y,&z)

#define scanfl(x) scanf("%f",&x)
#define scanc(x) scanf("%c",&x)
#define scand(x) scanf("%lf",&x)

#define scanll(x) scanf("%lli",&x)
#define scan2ll(x,y) scanf("%lli %lli",&x,&y)
#define scan3ll(x,y) scanf("%lli %lli %lli",&x,&y,&z);

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
#define newl cout<<"\n"
#define F first
#define S second
#define FILL(A,value) memset(A,value,sizeof(A))

inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }

//maths
#define PI acos(-1)

#define INTmax numeric_limits<int>::max()
#define LLmax numeric_limits<ll>::max()
#define ULLmax numeric_limits<ull>::max()

#define INTmin numeric_limits<int>::min()


using namespace std;

template<typename type>
void get_arr(type a[],type n) {for(type i=0;i<n;i++) cin>>a[i];}

template<typename type>
void show_arr(type a[],type n=1) {for(type i=0;i<n;i++) cout<<a[i]<<" ";}

template<typename type>
inline type max3(type a,type b,type c){	 return max(max(a,b),c);}

template<typename type>
inline type min3(type a,type b,type c){	 return min(a,min(b,c));}

template<typename type>
inline type min4(type a,type b,type c,type d){	 return min(a,min3(b,c,d));}


template<typename type>
type fastpow(type a, type b, type c) { type ans=1;  while(b != 0){ if(b%2 == 1) ans=(ans*a)%c;  a=(a*a)%c; b /= 2; } return ans; }

template<typename type>
type phi(type n){ type result = n;  for (type p=2; p*p<=n; ++p) { if (n % p == 0){ while (n % p == 0)   n /= p; result -= result / p; } }
if (n > 1) result -= result / n; return result;
}



inline void FAST_IO(){ios_base::sync_with_stdio(false);}

#define SIZE int(1e3)+1
#define MOD
#define debug
//#define Online_judge



int arr[183*183];long dist[183*183];

vector<int> Graph[183*183];

bool visited[183*183];


int main()
{
		FAST_IO();

		ifstream cin("ip");

int t;
cin>>t;
while(t--)
{

	    int i,j,n,m;



		cin>>n>>m;



		int k,pred;char ch;

		reptill(i,1,m*n){

		  cin>>ch;
		  arr[i]=(ch-'0')?1:0;
		  Graph[i].clear();
		}

#ifdef debug1
		reptill(i,1,m*n){
			cout<<arr[i]<<" ";
			if(i%m==0) newl;
		}
#endif
		for(int i=1;i<=m*n;i+=m)
		{

			for(int j=i+1;j<i+m;j++)
			{

				Graph[j].pb(j-1);
				Graph[j-1].pb(j);
			}
		}


		for(int i=1;i<=m;i++)
		{
			for(int j=i+m;j<=i+4*(n-1);j+=m)
			{

				Graph[j].pb(j-m);
				Graph[j-m].pb(j);

			}

		}

#ifdef debug2
		int v;
		reptill(v,1,m*n)
		{
			cout<<v<<"-";
			rep(j,0,Graph[v].size())
			{
				cout<<Graph[v][j]<<" ";
			}
		   newl;
		}
newl;newl;
#endif // debug2


	reptill(i,1,m*n)
	{


		if((i!=1) and ((i-1)%m==0))
		  newl;

		long ans=LONG_MAX;

		if(arr[i]){
		  cout<<"0 ";
		  continue;
		}

		reptill(k,1,m*n)
		visited[k]=false,dist[k]=LONG_MAX;

		queue<int> q;

		q.push(i);
		dist[i]=0;


		while(!q.empty())
		{

			int u=q.front();
			q.pop();
			visited[u]=true;
			for(int j=0;j<Graph[u].size();j++)
			{
				int v=Graph[u][j];
				if(!visited[v])
				{
					visited[v]=true;
					dist[v]=dist[u]+1;
					if(arr[v])
						ans=min(ans,dist[v]);

					q.push(v);
				}
			}

		}
			cout<<ans<<" ";

	}
	newl;
}


}
