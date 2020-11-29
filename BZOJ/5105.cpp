#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
LL a,b,c;
LL gcd(LL x,LL y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
int main()
{
	cin>>a>>b>>c;
	LL num=a*b/gcd(a,b);
	LL tt=num*c/gcd(num,c);
	cout<<tt<<endl;
}