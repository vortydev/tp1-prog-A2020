/*
 * Auteur:		�tienne M�nard
 * Date:		23/09/2020
 * Fichier:		camouflage.cpp
 * Description:	D�clare les m�thodes qui run le jeu Camouflage
 */

#include "camouflage.h"

//fonction d'ouverture du ficher contenant la matrice
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

void camouflage::init() {
    readFile();
}


bool camouflage::solutionRecursive(int nbPiece)
{
    if (nbPiece == 6)
        return true;
    for (int ligne = 0; ligne < 3; ligne++)
    {
        for (int col = 0; col < 3; col++)
        {
            for (int rotation = 0; rotation < 4; rotation++)
            {
                if (pieceBienPlacee(nbPiece, ligne, col))
                {
                    nbPiece++;
                    if (solutionRecursive(nbPiece))
                    {
                        return true;
                    }
                    removePiece(nbPiece, ligne, col);
                }
            }
        }
    }
    return false;
}

bool camouflage::pieceBienPlacee(int pieceAnalysee, int ligne, int col)
{
    for (int xPos = 0; xPos < 2; xPos++)
    {
        for (int yPos = 0; yPos < 2; yPos++)
        {
            if (!pieces[pieceAnalysee].emptyAt(xPos, yPos))
            {
                if ((((pieces[pieceAnalysee].valueAt(xPos, yPos) == 'O') && (_mapPlanche.at(ligne + xPos, col + yPos) != 'B')) || ((pieces[pieceAnalysee].valueAt(xPos, yPos) == 'P') && (_mapPlanche.at(ligne + xPos, col + yPos) != 'E'))) && (_mapSolution.at(ligne + xPos, col + yPos) != '\0'))
                {
                    return false;
                }
            }
        }
    }
    putPiece(pieceAnalysee, ligne, col);
    return true;
}
