typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#include<bits/stdc++.h>

//MACROS{
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
#define scan3ll(x,y,z) scanf("%lli %lli %lli",&x,&y,&z);

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
#define nl ("\n")
#define newl cout<<nl
#define FILL(A,value) memset(A,value,sizeof(A))

#define whole(x) x.begin(),x.end()
#define pb push_back
#define in insert
#define mp make_pair
#define get(tp_name,x) (get<x>(tp_name))   ///to access tuple(i)
#define umap unordered_map


#define F first
#define S second
//}END MACROS

using namespace std;


///comparator class for ordering on the basis of 'Second'
/*
class CompareDist
{
	public:				///pairType doesn't name a type ,its just to show type of pair object passed in operatorfunction

    bool operator()( pairType p1, pairType p2) {
        return p1.S>p2.S;
    }
};
*/

typedef pair<int,int> II;
typedef pair<ll,ll> LL;
typedef vector<II> VII;
typedef vector<LL> VLL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<ll> VL;
typedef vector< VI > VVI;
typedef vector< VL > VVL;
typedef vector<string> VS;

//maths
#define PI acos(-1)

#define INTmax numeric_limits<int>::max()
#define LLmax numeric_limits<ll>::max()
#define ULLmax numeric_limits<ull>::max()

#define INTmin numeric_limits<int>::min()

typedef priority_queue<II,vector<II>, greater<II> > P_Queue;             ///priority queue contianing II (having vector<II> as underlying container) with greater as functor
																		///		heapify on the basis of comparisons of  II.first  values

template<typename type>
void get_arr(type a[],type n)
{
	for(type i=0;i<n;i++) cin>>a[i];
}

template<typename type>
void show_arr(type a[],type n=1) {for(type i=0;i<n;i++) cout<<a[i]<<" ";}

template<typename type>
inline type max3(type a,type b,type c){	 return max(max(a,b),c);}

template<typename type>
inline type min3(type a,type b,type c){	 return min(a,min(b,c));}

template<typename type>
inline type min4(type a,type b,type c,type d){	 return min(a,min3(b,c,d));}

template<typename type>
inline type max4(type a,type b,type c,type d){	 return max(a,max3(b,c,d));}


template<typename type>
type modpowIter(type a, type b, type c) { type ans=1;  while(b != 0){ if(b%2 == 1) ans=(ans*a)%c;  a=(a*a)%c; b /= 2; } return ans; }

template<typename type>
type phi(type n){ type result = n;  for (type p=2; p*p<=n; ++p) { if (n % p == 0){ while (n % p == 0)   n /= p; result -= result / p; } } if (n > 1) result -= result / n; return result; }

template<typename type> type gcd(type A,type B){	if(B==0)	return A;	else return gcd(B, A % B);	}

template<class type>
type ncr(type n,type r){  	assert(n>=r); type ans=1,i; 	if(n==r) return 1; if(r==1) return n; if(r>(n-r)) r=n-r; reptill(i,0,r-1) ans=ans*(n-i)/(i+1);	return ans; }

template<typename type>  unsigned long long fact(type x){ ull ans=1; for(type i=1;i<=x;i++){ ans*=i;        /*ans%=MOD;   /Optional*/ } return ans; }

template<typename type>
int Digs(type n){ return (n >= 10) ? 1 + Digs(n/10): 1; }

template<typename type> type tonum(string s){	type ans=0,i;	rep(i,0,s.size())	ans=ans*10+(s[i]-'0'); return ans; }

template<typename T_> inline bool is_perfsq(T_ n){T_ a=(T_)sqrt((double) n); return (a*a==n || (a+1)*(a+1)==n);/* in case of an off-by-one float error*/}

inline void FAST_IO(){ios_base::sync_with_stdio(false);}

#define SIZE (int(1e4)+2)
#define MOD
#define debug
#define MAX1
#define MAX2

bool isprime[SIZE];

