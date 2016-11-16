///////////////////////////////////////////////////////////
//  CommandeTranfertLiqReservBouil.cpp
//  Implementation of the Class CommandeTranfertLiqReservBouil
//  Created on:      15-nov.-2016
//  Original author: francois
///////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>

#include "CommandeTransfertLiqReservBouil.h"

void CommandeTransfertLiqReservBouil::VisiteurTransfertLiqReservBouil::traiterReservoir(Reservoir * _reserv)
{
	// Verifier s'il y a suffisamment de liquide dans le reservoire
	// Si oui, reduire le niveau du reservoir d'une quantite equivalente au volume transfere
	// A completer
	if (_reserv->getNiveau() >= m_volume)
		_reserv->setNiveau(_reserv->getNiveau() - m_volume);
	else
		throw std::range_error("Erreur d'operation: le réservoir est vide");
}

void CommandeTransfertLiqReservBouil::VisiteurTransfertLiqReservBouil::traiterPompe(Pompe * _pomp)
{
	// Operer la pompe pour une duree correspondant au temps necessaire pour transferer le volume de liquide
	// La duree d'operation est le volume a transferer divise par le debit de la pompe
	// A completer
	_pomp->operer(_pomp->volumeLiquide / _pomp->getDebit());
}

void CommandeTransfertLiqReservBouil::VisiteurTransfertLiqReservBouil::traiterBouilloire(Bouilloire * _bouil)
{
	// Verifier si le volume restant de la bouilloire peut contenir la quantite de liquide transferee
	// Si oui, augmenter le niveau de la bouilloire d'une quantite equivalente au volume transfere
	// A completer
	float vol = _bouil->getVolume();
	if (_bouil->getVolume() >= _bouil->getNiveau() + m_volume)
		_bouil->setNiveau(_bouil->getNiveau() + m_volume);
	else
		throw std::range_error("Erreur d'operation: la bouillore est trop pleine");
}
