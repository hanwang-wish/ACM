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
const int maxn=10100;
int y[maxn],c[maxn];
int n,s;
int main()
{
    while(cin>>n>>s)
	{
		for(int i=0;i<n;i++)
			scanf("%d%d",&y[i],&c[i]);
		for(int i=1;i<n;i++)
			y[i]=min(y[i-1]+s,y[i]);
		long long sum=0;
		for(int i=0;i<n;i++)
			sum+=y[i]*c[i];
		cout<<sum<<endl;
	}
    return 0;
}
