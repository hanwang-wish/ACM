#include "bits/stdc++.h"
using namespace std;
int vis[10];
char s[10];
vector<string>res;
void dfs(int pos,string str)
{
    if(pos==5){
        res.push_back(str);
        return;
    }
    for(int i=1;i<=4;i++){
        if(!vis[i]){
            str+=s[i];
            vis[i]=1;
            dfs(pos+1,str);
            str.pop_back();
            vis[i]=0;
        }
    }
}
bool judge(string a){
    if(a[0]>'2') return false;
    if(a[0]=='2'){
        if(a[1]>'3') return false;
    }
    return true;
}
bool judge1(string b){
    if(b[0]>='6') return false;
    return true;
}
int main()
{
    for(int i=1;i<=4;i++){
        char ch;
        cin>>ch;
        getchar();
        s[i]=ch;
    }
    sort(s+1,s+5);
    dfs(1,"");
    string r;
    int flag=0;
    for(int i=res.size()-1;i>=0;i--){
        r="";
        r=res[i];
        if(judge(r.substr(0,2))&&judge1(r.substr(2,2))){
            flag=1;
            break;
        }
        //cout<<res[i]<<endl;
    }
    if(!flag){
        cout<<"NOT POSSIBLE"<<endl;
        return 0;
    }
    string t="";
    t+=r[0];
    t+=r[1];
    t+=':';
    t+=r[2];
    t+=r[3];
    cout<<t<<endl;
}
