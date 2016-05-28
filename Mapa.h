/*
 * mapa2.h
 *
 *  Created on: 23/04/2016
 *      Author: Utilizador
 */

#ifndef MAPA_H_
#define MAPA_H_


#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "Graph.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
template <class T>
class Mapa
{

public:
    Mapa(){};
    /**
     *
     *  Le os ficheiros de texto e gera o grafo;
     */
    Graph<string>* readfiles()
	{

    	Graph<string>* grafo= new Graph<string>();
    	string line;
    	string info;
        fstream file1;
        file1.open("ficheiro.txt");
    	fstream file2;
    	file2.open("ficheiro2.txt");
    	fstream file3;
    	file3.open("ficheiro3.txt");
    	double latitude;
    	double longitude;
    	int id=0;
    	while(getline(file1,line))
    	{
    		stringstream linestream(line);
    		string data;

    		getline(linestream, data,';');
    		info = data;

    		getline(linestream, data,';');
    		latitude =atof(data.c_str());

    		getline(linestream,data,';');
    		longitude =atof(data.c_str());


    		grafo->addVertex(info,latitude,longitude,id);
    		id++;
    	}
    	string vertexS;
    	string vertexD;
    	while(getline(file3,line))
    	{
    		stringstream linestream(line);
    		string data;


    		getline(linestream, data,';');
    		info = data;

    		getline(linestream, data,';');
    		vertexS =data;

    		getline(linestream,data,';');
    		vertexD =data;


    		grafo->addEdge(vertexS,vertexD,info);

    	}

    	string roadname;
    	string two_way;
    	while(getline(file2,line))
    	{
    		stringstream linestream(line);
    		string data;


    		getline(linestream, data,';');
    		info = data;

    		getline(linestream, data,';');
    		roadname = data;

    		getline(linestream,data);
    		two_way = data;

    		if (two_way=="True")
    		{
    			for (int i=0; i < grafo->vertexSet.size();i++)
    			{
    				bool para=false;
    				if (para==true)
    				{
    					break;
    				}
    				for(int j=0; j<grafo->vertexSet[i]->adj.size(); j++)
    				{
    					if(grafo->vertexSet[i]->adj[j].info==info)
    					{
    						vertexS=grafo->vertexSet[i]->adj[j].dest->info;
    						vertexD=grafo->vertexSet[i]->info;
    						grafo->addEdge(vertexS,vertexD,info);
    						grafo->addRoad(vertexS,vertexD,roadname);
    						para=true;
    						break;

    					}
    				}

    			}
    		}
    		else
    		{
    			for (int i=0; i < grafo->vertexSet.size();i++)
    			{
    				for(int j=0; j<grafo->vertexSet[i]->adj.size(); j++)
    				{
    					if(grafo->vertexSet[i]->adj[j].info==info)
    					{
    						vertexS=grafo->vertexSet[i]->info;
    						vertexD=grafo->vertexSet[i]->adj[j].dest->info;
    						grafo->addRoad(vertexS,vertexD,roadname);
    					}
    				}

    			}
    		}
    	}

    	for (int i=0; i < grafo->vertexSet.size();i++)
    	{
    		for(int j=0; j<grafo->vertexSet[i]->adj.size(); j++)
    		{
    			grafo->vertexSet[i]->adj[j].weight=sqrt(pow(grafo->vertexSet[i]->latitude - grafo->vertexSet[i]->adj[j].dest->latitude,2)+pow(grafo->vertexSet[i]->longitude - grafo->vertexSet[i]->adj[j].dest->longitude,2));
    		}
        }

    	return grafo;
	}



};






#endif /* MAPA_H_ */
