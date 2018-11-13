#include<bits/stdc++.h>
using namespace std;


int main(){
cout<<"Enter no of stations:";
int n,e1,e2,x1,x2;
cin>>n;
cout<<"Enter entry costs :";
cin>>e1>>e2;
int cost[n][2],ch[n-1][2];
cout<<"cost of processing at each station of line 1 ";
for(int i=0;i<n;++i)
cin>>cost[i][0];
cout<<"cost of processing at each station of line 2 ";
for(int i=0;i<n;++i)
cin>>cost[i][1];

cout<<"cost of changing station of line 1 ";
for(int i=0;i<n-1;++i)
cin>>ch[i][0];

cout<<"cost of changing station of line 2 ";
for(int i=0;i<n-1;++i)
cin>>ch[i][1];

cout<<"exit costs\n";
cin>>x1>>x2;
int l[n][2];
int a[n][2];
a[0][0]=e1+cost[0][0];
a[0][1]=e2+cost[0][1];
if(a[0][0]<=a[0][1])
l[0][0]=l[0][1]=1;
else
l[0][0]=l[0][1]=2;
for(int i=1;i<n;++i){
if(a[i-1][0]+cost[i][0]<=a[i-1][1]+ch[i-1][1]+cost[i][0]){
l[i][0]=1;
}
else
l[i][0]=2;
a[i][0]=min(a[i-1][0]+cost[i][0],a[i-1][1]+ch[i-1][1]+cost[i][0]);
if(a[i-1][1]+cost[i][1]<=a[i-1][0]+ch[i-1][0]+cost[i][1])
l[i][1]=2;
else
l[i][1]=1;
a[i][1]=min(a[i-1][1]+cost[i][1],a[i-1][0]+ch[i-1][0]+cost[i][1]);
}
int res=min(a[n-1][0]+x1,a[n-1][1]+x2);
cout<<res<<endl;
int ll=(a[n-1][0]+x1<=a[n-1][1]+x2)?1:2;
cout<<ll<<endl;
for(int i=0;i<n;++i){
cout<<a[i][0]<<" "<<a[i][1]<<endl;
cout<<l[i][0]<<" "<<l[i][1]<<endl;
}
int route[n+1];
route[n]=ll;
for(int i=n-1;i>=0;--i){
if(l[i][0]==l[i][1])
route[i]=l[i][0];
else if(l[i][route[i+1]-1]==route[i+1])
route[i]=route[i+1];
}
for(int i=0;i<=n;++i)
cout<<route[i]<<" ";
return 0;
}
