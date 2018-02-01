/*************************************************************************
	> File Name: POJ1419.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年02月01日 星期四 23时32分23秒
 ************************************************************************/

#include<iostream>
using namespace std;
char map[105][105];
int v,e;
int ans[105];
int maxn,count,k;
int temp[105];
bool vis[105];
void dfs(int step)
{
    bool flag=0;
    if(step>=v){
        for(int i=0;i<v;i++){
            temp[i]=vis[i];
        }
        maxn=count;   
        return ;
    }
    for(int i=0;i<step;i++){
        if(vis[i] && map[step][i]){
            flag=1;
            break;
        }
    }
    if(!flag){
        vis[step]=1;
        count++;
        dfs(step+1);
        count--;
        vis[step]=0;
    }
    if(count+v-step>maxn){
        dfs(step+1);
    }
}

int main()
{
    int T;
    int e1,e2;
    bool flag;
    cin>>T;
    while(T--){
        for(int i=0;i<105;i++){
            ans[i]=0;
            vis[i]=0;
            for(int j=0;j<105;j++){
                map[i][j]=0;
            }
        }
        k=0;
        count=0;
        maxn=0;
        cin>>v>>e;
        for(int i=0;i<e;i++){
            cin>>e1>>e2;
            map[e1-1][e2-1]=1;
            map[e2-1][e1-1]=1;
        }
        dfs(0);
        cout<<maxn<<endl;
        flag=0;
        for(int i=0;i<v;i++)
        {
        if(temp[i]){ 
           if(flag) cout<<" ";
           cout<<i;
           flag=1;
        }
        }
        cout<<endl;
    }
    return 0;
}
