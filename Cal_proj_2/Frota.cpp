/*
 * Frota.cpp
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */
#include "Frota.h"
using namespace std;

Frota::Frota(vector<Camiao *> f)
{
	numeroCamioes =0;
	frota = f;
}

void Frota::addCamiao(Camiao* camiao)
	{

		numeroCamioes++;
		camiao->setId(numeroCamioes);
		frota.push_back(camiao);
	}
void Frota::addCamiao(int peso)
	{
		Camiao camiao(peso);
		camiao.setId(frota.size()+1);
		frota.push_back(&camiao);

	}
vector<Camiao *> Frota::getFrota()
{
	return frota;
}
