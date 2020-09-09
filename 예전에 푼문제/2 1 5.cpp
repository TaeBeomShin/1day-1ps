#include<bits/stdc++.h>

using namespace std;

int main(){
	int A,B,V;
	cin>>A>>B>>V;
	//아침에 A만큼 올라가고, 밤에 B만큼 내려감, 총 V미터올라가야함.
	//(V-B-1)/(A-B)+1;
	int result=(V-B-1)/(A-B)+1;
	cout<<result;
}
