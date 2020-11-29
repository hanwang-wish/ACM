#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<cctype>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
const int maxn=2000+10;
int a[maxn][maxn];
int h[maxn];
int m,n;
int main()
{
	while(cin>>m>>n)
	{
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		memset(h,0,sizeof(h));
		int ans=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0)
					h[j]=0;
				else
					++h[j];
			}
			stack<int> s;
			s.push(0); h[++n]=0;
			for(int j=1;j<=n;j++){
				while(h[j]<h[s.top()]){
					int a=h[s.top()]; s.pop();
					int b=j-s.top()-1;
					ans=max(ans,a*b);
				}
				s.push(j);
			}
			--n;
		}
		cout<<ans<<endl;
	}
	return 0;
}