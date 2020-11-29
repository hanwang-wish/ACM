#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
typedef struct Point
{
	int x,y;
}Point;
int main()
{
	Point p,v;
	while(cin>>p.x>>p.y>>v.x>>v.y)
	{
		int Pwin=p.x+p.y;
		int Vwin=max(v.x,v.y);
		if(Pwin<=Vwin){
			cout<<"Polycarp"<<endl;
		}
		else{
			if(p.x<=v.x&&p.y<=v.y){
				cout<<"Polycarp"<<endl;
			}
			else
				cout<<"Vasiliy"<<endl;
		}
			
	}
	return 0;
}