///////////////////////////////////////////////////////////
//  VisiteurCalculerPuissance.cpp
//  Implementation of the Class VisiteurCalculerPuissance
//  Created on:      15-nov.-2016
//  Original author: francois
///////////////////////////////////////////////////////////

#include "VisiteurCalculerPuissance.h"

VisiteurCalculerPuissance::VisiteurCalculerPuissance()
	: m_puissanceTotale(0.0)
{
}

void VisiteurCalculerPuissance::traiterBouilloire(Bouilloire* _bouil)
{
	// A completer
	m_puissanceTotale += _bouil->getPuissance();
}

void VisiteurCalculerPuissance::traiterPompe(Pompe * _pomp)
{
	// A completer
	m_puissanceTotale += _pomp->getPuissance();
}

void VisiteurCalculerPuissance::traiterMoteur(Moteur * _mot)
{
	// A completer
	m_puissanceTotale += _mot->getPuissance();
}
