/*
 * Auteur:		Étienne Ménard
 * Date:		23/09/2020
 * Fichier:		camouflage.h
 * Description:	Déclare les méthodes qui run le jeu Camouflage
 */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "vecteur.hpp"
#include "map.hpp"
#include "pieces.h"
using namespace std;

class camouflage
{
	private:
		map<char> _mapPlanche;
		map<char> _mapSolution;
		// vecteur<pieces> pieces;

	public:
		void init();												// initialise les composants du jeu
		bool findSolution(int indexPiece = 0);						//le brut force récursif
		bool verifPiece(int pieceAnalysee, int ligne, int col);		//vérifie si la position de la pièce peut correspondre

		void putPiece(int indexPiece, int indLine, int indCol);		//place la pièce dans la solution à l’index 
																	//line et col reçu
		void removePiece(int indexPiece, int indLine, int indCol);	//retire la pièce dans la solution à l’index

		void readFile();

};