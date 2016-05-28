/*
 * Camiao.h
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#ifndef CAMIAO_H_
#define CAMIAO_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "Item.h"

using namespace std;
/**
 * Class Camiao
 */
class Camiao
{
	public:
	/**
	 * Construtor da Classe
	 *
	 * \param capacidadePeso Capacidade do camiao
	 *
	 */
	 Camiao(int capacidadePeso);
	 /**
	  * Vector dos items contidos no camiao;
	  */
	 vector <Item* > items;
	 /**
	  * Retorna o peso atual dentro do camiao;
	  */
	 int getPeso();
	 /**
	  * Retorna o id do camiao;
	  */
	 int getId();
	 /**
	  * Muda o id do camiao para id;
	  *
	  * \param id id dado;
	  */
	 void setId(int id);
	 /**
	  * Retorna o vector de items
	  */
	 vector <Item* > getItems(){return items;}
	 /**
	  * Capacidade do Camiao
	  */
	 int capacidade_peso;
	 private:
	 /**
	  * Id do Camiao
	  */
	 int id;
};

#endif /* CAMIAO_H_ */
