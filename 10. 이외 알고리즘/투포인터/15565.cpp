/*
	투포인터 기본.
	1. start,end 포인터를 0으로 둔다.
	2. start ~ end 까지 인형의 개수가 k보다 작으면 end를 늘리고, 크거나 같으면 start를 늘린다.
	3. 최솟값이 있으면 최솟값 출력, 아니면 -1 을 출력한다.  
*/
#include<bits/stdc++.h>
using namespace std;

int lion[1000000]={0,}; 
int main(){
	int n,k;cin>>n>>k;
	
	for(int i=0;i<n;i++) cin>>lion[i];
	
	int start=0,end=0;
	
	int count;
	(lion[0]==1)?count=1:count=0;
	int size=1e7;
	while(start<=end&&end<n){
//		cout<<start<<" "<<end<<" "<<count<<"\n";
		if(count<k){
			end++;
			if(lion[end]==1) count++;
		}else{
			size=min(size,end-start+1);
			if(lion[start]==1) count--;
			start++;
		}
	}
	(size==1e7)?cout<<-1:cout<<size;
}
