// #include <bits/stdc++.h>
// #define V 6
// using namespace std;

// class Graph
// {
//     int vertices;
//     int weight;
//     int edges;
//     int **matrix;

// public:
//     Graph()
//     {
//         int n, m;
//         cout << "Enter the Total no of vertices :" << endl;
//         cin >> n;
//         cout << "Enter the Total no of edges :" << endl;
//         cin >> m;
//         edges = m;
//         vertices = n;
//         weight = 0;
//         matrix = new int *[n];

//         for (int i = 0; i <= n; i++)
//         {
//             matrix[i] = new int[n];
//         }
//         for (int i = 0; i <= vertices; i++)
//         {
//             for (int j = 0; j <= vertices; j++)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }

//     void create()
//     {
//         for (int i = 0; i < edges; i++)
//         {
//             int a, b, c;
//             cout << "Enter the source :" << endl;
//             cin >> a;
//             cout << "Enter the destination :" << endl;
//             cin >> b;
//             cout << "Enter the weight :" << endl;
//             cin >> c;
//             matrix[a][b] = c;
//             matrix[b][a] = c;
//         }
//     }

//     void display()
//     {
//         cout << "     ";
//         for (int i = 0; i <= vertices; i++)
//         {
//             cout << i << "     ";
//         }
//         cout << endl;
//         for (int i = 0; i <= vertices; i++)
//         {
//             cout << i << "    ";
//             for (int j = 0; j <= vertices; j++)
//             {
//                 cout << matrix[i][j];
//                 cout << "     ";
//             }
//             cout << endl;
//         }
//     }

//     int selectMinVertex(int value[],bool setMST[])
//     {
//         int minimum = INT_MAX;
//         int vertex;
//         for (int i = 0; i < V; ++i)
//         {
//             if (setMST[i] == false && value[i] < minimum)
//             {
//                 vertex = i;
//                 minimum = value[i];
//             }
//         }
//         return vertex;
//     }

//     void prims()
//     {
//         int value[vertices];
//         bool setMST[vertices];
//         int parent[vertices];


//         for(int i=0;i<vertices;i++)
//         {
//             value[i]=INT_MAX;
//             setMST[i]=false;
//         }

//         parent[0] = -1;
//         setMST[0] = true;
        
        

//         for (int i = 0; i < vertices - 1; i++)
//         {
//             int U = selectMinVertex(value, setMST);
//             setMST[U] = true; // Include new Vertex in MST

//             // Relax adjacent vertices (not yet included in MST)
//             for (int j = 0; j < V; ++j)
//             {
//                 /* 3 constraints to relax:-
//                       1.Edge is present from U to j.
//                       2.Vertex j is not included in MST
//                       3.Edge weight is smaller than current edge weight
//                 */
//                 if (matrix[U][j] != 0 && setMST[j] == false && matrix[U][j] < value[j])
//                 {
//                     value[j] = matrix[U][j];
//                     parent[j] = U;
//                 }
//             }
//         }

//         for(int i=1;i<vertices;++i){
// 		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<matrix[parent[i]][i]<<"\n";
//     }
// }

//     void krushkals()
//     {
        
//     }

// };



// int main()
// {
//     Graph g;
//     g.create();
//     g.display();
//     g.prims();
// }



#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices =6

int selectMinVertex(vector<int>& value,vector<bool>& setMST)
//refrencing is used so that , yahi particular value inc/dec/affect/change hoga
{
	int minimum = INT_MAX; //int_max is infinity
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(setMST[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i]; //=0
		}
	}
	return vertex;
}

void findMST(int graph[V][V])
{
	int parent[V];		//Stores MST
	vector<int> value(V,INT_MAX);	//Used for edge relaxation
	vector<bool> setMST(V,false);	//TRUE->Vertex is included in MST

// value naam ke vector mai V elements hai and initially vo infinite hai

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Form MST with (V-1) edges
	for(int i=0;i<V-1;++i)
	{
		//Select best Vertex by applying greedy method
		int U = selectMinVertex(value,setMST);
		setMST[U] = true;	//Include new Vertex in MST

		//Relax adjacent vertices (not yet included in MST)
		for(int j=0;j<V;++j)                           //distance find karnya sathi
		{
			/* 3 constraints to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in MST
			      3.Edge weight is smaller than current edge weight
			*/
			if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j]) //egde exist karto ,not present in mst,graph[0][1]=1<value[1]=infinite
			{
				value[j] = graph[U][j];  //=1
				parent[j] = U;   //=0
			}
		}
	}
	//Print MST
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
}

int main()
{
	int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };

	findMST(graph);	
	return 0;
}
