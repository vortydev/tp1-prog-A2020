#include "piece.h"

piece::piece(char nomPiece, char hautGauche, char hautDroite, char basGauche, char basDroite)
{
	_nomPiece = nomPiece;

	_partiesPiece[0][0]._vide = (hautGauche == '\0');
	_partiesPiece[0][1]._vide = (hautDroite == '\0');
	_partiesPiece[1][0]._vide = (basGauche == '\0');
	_partiesPiece[1][1]._vide = (basDroite == '\0');
	_partiesPiece[0][0]._valeurPiece = hautGauche;
	_partiesPiece[0][1]._valeurPiece = hautDroite;
	_partiesPiece[1][0]._valeurPiece = basGauche;
	_partiesPiece[1][1]._valeurPiece = basDroite;
}

piece::~piece()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			_partiesPiece[i][j]._vide = false;
			_partiesPiece[i][j]._valeurPiece = '\0';
		}
}

char piece::name()
{
	return _nomPiece;
}

casePiece piece::at(int x, int y)
{
	return _partiesPiece[x][y];
}

bool piece::emptyAt(int x, int y)
{
	return _partiesPiece[x][y]._vide;
}

char piece::valueAt(int x, int y)
{
	return _partiesPiece[x][y]._valeurPiece;
}

void piece::rotateClockwise()
{
	casePiece tempBuffer = _partiesPiece[0][0];
	_partiesPiece[0][0] = _partiesPiece[1][0];
	_partiesPiece[1][0] = _partiesPiece[1][1];
	_partiesPiece[1][1] = _partiesPiece[0][1];
	_partiesPiece[0][1] = tempBuffer;
}
void piece::rotateCounterClockwise()
{
	casePiece tempBuffer = _partiesPiece[0][0];
	_partiesPiece[0][0] = _partiesPiece[0][1];
	_partiesPiece[0][1] = _partiesPiece[1][1];
	_partiesPiece[1][1] = _partiesPiece[1][0];
	_partiesPiece[1][0] = tempBuffer;
}