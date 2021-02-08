#include<bits/stdc++.h>
using namespace std;
/*
	병든 나이트가 여행에서 방문할 수 있는 칸의 최대개수.
	1. 2칸위로 1칸 오른쪽
	2. 1칸위로 2칸 오른쪽
	3. 1칸 아래로 2칸 오른쪽
	4. 2칸 아래로 2칸 오른 쪽
	
	n과 m은 20억 보다 작거나 같은 자연수. O(1)만에 찾아야함. 
*/
int main(){
	int n,m;cin>>n>>m;
	//총 4개의 case; 
	if(n==1) cout<<1;
	else if(n==2) cout<<min(4,(m+1)/2);
	else if(n>=3){
		if(m<=6) cout<<min(4,m);
		else cout<<m-2;
	}
}
