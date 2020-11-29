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
int n;
int main()
{
    while(cin>>n)
	{
		vector<int> p;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			int flag=0;
			for(int j=0;j<p.size();j++)
			{
				if(x==p[j]){
					flag=1; break;
				}
			}
			if(!flag)  p.push_back(x);
		}
		cout<<p.size()<<endl;
		int t=p.size();
		int b[maxn];
		for(int i=0;i<t;i++)
			b[i]=p[i];
		sort(b,b+t);
		for(int i=0;i<t-1;i++)
			cout<<b[i]<<" ";
		cout<<b[t-1]<<endl;
	}
    return 0;
}
