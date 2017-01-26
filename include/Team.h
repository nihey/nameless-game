#ifndef TEAM_H
#define	TEAM_H


#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>

#include "Player.h"

enum Color{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    WHITE
};

using namespace std;

class Team {
  private:
    string mName;
    Color mColor;
    int mWin;
    int mLose;
    int mDraw;
    vector<Player *> mPlayers;

  public:
    /**
     * @brief Sets a name and a color to the team. Sets Win, Lose and Draw to 0. Allocates space to the vector mPlayers;
     *
     * @param pName Name to be set to the team
     * @param pColor Color to be set to the team
     */
    Team(string, Color);

    /**
     * Destroys this
     *
     */

    virtual ~Team();

    /**
     * @return Team's name
     */
    string getName();

    /**
     * @return Team's color
     */
    Color getColor();

    /**
     * @param index of the Player
     * @return Team's Player
     */
    Player* getPlayer(int);

    /**
     * @return Returns a string with Win, Lose and Draw
     *
     */
    string getResults();

    /**
     * @brief ...
     *
     */
    void victory();

    /**
     * @brief ...
     *
     */
    void draw();

    /**
     * @brief ...
     *
     */
    void defeat();

    /**
     * @brief adds a Player to the team
     *
     * @param pPlayer the Player to be added
     */
    void addPlayer(Player*);

    /**
     * @return Begin Iterator
     */

    vector<Player *>::iterator begin();

    /**
     * @return End Iterator
     */

    vector<Player *>::iterator end();

    /**
     * Search a Player by his Alias
     *
     * @param pAlias Alias to search the Player for
     * @return found Player
     */

    Player* searchChar(string pAlias);
};

#endif
