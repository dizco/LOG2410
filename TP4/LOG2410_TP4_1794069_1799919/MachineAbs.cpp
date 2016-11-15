///////////////////////////////////////////////////////////
//  MachineAbs.cpp
//  Implementation of the Class MachineAbs
//  Created on:      27-oct.-2016 15:12:15
//  Original author: francois
///////////////////////////////////////////////////////////

#include <iostream>

#include "MachineAbs.h"

MachineAbs::MachineAbs( FiltrePtr f )
: m_filtre(f)
{
}

MachineAbs::~MachineAbs(){
}

resultat_test MachineAbs::diagnostiquer(){
	// Methode servant a appeler les operations de diagnostique pour les differentes composantes de la machine

	// Diagnostiquer le filtre
	if (opDiagnostiquerFiltre() == resultat_test::echec)
		return resultat_test::echec;
	// Diagnostiquer le circuit d'eau chaude
	if (opDiagnostiquerCircuitEau() == resultat_test::echec)
		return resultat_test::echec;
	// Diagnostiquer le circuit de the
	if (opDiagnostiquerCircuitThe() == resultat_test::echec)
		return resultat_test::echec;
	// Verifier si la machine a un circuit pour le lait, et si oui, le Diagnostiquer
	if (opACircuitLait() && opDiagnostiquerCircuitLait() == resultat_test::echec)
		return resultat_test::echec;
	// Verifier si la machine a un circuit pour le sucre, et si oui, le Diagnostiquer
	if (opACircuitSucre() && opDiagnostiquerCircuitSucre() == resultat_test::echec)
		return resultat_test::echec;

	return resultat_test::succes;
}


void MachineAbs::nettoyer(){
	// Methode servant a appeler les operations de nettoyage pour les differentes composantes de la machine
	
	// Nettoyer le filtre
	opNettoyerFiltre();
	// Nettoyer le circuit d'eau chaude
	opNettoyerCircuitEau();
	// Nettoyer le circuit de the
	opNettoyerCircuitThe();
	// Verifier si la machine a un circuit pour le lait, et si oui, le nettoyer
	if (opACircuitLait())
		opNettoyerCircuitLait();
	// Verifier si la machine a un circuit pour le sucre, et si oui, le nettoyer
	if (opACircuitSucre())
		opNettoyerCircuitSucre();
}

