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
const int maxn=30030;
int a[maxn];
int w,n;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
    while(cin>>w>>n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int i=1,k=n;
		int cnt=0;
		while(i<=k){
			if(w-a[k]>=a[i]){
				k--;
				i++;
			}else{
				k--;
			}
			//cout<<k<<" "<<i<<endl;
			cnt++;
		}
		cout<<cnt<<endl;
	}
    return 0;
}
