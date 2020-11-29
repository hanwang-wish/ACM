#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
int n;
int vis[11];
bool judge(int a,int b){
	memset(vis,0,sizeof(vis));
	if(a>98765) return false;
	if(b<10000) vis[0]=1;
	while(a){
		vis[a%10]=1;
		a/=10;
	} 
	while(b){
		vis[b%10]=1;
		b/=10;
	}
	int sum=0;
	for(int i=0;i<10;i++)
		sum+=vis[i];
	if(sum==10)  return true;
	return false;
}
int main()
{
	int cnt=0;
	while(cin>>n)
	{
		if(n==0)  break;
		if(cnt++)
		printf("\n");
		int flag=0;
		for(int i=1234;i<=98765;i++){
			if(judge(i*n,i)){
				printf("%05d / %05d = %d\n", i * n, i, n);
				flag=1;
			}
		}
		if(!flag)
			printf("There are no solutions for %d.\n",n);
		//printf("\n");
	}
	return 0;
}