#include <iostream>
#include<vector>
using namespace std;

int main(){
    /* Graph -> set of vertices and edges 
    vertices are nothing but nodes and edges connect the vertices*/

    /*for example like in social media like facebook each user is a node
    then edge means the two vertices or the users are friends
    there may be a number of user and they are not friend hence no edge but this
    is also a valid graph
    */

    /* the data structure tree is also a type of graph
    but it is a connected graph as there is always from one node to another
    the graph can be connected as well as disconnected
    
    tree is always acyclic whereas a graph can be cyclic that is each node in a cycle is connected to more than one node
    consider it as a triangle or a square where the nodes are the vertices and each of them is connected to more than
    one vertices via edges */

    /*Graph Terminologies:
    ->Adjacent vertices : there will be a direct edge
    ->Degree of a node : number of edges going through that node
    ->Path : collection of edges through which we can move from one edge to the other
    ->Connected Graph : when there is at least one edge through every node
    ->Connected component : all the isolated sub graph the isolated sub graph may contain a single node
    ->Tree : a connected graph which is  acyclic
    ->Complete Graph: when there is a direct edge between any two nodes example a square with its diagonal
                        take any vertices there is an edge that connects the node to other three nodes
                        number of edges = nC2 or n(n-1)/2 . We can say that minimum number of edges are of the order O(n^2);
    ->
    */

    /*for a graph with n vertices :
    minimum number of edges = 0
    minimum number of edges in a connected graph = n-1 (min edges are of the order O(n), which is the case with the tree
    maximum number of edges in a graph(case of connected graph) = nC2 or n(n-1)/2 or the order of O(n^2);
    */

    /*ways to implement a graph:
    -> edge list
    ->adjacency list
    ->adjacency matrix*/
    
    /*Edge list
    a class will contain two arrays one containing all the vertices and other containing the pair of edges between two vertices
    
    horrible way as for checking for a connection we will iterate over the edge array and the time complexity
    is directly related to the number of edges which in case of worst case is O(n^2) */

   /*Adjacency list:
   an array of vertices such that each vertex will have a list which contain the vertex which it has direct edge to
   better way than edge list as for checking if there is a connection we have to iterate over the number of vertices which is n-1
   in case of worst case hence the time complexity is O(n)

   this linear time complexity can be made constant by using hashmap for finding connection with the node where the nodes are the 
   keys and the values are boolean values true or false
   */

  /*
    Adjacency matrix:
    construct a 2D array of size  n*n where n is the number of vertices, which consists of boolean values and if we want to check if there is an edge between
    say 3 and 4 we can go to 3rd row and 4th column and check for the boolean value present there
    cons: consumes a lot of space O(n^2)
        : in case of sparse graph(very few edges ) lot of space will be consumned for false values and they are of no use
  */

  /*implementing graph using adjacency matrix*/
  int n,e;
  cin>>n>>e;

  vector<vector<int>> matrix (n,vector<int>(n,0));// intitalsing with all zeroes
  for(int i=1;i<=e;i++){
    int fv,sv;
    cin>>fv>>sv;
    matrix[fv][sv]=1;
    matrix[sv][fv]=1;
  }
}