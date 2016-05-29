/*
 * Item.h
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */

#ifndef SRC_ITEM_H_
#define SRC_ITEM_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
using namespace std;

/**
 * Classe Item
 */
class Item
{
   public:
	/**
	 * Retorna o nome do Item;
	 */
   	string getNome();
   	/**
   	 * Retorna o valor do Item;
   	 */
   	double getValor();
   	/**
   	 * Retorna o destino do Item;
   	 */
   	string getDest();
   	string getProp();
   	/**
   	 * Retorna a fatura do Item;
   	 */
   	int getFatura();
   	/**
   	 * Retorna o peso do Item;
   	 */
  	int getPeso();
  	/**
  	 * Cria Item
  	 *
  	 *\param nome nome do Item
  	 *\param valor valor do Item
  	 *\param peso peso do Item
  	 *\param destino destino do Item
  	 *\param fatura fatura do Item
  	 *
  	 */
   	Item(string nome, string propriet, int valor, int peso, string destino, int fatura);
  /**
   * Cria Item
   */
   	Item(){
   		peso = 0;
   		fatura = 0;
   		valor = 0;
   	};
   	/**
   	 * Destino do Item
   	 */
 	string dest;
 	/**
 	 * Destino do Item em id
 	 */
 	string destinf;
 	/**
 	 * Nome do Item
 	 */
	string nome;
	string propriet;
	/**
	 * Valor do Item
	 */
   	double valor;
   	/**
   	 * Fatura do Item
   	 */
   	int fatura;
   	/**
   	 * Peso do Item
   	 */
   	int peso;
   	/**
   	 * Se esta marcado
   	 */
   	bool marcado=false;


};


#endif /* SRC_ITEM_H_ */
