/*
 * Auteur.e.s:	Étienne Ménard et Camélia Groleau
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
#include "piece.h"
using namespace std;

class camouflage
{
	private:
		map<char> _mapPlanche;										//stocke la planche de jeu
		map<string> _mapSolution;									//stocke la solution
		vecteur<piece> _pieces = vecteur<piece>(6);					//stocke les pièces

	public:
		void init();												//initialise les composants du jeu
		bool findSolution(int indexPiece = 0);						//le brut force récursif
		bool verifPiece(int indexPiece, int ligne, int col);		//vérifie si la position de la pièce peut correspondre

		void putPiece(int indexPiece, int indLine, int indCol);		//place la pièce dans la solution à l’index 
																	//line et col reçu
		void removePiece(int indexPiece, int indLine, int indCol);	//retire la pièce dans la solution à l’index

		void readFile();											// lis du fichier entré pour loader la mapPlanche
		void printFile();											// print dans un fichier la mapPlanche et la mapSolution
};