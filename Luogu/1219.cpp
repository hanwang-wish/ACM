#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=100;
int d1[maxn],d2[maxn],d3[maxn],d4[maxn],a[maxn];
int n,cnt;
void dfs(int cur){
	if(cur==n+1){
		if(cnt<3){
			for(int i=1;i<=n;i++)
				printf("%d ",a[i]);
			printf("\n");
		}
		cnt++;
	}else{
		for(int i=1;i<=n;i++){
			if(!d1[cur]&&!d2[i]&&!d3[cur-i+n]&&!d4[cur+i]){
				a[cur]=i;
				d1[cur]=1,d2[i]=1,d3[cur-i+n]=1,d4[cur+i]=1;
				dfs(cur+1);
				a[cur]=0;
				d1[cur]=0,d2[i]=0,d3[cur-i+n]=0,d4[cur+i]=0;
			}
		}
	}
}
int main()
{
	cin>>n;
	cnt=0;
	dfs(1);
	cout<<cnt<<endl;
	return 0;
}