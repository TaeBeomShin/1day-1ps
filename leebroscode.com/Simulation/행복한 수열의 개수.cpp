#include<bits/stdc++.h>
using namespace std;

int arr[101][101]={0,};
int main(){
	int n,m;cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	
	int count=0;
	for(int i=0;i<n;i++){
		bool check1=false,check2=false;
		for(int j=m-1;j<n;j++){
			int count1=0,count2=0;
			for(int k=0;k<m;k++){
				if(arr[i][j]==arr[i][j-k]) count1++;
				if(arr[j][i]==arr[j-k][i]) count2++;
			}
			if(count1==m) check1=true;
			if(count2==m) check2=true;
		}
		if(check1) count++;
		if(check2) count++;
	}
	cout<<count;
}
