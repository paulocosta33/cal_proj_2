/*
 * Item.cpp
 *
 *  Created on: 19/04/2016
 *      Author: up201404022
 */
#include "Item.h"

using namespace std;

Item::Item(string nome,string propriet, int valor, int peso, string destino, int fatura)
{
	this->valor=valor;
	this->dest=destino;
	this->nome=nome;
	this->peso=peso;
	this->fatura=fatura;
	this->propriet=propriet;
}

string Item::getNome(){return nome;}
double Item::getValor(){return valor;}
string Item::getDest(){return dest;}
int Item::getFatura(){return fatura;}
int Item::getPeso(){return peso;}
string Item::getProp(){return propriet;}

