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
}

void CircuitSolComposite::addSousElement(ElmCircuitSolide* sousElem){
	addSousElement((ElmCircuitSolPtr)sousElem);
}

float CircuitSolComposite::getDebris(void) const {
	// Recuperer la quantite de debris maximum parmi tous les enfants
	float debrisMax = 0;
	for (auto i = m_CircuitSolide.begin(); i != m_CircuitSolide.end(); i++) {
		float debris = (*i)->getDebris();
		if (debris > debrisMax)
			debrisMax = debris;
	}
	return debrisMax;
}

void CircuitSolComposite::operer( float duree ){
	if (duree <= 0.0)
		return;

	for (auto i = m_CircuitSolide.begin(); i != m_CircuitSolide.end(); i++) {
		(*i)->operer(duree);
	}
}

void CircuitSolComposite::nettoyer(){
	m_CircuitSolide.clear();
}


