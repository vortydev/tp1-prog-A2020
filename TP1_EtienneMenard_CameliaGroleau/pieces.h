#pragma once

struct casePiece
{
	char _valeurPiece;
	bool _vide;
};

class piece
{
private:
	casePiece** _partiesPiece;
	char _nomPiece;
public:
	piece(char nomPiece, char hautGauche, char hautDroite, char basGauche, char basDroite);
	~piece();
};