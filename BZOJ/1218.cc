#include "bits/stdc++.h"
using namespace std;
const int maxn=5e3+10;
int n,a[maxn][maxn],R;
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&R);
    for(int i=1;i<=n;i++){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        a[x+1][y+1]+=v;
    }
    for(int i=1;i<=5001;i++)
        for(int j=1;j<=5001;j++)
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
    int mx=0;
    for(int i=R;i<=5001;i++)
        for(int j=R;j<=5001;j++)
            mx=max(mx,a[i][j]-a[i-R][j]-a[i][j-R]+a[i-R][j-R]);
    printf("%d\n",mx);
    return 0;
}