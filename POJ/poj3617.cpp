#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>		
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
using namespace std;
const int maxn=2200;
char s[maxn],t[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++){
            scanf(" %c",&t[i]);
        }
        int i=0,j=n-1;
        for(int k=0;k<n;k++){
            if(t[i]<t[j]){
                s[k]=t[i++];
            }
            else if(t[i]>t[j]){
                s[k]=t[j--];
            }
            else{
                int ti=i,tj=j;
                while(t[ti]==t[tj]&&ti<=tj) ti++,tj--;
                if(t[ti]<t[tj]) s[k]=t[i++];
                else s[k]=t[j--];
            }
        }
        for(int i=0;i<n;i++){
            printf("%c",s[i]);
            if(i%80==79) printf("\n");
        }
        if(n%80)  printf("\n");
    }
    return 0;
}
