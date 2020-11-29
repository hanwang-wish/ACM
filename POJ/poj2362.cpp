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
const int maxn=25;
int a[maxn],vis[maxn];
int n,cnt;
bool dfs(int pos,int len,int step)
{
	if(step==3) return true;
	for(int i=pos;i>=0;i--) //逆序更快
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(len+a[i]<cnt){
				if(dfs(i-1,len+a[i],step)) return true;
			}else if(len+a[i]==cnt)
			{
				if(dfs(n-1,0,step+1)) return true;
			}
			vis[i]=0;
		}
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		memset(vis,0,sizeof(vis));
		sort(a,a+n);
		if(sum%4||a[n-1]>sum/4)
		{
			cout<<"no"<<endl;
			continue;
		}
		cnt=sum/4;
		if(dfs(n-1,0,0))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
    
    return 0;
}
