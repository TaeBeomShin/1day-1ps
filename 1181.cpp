#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(string s1,string s2){
	if(s1.size()==s2.size()){//ũ�� ������ ��. 
		return s1<s2;
	}
	return s1.size()<s2.size();//ũ�� �ٸ���. 
}
int main(){
	int N;
	cin>>N;
	vector <string> v; 
	
	string temp;
	for(int i=0;i<N;i++){
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),comp);
	
	v.erase(unique(v.begin(),v.end()),v.end());
	//�ߺ� �����ϴ� ��� �ܿ��� ��. 
	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<"\n";
	}
	
	return 0;
}
