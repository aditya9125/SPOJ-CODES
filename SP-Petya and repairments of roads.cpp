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
#define newl cout<<"\n"
#define FILL(A,value) memset(A,value,sizeof(A))


#define whole(x) x.begin(),x.end()
#define pb push_back
#define in insert
#define get(tp_name,x) (get<x>(tp_name))   ///to access tuple(i)
#define umap unordered_map
#define mp make_pair


using namespace std;


#define F first
#define S second



///learning corner

///vector< vector<int> > costs(N, vector<int>(M, 0));   //NxM 2d preinitialized(0) vector



typedef pair<int,int> ii;
typedef vector<ii> vii;



inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }

//maths
#define PI acos(-1)

#define INTmax numeric_limits<int>::max()
#define LLmax numeric_limits<ll>::max()
#define ULLmax numeric_limits<ull>::max()

#define INTmin numeric_limits<int>::min()


typedef priority_queue<ii,vector<ii>, greater<ii> > P_Queue;             ///priority queue contianing ii (having vector<ii> as underlying container) with greater as functor
																		///		heapify on the basis of comparisons of  ii.first  values

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

template<class type>
type ncr(type n,type r)
{  	assert(n>=r);
	type ans=1,i;
	if(n==r) return 1; if(r==1) return n; if(r>(n-r)) r=n-r;
	reptill(i,0,r-1) ans=ans*(n-i)/(i+1);
	return ans;
}
template<typename type>  unsigned long long fact(type x){ ull ans=1; for(type i=1;i<=x;i++){ ans*=i;        /*ans%=MOD;   //Optional } return ans; */ } }


inline void FAST_IO(){ios_base::sync_with_stdio(false);}



#define SIZE int(1e5)+2
#define MOD
#define debug
#define MAX1
#define MAX2

//#define Online_judge

//vector<ll> adj[SIZE];

ll parent[SIZE];
typedef pair<ii,ll>  pairType;



class compClass
{
	public:				///pairType doesn't name a type ,its just to show type of pair object passed in operatorfunction

    bool operator()( pairType p1, pairType p2) {
        return p1.S>p2.S;
    }
};


ll Size[SIZE];

bool isMilkmen[SIZE];


ll _findroot(ll x)
{
	while(parent[x]!=x)  ///_findroot along with path compression
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}

void Union(ll head1,ll head2)
{
	//ll head1=_findroot(x);
	//ll head2=_findroot(y);
    if(head1==head2)
	 return ;

	if(Size[head2]>Size[head1])
		swap(head1,head2);

    parent[head2]=head1;

	Size[head1]+=Size[head2];
}




ll mst(priority_queue < pairType,vector<pairType>,compClass > & pq,ll n)
{
	ll mincost=0,c=0,i;//,ctcovered=0;


	while(!pq.empty() and c<n-1)
	{
		ll x=pq.top().F.F,y=pq.top().F.S,root1,root2;

		if((root1=_findroot(x) )!= (root2=_findroot(y)))   ///then doesn't form cycle
		{
			//cout<<"Adding cost for "<<x <<" "<<y<<"  "<<pq.top().S<<"\n";
			//cout<<" ctcov= "<<ctcovered<<", cz= "<<cz<<"\n";
			mincost+=pq.top().S;
			Union(root1,root2);
			c++;
		}
		pq.pop();
	}

	rep(i,1,n)
	{
		if( !isMilkmen[i]   and (_findroot(i)!=_findroot(0)))
			return -1;
	}

	return mincost;//(c==n-1) ? mincost:-1;
}




int main()
{
	FAST_IO();

	ifstream cin("ip");
//	ofstream cout("op");
	int t;
	cin>>t;
	while(t--)
	{

		ll n,j,k,i,edg,m;

		cin>>n>>m;

		reptill(i,0,n)
		 parent[i]=i,Size[i]=1;

		typedef pair<ii,long long>  pairType;

		priority_queue <  pairType ,vector<pairType> , compClass > pq;

		reptill(i,1,n)
		{
			cin>>isMilkmen[i];

			if(isMilkmen[i])
				pq.push(mp(mp(i,0),0));
		}
//		while(!pq.empty()){			cout<<pq.top().first.F<<" "<<pq.top().F.second<<"\n"; pq.pop(); }
		ll a,b,w;
		rep(i,0,m)
		{
			cin>>a>>b>>w;
			pq.push(mp(mp(a,b),w));

		}
//		while(!pq.empty()) {			cout<<pq.top().F.F<<" "<<pq.top().F.S<<" "<<pq.top().S<<"\n";pq.pop();		}
			ll ans=mst(pq,n+1);

			if(ans==-1) cout<<"impossible\n";
			else cout<<ans<<"\n";

	}

}
