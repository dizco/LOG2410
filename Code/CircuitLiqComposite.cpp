///////////////////////////////////////////////////////////
//  CircuitLiqComposite.cpp
//  Implementation of the Class CircuitLiqComposite
//  Created on:      27-oct.-2016 15:19:51
//  Original author: francois
///////////////////////////////////////////////////////////

#include <stdexcept>

#include "CircuitLiqComposite.h"


CircuitLiqComposite::CircuitLiqComposite(){

}

CircuitLiqComposite::~CircuitLiqComposite(){

}

ElmCircuitLiquide::ElmCircuitLiqPtr CircuitLiqComposite::getSousElement( size_t index ){
	return  nullptr;
}

const ElmCircuitLiquide::ElmCircuitLiqPtr CircuitLiqComposite::getSousElement(size_t index) const {
	return  nullptr;
}

int CircuitLiqComposite::nombreSousElements() const {

	return 0;
}

void CircuitLiqComposite::addSousElement(const ElmCircuitLiqPtr& sousElm){
}


void CircuitLiqComposite::addSousElement(ElmCircuitLiquide* sousElm){
}

float CircuitLiqComposite::getTartre(void) const {
	// Recuperer la quantite de tartre maximum parmi tous les enfants
	float tartreMax = 0;
	return tartreMax;
}

void CircuitLiqComposite::operer(float duree){
}

void CircuitLiqComposite::nettoyer(){
}


