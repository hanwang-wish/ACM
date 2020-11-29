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
int n;
int main()
{
    while(cin>>n)
	{
		int k;
		string max="";
		int len1=0;
		for(int i=1;i<=n;i++)
		{
			len1=max.length();
			string s;
			cin>>s;
			int len2;
			len2=s.length();
			if(len2>len1)
			{
				max="";
				for(int j=0;j<len2;j++)
					max+=s[j];
				k=i;
			}else if(len2==len1){
				if(s>max)
				{
					max="";
					for(int j=0;j<len2;j++)
						max+=s[j];
					k=i;
				}
			}
		}
		cout<<k<<endl<<max<<endl;
	}
    return 0;
}
