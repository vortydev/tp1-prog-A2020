/*
 * Auteur:		�tienne M�nard
 * Date:		23/09/2020
 * Fichier:		camouflage.h
 * Description:	D�clare les m�thodes qui run le jeu Camouflage
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
		bool findSolution(int indexPiece = 0);						//le brut force r�cursif
		bool verifPiece(int pieceAnalysee, int ligne, int col);		//v�rifie si la position de la pi�ce peut correspondre

		void putPiece(int indexPiece, int indLine, int indCol);		//place la pi�ce dans la solution � l�index 
																	//line et col re�u
		void removePiece(int indexPiece, int indLine, int indCol);	//retire la pi�ce dans la solution � l�index

		void readFile();

};