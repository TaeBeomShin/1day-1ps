#include<iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int h,w,n;//h:호텔의 층수, w: 각 층의 방수,n: 몇 번째 손님인가.
		cin>>h>>w>>n;
		//채워가는 순서. 101 201 ... h01, 102,...
		int result=(n-1)/h+1+((n-1)%h+1)*100;
		cout<<result<<"\n"; 
	}
}
