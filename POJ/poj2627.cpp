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
const int maxn=2020;
typedef struct P
{
	double x,y;
	int rec;
	bool vis;
}P;
P p[maxn];
double sx,sy,gx,gy;
double distance(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double v,m;
int main()
{
    cin>>v>>m;
	cin>>sx>>sy>>gx>>gy;
	int h=1;
	while(cin>>p[h].x>>p[h].y)
	{
		p[h].rec=0;
		p[h].vis=false;
		h++;
	}
	double dist=v*m*60;
	if(distance(sx,sy,gx,gy)<=dist)
	{
		cout<<"Yes, visiting 0 other holes."<<endl;
		return 0;
	}
	P s;
	queue<P> que;
	s.x=sx,s.y=sy,s.rec=0,s.vis=true;
	que.push(s);
	int ans=0x3ffff;
	int flag=0;
	while(!que.empty())
	{
		P t=que.front();
		que.pop();
		if(distance(t.x,t.y,gx,gy)<=dist)
		{
			flag=1;
			ans=min(ans,t.rec);
		}
		for(int i=1;i<h;i++)
		{
			if(distance(t.x,t.y,p[i].x,p[i].y)>dist||p[i].vis==true)
				continue;
			p[i].rec=t.rec+1;
			p[i].vis=true;
			que.push(p[i]);
		}
	}
	if(flag)
		cout<<"Yes, visiting "<<ans<<" other holes."<<endl;
	else
		cout<<"No. "<<endl;
    return 0;
}
