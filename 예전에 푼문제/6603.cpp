#include<iostream>

using namespace std;

int lotto[13];
int combi[13];
int number =6;
int k;
void dfs(int start,int depth){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	if(depth==6){
		for(int i=0;i<6;i++) cout<<combi[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=start;i<k;i++){
		combi[depth]=lotto[i];
		dfs(i+1,depth+1);
	}
} 
int main(){
	
	while(cin>>k&&k!=0){
		for(int i=0;i<k;i++){
			cin>>lotto[i];//뽑을 번호를 받는다.
//kC6개의 경우의 수를 모두 출력한다.
//dfs로 구현?
		}
			dfs(0,0);
			cout<<"\n";
	}
	return 0;
}
