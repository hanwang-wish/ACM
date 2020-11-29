#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
using namespace std;
const int maxn=1010;
int a[maxn];
int main()
{
    int n,r;
    while(cin>>r>>n)
    {
        if(r==-1&&n==-1)  break;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int i=0,ans=0;
        while(i<n){
            int s=a[i++];
            while(i<n&&a[i]<=s+r) i++;
            int p=a[i-1];
            while(i<n&&a[i]<=p+r) i++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
