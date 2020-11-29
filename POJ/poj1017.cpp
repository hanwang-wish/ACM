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
int s1,s2,s3,s4,s5,s6;
int main()
{
    while(cin>>s1>>s2>>s3>>s4>>s5>>s6)
	{
		if(s1+s2+s3+s4+s5+s6==0) break;
		int cnt=0;
		cnt+=s6;  //对剩余的6*6的处理
		s6=0;
		cnt+=s5;  //对剩余的5*5的处理
		s1-=11*s5;
		s5=0;
		s1=max(0,s1);
		cnt+=s4;   //对剩余的4*4的处理
		if(s2>=(s4*5)){
			s2-=s4*5;
		}
		else{
			int s=6*6*s4-4*4*s4-2*2*s2;
			s1-=s;
			s1=max(s1,0);
			s2=0;
		}
		s4=0;
		cnt+=(s3+3)/4;  //对剩余的3*3的处理
		s3%=4;
		if(s3)
		{
			if(s2>=7-2*s3)
			{
				s2-=7-2*s3;
				s1=max(0,s1-(8-s3));

			}
			else{
				s1=max(0,s1-(36-9*s3-4*s2));
				s2=0;
			}
		}
		s3=0;
		cnt+=(s2+8)/9;	//对剩余的2＊2进行处理
		s2%=9;
		if(s2)
		s1=max(0,s1-(36-4*s2));
		s2=0;
		cnt+=(s1+35)/36;  //对剩余的1*1进行处理
		cout<<cnt<<endl;
	}
    return 0;
}
