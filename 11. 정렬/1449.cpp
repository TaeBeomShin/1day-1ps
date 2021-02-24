#include<bits/stdc++.h>
using namespace std;

int arr[1001];
bool visited[1001];

int main(){
	int n,l;cin>>n>>l;	
 
	for(int i=0;i<n;i++)
		cin>>arr[i];		
	sort(arr,arr+n);
	//둘 사이의 거리가 l-1보다 가까우면 한테이프로 이어 붙일 수 있음.

	int count =0;
	for(int i=0;i<n;i++){
		if(!visited[arr[i]]){
			for(int j=arr[i];j<min(arr[i]+l,1001);j++) visited[j]=true;
			count++;
		}
	}
	cout<<count;
}
