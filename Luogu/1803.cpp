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
const int maxn=1000010;
typedef struct node{
	int s,e;
}node;
node p[maxn];
int n;
bool cmp(node a,node b)
{
	return a.e<b.e;
}
int main()
{
    while(cin>>n)
	{
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].s,&p[i].e);
		}sort(p,p+n,cmp);
		int et=-1;
		int cnt=0;
		for(int i=0;i<n;i++){
			//cout<<et<<endl;
			if(p[i].s>=et){
				cnt++;
				et=p[i].e;
			}
			//cout<<"abc"<<et<<endl;
		}
		cout<<cnt<<endl;
	}
    return 0;
}
