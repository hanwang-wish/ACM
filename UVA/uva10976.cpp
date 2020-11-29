#include "iostream"
#include "cstdio"
#include "cstring"
#include "vector"
using namespace std;
int k;
int main()
{
	while(cin>>k)
	{
		vector<int> que1,que2;
		for(int i=k+1;i<=(2*k);i++){
			if(i*k%(i-k)==0){
				que1.push_back(i);
				que2.push_back(i*k/(i-k));
			}
		}
		int t=que1.size();
		printf("%d\n",t);
		for(int i=0;i<que1.size();i++){
			printf("1/%d = 1/%d + 1/%d\n",k,que2[i],que1[i]);
		}
	}
}