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
const int maxn=26;
int vis[maxn];
string s;
bool judge(int x)
{
	bool flag=true;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			flag=false;
			break;
		}
	}
	return flag;
}
int main()
{
    while(cin>>s)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<s.length();i++)
		{
				vis[s[i]-97]++;
		}
//		int n=s.length();
		sort(vis,vis+26);
		int k=-1;
		for(int i=0;i<26;i++)
		{
			if(vis[i])
			{
				k=i; break;
			}
		}
		int tt=vis[25]-vis[k];
		if(tt==0){
			cout<<"No Answer"<<endl<<"0";
			continue;
		}
		if(tt==1)
		{
			cout<<"No Answer"<<endl<<"0";
			continue;
		}
		if(judge(tt))
		{
			cout<<"Lucky Word"<<endl<<tt;
		}
		else
		cout<<"No Answer"<<endl<<"0";
	}
    return 0;
}
