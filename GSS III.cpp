
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



using namespace std;


#define F first
#define S second



///Optional

///vector< vector<int> > costs(N, vector<int>(M, 0));   //NxM 2d preinitialized(0) vector

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

inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }

//maths
#define PI acos(-1)

#define INTmax numeric_limits<int>::max()
#define LLmax numeric_limits<ll>::max()
#define ULLmax numeric_limits<ull>::max()

#define INTmin numeric_limits<int>::min()


typedef priority_queue<II,vector<II>, greater<II> > P_Queue;             ///priority queue contianing II (having vector<II> as underlying container) with greater as functor
																		///		heapify on the basis of comparisons of  II.first  values

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
type modpowIter(type a, type b, type c) { type ans=1;  while(b != 0){ if(b%2 == 1) ans=(ans*a)%c;  a=(a*a)%c; b /= 2; } return ans; }

template<typename type>
type phi(type n){ type result = n;  for (type p=2; p*p<=n; ++p) { if (n % p == 0){ while (n % p == 0)   n /= p; result -= result / p; } }
if (n > 1) result -= result / n; return result;
}
template<typename type>
type gcd(type A,type B){	if(B==0)	return A;	else return gcd(B, A % B);	}

template<class type>
type ncr(type n,type r)
{  	assert(n>=r);
	type ans=1,i;
	if(n==r) return 1; if(r==1) return n; if(r>(n-r)) r=n-r;
	reptill(i,0,r-1) ans=ans*(n-i)/(i+1);
	return ans;
}
template<typename type>  unsigned long long fact(type x){ ull ans=1; for(type i=1;i<=x;i++){ ans*=i;        /*ans%=MOD;   /Optional*/ } return ans; }

template<typename type>
int Digs(type n){ return (n >= 10) ? 1 + Digs(n/10): 1; }

template<typename type>
type tonum(string s)
{	type ans=0,i;	rep(i,0,s.size())	ans=ans*10+(s[i]-'0');
	return ans;
}





inline void FAST_IO(){ios_base::sync_with_stdio(false);}



#define SIZE (int(5e4)+2)
#define MOD
#define debug
#define MAX1
#define MAX2
#define left (2*v)
#define rit (2*v+1)

class Node
{
	public:

	int ts,bs,bps,bss;
	bool isvalid;
/*
	Node(int ts=-1,int bs=-1,int bps=-1,int bss=-1)
	{
		this->ts=ts;
		this->bs=bs;
		this->bps=bps;
		this->bss=bss;
	}
*/
	Node(bool flag=true) { ts =0,bs=0 ,bps=0,bss=0,isvalid=flag;}

	Node(int Ts ,int Bs,int Bps,int Bss){ ts= Ts ,bs= Bs, bps=Bps,bss= Bss;}

};

vector<Node> tree;


int arr[SIZE];

void build(int l,int r,int v)
{
	//cout<<"Called for  "<<l<<" "<<r<<endl;;
	if(l==r)
	{
		tree[v].ts=	tree[v].bs=tree[v].bps=tree[v].bss=arr[l];
		return ;
	}
	int mid=(l+r)>>1;

	build(l,mid,left);
	build(mid+1,r,rit);

	tree[v].ts= tree[left].ts+ tree[rit].ts;

	tree[v].bps= max(tree[left].bps , tree[left].ts + tree[rit].bps);

	tree[v].bss= max(tree[rit].bss , tree[rit].ts + tree[left].bss);

	tree[v].bs= max3(tree[left].bs , tree[rit].bs , tree[left].bss + tree[rit].bps);

}



void update(int l,int r,int idx,int New,int v)
{
	//cout<<"In "<<l<<" , "<<r<<endl;
	if(l==idx and r==idx)
	{
		arr[idx]=New;
		tree[v].ts=	tree[v].bs=tree[v].bps=tree[v].bss=New;
		return ;
	}

	int mid= (l+r)>>1;

	if(idx<=mid) update(l,mid,idx,New,left);
	else update(mid+1,r,idx,New,rit);

	tree[v].bps= max(tree[left].bps , tree[left].ts + tree[rit].bps);

	tree[v].bss= max(tree[rit].bss , tree[rit].ts + tree[left].bss);

	tree[v].bs= max3(tree[left].bs , tree[rit].bs , tree[left].bss + tree[rit].bps);

	tree[v].ts= tree[left].ts+ tree[rit].ts;
}

Node query(int ql,int qr,int l,int r,int v)
{
	//No overlap
	if(ql>r or qr<l)
	 return Node(false);

	if(ql<= l and qr>=r)	///total overlap
	 return tree[v];

	int mid= (l+r)>>1;

	Node leftquery= query(ql,qr,l,mid,left);
	Node ritquery= query(ql,qr,mid+1,r,rit);

	if(leftquery.isvalid and ritquery.isvalid)
	{
		Node AnsNode ;

		AnsNode.bps= max(leftquery.bps, leftquery.ts + ritquery.bps);
		AnsNode.bss = max(ritquery.bss,ritquery.ts + leftquery.bss);
		AnsNode.bs= max3( leftquery.bs, ritquery.bs , leftquery.bss+ ritquery.bps);
		AnsNode.ts= leftquery.ts+ ritquery.ts;
		return AnsNode;
	}

	return leftquery.isvalid ? leftquery: ritquery;

}


int main()
{

	FAST_IO();

	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

//	ofstream cout("/home/aditya/Documents/op");
	tree = vector<Node>(4*SIZE,Node());

	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}

	build(1,n,1);


	//for(int i=1;i<=2*n-1;i++)	cout<<"tree["<<i<<"]= "<<tree[i].bps<<","<<tree[i].bs<<","<<tree[i].bss<<","<<tree[i].ts,newl;
	//bulded successfully	newl;
	int q;
	cin>>q;
	while(q--)
	{
		int qtype,x,y;

		cin>>qtype>>x>>y;

		if(qtype) {

			//Node res = query(x,y,1,n,1);
			//cout<<res.bps <<" "<<res.bs<<" "<<res.bss<<" "<<res.ts<<nl;
			cout<<query(x,y,1,n,1).bs<<"\n";
		}
		else update(1,n,x,y,1);
	}


}

