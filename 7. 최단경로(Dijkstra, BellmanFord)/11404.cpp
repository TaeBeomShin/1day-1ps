#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
const int INF=1e9;
int arr[101][101];

int main(){
	fastio;
	int n,m;cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j]=i==j?0:INF;
			
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		arr[a-1][b-1]=min(arr[a-1][b-1],c);
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]<INF)
				cout<<arr[i][j]<<" ";
			else
				cout<<"0 ";
		}
		cout<<"\n";
	}
}
