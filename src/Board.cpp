#include "Board.h"

/**
 * File: Team.cpp
 * Author: Nihey and Hiroki
 *
 * Created on May 4, 2012, (may the 4th be with you)
 */

Board::Board() {
    mHeight = 5;
    mWidth = 5;
	
}

Board::Board(int pHeight, int pWidth) {
    mHeight = pHeight;
    mWidth = pWidth;
	
}

Board::~Board() {


    for(map<int, Team*>::iterator it = mTeams.begin(); it != mTeams.end() ; it++) {
        delete (*it).second;
    }
    mTeams.clear();

    for(set<BoardPosition *>::iterator it = mPositions.begin(); it != mPositions.end(); it++){

        delete *it;
    }
    mPositions.clear();

}

void Board::addTeam(Color pColor, Team *pTeam) {
    mTeams.insert(pair<int, Team*>(pColor, pTeam));
}

void Board::removeTeam (Team *pTeam) {

    delete mTeams[pTeam->getColor()];
    mTeams.erase(pTeam->getColor());

}

void Board::removeTeam (Color pColor) {

    delete mTeams[pColor];
    mTeams.erase(pColor);
}

void Board::setCharPos(int pX, int pY, Character* pChar) {

    mPositions.insert(new BoardPosition(pChar, pX, pY));
}

Coordinate2D *Board::getCharPos(string pAlias){

    for(set<BoardPosition *>::iterator it = mPositions.begin(); it != mPositions.end(); it++){

        if((*it)->getOccup()->getName().compare(pAlias) == 0){

            return (*it)->getPosition();
        }
    }
}