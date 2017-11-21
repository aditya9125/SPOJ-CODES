
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


int r,c;

VVI mat;
VVI visited,dp;



int solver(int i,int j)
{

	if(i<0 or i>=r or j<0 or j>=c)
	 return -1;


	if(visited[i][j])
		return dp[i][j];


	///These 8 ifs can be cut down to 1 for loop,try no of Islands (GeeksforGeeks)


	if(j-1>=0 and mat[i][j-1]==mat[i][j]+1)	///left
		dp[i][j]=max(dp[i][j],1+solver(i,j-1));

	if(j+1<c and mat[i][j+1]==mat[i][j]+1)	///rit
		dp[i][j]=max(dp[i][j],1+solver(i,j+1));


	if(i-1>=0 and mat[i-1][j]==mat[i][j]+1)	///up
		dp[i][j]=max(dp[i][j],1+solver(i-1,j));


	if(i+1<c and mat[i+1][j]==mat[i][j]+1)	///down
		dp[i][j]=max(dp[i][j],1+solver(i+1,j));


	if(i-1>=0 and j-1>=0 and mat[i-1][j-1]==mat[i][j]+1)	///left up
		dp[i][j]=max(dp[i][j],1+solver(i-1,j-1));

	if(i+1<r and j-1>=0 and mat[i+1][j-1]==mat[i][j]+1)	///left down
		dp[i][j]=max(dp[i][j],1+solver(i+1,j-1));

	if(i-1>=0 and j+1<c and mat[i-1][j+1]==mat[i][j]+1)	///rit up
		dp[i][j]=max(dp[i][j],1+solver(i-1,j+1));

	if(i+1<r and j+1<c and mat[i+1][j+1]==mat[i][j]+1)	///rit down
		dp[i][j]=max(dp[i][j],1+solver(i+1,j+1));


	visited[i][j]=true;

	return dp[i][j];


}

int main()
{
	FAST_IO();

	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

	//ofstream cout("/home/aditya/Documents/op");

int t=0;

while(true)
{


	cin>>r>>c;

	if(!r and !c)
	 break;

	t++;

	VII apos;

	visited= VVI(r+1,VI(c+1));
	dp= VVI(r+1,VI(c+1));

	mat= VVI(r+1,VI(c+1));

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			char c;
			cin>>c;


			if(c=='A')
				apos.pb({i,j});

			mat[i][j]=c-'A';

			visited[i][j]=0;
			dp[i][j]=0;
		}
	}

	int ans=-1;

	for(int i=0;i<apos.size();i++)
	{

		ans=max(ans, solver(apos[i].F,apos[i].S) );
	}


	cout<<"Case "<<t<<": "<<ans+1<<'\n';

}


}

