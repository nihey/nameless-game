#ifndef BOARD_H
#define	BOARD_H

#include <map>
#include <set>
#include <string>
#include <cstdlib>

#include "Team.h"
#include "BoardPosition.h"

using namespace std;

class Board {

    private:

        map<int, Team *> mTeams;
        int mHeight;
        int mWidth;
        set<BoardPosition *> mPositions;

    public:
       /**
        * @brief Sets height and width as 5 and allocate *mTeams
        *
        */
	Board();

       /**
        * @brief Sets height and width
        *
        * @param pHeight Height to be set to de Board
        * @param pWidth Width to be set to de Board
        */
	Board(int, int);

	/**
         * Destroys this
         *
         */
        virtual ~Board();

	/**
	 * @brief adds a Team to the vector
	 *
	 * @param pTeam Team to be added
         * @param pColor Team's color
	 */
	void addTeam(Color, Team*);

	/**
	 * @brief remove a Team from the vector mTeams
	 *
 	 * @param pTeam Team to be removed
	 */

	void removeTeam (Team*);

	/**
	 * @brief remove a Team from the vector mTeams
	 *
	 * @param pColor Color of the Team that is going to be removed
	 */
	void removeTeam (Color);

	/**
	 * @brief set the position of a character
	 *
	 * @param pX the X coordinate
	 * @param pY the Y coordinate
	 * @param pChar Character alias to be added
	 *
	 */

        // Mudança do tipo int para string -> faz mais sentido inserir o personagem de uma só vez

	void setCharPos(int pX, int pY, Character* pChar);

        /**
         * Get Character position on the board
         *
         * @param pAlias Character Alias
         * @return Character position, or NULL if not found.
         */

        Coordinate2D *getCharPos(string pAlias);
};

#endif
