#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
const int maxn=110;
int s[maxn];
int n,l;
int cnt;
bool dfs(int cur){
	if(cnt++==n){
		for(int i=0;i<cur;i++){
			if(i%64==0&&i)
				printf("\n");
			else if(i%4==0&&i)
				printf(" ");
			printf("%c",'A'+s[i]);
		}
		printf("\n");
		printf("%d\n",cur);
		return false;
	}
	for(int i=0;i<l;i++){
		int ok=0;
		s[cur]=i;
		for(int j=1;2*j<=cur+1;j++){  //枚举2*j长度的后缀
			int flag=0;
			for(int k=0;k<j;k++){    //判断是否出现重复子串
				if(s[cur-k]!=s[cur-j-k]){
					flag=1; break;
				}
			}
			if(!flag){   //出现重复子串，不满足
				ok=1; break;  
			}
		}
		if(!ok){
			if(!dfs(cur+1))  return false;
		}
	}
	return true;
}
int main()
{
	while(cin>>n>>l)
	{
		if(!n&&!l)  break;
		memset(s,0,sizeof(s));
		cnt=0;
		bool flag=dfs(0);
	}
}