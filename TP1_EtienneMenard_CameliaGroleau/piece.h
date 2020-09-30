/*
 * Auteur:		Cam�lia Groleau
 * Date:		23/09/2020
 * Fichier:		piece.h
 * Description:	Classe permettant de stocker les valeurs et m�thodes reli�es aux pi�ces du jeu Camouflage
 */
#pragma once

struct casePiece		//Correspond � une partie de la pi�ce
{
	char _valeurPiece;	//Stocke la valeur de la partie de la pi�ce
	bool _vide;			//Stocke si la partie fait partie de la pi�ce
};

class piece
{
private:
	casePiece _partiesPiece[2][2];		//Stocke les donn�es des
										//parties de la piece
	char _nomPiece;						//Stocke la lettre
										//repr�sentant le nom de la
										//pi�ce
public:
	piece();																				//Constructeur vide
	piece(char nomPiece, char hautGauche, char hautDroite, char basGauche, char basDroite);	//Constructeur utilis�
																							//habituellement
	~piece();																				//Destructeur de la classe

	char name();						//Retourne la lettre de nom

	casePiece at(int x, int y);			//Retourne la casePiece �
										//la position voulue
	bool emptyAt(int x, int y);			//Retourne si la position
										//voulue est vide
	char valueAt(int x, int y);			//Retourne la valeur � la
										//position voulue

	void rotateClockwise();				//Pivote les valeurs comme
										//lors d'une rotation
										//horaire
	void rotateCounterClockwise();		//Pivote les valeurs comme
										//lors d'une rotation
										//anti-horaire
};