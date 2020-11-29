#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int maxn=20020;
int main()
{
    int n,a[maxn];
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        priority_queue<int,vector<int>,greater<int> >que;  //优先队列从最小值开始输出
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            que.push(a[i]);
        }
        long long ans=0;
        while(que.size()>1){
            long long l1=que.top();
            que.pop();
            long long l2=que.top();
            que.pop();
            long long t=l1+l2;
            ans+=t;
            que.push(t);
        }
        cout<<ans<<endl;
    }
    return 0;
}
