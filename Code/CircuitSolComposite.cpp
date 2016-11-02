///////////////////////////////////////////////////////////
//  CircuitSolComposite.cpp
//  Implementation of the Class CircuitSolComposite
//  Created on:      27-oct.-2016 15:12:34
//  Original author: francois
///////////////////////////////////////////////////////////

#include <stdexcept>

#include "CircuitSolComposite.h"


CircuitSolComposite::CircuitSolComposite(){

}



CircuitSolComposite::~CircuitSolComposite(){

}


CircuitSolComposite::ElmCircuitSolPtr CircuitSolComposite::getSousElement(size_t index){
	if (index < 0 || index > m_CircuitSolide.size() - 1)
		return nullptr;
	return m_CircuitSolide[index];
	//TODO: Voir si possible d'appeler l'autre fonction pareille mais const?
}

const CircuitSolComposite::ElmCircuitSolPtr CircuitSolComposite::getSousElement(size_t index) const {
	if (index < 0 || index > m_CircuitSolide.size() - 1)
		return nullptr;
	return m_CircuitSolide[index];
}

int CircuitSolComposite::nombreSousElements() const {
	return m_CircuitSolide.size();
}


void CircuitSolComposite::addSousElement(const ElmCircuitSolPtr& sousElem){
	m_CircuitSolide.push_back(sousElem);
	//TODO: Voir si possible d'appeler l'autre fonction pareille mais const?
}

void CircuitSolComposite::addSousElement(ElmCircuitSolide* sousElem){
	int i = 0;
	//m_CircuitSolide.push_back(sousElem);
}

float CircuitSolComposite::getDebris(void) const {
	// Recuperer la quantite de debris maximum parmi tous les enfants
	float debrisMax = 0;
	return debrisMax;
}

void CircuitSolComposite::operer( float duree ){
}

void CircuitSolComposite::nettoyer(){
}


