/*************************************************************************
	> File Name: POJ2965.cpp
	> Author:Jacky.C 
	> Mail: 
	> Created Time: 2018年01月29日 星期一 10时44分03秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
int map[5][5];
struct point
{
    int x;
    int y;
    point(){x=0;y=0;}
    point(int i,int j):x(i),y(j){}
};


void read()
{
    char c;
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
        cin>>c;
        if(c=='-')
        map[i][j]=1;
        else map[i][j]=0;
    }
}
void change ( int x,int y )
{
    for(int i=0;i<4;i++)
        if(map[x][i]) map[x][i]=0;
        else map[x][i]=1;
    for(int j=0;j<4;j++)
        if(map[j][y]) map[j][y]=0;
        else map[j][y]=1;
    map[x][y]=!map[x][y];
}

bool check()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        if(!map[i][j]) return false;
    return true;
}

int ans=999;
point path[100];
point anspath[100];
void dfs(int p, int step)
{
    if(check())
    {
        if(step<ans) ans=step;
        for(int i=0;i<ans;i++)
        {
            anspath[i]=path[i];
        }
        return ;
    }
    if(p>15) return ;
    int x=p/4;
    int y=p%4;
    dfs(p+1,step);
    change(x,y);
    path[step]=point(x+1,y+1);
    dfs(p+1,step+1);
    change(x,y);
}
void print()
{
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
    {
        point p=anspath[i];
        int x=p.x;
        int y=p.y;
        cout<<x<<" "<<y<<endl;
    }
}
int main()
{
    read();
    dfs(0,0);
    print();
    return 0;
}













