/*
 * Auteur:		Étienne Ménard
 * Date:		23/09/2020
 * Fichier:		camouflage.cpp
 * Description:	Déclare les méthodes qui run le jeu Camouflage
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
