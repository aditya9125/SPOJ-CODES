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
#define newline cout<<"\n"
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

template<typename type=int>
void get_arr(type a[],type n) {for(type i=0;i<n;i++) cin>>a[i];}

template<typename type=int>
void show_arr(type a[],type n=1) {for(type i=0;i<n;i++) cout<<a[i]<<" ";}

template<typename type=int>
inline type max3(type a,type b,type c){	 return max(max(a,b),c);}

inline void FAST_IO(){ios_base::sync_with_stdio(false);}

#define SIZE int(1e3)+1
#define MOD
#define debug
//#define Online_judge
int ara[SIZE],ard[SIZE];


int main()
{
	ifstream cin("ip");

	while(true)
	{
	  int a,d,i,j;
	  cin>>a>>d;

	  if(!a or !d)
	   break;

	   rep(i,0,a)
	   cin>>ara[i];

	   rep(i,0,d)
	   cin>>ard[i];

	   bool ans=false;


        sort(ard,ard+d);
       // cout<<"After sorting \n";

	   //rep(i,0,d)
         //   cout<<ard[i]<<" ";
        //newline;

	   rep(i,0,a)
	   {

            if(ara[i]<ard[1]){
              ans=true;
             // cout<<"Yes got for "<<ara[i]<<" "<<ard[2]<<endl;
              break;
              }

	   }
	   if(ans)
	     cout<<"Y\n";
	     else cout<<"N\n";
	}

}






















