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
typedef struct p
{
	int value,num;
}p;
bool cmp(p a,p b)
{
	return a.value>b.value;
}
p s[maxn];
int n,t;
int need[maxn];
int main()
{
    while(cin>>n>>t)
	{
		int mx;
		for(int i=0;i<n;i++)
			cin>>s[i].value>>s[i].num;
		sort(s,s+n,cmp);
		int cnt=0;
		for(int i=0;i<n;i++) //比t大的直接加上即可
		{
			if(s[i].value>=t)
			{
				cnt+=s[i].num;
				s[i].num=0;
			}
		}
		while(true)
		{
			int sum=t,flag=0;
			memset(need,0,sizeof(need));
			for(int i=0;i<n;i++) //从大到小进行分配看剩余多少
			{
				int tmp=sum/s[i].value;
				int mi=min(tmp,s[i].num);
				sum-=mi*s[i].value;
				need[i]=mi;
				if(sum<=0){
					flag=1; break;
				}
			}
			if(sum>0)
			{
				for(int i=n-1;i>=0;i--) //从小到大进行填充
				{
					if(need[i]<s[i].num)
					{
						while(need[i]<s[i].num)
						{
							sum-=s[i].value;
							need[i]++;
							if(sum<=0){
								flag=1; break;
							}
						}
					}
					if(flag)  break;
				}
			}
			if(!flag)  break;
			mx=0x3ffff;
			for(int i=n-1;i>=0;i--) //统计这样的分配方式最多有几种
			{
				if(need[i])
					mx=min(mx,s[i].num/need[i]);
			}
			cnt+=mx;
			for(int i=n-1;i>=0;i--)
			{
				if(need[i])
					s[i].num-=mx*need[i];
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}
