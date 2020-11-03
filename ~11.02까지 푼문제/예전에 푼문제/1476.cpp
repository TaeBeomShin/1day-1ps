#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

int main(){
	int E,S,M;
	cin>>E>>S>>M;//지구,태양,달. 한 수가 범위넘어 갈때마다 1씩 증가함. 
	
	int a=1,b=1,c=1;
	int count =1;
	//반복문을 이용한 풀이. 
	while(a!=E||b!=S||c!=M){
		a++;b++;c++;
		if(a>15) a=1;
		if(b>28) b=1;
		if(c>19) c=1;
		count++;
	}
	cout<<count;

	return 0;
}
