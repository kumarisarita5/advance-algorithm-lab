#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >v(10);
vector<vector<int> >trans(10);


int main(){
//memset(vis,0,sizeof(vis));
int n,e,a,b;
cin>>n>>e;
for(int i=0;i<e;++i){
cin>>a>>b;
v[a].push_back(b);
}
for(int i=0;i<n;++i){
for(int j=0;j<v[i].size();++j){
trans[v[i][j]].push_back(i);
}
}

for(int i=0;i<n;++i){
if(v[i].size()>0)
cout<<"\n"<<i;
for(int j=0;j<v[i].size();++j){
cout<<"->"<<v[i][j];
}
}

for(int i=0;i<n;++i){
if(trans[i].size()>0)
cout<<"\n"<<i;
for(int j=0;j<trans[i].size();++j){
cout<<"->"<<trans[i][j];
}
}
return 0;
}
