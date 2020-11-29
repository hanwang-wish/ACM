//
//  main.cpp
//  Luogu1086
//
//  Created by wanghan on 16/9/20.
//  Copyright © 2016年 wanghan. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<set>
#include<cctype>
#include<deque>
using namespace std;
const int maxn=25;
int a[maxn][maxn];
int n,m,k;
typedef struct node{
    int num;
    int x,y;
    friend bool operator<(node a,node b){
        return a.num<b.num;
    }
}node;
int main(int argc, const char * argv[]) {
    // insert code here...
    while(cin>>n>>m>>k)
    {
        priority_queue<node> que;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                node t;
                cin>>a[i][j];
                if(a[i][j]){
                    t.num=a[i][j];
                    t.x=i,t.y=j;
                    que.push(t);
                }
            }
        }
        int cnt=0;
        node p;
        p=que.top();
        que.pop();
        int posx,posy;
        posx=p.x,posy=p.y;
        k-=posx+1;
        if(k<posx){
            cout<<"0"<<endl;
            continue;
        }else{
            cnt+=p.num;
        }
        while(!que.empty())
        {
            p=que.top();
            que.pop();
            int ans=abs(p.x-posx)+abs(p.y-posy)+1;
            posx=p.x,posy=p.y;
            k-=ans;
            if(k<posx){
                break;
            }
            cnt+=p.num;
        }
        cout<<cnt<<endl;
        
    }
    return 0;
}
