#include<bits/stdc++.h>
using namespace std;

int k,n;
vector<int> selected_nums;
void printValue(){
	for(int num:selected_nums) cout<<num<<" ";
	puts("");
}
void dfs(int count){
	if(count==n){
		printValue();
		return;
	}
	for(int i=1;i<=k;i++){
		if(count>=2&&i==selected_nums[count-1]&&i==selected_nums[count-2]) continue;
		selected_nums.push_back(i);
		dfs(count+1);
		selected_nums.pop_back();
	}
}
int main(){
	cin>>k>>n;
	dfs(0);
}
