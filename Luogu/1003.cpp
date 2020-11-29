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
const int maxn=10010;
typedef struct pos
{
	int a,b,g,k;
}pos;
pos p[maxn];
int n;
int x,y;
int main()
{
    while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d%d",&p[i].a,&p[i].b,&p[i].g,&p[i].k);
		cin>>x>>y;
		int flag=0;
		int pos=-1;
		for(int i=1;i<=n;i++)
		{
			if((x>=p[i].a&&x<=(p[i].a+p[i].g))&&(y>=p[i].b&&y<=(p[i].k+p[i].b)))
			{
				flag=1;
				pos=i;
			}
		}
		if(flag)  cout<<pos<<endl;
		else  cout<<"-1"<<endl;
	}
    return 0;
}
