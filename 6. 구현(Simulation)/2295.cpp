#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;

int n;
// x+y+z=w, x+y=w-z; 각각의 map 만들어서 있는지 비교.?? x,y,z,w는 서로 같아도됨.

int arr[1000];
map <int,int> M1;
priority_queue <P,vector<P>> PQ;
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int num=arr[i]+arr[j];
			if(M1.find(num)==M1.end()) M1[num]=1;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int num=arr[j]-arr[i];
			if(num<=0) continue;
			PQ.push({arr[j],num});
		}
	}
	
	while(!PQ.empty()){
		auto cur=PQ.top();PQ.pop();
		int num=cur.first,result=cur.second;
		if(M1.find(result)!=M1.end()){
			cout<<num;
			break;
		}
	}
}
