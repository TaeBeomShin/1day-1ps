#include<iostream>
#include<deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N;
	cin>>N;
	
	deque<int> router;
	
	int packet;
	while(cin>>packet&&packet!=-1){
		if(packet==0){
			if(router.empty()) continue;
			router.pop_front();
		}else if(router.size()==N){
			continue;
		}
		else{
			router.push_back(packet);
		}
	}
	
	if(router.empty()) cout<<"empty";
	else{
	for(int i=0;i<router.size();i++){
		cout<<router[i]<<" ";
	}
	}
	return 0;
}
