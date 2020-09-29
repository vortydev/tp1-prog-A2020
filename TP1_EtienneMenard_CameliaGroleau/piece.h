#pragma once

struct casePiece
{
	char _valeurPiece;
	bool _vide;
};

class piece
{
private:
	casePiece _partiesPiece[2][2];
	char _nomPiece;
public:
	piece();
	piece(char nomPiece, char hautGauche, char hautDroite, char basGauche, char basDroite);
	~piece();

	char name();

	casePiece at(int x, int y);
	bool emptyAt(int x, int y);
	char valueAt(int x, int y);

	void rotateClockwise();
	void rotateCounterClockwise();
};