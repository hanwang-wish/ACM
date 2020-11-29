#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
const int maxn=100;
typedef long long LL;
LL a[maxn];
int n;
int main()
{
	while(cin>>n){
		memset(a,0,sizeof(a));
		a[1]=3;
		a[2]=6;
		a[3]=6;
		for(int i=4;i<=n;i++){
			a[i]=a[i-1]+2*a[i-2];
		}
		cout<<a[n]<<endl;
	}
}