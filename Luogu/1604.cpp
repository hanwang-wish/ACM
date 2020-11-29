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
const int maxn=2200;
char s[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int n; //进制
int vis1[maxn],vis2[maxn];
int ans[maxn];
int main()
{
    while(cin>>n)
	{
		string a,b;
		cin>>a;
		cin>>b;
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		int len1=a.length();  //反转第一个串
		for(int i=0;i<len1/2;i++){
			char temp=a[i];
			a[i]=a[len1-1-i];
			a[len1-1-i]=temp;
		}
		for(int i=0;i<len1;i++){
			int pos;
			for(int j=0;j<36;j++){
				if(a[i]==s[j]){
					pos=j; break; 
				}
			}
			vis1[i]=pos;
		}
		int len2=b.length();   //反转第二个串
		for(int i=0;i<len2/2;i++){
			char tt=b[i];
			b[i]=b[len2-i-1];
			b[len2-1-i]=tt;
		}
		for(int i=0;i<len2;i++){
			int pos;
			for(int j=0;j<36;++j){
				if(b[i]==s[j]){
					pos=j; break;
				}
			}
			vis2[i]=pos;
		}
		int mx=max(len1,len2);
		int cnt=0;
		for(int i=0;i<mx;i++){
			int temp=vis1[i]+vis2[i]+cnt;
			if(temp>=n){
				cnt=1;
				ans[i]+=temp%n;
			}else{
				cnt=0;
				ans[i]+=temp;
			}
		}
		if(cnt==1){
			ans[mx]=1; ++mx;
		}
		string ss;
		for(int i=0;i<mx;i++){
			ss+=s[ans[i]];
		}
		for(int i=0;i<mx/2;i++){
			char yy=ss[i];
			ss[i]=ss[mx-i-1];
			ss[mx-i-1]=yy;
		}
		cout<<ss<<endl;
	}
    return 0;
}
