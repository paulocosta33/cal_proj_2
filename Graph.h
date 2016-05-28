/*
 * Graph.h
 *
 *  Created on: 16/04/2016
 *      Author: jigsawkiller
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <stddef.h>
#include "Frota.h"
using namespace std;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = 1000000;
const int V = 4;
const int INF = 99999;

template <class T> class Graph;
template <class T> class Vertex;
template <class T> class Edge;


/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template <class T>
class Edge {

public:
	Edge(Vertex<T> *d, double w);
	Edge(Vertex<T> *d,T I);
	Edge(Vertex<T> *s, Vertex<T> *d);
	friend class Graph<T>;
	friend class Vertex<T>;
	Vertex<T> * dest;
	Vertex<T> * source;

	double weight;
	string nome;
	string road;
	T info;
	bool duploSentido;
	Edge();
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w)
{
	duploSentido = false;
}
template <class T>
Edge<T>::Edge(Vertex<T> *d,T I): dest(d),info(I)
{
	duploSentido = false;
	weight = 0;
};

template <class T>
Edge<T>::Edge(Vertex<T> *s,Vertex<T> *d): source(s),dest(d)
{

	duploSentido = false;
	weight = 0;
};



/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template <class T>
class Vertex {
public:
	//Vertex();
	T info;
	bool visited;
	bool processing;
	int indegree=0;
	int id;
	double dist; //dist acumulada
	double latitude;
	double longitude;
	Vertex(T in);
	vector<Edge<T>  > adj;
	friend class Graph<T>;
	Vertex* path;
	//void addEdge(Vertex<T> *dest, double w);
	void addEdge(Vertex<T> *dest, T info);
	bool removeEdgeTo(Vertex<T> *d);
	T getInfo() const;
	void setInfo(T info);
	int getDist() const;
	int getIndegree() const;
	bool operator<(const Vertex<T> vertex);


};

template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	d->indegree--; //adicionado do exercicio 5
	typename vector<Edge<T> >::iterator it= adj.begin();
	typename vector<Edge<T> >::iterator ite= adj.end();
	while (it!=ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		}
		else it++;
	}
	return false;
}


template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false), processing(false), indegree(0), dist(0) {
	latitude = 0;
	longitude = 0;
	path = NULL;
}


template <class T>
void Vertex<T>::addEdge(Vertex<T> *dest, T info)
{
	Edge<T> edgeD(dest,info);
	adj.push_back(edgeD);
}


template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
int Vertex<T>::getDist() const {
	return this->dist;
}


template <class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}

template <class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}


template <class T>
struct vertex_greater_than {
    bool operator()(Vertex<T> * a, Vertex<T> * b) const {
        return a->getDist() > b->getDist();
    }
};


/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template <class T>
class Graph {

	void dfs(Vertex<T> *v, vector<T> &res) const;
	int numCycles; //
	void dfsVisit(Vertex<T> *v);
	void dfsVisit();


	int ** W;   //weight
	int ** P;   //path

public:

	Graph()
	{P = NULL;
	 W = 0;
	 numCycles = 0;
	};
	Graph(vector<Vertex<T>*> v);
	vector<Edge<T> *> edgeSet;
	vector<Vertex<T> *> vertexSet;
	bool addVertex(const T &in,double latitude,double longitude,int id);
	void addEdge(const T &sourc,const T &dest, T I);
	void addRoad(const T &sourc,const T &dest,string roadname);
	Edge<T>* getEdge(const T &sourc, const T &dest);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T> getPath(const T &origin, const T &dest);
	vector<T> dfs() const;
	vector<T> bfs(Vertex<T> *v) const;
	vector<T> path_res;
	int maxNewChildren(Vertex<T> *v, T &inf) const;
	vector<Vertex<T> * > getVertexSet() const;
	int getNumVertex() const;
	Vertex<T>* getVertex(const T &v) const;
	void resetIndegrees();
	vector<Vertex<T>*> getSources() const;
	int getNumCycles();
	vector<T> topologicalOrder();
	void unweightedShortestPath(const T &v);
	bool isDAG();
	void getfloydWarshallPath(const T &origin, const T &dest);
	void getfloydWarshallPathAux(int index1, int index2, vector<T> & res);
	int edgeCost(int vOrigIndex, int vDestIndex);
	void floydWarshallShortestPath();

};

template <class T>
Graph<T>::Graph(vector<Vertex<T>*> v){
	P = NULL;
	W = 0;
	numCycles = 0;
	vertexSet =v;
};

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest){

	list<T> buffer;
	Vertex<T>* v = getVertex(dest);

	buffer.push_front(v->info);
	while ( v->path != NULL &&  v->path->info != origin) {
		v = v->path;
		buffer.push_front(v->info);
	}
	if( v->path != NULL )
		buffer.push_front(v->path->info);


	vector<T> res;
	while( !buffer.empty() ) {
		res.push_back( buffer.front() );
		buffer.pop_front();
	}
	return res;
}

template <class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for(unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v) return vertexSet[i];
	return NULL;
}

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}
template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
	return vertexSet;
}

template <class T>
int Graph<T>::getNumCycles() {
	numCycles = 0;
	dfsVisit();
	return this->numCycles;
}

template <class T>
bool Graph<T>::isDAG() {
	return (getNumCycles() == 0);
}


template <class T>
bool Graph<T>::addVertex(const T &in,double latitude,double longitude,int id) {
	typename vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite= vertexSet.end();
	for (; it!=ite; it++)
		if ((*it)->info == in) return false;
	Vertex<T> *v1 = new Vertex<T>(in);
	v1->longitude=longitude;
	v1->latitude=latitude;
	v1->id=id;
	vertexSet.push_back(v1);
	return true;
}

template <class T>
void Graph<T>::addRoad(const T &sourc, const T & dest, string roadname){

	for(int i =0; i<edgeSet.size();i++)
	{
		if(edgeSet[i]->source->info == sourc && edgeSet[i]->dest->info == dest)
		{
			edgeSet[i]->road = roadname;
		}
	}
}

template <class T>
void Graph<T>::addEdge(const T &sourc, const T &dest, T I) {
	typename vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<T> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if((*it)->info.compare(sourc)==0) // ( (*it)->info == sourc ), changed to str
			{ vS=*it; found++;}
		if((*it)->info.compare(dest)==0)
			{ vD=*it; found++;}
		it ++;
	}
	//if (found!=2);
	vD->indegree++;
	vS->addEdge(vD,I);
	Edge<T> * edge = new Edge<T>(vS,vD);
	edge->source=vS;
	edge->dest=vD;
	edgeSet.push_back(edge);
}

template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T>*>::iterator it= vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite= vertexSet.end();
	int found=0;
	Vertex<T> *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->info == sourc )
			{ vS=*it; found++;}
		if ( (*it)->info == dest )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2)
		return false;

	vD->indegree--;

	return vS->removeEdgeTo(vD);
}

template<class T>
void Graph<T>::getfloydWarshallPath(const T &origin, const T &dest){

	int originIndex = -1, destinationIndex = -1;

	for(unsigned int i = 0; i < vertexSet.size(); i++)
	{
		if(vertexSet[i]->info == origin)
			originIndex = i;
		if(vertexSet[i]->info == dest)
			destinationIndex = i;

		if(originIndex != -1 && destinationIndex != -1)
			break;
	}


	if(W[originIndex][destinationIndex] == INT_INFINITY)
	{}

	path_res.push_back(vertexSet[originIndex]->info);


	if(P[originIndex][destinationIndex] != -1)
	{
		int intermedIndex = P[originIndex][destinationIndex];

		getfloydWarshallPathAux(originIndex, intermedIndex, path_res);

		path_res.push_back(vertexSet[intermedIndex]->info);

		getfloydWarshallPathAux(intermedIndex,destinationIndex, path_res);
	}

	path_res.push_back(vertexSet[destinationIndex]->info);

}




template<class T>
void Graph<T>::getfloydWarshallPathAux(int index1, int index2, vector<T> & res)
{
	if(P[index1][index2] != -1)
	{
		getfloydWarshallPathAux(index1, P[index1][index2], res);

		res.push_back(vertexSet[P[index1][index2]]->info);

		getfloydWarshallPathAux(P[index1][index2],index2, res);
	}
}

template<class T>
int Graph<T>::edgeCost(int vOrigIndex, int vDestIndex)
{
	if(vertexSet[vOrigIndex] == vertexSet[vDestIndex])
		return 0;

	for(unsigned int i = 0; i < vertexSet[vOrigIndex]->adj.size(); i++)
	{
		if(vertexSet[vOrigIndex]->adj[i].dest == vertexSet[vDestIndex])
			return vertexSet[vOrigIndex]->adj[i].weight;
	}

	return INT_INFINITY;
}

template<class T>
void Graph<T>::floydWarshallShortestPath() {

	W = new int * [vertexSet.size()];
	P = new int * [vertexSet.size()];
	for(unsigned int i = 0; i < vertexSet.size(); i++)
	{
		W[i] = new int[vertexSet.size()];
		P[i] = new int[vertexSet.size()];
		for(unsigned int j = 0; j < vertexSet.size(); j++)
		{
			W[i][j] = edgeCost(i,j);
			P[i][j] = -1;
		}
	}

	for(unsigned int k = 0; k < vertexSet.size(); k++)
		for(unsigned int i = 0; i < vertexSet.size(); i++)
			for(unsigned int j = 0; j < vertexSet.size(); j++)
			{
				//se somarmos qualquer coisa ao valor INT_INFINITY, ocorre overflow, o que resulta num valor negativo, logo nem convém considerar essa soma
				if(W[i][k] == INT_INFINITY || W[k][j] == INT_INFINITY)
					continue;

				int val = min ( W[i][j], W[i][k]+W[k][j] );
				if(val != W[i][j])
				{
					W[i][j] = val;
					P[i][j] = k;
				}
			}

}






#endif /* GRAPH_H_ */
