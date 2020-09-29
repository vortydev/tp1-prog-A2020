/*
 * Auteur.e.s:	�tienne M�nard et Cam�lia Groleau
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
#include "piece.h"
using namespace std;

class camouflage
{
	private:
		map<char> _mapPlanche;										//stocke la planche de jeu
		map<string> _mapSolution;									//stocke la solution
		vecteur<piece> _pieces = vecteur<piece>(6);					//stocke les pi�ces

	public:
		void init();												//initialise les composants du jeu
		bool findSolution(int indexPiece = 0);						//le brut force r�cursif
		bool verifPiece(int indexPiece, int ligne, int col);		//v�rifie si la position de la pi�ce peut correspondre

		void putPiece(int indexPiece, int indLine, int indCol);		//place la pi�ce dans la solution � l�index 
																	//line et col re�u
		void removePiece(int indexPiece, int indLine, int indCol);	//retire la pi�ce dans la solution � l�index

		void readFile();											// lis du fichier entr� pour loader la mapPlanche
		void printFile();											// print dans un fichier la mapPlanche et la mapSolution
};