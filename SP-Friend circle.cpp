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
#define get(tp_name,x) (get<x>(tp_name))   ///to access tuple(i)


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

inline void FAST_IO(){ios_base::sync_with_stdio(false);}



#define SIZE int(2e5)+2
#define MOD (ll(1e9)+7)
#define debug
#define MAX1
#define MAX2

//#define Online_judge

int Size[SIZE];


int parent[SIZE];

int _findroot(int x)     ///Find the set (representative of set) x belongs to
{
	while(parent[x]!=x)  ///_findroot along with path compression
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}

int Union(int x,int y)  ///Union without rank
{

	int head1=_findroot(x);
	int head2=_findroot(y);

	if(head1==head2)
	 return Size[head1];

	if(Size[head1]>Size[head2]){
		parent[head2]=head1,Size[head1]+=Size[head2];
		return Size[head1];
	}
	else{
	 parent[head1]=head2,Size[head2]+=Size[head1];
	 return Size[head2];
	}
}

bool isInSameSet(int x,int y)
{
	return (_findroot(x)==_findroot(y));
}

int main()
{
	FAST_IO();

//	ifstream cin("ip");
//	ofstream cout("op");

	int t, n,q,i;

	cin>>t;

	while(t--)
	{



		int n;
		cin>>n;

		reptill(i,0,2*n)
		 Size[i]=1,parent[i]=i;

		map<string,int> enums;


		rep(i,0,n)
		{
			string a,b;
			cin>>a>>b;

			int x=2*i,y=2*i+1;

			auto ita=enums.find(a);

			if(ita!=enums.end()) {

				x=ita->S;

			}
			else enums.insert({a,x});

			auto itb=enums.find(b);

			if(itb!=enums.end()){

				y=itb->S;
			}
			else enums.insert({b,y});

			cout<<Union(x,y)<<"\n";

		}


	}


}



