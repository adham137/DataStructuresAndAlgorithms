#include"SearchingAlgorithms.h"

void depthFirstSearch(vector<int> graph[] ,int nVerticies , int start) {
	stack<int> s; 
	vector<bool> visited(nVerticies,false); //store visited verticies , initialize all values to false
	int v = start; //start at first node
	s.push(v);
	cout << "traversing graph using depth first search: ";
	while (!s.empty()) {
		cout << v << " ";
		visited[v] = true; //mark v as visited
		for (int i = 0;i < graph[v].size();i++) {
			if (visited[graph[v][i]] == false) { //if vertex is unvisited , visit it 
				v = graph[v][i];
				s.push(v);
				break;
			}
		}
		s.pop(); //if all neighbour verticies are visited , remove v from stack
	}
	cout << endl;
}


void breadthFirstSearch(vector<int> graph[], int nVerticies , int start) {
	queue<int> q;
	vector<bool> visited(nVerticies, false); //store visited verticies , initialize all values to false
	int v = start; //start at first node
	q.push(v);
	visited[v] = true; //mark v as visited
	cout << "traversing graph using breadth first search: ";
	
	while (!q.empty()) {
		v = q.front();
		cout << v << " ";

		for (int i = 0;i < graph[v].size();i++) {
			if (visited[graph[v][i]] == false) { //if vertex is unvisited , visit it 
				q.push(graph[v][i]);
				visited[graph[v][i]] = true;
			}
		}
		q.pop();
		

	}
	cout << endl;

}


void dijsktraSearch(vector<pair<int,int>> graph[], int nVerticies) {
	//graph structure ----> vertex , (vertex , weight of edge)
	cout << endl << "traversing graph using dijsktra's search: " << endl;

	vector<int> distance(nVerticies, INT_MAX);
	vector<int> parent(nVerticies);
	vector<bool> visited(nVerticies, false);

	distance[0] = 0;
	parent[0] = -1;

	int i, j, k, V, A;
	for (i = 0;i < nVerticies;i++) {

		int leastDistance = INT_MAX;
		//select node which is 1.unvisited , 2.has least distance , let it be V
		for (j = 0;j < nVerticies;j++) {
			if ((visited[j] == false) && (distance[j] < leastDistance)) {
				V = j;
				leastDistance = distance[V];
			}
		}
		
		//mark it as visited
		visited[V] = true;
		

		//read it's adjacent nodes one by one , let it be A
		for (k = 0;k < graph[V].size();k++) {

			//if A is 1.unvisited , 2.distance V+A is less than distance to A
			//1.input distance (V+A) in distance[A]
			//2.input V as parent of A

			A = graph[V][k].first;
			if ((visited[A] == false) && ((distance[V] + graph[V][k].second) < (distance[A]))) {
				distance[A] = distance[V] + graph[V][k].second;
				parent[A] = V;
			}

		}

	}

	//output 1.vertex 2.parent 3.minimum distance to reach this vertex
	for (i = 0;i < nVerticies;i++) {
		cout << "Vertex: " << i << " ,Parent: " << parent[i] << " ,Minimum distance to reach it: " << distance[i] << endl;
	}

}


//int main() {
//
//	vector<int> graph[5];
//	graph[0].push_back(1);
//	graph[0].push_back(4);
//
//	graph[1].push_back(0);
//	graph[1].push_back(2);
//	graph[1].push_back(3);
//	graph[1].push_back(4);
//
//	graph[2].push_back(1);
//	graph[2].push_back(3);
//
//	graph[3].push_back(1);
//	graph[3].push_back(2);
//	graph[3].push_back(4);
//
//	graph[4].push_back(0);
//	graph[4].push_back(1);
//	graph[4].push_back(3);
//
//	depthFirstSearch(graph , 5 , 0);
//	breadthFirstSearch(graph, 5 , 0);
//
//	vector<pair<int, int>> Wgraph[5];
//	Wgraph[0].push_back(make_pair(1, 10));
//	Wgraph[0].push_back(make_pair(4, 20));
//
//	Wgraph[1].push_back(make_pair(0, 10));
//	Wgraph[1].push_back(make_pair(3, 40));
//	Wgraph[1].push_back(make_pair(4, 50));
//	Wgraph[1].push_back(make_pair(2, 30));
//
//
//	Wgraph[2].push_back(make_pair(1, 30));
//	Wgraph[2].push_back(make_pair(3, 60));
//
//	Wgraph[3].push_back(make_pair(4, 70));
//	Wgraph[3].push_back(make_pair(1, 40));
//	Wgraph[3].push_back(make_pair(2, 60));
//
//	Wgraph[4].push_back(make_pair(0, 20));
//	Wgraph[4].push_back(make_pair(1, 50));
//	Wgraph[4].push_back(make_pair(3, 70));
//
//	dijsktraSearch(Wgraph, 5);
//	return 0;
//}