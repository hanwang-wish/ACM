#include "bits/stdc++.h"
using namespace std;
const int maxn=1e5+100;
int n,a[maxn],b[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int pos1=n;
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            pos1=i; break;
        }
    }
    int pos2=1;
    for(int i=n;i>=1;i--){
        if(a[i]!=b[i]){
            pos2=i; break;
        }
    }
    printf("%d\n",abs(pos1-pos2)+1);
}
