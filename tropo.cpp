#include<bits/stdc++.h>
using namespace std;

bool a[15][15];
bool vis[15];
int tim[2][15];
int t=0;
struct node{
int dt;
node *next;
};
struct node* dfs(int s,int n, node* root){
if(vis[s]==true) return NULL;
t++;
vis[s]=true;
tim[0][s]=t;
for(int i=0;i<n;++i){
if(a[s][i]==true && vis[i]==false)
 dfs(i,n,root);
}
t++;
tim[1][s]=t;
struct node *a=new node;
a->dt=s;
a->next=root;
root=a;
return root;
}


int main(){
memset(vis,0,sizeof(vis));
memset(a,0,sizeof(a));
int n,e,x,y;
cin>>n>>e;

for(int i=0;i<e;++i){
cin>>x>>y;
a[x][y]=1;
}
struct node *root=NULL;
for(int i=0;i<n;++i){
if(vis[i]==false)
root=dfs(i,n,root);
}

struct node *b=root;
while(b!=NULL){
cout<<b->dt<<" ";
b=b->next;
}
cout<<"\n***********time*************\n";
for(int i=0;i<n;++i)
cout<<tim[0][i]<<" "<<tim[1][i]<<endl;
cout<<endl;
return 0;
}
