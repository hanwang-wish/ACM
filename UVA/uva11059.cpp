#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std;
const int maxn=25;
int a[maxn];
int main()
{
	int cas=0;
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				long long cnt=1;
				for(int k=j;k<=i;k++){
					cnt*=a[k];
				}
				ans=max(cnt,ans);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n",++cas,ans);
		printf("\n");
	}
	return 0;
}