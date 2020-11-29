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
const int maxn=22;
int a[maxn],vis[maxn];
int prime[]={3,5,7,11,13,17,19,23,29,31,37};  //40以内的素数打表
int n;
bool judge(int k)
{
	int flag=0;
	for(int i=0;i<11;i++)
	{
		if(k==prime[i])
		{
			flag=1; break;
		}
	}
	if(flag)  return true;
	else  return false;
}
void dfs(int step)
{
	if(step==n&&judge(a[step-1]+a[0]))
	{
		for(int i=0;i<step-1;i++)
			cout<<a[i]<<" ";
		cout<<a[step-1]<<endl;
	}
	else{
		for(int i=2;i<=n;i++)
		{
			if(!vis[i]&&judge(i+a[step-1]))
			{
				vis[i]=1;
				a[step]=i;
				dfs(step+1);
				vis[i]=0;   //回溯
			}
		}
	}
}
int main()
{
    int cas=0;
	while(cin>>n)
	{
		memset(vis,0,sizeof(vis));
		printf("Case %d:\n",++cas);
		a[0]=1;
		vis[1]=1;
		dfs(1);
		cout<<endl;
	}
    return 0;
}
