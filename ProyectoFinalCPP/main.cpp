
#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"


using namespace std;
// 1 Jugador



int main()
{
    GameMap Map;
    Player Hero;

    Map.DrawIntro();
    Map.Draw();

    //cout<<"Inicia el juego!!"<< endl;
    while(Map.isGameOver == false){
         //Aquí es el loop de nuestro juego
         cout<<"Introduce el comando de movimiento 'w' 'a' 's''d':"<<endl;
         Hero.CallInput();

         //Actualizado de información heroe a Mapa
         if(Map.SetPlayerCell(Hero.x,Hero.y))
         {
             Map.Draw();
         }
         else{
             Hero.ResetToSafePosition();
             Map.Draw();
         }
         //Aqui Dibujamos elmapa
         Map.Draw();

    }

    return 0;
}
