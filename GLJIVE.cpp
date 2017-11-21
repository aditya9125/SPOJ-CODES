#include<bits/stdc++.h>



#define whole(x) x.begin(),x.end()
using namespace std;

int main()
{
    int Array[10], sum = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &Array[i]);
        sum += Array[i];
        if (sum >= 100) {
            if (sum - 100 <= 100 - (sum-Array[i])) printf("%d\n", sum);
            else printf("%d\n", sum-Array[i]);
            return 0;
        }
    }
    printf("%d\n", sum);
    return 0;
}

