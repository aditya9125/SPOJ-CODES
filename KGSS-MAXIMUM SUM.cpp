
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
#define LLmin numeric_limits<ll>::min()
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

template<typename type>
type tonum(string s){	type ans=0,i;	rep(i,0,s.size())	ans=ans*10+(s[i]-'0'); return ans; }

template<typename T_> inline bool is_perfsq(T_ n){T_ a=(T_)sqrt((double) n); return (a*a==n || (a+1)*(a+1)==n);/* in case of an off-by-one float error*/}

inline void FAST_IO(){ios_base::sync_with_stdio(false);}


#define printMat(x,r,c) for(int i=0;i<r;i++){ for(int j=0;j<c;j++) cout<<x[i][j]<<" "; newl; }

#define SIZE (int(2e3)+1)
#define MOD
#define debug
#define MAX1
#define MAX2

VI arr;

class node
{

	public:
		int a,b;

		node() { a=-1 ,b=-1;};
};

vector<node> tree;


void build(int l,int r,int v)
{

	if(l==r)
	{

		tree[v].a=arr[l];
		tree[v].b=-1;
		return ;

		}

	int mid=(l+r)>>1;

	build(l,mid,2*v);
	build(mid+1,r,2*v+1);

	VI aux{tree[2*v].a,tree[2*v+1].a,tree[2*v].b,tree[2*v+1].b};

	sort(whole(aux));


	tree[v].a=aux[3];
	tree[v].b= aux[2];
}


void update(int l,int r,int v,int indx,int y)
{

	if(indx == l and indx==r )
	{
		tree[v].a= y,tree[v].b= -1;
		return ;

	}
	//no overlap
	if(indx>r or indx<l)
	 return;

	int mid= (l+r)>>1;

	update(l,mid,2*v,indx,y);
	update(mid+1,r,2*v+1,indx,y);


	VI aux{tree[2*v].a,tree[2*v+1].a,tree[2*v].b,tree[2*v+1].b};

	sort(whole(aux));

	assert(aux[2]!=-1 and aux[3]!=-1);

	tree[v].a=aux[3];
	tree[v].b=aux[2];

}



II query(int l,int r,int ql,int qr,int v)
{
	//no overlap
	if(r<ql or l>qr)
		return {-1,-1};

	//total overlap
	if(l>=ql and r<=qr)
		return II(tree[v].a, tree[v].b);

	int mid=(l+r)>>1;

	II left = query(l,mid,ql,qr,2*v);

	II rit  = query(mid+1,r,ql,qr,2*v+1);

    if(left.F==-1 and left.S==-1)
		return rit;
	else if(rit.F==-1 and rit.S==-1)
		return left;

		VI aux{left.F,left.S,rit.F,rit.S};

	sort(whole(aux));

	return {aux[2],aux[3]};

}

int main()
{

	FAST_IO();

#ifndef ONLINE_JUDGE
ifstream cin("/home/aditya/Documents/ip");
#endif

//ofstream cout("/home/aditya/Documents/op");

	int n;
	cin>>n;

	arr=VI(n+1);

	tree= vector<node>(4*n);

	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}

	//cout<<"Hello\n";

	build(1,n,1);

//	for(int i=1;i<=4*n;i++) cout<<i<<" "<<tree[i].a<<" "<<tree[i].b<<nl;

	int q;
	cin>>q;
	while(q--)
	{

		char c;int x,y;

		cin>>c>>x>>y;
		if(c=='U')
		{
			//arr[x]=y;
			//build(1,n,1);
			arr[x]=y;
			update(1,n,1,x,y);
		}
		else
		{

			II ans=query(1,n,x,y,1);

			if(x==y)
			 cout<<2*arr[x]<<nl;
			else cout<<ans.first+ans.second<<nl;
		}

	}








}

