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
const int maxn=120;
typedef struct node{
	string name;
	int ave;
	int cls;
	char stu;
	char west;
	int num;
	int id;
	int money;
}node;
node p[maxn];
bool cmp(const node a,const node b)
{
	if(a.money==b.money)
		return a.id<b.id;
	return a.money>b.money;
}
int t;
int main()
{
    while(cin>>t)
	{
		for(int i=1;i<=t;i++){
			cin>>p[i].name>>p[i].ave>>p[i].cls>>p[i].stu>>p[i].west>>p[i].num;
			p[i].id=i;
			p[i].money=0;
		}
		int cnt=0;
		for(int i=1;i<=t;i++){
			if(p[i].ave>80&&p[i].num>=1)
				p[i].money+=8000;
			if(p[i].ave>85&&p[i].cls>80)
				p[i].money+=4000;
			if(p[i].ave>90)
				p[i].money+=2000;
			if(p[i].ave>85&&p[i].west=='Y')
				p[i].money+=1000;
			if(p[i].cls>80&&p[i].stu=='Y')
				p[i].money+=850;
			cnt+=p[i].money;
		}
		sort(p+1,p+1+t,cmp);
		cout<<p[1].name<<endl<<p[1].money<<endl<<cnt<<endl;
	}
    return 0;
}
