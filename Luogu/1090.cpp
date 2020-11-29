//
//  main.cpp
//  1090
//
//  Created by wanghan on 16/9/22.
//  Copyright © 2016年 wanghan. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int main(int argc, const char * argv[]) {
    // insert code here...
    while(cin>>n)
    {
        priority_queue<int,vector<int>,greater<int> > que;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            que.push(x);
        }
        int cnt=0;
        while(!que.empty()){
            int t1,t2;
            t1=que.top();
            que.pop();
            if(que.empty()) break;
            t2=que.top();
            que.pop();
            cnt+=(t1+t2);
            //cout<<cnt<<endl;
            que.push(t1+t2);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
