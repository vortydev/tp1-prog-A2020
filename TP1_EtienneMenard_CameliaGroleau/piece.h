/*
 * Auteur:		Camélia Groleau
 * Date:		23/09/2020
 * Fichier:		piece.h
 * Description:	Classe permettant de stocker les valeurs et méthodes reliées aux pièces du jeu Camouflage
 */
#pragma once

struct casePiece		//Correspond à une partie de la pièce
{
	char _valeurPiece;	//Stocke la valeur de la partie de la pièce
	bool _vide;			//Stocke si la partie fait partie de la pièce
};

class piece
{
private:
	casePiece _partiesPiece[2][2];		//Stocke les données des
										//parties de la piece
	char _nomPiece;						//Stocke la lettre
										//représentant le nom de la
										//pièce
public:
	piece();																				//Constructeur vide
	piece(char nomPiece, char hautGauche, char hautDroite, char basGauche, char basDroite);	//Constructeur utilisé
																							//habituellement
	~piece();																				//Destructeur de la classe

	char name();						//Retourne la lettre de nom

	casePiece at(int x, int y);			//Retourne la casePiece à
										//la position voulue
	bool emptyAt(int x, int y);			//Retourne si la position
										//voulue est vide
	char valueAt(int x, int y);			//Retourne la valeur à la
										//position voulue

	void rotateClockwise();				//Pivote les valeurs comme
										//lors d'une rotation
										//horaire
	void rotateCounterClockwise();		//Pivote les valeurs comme
										//lors d'une rotation
										//anti-horaire
};