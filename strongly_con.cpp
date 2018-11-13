#include<bits/stdc++.h>
using namespace std;

bool a[15][15],b[15][15];
bool vis[15];
int tim[2][15];
int t=0;

void dfs(int s,int n){
if(vis[s]==true) return;
t++;
vis[s]=true;
tim[0][s]=t;
for(int i=0;i<n;++i){
if(a[s][i]==true && vis[i]==false)
 dfs(i,n);
}
t++;
tim[1][s]=t;
}

void dfs1(int s, int n){
if(vis[s]==true) return;
vis[s]=true;
for(int i=0;i<n;++i){
if(b[s][i]==true && vis[i]==false)
dfs1(i,n);
}
cout<<s<<" ";
}

int main(){
memset(b,0,sizeof(b));
memset(vis,0,sizeof(vis));
memset(a,0,sizeof(a));
int n,e,x,y;
cin>>n>>e;

for(int i=0;i<e;++i){
cin>>x>>y;
a[x][y]=1;
}

for(int i=0;i<n;++i){
if(vis[i]==false)
dfs(i,n);
}

for(int i=0;i<n;++i){
for(int j=0;j<n;++j)
b[j][i]=a[i][j];
}
memset(vis,0,sizeof(vis));
for(int oo=0;oo<n;++oo){
int max=0;
x=0;
for(int i=0;i<n;++i){
if(tim[1][i]>max && vis[i]==false){
max=tim[1][i];
x=i;
}
}
dfs1(x,n);
cout<<endl;
}
cout<<"\n***********time*************\n";
for(int i=0;i<n;++i)
cout<<tim[0][i]<<" "<<tim[1][i]<<endl;
cout<<endl;
return 0;
}
