//
//  main.cpp
//  Luogu
//
//  Created by wanghan on 16/9/11.
//  Copyright © 2016年 wanghan. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<deque>
using namespace std;
const int maxn=20020;
typedef struct point
{
    int w,d;
}point;
point p[maxn];
int e[maxn];
int c[maxn];
int n,k;
bool cmp(const point a,const point b)
{
    if(a.w==b.w)
        return a.d<b.d;
    return a.w>b.w;
}
int main(int argc, const char * argv[]) {
    while(cin>>n>>k)
    {
        for(int i=1;i<=10;i++)
        {
            cin>>e[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].w;
            p[i].d=i;
        }
        sort(p+1,p+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            c[i]=(i-1)%10+1;
            p[i].w+=e[c[i]];
        }
        sort(p+1,p+1+n,cmp);
        for(int i=1;i<k;i++)
            cout<<p[i].d<<" ";
        cout<<p[k].d<<endl;
    }
    return 0;
}
