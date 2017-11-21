///Status : AC
///Remark :
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#include<bits/stdc++.h>

//MACROS{

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
#define prints(x) printf("%s\n",x)

#define nl ("\n")
#define newl cout<<nl
#define FILL(A,value) memset(A,value,sizeof(A))
#define FILL_MAT(x,rrrr,cccc,value) for(int iiii=0;iiii<rrrr;iiii++){for(int jjjj=0;jjjj<cccc;jjjj++) x[iiii][jjjj]=value;}

#define whole(x) x.begin(),x.end()
#define pb push_back
#define in insert
#define mp make_pair

#define umap unordered_map


#define F first
#define S second
//}END MACROS

using namespace std;

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

#define LL_MAX numeric_limits<ll>::max()
#define LL_MIN numeric_limits<ll>::min()
															///		heapify on the basis of comparisons of  II.first  values
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

template<typename type>
type ncr(type n,type r){  	assert(n>=r); type ans=1; 	if(n==r) return 1; if(r==1) return n; if(r>(n-r)) r=n-r; for(int i=0;i<=r-1;i++) ans=ans*(n-i)/(i+1);	return ans; }

template<typename type>  unsigned long long fact(type x){ ull ans=1; for(type i=1;i<=x;i++){ ans*=i;        /*ans%=MOD;   /Optional*/ } return ans; }

template<typename type>
int Digs(type n){ return (n >= 10) ? 1 + Digs(n/10): 1; }

string toString(int n){    string str; stringstream ss; ss << n; ss >> str; return str; }

template<typename type>
type toNum(string s){	type ans=0;	for(int i=0;i<s.size();i++)	ans=ans*10+(s[i]-'0'); return ans; }

template<typename T_> inline bool is_perfsq(T_ n){T_ a=(T_)sqrt((double) n); return (a*a==n || (a+1)*(a+1)==n);/* in case of an off-by-one float error*/}

inline void FAST_IO(){ios_base::sync_with_stdio(false);}


#define printMat(x,r,c) for(int i=0;i<r;i++){ for(int j=0;j<c;j++) cout<<x[i][j]<<" "; newl; }

#define SIZE (int(2e3)+1)
#define MOD 1000000007
#define debug
#define MAX1
#define MAX2

int dx[] = {1, 0,-1,  0,-1,-1,1,1};
int dy[] = {0, 1, 0, -1,-1, 1,-1,1};

///frequently used
class comp
{
	public :
		bool operator()()
		{}
};

VI dp;
VI sum;

int main()
{

	FAST_IO();

	#ifndef ONLINE_JUDGE
		ifstream cin("/home/aditya/Documents/ip");
	#endif
	//ofstream cout("/home/aditya/Documents/op");




	int t;
	cin>>t;

	while(t--)
	{
		string s;

		cin>>s;


		int len=s.size();

		dp= VI(len);
		sum=VI(len);

		VI rp(26,-1);

		dp[0]=1;

        sum[0]=1;

        rp[s[0]-'A']=0;

		for(int i=1;i<s.size();i++)
		{
//			assert(s[i]-'A'>=0 and s[i]-'A'<=25);

//			assert(	rp[s[i]-'A']>=0 and rp[s[i]-'A' ]<i);

			int rec_pos= rp[ s[i]-'A'];

            dp[i]=sum[i-1];


            //if(sum[i-1]- sum[rec_pos-1]<0) {	cout<<i<<" :"<<sum[i-1]<<" :: "<<sum[rec_pos-1]<<"\n"; break;}

            if(rec_pos!=-1 )
            {
                if(rec_pos>0){

						dp[i]=dp[i]- sum[rec_pos-1];

						if(dp[i]<0) dp[i] = (dp[i]  + MOD );

					}

            }
            else dp[i]= (dp[i]+1)%MOD;


            sum[i]=(sum[i-1]%MOD+dp[i]%MOD)%MOD;

			rp[s[i]-'A']=i;
		}


//		for(int i=0;i<s.size();i++)			cout<<i<<" "<<dp[i]<<" "<<'-'<<sum[i]<<'\n';

		cout<<(1+sum.back())%MOD<<'\n';

	}

}

