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
#include<algorithm>
#include<cmath>
#include<string>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<cmath>
using namespace std;
const int maxn=110;
long long a[maxn];
int n;
int main(int argc, const char * argv[]) {
    while(cin>>n)
    {
        long long ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans+=a[i];
        }
        long long cnt=ans/n;
        int tt=0;
        long long num=0;
        for(int i=1;i<=n;i++)
        {
            num+=a[i];
            if(num!=i*cnt) tt++;
        }
        cout<<tt<<endl;
    }
    return 0;
}
