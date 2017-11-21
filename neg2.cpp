#include<bits/stdc++.h>

using namespace std;

string toString(int n){    string str; stringstream ss; ss << n; ss >> str; return str; }

string toNegativeBase(int n, int negBase)
{
    //  If n is zero then in any base it will be 0 only
    if (n == 0)
        return "0";

    string converted = "";
    while (n != 0)
    {
        // Get remainder by negative base, it can be
        // negative also
        int remainder = n % negBase;
        n /= negBase;

        // if remainder is negative, add abs(base) to
        // it and add 1 to n
        if (remainder < 0)
        {
            remainder += (-negBase);
            n += 1;
        }

        // convert remainder to string add into the result
        converted = converted +toString(remainder);
    }

    reverse(converted.begin(),converted.end());

    return converted;
}

int main()
{
    int n;

    cin>>n;


    string ans= toNegativeBase(n,-2);

    cout<<ans;
}


