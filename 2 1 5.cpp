#include<bits/stdc++.h>

using namespace std;

int main(){
	int A,B,V;
	cin>>A>>B>>V;
	//��ħ�� A��ŭ �ö󰡰�, �㿡 B��ŭ ������, �� V���Ϳö󰡾���.
	//(V-B-1)/(A-B)+1;
	int result=(V-B-1)/(A-B)+1;
	cout<<result;
}
