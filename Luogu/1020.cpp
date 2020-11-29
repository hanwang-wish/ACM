#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "vector"
using namespace std;
const int maxn=110;
int dp[maxn];
int pre[maxn];
int main()
{
    int x,n;
    vector<int>h;
    while(scanf("%d",&x)!=EOF){
        h.push_back(x);
    }
    int ans=0,cnt=0;
    while(!h.empty()){
        n=h.size();
        for(int i=0;i<=n;i++) pre[i]=i;
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(h[j]>h[i]&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
        }
        int tt=0,pos;
        for(int i=0;i<n;i++){
            if(dp[i]>tt){
                tt=dp[i];
                pos=i;
            }
        }
        ans=max(tt,ans);
        int flag=0;
        while(!flag){
            h.erase(h.begin()+pos);
            if(pos==pre[pos])  flag=1;
            pos=pre[pos];
        }
        ++cnt;
    }
    cout<<ans<<endl;
    cout<<cnt<<endl;
}