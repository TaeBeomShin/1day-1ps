#include<iostream>
#include<cstring>
#include<deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int test;
	cin>>test;
//각 기호의 의미 -: 백스페이스, < > : 커서위치 이동(움직일 수 있다면)

	for(int i=0;i<test;i++){
		deque<char> passward;
		string a;
		cin>>a;
//		1.string에 주어진 문자열을 저장한다.
//		2.문자를 하나씩 받는다.
//		- <,>,-일때 빼고는 자료구조에 저장한다.
//		3.커서의 위치를 저장해야한다. <,>,-에따라 커서의 위치를 변화시킨다.
//		4.반복하여 수행한다.
		int cursor=0;
		for(int j=0;j<a.size();j++){
			//deque가 비어있는 경우. 
			if(a[j]=='<'){
				if(passward.empty()||cursor==0) continue;
				cursor--;
			}else if(a[j]=='>'){
				if(passward.size()==cursor) continue;
				cursor++;
			}//deque가 비어있지 않은경우.
			else if(a[j]=='-'){
				if(cursor==0) continue;
				auto it = passward.begin() + cursor-1;
				passward.erase(it);
				if(cursor==0) continue;
				cursor--;
			}else{
				auto it = passward.begin() + cursor;
				passward.insert(it,a[j]);
				cursor++;
			}
		}
		for(int i=0;i<passward.size();i++) cout<<passward[i];
		cout<<"\n";
	}	
	

	
	return 0;
}
