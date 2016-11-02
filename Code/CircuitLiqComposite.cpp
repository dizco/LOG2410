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
	if (index < 0 || index > m_CircuitLiquide.size() - 1)
		return nullptr;
	return m_CircuitLiquide[index];
}

const ElmCircuitLiquide::ElmCircuitLiqPtr CircuitLiqComposite::getSousElement(size_t index) const {
	if (index < 0 || index > m_CircuitLiquide.size() - 1)
		return nullptr;
	return m_CircuitLiquide[index];
}

int CircuitLiqComposite::nombreSousElements() const {
	return m_CircuitLiquide.size();
}

void CircuitLiqComposite::addSousElement(const ElmCircuitLiqPtr& sousElm){
	m_CircuitLiquide.push_back(sousElm);
}


void CircuitLiqComposite::addSousElement(ElmCircuitLiquide* sousElm){
	addSousElement((ElmCircuitLiqPtr)sousElm);
}

float CircuitLiqComposite::getTartre(void) const {
	// Recuperer la quantite de tartre maximum parmi tous les enfants
	float tartreMax = 0;
	for (auto i = m_CircuitLiquide.begin(); i != m_CircuitLiquide.end(); i++) {
		float tartre = (*i)->getTartre();
		if (tartre > tartreMax)
			tartreMax = tartre;
	}
	return tartreMax;
}

void CircuitLiqComposite::operer(float duree){
	if (duree <= 0.0)
		return;
	for (auto i = m_CircuitLiquide.begin(); i != m_CircuitLiquide.end(); i++) {
		(*i)->operer(duree);
	}
}

void CircuitLiqComposite::nettoyer(){
	m_CircuitLiquide.clear();
}


