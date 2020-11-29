#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "map"
#include "queue"
using namespace std;
const int maxn=50;
string a[maxn],b[maxn],x,y;
int cnt;
struct node{string s; int num;};
map<string,int>mp;
bool bfs(){
	queue<node>que;
	que.push((node){x,0});
	mp[x]=1;
	while(!que.empty()){
		node u=que.front();
		que.pop();
		if(u.num>10) return 0;
		if(u.s==y){
			printf("%d\n",u.num);
			return 1;
		}
		string t=u.s;
		int len=t.length();
		string res;
		for(int i=1;i<=cnt;i++){
			int lena=a[i].length();
			for(int j=0;j<len;j++){
				if(t.substr(j,lena)==a[i]){
					res=t;
					res.replace(j,lena,b[i]);
					if(!mp[res]){
						mp[res]=1;
						que.push((node){res,u.num+1});
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	cin>>x>>y;
	cnt=0;
	while(cin>>a[++cnt])
		cin>>b[cnt];
	--cnt;
	if(!bfs())  cout<<"NO ANSWER!"<<endl;
}