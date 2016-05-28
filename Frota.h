/*
 * Frota.h
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#ifndef FROTA_H_
#define FROTA_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "Camiao.h"
using namespace std;
/**
 * Classe Frota;
 */
class Frota
{
	private:
		/**
		 * Numero de Camioes na frota
		 */
		int numeroCamioes=0;
	public:
		/**
		 * Vector com os camioes pertencentes á frota;
		 */
		vector<Camiao *> frota;
		/**
		 * Retorna o Vector com os camioes pertencentes á frota;
		 */
		vector<Camiao *> getFrota();
		/**
		 * Adiciona um camiao a frota;
		 *
		 * \param camiao camiao a adicionar
		 */
		void addCamiao(Camiao* camiao );
		/**
		 * Adiciona um camiao a frota;
		 *
		 * \param peso do camiao a adicionar
		 */
		void addCamiao(int peso );
		/**
		 * Cria uma frota com o vector frota igual ao parametro frota
		 *
		 * \param frota vector de camioes
		 */
		Frota(vector<Camiao *> frota);
		Frota(){};

};



#endif /* FROTA_H_ */
