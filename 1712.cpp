#include<bits/stdc++.h>
using namespace std;
int main(){
	int A,B,C;cin>>A>>B>>C;
	(B>=C)?cout<<-1:cout<<A/(C-B)+1;
}
