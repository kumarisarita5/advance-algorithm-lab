//dijkastra
#include<bits/stdc++.h>
using namespace std;

int main(){

int n,e,a,b,wt;
cin>>n>>e;
int w[n][n];
memset(w,0,sizeof(w));
for(int i=0;i<e;++i){
cin>>a>>b>>wt;
w[a][b]=wt;
}


int dis[n];
for(int i=0;i<n;++i)
dis[i]=9999;

bool vis[n];

int src;
cout<<"Enter source\n";
cin>>src;
dis[src]=0;
int m=888,y=src;

for(int i=0;i<n;++i){
m=888;
for(int j=0;j<n;++j){
if(dis[j]<m && vis[j]==false){
m=dis[j];
y=j;
}
}
vis[y]=1;
for(int k=0;k<n;++k){
if(w[y][k]>0)
dis[k]=min(dis[k],dis[y]+w[y][k]);
}

}
for(int i=0;i<n;++i)
cout<<dis[i]<<" ";
return 0;
}
