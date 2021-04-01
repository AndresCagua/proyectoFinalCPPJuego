#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "MapCell.h"

class GameMap
{
    public:
        GameMap();

        MapCell* PlayerCell;
        MapCell cells[15][10];

        void DrawIntro();
        void Draw();
        void DrawVictory();
        //Esta función obtiene las cooordenadas de player y actualiza el mapa
        bool SetPlayerCell(int PlayerX, int PlayerY);
        bool isGameOver = false;

    protected:
       void LoadMapFromFile();
    private:
};

#endif // GAMEMAP_H
