//bellman ford all pair shortest path
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

int dis[n],f=0;
for(int i=0;i<n;++i)
dis[i]=999;
int src;
cin>>src;
dis[src]=0;
for(int i=1;i<n;++i){
for(int j=src;j<n;(++j)%n){
for(int k=0;k<n;++k){
if(w[j][k]!=0 && dis[j]<20)
dis[k]=min(dis[k],dis[j]+w[j][k]);
}
}
}

for(int j=0;j<n;++j){
for(int k=0;k<n;++k){
if(w[j][k]!=0){
if(dis[j]+w[j][k]<dis[k])
f=1;
}
}
}
if(f)
cout<<"cycle\n";
else{
for(int i=0;i<n;++i)
cout<<dis[i]<<" ";
}
return 0;
}
