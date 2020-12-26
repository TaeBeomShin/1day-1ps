#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;
	
	Graph(): N(0){}
	Graph(int n): N(n){
		adj.resize(N);
		visited.resize(N);
	}
	
	void addEdge(int u, int v){
		add[u].push_back(v);
		add[v].push_back(u);
	}
	
	void sortList(){
		for(int i=0;i<N;i++)
			sort(adj[i].begin(),adj[i].end);
	}
	void dfs(){
		fill(visited.begin(),visited.end(),false);
		dfs(0);
	}

private:
	void dfs(int curr){
		visited[curr]=true;
		cout<<"node "<<curr<" visited"<<endl;
		for(int next: adj[curr])
			if(!visited[next]) dfs(next);
	}
};

int main(){
	Graph G(9);
	G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 5);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(2, 6);
    G.addEdge(2, 8);
    G.addEdge(6, 7);
    G.addEdge(6, 8);
    G.sortList();
    G.dfs();
}
