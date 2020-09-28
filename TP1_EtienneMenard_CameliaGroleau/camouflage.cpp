/*
 * Auteur:		Étienne Ménard
 * Date:		23/09/2020
 * Fichier:		camouflage.cpp
 * Description:	Déclare les méthodes qui run le jeu Camouflage
 */

#include "camouflage.h"

//fonction d'ouverture du ficher contenant la matrice

void camouflage::init() {
    readFile();
    _pieces[0] = piece('U', ' ', 'P', 'O', '\0');
    _pieces[1] = piece('V', 'P', ' ', 'O', '\0');
    _pieces[2] = piece('W', ' ', 'O', 'P', '\0');
    _pieces[3] = piece('X', 'P', 'P', '\0', '\0');
    _pieces[4] = piece('Y', 'P', 'O', '\0', '\0');
    _pieces[5] = piece('Z', ' ', '\0', 'O', ' ');
}

bool camouflage::findSolution(int indexPiece)
{
    if (indexPiece == 6)
        return true;
    for (int ligne = 0; ligne < 3; ligne++)
    {
        for (int col = 0; col < 3; col++)
        {
            for (int rotation = 0; rotation < 4; rotation++)
            {
                if (verifPiece(indexPiece, ligne, col))
                {
                    indexPiece++;
                    if (findSolution(indexPiece))
                    {
                        return true;
                    }
                    removePiece(indexPiece, ligne, col);
                }
            }
        }
    }
    return false;
}

bool camouflage::verifPiece(int indexPiece, int ligne, int col)
{
    for (int xPos = 0; xPos < 2; xPos++)
    {
        for (int yPos = 0; yPos < 2; yPos++)
        {
            if (!_pieces[indexPiece].emptyAt(xPos, yPos))
            {
                if ((((_pieces[indexPiece].valueAt(xPos, yPos) == 'O') && (_mapPlanche.at(ligne + xPos, col + yPos) != 'B')) || ((_pieces[indexPiece].valueAt(xPos, yPos) == 'P') && (_mapPlanche.at(ligne + xPos, col + yPos) != 'E'))) && (_mapSolution.at(ligne + xPos, col + yPos)[0] != '\0'))
                {
                    return false;
                }
            }
        }
    }
    putPiece(indexPiece, ligne, col);
    return true;
}

void camouflage::putPiece(int indexPiece, int indLine, int indCol)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            _mapSolution[i + indLine][j + indCol][0] = _pieces[indexPiece].name();
            _mapSolution[i + indLine][j + indCol][1] = _pieces[indexPiece].valueAt(i, j);
        }
    }
}

void camouflage::removePiece(int indexPiece, int indLine, int indCol)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int pos = 0; pos < 2; pos++)
                _mapSolution[i + indLine][j + indCol][pos] = '\0';
        }
    }

}

void camouflage::readFile() {
    string userInput;
    string plancheFileName;
    string solutionFileName;
    bool isValid = false;

    do {
        cout << "Entrer la map a solutionner (ex: Expert25) : ";
        cin >> userInput;
        ifstream file("map" + userInput + ".txt");
        if (file.is_open()) {
            isValid = true;
            file.close();
        }   
    } while (!isValid);

    plancheFileName = "map" + userInput + ".txt";
    solutionFileName = "map" + userInput + ".txt";

    ifstream plancheFile(plancheFileName); //ouverture du ficher
    int nbLine, nbCol;
    if (plancheFile.is_open())
    {
        _mapPlanche.setName(userInput.c_str());
        plancheFile >> nbLine >> nbCol;
        _mapPlanche.resize(nbLine, nbCol);
        plancheFile >> _mapPlanche; //lecture de la matrice
        plancheFile.close();
    }
    else
        cout << "Fichier : " << plancheFileName << " innexistant";

    ifstream solutionFile(solutionFileName); //ouverture du ficher
    if (solutionFile.is_open())
    {

        _mapSolution.setName(solutionFileName.c_str());
        _mapSolution.resize(nbLine, nbCol);
        /*for (int i = 0; i < 7; i++) {
            getline(solutionFile, line);
        }*/
        solutionFile >> _mapPlanche; //lecture de la matrice
        solutionFile.close();
    }
    else
        cout << "Fichier : " << solutionFileName << " innexistant";

    cout << "Contenu original de la planche du fichier: " << endl << _mapPlanche << endl;
    cout << "Contenu de la planche de solution:" << endl << _mapSolution << endl;
}

void camouflage::printFile() {
    string solutionFileName = _mapPlanche.getName();
    ofstream solutionFile("solution" + solutionFileName + ".txt");

    solutionFile << "Pour la map suivante:" << endl;
    solutionFile << _mapPlanche << endl;
    solutionFile << "Une solution a été trouvee:" << endl;
    solutionFile << _Syserror_map << endl;
}