void sieve(void)
{
	FILL(isprime,true);

	const int n=10000;

	for(int i=2;i*i<=n;i++)
	{
		if(isprime[i])
			for(int j=i*i;j<=n;j+=i)
				isprime[j]=false;
	}
}

/*
void show_primes(ofstream &cout ,int a,int b)
{
	for(int i=a;i<=b;i++)
	{
		if(isprime[i])
			cout<<i<<" ";
	}
	newl;
}
*/
inline int num(int x,int y,int z,int w)
{
	return (x*1000+y*100+ z*10+w);
}

class Graph
{

  public:
    int n;    // No. of vertices

    VVI adj;

	VB visited;
	VI dist;

	// Constructor and destructor ,n = no of veritces
    Graph(int n)
    {
		this->n = n;

		visited= VB(n+1,false);
		dist= VI(n+1,INTmax);
		adj= VVI(n+1);


    }
	///I don't know how to create a destructor for the objects of this class,if someone reads this code ,kindly tell me.
    // function to add an edge to graph

		void addEdge(int u, int v)
		{
			if(u!=v)
			adj[u].push_back(v),adj[v].push_back(u);  // Note: the graph undirected
		}
	//bool isBipartiteDFS(int node,int par);

	void bfs(int source,int dest);

};


void Graph::bfs(int source,int dest)
{

	dist[source]=0;

	queue<int> q;

	q.push(source);

	while(!q.empty() and q.front()!=dest)
	{
		int par=q.front();

		q.pop();

		visited[par]=true;

		for(int j=0;j<adj[par].size();j++)
		{
			int neb= adj[par][j];
			dist[neb]=min(dist[neb],1+ dist[par]);

			if(!visited[neb])
			 q.push(neb);
		}
	}
}

void build_graph(Graph & G)		///this itb should actuainty be itb+1
{
	///this function would be a part of pre computation

	for(int p=1000;p<=9999;p++)
	{		///Iterating over the primes between the two given primes  for ex. [1033,8179]


		if(!isprime[p])
				continue;


		int d1=p%10,d2=p/10%10,d3=p/100%10,d4=p/1000;	///obtain the digits

			//cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
		//cout<<p<<nl;

		for(int k=1;k<=9;k++)
		{
			int tn= num(k,d3,d2,d1);


			if(isprime[tn])
				G.addEdge(p,tn);

		}

		for(int k=0;k<=9;k++)		///Changing the hundreds digit
		{
			int tn=num(d4,k,d2,d1);


			if(isprime[tn])
				G.addEdge(p,tn);
		}

		for(int k=0;k<=9;k++)		///Changing the hundreds digit
		{
			int tn=num(d4,d3,k,d1);



			if(isprime[tn])
				G.addEdge(p,tn);
		}
		for(int k=0;k<=9;k++)		///Changing the hundreds digit
		{
			int tn=num(d4,d3,d2,k);



			if(isprime[tn])
				G.addEdge(p,tn);
		}
	}
}

int main()
{
	//FAST_IO();
	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

	//ofstream cout("/home/aditya/Documents/op");
	sieve();

	Graph G(10000);

	build_graph(G);

#ifdef debug1

for(ll i=1000;i<=9999;i++)
 if(isprime[i])
   cout<<i<<" ";
	newl;

#endif // debug1

/*
	for(int i=1000;i<=9999;i++)
	{
		if(G.adj[i].size())
		{
			cout<<i<<"-";
			for(int j=0;j<G.adj[i].size();j++)	cout<<G.adj[i][j]<<" ";
			newl;
		}
	}
*/

int t;

cin>>t;

while(t--)
{
	int pa,pb;

	G.dist= VI(10000,INTmax);
	G.visited =VB(10000,false);


	cin>>pa>>pb;

	G.bfs(pa,pb);

	if(G.dist[pb]!=INTmax)	cout<<G.dist[pb]<<nl;
	else cout<<"Impossible\n";

}

}

