//
//  main.cpp
//  1208
//
//  Created by wanghan on 16/9/23.
//  Copyright © 2016年 wanghan. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=2000020;
typedef struct node{
    int p,a;
}node;
node s[maxn];
bool cmp(const node x,const node y){
    if(x.p==y.p) return x.a>y.a;
    return x.p<y.p;
}
int n,m;
int main(int argc, const char * argv[]) {
    // insert code here...
    while(cin>>n>>m)
    {
        for(int i=1;i<=m;i++){
            scanf("%d%d",&s[i].p,&s[i].a);
        }sort(s+1,s+1+m,cmp);
        int cnt=0;
        for(int i=1;i<=m;i++){
            if(n<=0) break;
            if(n>=s[i].a){
                cnt+=s[i].p*s[i].a;
                n-=s[i].a;
            }else{
                cnt+=n*s[i].p;
                n=0;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
