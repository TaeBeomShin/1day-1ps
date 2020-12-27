#include<bits/stdc++.h>
using namespace std;

char Tree[26][2]={'.'};

void preorder(char root){
	if(root=='.') return;
	cout<<root;
	preorder(Tree[root-'A'][0]);
	preorder(Tree[root-'A'][1]);
}

void inorder(char root){
	if(root=='.') return;
	
	inorder(Tree[root-'A'][0]);
	cout<<root;
	inorder(Tree[root-'A'][1]);
}

void postorder(char root){
	if(root=='.') return;
	postorder(Tree[root-'A'][0]);
	postorder(Tree[root-'A'][1]);
	cout<<root;
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		char x,y,z;cin>>x>>y>>z;
		Tree[x-'A'][0]=y;
		Tree[x-'A'][1]=z;
	}
	preorder('A');
	cout<<"\n";
	inorder('A');
	cout<<"\n";
	postorder('A');
}
