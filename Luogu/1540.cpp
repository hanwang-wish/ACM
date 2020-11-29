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
#include<deque>
using namespace std;
const int maxn=1010;
int a[maxn];
int n,m;
int main()
{
    while(cin>>m>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		deque<int> que;
		int num=0;
		for(int i=0;i<n;i++)
		{
			int flag=0;
			for(int j=0;j<que.size();j++)
			{
				if(que[j]==a[i])
				{
					flag=1; break;
				}
			}
			if(!flag)
			{
				if(que.size()==m)
				{
					que.pop_front();
					que.push_back(a[i]);
					num++;
				}else{
					que.push_back(a[i]);
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
    return 0;
}
