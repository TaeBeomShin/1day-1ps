#include<iostream>
#include<cstring>
#include<deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int test;
	cin>>test;
//�� ��ȣ�� �ǹ� -: �齺���̽�, < > : Ŀ����ġ �̵�(������ �� �ִٸ�)

	for(int i=0;i<test;i++){
		deque<char> passward;
		string a;
		cin>>a;
//		1.string�� �־��� ���ڿ��� �����Ѵ�.
//		2.���ڸ� �ϳ��� �޴´�.
//		- <,>,-�϶� ����� �ڷᱸ���� �����Ѵ�.
//		3.Ŀ���� ��ġ�� �����ؾ��Ѵ�. <,>,-������ Ŀ���� ��ġ�� ��ȭ��Ų��.
//		4.�ݺ��Ͽ� �����Ѵ�.
		int cursor=0;
		for(int j=0;j<a.size();j++){
			//deque�� ����ִ� ���. 
			if(a[j]=='<'){
				if(passward.empty()||cursor==0) continue;
				cursor--;
			}else if(a[j]=='>'){
				if(passward.size()==cursor) continue;
				cursor++;
			}//deque�� ������� �������.
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
