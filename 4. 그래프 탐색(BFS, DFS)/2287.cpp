#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int minDepth=MAX;

void dfs(int N,int number,int depth,int num){
    if(depth>=MAX) return;
    if(num==number) minDepth=min(depth,minDepth);
    
    int operand=0;
    for(int i=1;i<=MAX;i++){
        operand=operand*10+N;
        
        dfs(N,number,depth+i,num+operand);
        dfs(N,number,depth+i,num-operand);
        
        if(num!=0){
            dfs(N,number,depth+i,num*operand);
            dfs(N,number,depth+i,num/operand);
        }
    }
}
void solution(int N, int number) {
    dfs(N,number,0,0);
    minDepth>=MAX?cout<<"NO\n":cout<<minDepth<<"\n";
    minDepth=MAX;
}

int main(){
	int N,t;cin>>N>>t;
	while(t--){
		int number;cin>>number;
		solution(N,number);
	}
}
