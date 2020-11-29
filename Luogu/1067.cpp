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
const int maxn=110;
int p[maxn];
int n;
void solve(int a,int t)
{
	if(a!=0)
	{
		if(t==0)
		{
			if(a>0)
			printf("+%d",a);
			else if(a<0)
				printf("%d",a);
			return;
		}
		if(t==1)
		{
			if(a>1)
				printf("+%dx",a);
			else if(a<-1)
				printf("%dx",a);
			else if(a==1)
				printf("+x");
			else if(a==-1)
				printf("-x");
			return;
		}
		if(a==1)
			printf("+x^%d",t);
		else if(a==-1)
		{
			printf("-x^%d",t);
		}
		else
		{
			if(a>0)
			{
				printf("+%dx^%d",a,t);
			}else{
				printf("%dx^%d",a,t);
			}
		}
	}
}
int main()
{
    while(cin>>n)
	{
		for(int i=1;i<=n+1;i++)
			cin>>p[i];
		int k;
		for(int i=1;i<=n+1;i++)
		{
			if(p[i])
			{
				k=i;
				break;
			}
		}
		if(k==-1){
			cout<<"0"<<endl;
			continue;
		}
		if(k==n+1)
		{
			cout<<p[n]<<endl;
			continue;
		}
		int num=n-k+1;
		if(p[k]!=1&&p[k]!=-1)
		{
			if(num!=1)
			printf("%dx^%d",p[k],num);
			else
			printf("%dx",p[k]);
		}else if(p[k]==1)
		{
			if(num!=1)
			printf("x^%d",num);
			else
			printf("%dx",p[k]);
		}else
		{
			if(num!=1)
			printf("-x^%d",num);
			else
			printf("-%dx",p[k]);
		}
		for(int i=k+1;i<=n+1;i++)
		{
			--num;
			solve(p[i],num);
		}
		cout<<endl;
	}
    return 0;
}
