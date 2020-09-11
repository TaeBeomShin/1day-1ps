#include<bits/stdc++.h>
using namespace std;

int n,c;
int location[200001];

int binarysearch(int left,int right){
	int d=0;
	while(left<=right){
		int mid=(left+right)/2;
		int start=location[0];
		int count=1;
	
		for(int i=1;i<n;i++){
			d=location[i]-start;
			if(mid<=d){
				count++;
				start=location[i];
			}

		}
		if(count>=c){
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	return right;
}
int main(){
	cin>>n>>c;
	for(int i=0;i<n;i++) cin>>location[i];
	sort(location,location+n);
	
	cout<<binarysearch(1,location[n-1]-location[0]);
}
