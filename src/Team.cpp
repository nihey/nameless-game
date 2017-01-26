#include "Team.h"

/**
 * File: Team.cpp
 * Author: Nihey and Hiroki
 *
 * Created on May 4, 2012, (may the 4th be with you)
 */
Team::Team(string pName, Color pColor) {
    mName = pName;
    mColor = pColor;
    mWin = 0;
    mLose = 0;
    mDraw = 0;
}

Team::~Team() {

    for(vector<Player *>::iterator it = begin(); it != end(); it++){

        delete (*it);
    }
}

string Team::getName() {
    return mName;
}

Color Team::getColor() {
    return mColor;
}

Player* Team::getPlayer(int i) {
    return mPlayers.at(i);
}

string Team::getResults() {
	stringstream aux;
	aux	<< "Vitorias: " << mWin << " Empates: " << mDraw << " Derrotas: " << mLose;
    return (aux.str());
}

void Team::victory() {

    mWin++;
}

void Team::draw() {

    mDraw++;
}

void Team::defeat() {

    mLose++;
}

void Team::addPlayer(Player *pPlayer) {

    for(vector<Player *>::iterator it = begin(); it != end(); it++){

        (*it)->addEntity(pPlayer);
        pPlayer->addEntity(*it);
    }

    mPlayers.push_back(pPlayer);
}

vector<Player *>::iterator Team::begin(){

    return mPlayers.begin();
}

vector<Player *>::iterator Team::end(){

    return mPlayers.end();
}