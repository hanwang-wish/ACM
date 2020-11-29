#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int maxn=100010;
long long a[maxn];
int n;
int main()
{
    while(cin>>n)
	{
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		for(int i=0;i<n-1;i++)
			printf("%lld ",a[i]);
		printf("%lld\n",a[n-1]);
	}
    return 0;
}
