
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

inline void FAST_IO(){ios_base::sync_with_stdio(false);}

#define SIZE (int(1e4)+2)
#define MOD
#define debug1
#define MAX1
#define MAX2

int main()
{
	//FAST_IO();

	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif

	//ofstream cout("/home/aditya/Documents/op");


	while(true)	{



		int na,nb,i,j;

		cin>>na;

		if(!na ) break;

		VI A,sumA(SIZE);

		int val;

		A.pb(-10001);

		reptill(i,1,na)
		{
			cin>>val;
			A.pb(val);
			sumA[i]+=sumA[i-1]+val;
		}
		sumA[i]=sumA[i-1];

		cin>>nb;


		VI B,sumB(SIZE);

		B.pb(-10001);

		reptill(i,1,nb)
		{
			cin>>val;
			B.pb(val);
			sumB[i]+=sumB[i-1]+val;
		}
		sumB[i]=sumB[i-1];



		A.pb(10001);
		B.pb(10001);

	#ifdef debug

		for(int i=0;i<A.size();i++)
		 cout<<sumA[i]<<" ";



		newl;

		for(int i=0;i<B.size();i++)
		 cout<<sumB[i]<<" ";

		newl;

	#endif // debug2


	///Start of matching

	VL auxA,auxB;
	int la=0,ra,lb=0,rb;



	for(int i=0;i<B.size();i++)
	{

		auto itA=lower_bound(whole(A),B[i]);

		if(itA!=A.end() and *itA==B[i])
		{

			ra= itA- A.begin();
			rb=i;

			auxA.pb(sumA[ra-1]-sumA[la]);	auxA.pb(B[i]);
			auxB.pb(sumB[rb-1]-sumB[lb]);	auxB.pb(B[i]);

			la=ra;
			lb=rb;
		}
	}


	#ifdef debug2

	for(auto item:auxA)
	cout<<item<<" ";
	newl;
	for(auto item:auxB)
	cout<<item<<" ";
	newl;


	#endif // debug1

	assert(auxA.size()==auxB.size());

	ll ans=0;

	for(int i=0;i<auxA.size();i++)
	{
		ans = ans + ( (auxA[i]!=-10001 and auxA[i]!=10001) ? max(auxA[i],auxB[i]):0);
	}
	cout<<ans<<"\n";


	}

}

