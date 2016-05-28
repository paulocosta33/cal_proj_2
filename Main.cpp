//============================================================================
// Name        : cal_proj.cpp
// Author      : paulo costa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Graph.h"
#include "Frota.h"
#include <stdio.h>
#include <iostream>
#include "Mapa.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include "menu.h"
using namespace std;

double dist_calc(double long1,double lat1,double long2, double lat2){
	double dlong = long2 - long1;
	double dlat = lat2 - lat1;
	double res;
	res = sqrt((double)dlong*dlong + dlat*dlat);
	return res;
}

static bool sort_lesser_than(double u, double v)
{
   return u < v;
}

vector<string> orderMP(string node_ss, vector<string> mustp,Graph<string>* g){
	vector<string> mp_order;
	double d1,d2,d3,d4;
	int s_tag;
	vector<double> mp_distini;
	vector<double> mp_distini_ordered;
	vector<int> indice;
	for(unsigned int u =0; u < g->vertexSet.size();u++)
	{
		if(g->vertexSet[u]->info == node_ss) s_tag = u;
	}
	for(unsigned int y= 0;y < mustp.size(); y++)
	{
		for(unsigned int x =0; x < g->vertexSet.size();x++)
		{
			if(mustp[y].compare(g->vertexSet[x]->info)==0)
			{
				d1 = g->vertexSet[s_tag]->longitude;
				d2 = g->vertexSet[s_tag]->latitude;
				d3 = g->vertexSet[x]->longitude;
				d4 = g->vertexSet[x]->latitude;
				//distancia de cada mustpasspoint ao inicio
				mp_distini.push_back(dist_calc(d1,d2,d3,d4));
			}
		}
	}

	mp_distini_ordered = mp_distini;
	sort(mp_distini_ordered.begin(),mp_distini_ordered.end(),sort_lesser_than);

	for(unsigned int i =0; i<mp_distini.size();i++)
	{
		for(unsigned int j=0; j<mp_distini_ordered.size();j++)
		{
			if (mp_distini[i]==mp_distini_ordered[j])
			{
				indice.push_back(j);
			}
		}
	}

	for(unsigned int z=0; z<mp_order.size();z++)
	{
		mp_order[z] = mustp[indice[z]];
	}
	return mp_order;
}


template <typename T>
string NumberToString ( T Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}


int main() {

Menu* menu= new Menu;
menu->menu1();

}


