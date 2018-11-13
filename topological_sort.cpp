#include<bits/stdc++.h>
using namespace std;
stack<int>st;
vector<vector<int> >v(10);
bool vis[15];
void dfs(int s){
if(vis[s]==true) return;
vis[s]=true;
for(int i=0;i<v[s].size();++i){
if(vis[v[s][i]]==false) dfs(v[s][i]);
}
st.push(s);
}

int main(){
memset(vis,0,sizeof(vis));
int n,e,a,b;
cin>>n>>e;
for(int i=0;i<e;++i){
cin>>a>>b;
v[a].push_back(b);
}
for(int i=0;i<n;++i){
if(vis[i]==false)
dfs(i);
}
while(!st.empty()){
int x=st.top();
st.pop();
cout<<x<<" ";
}
cout<<endl;
return 0;
}
