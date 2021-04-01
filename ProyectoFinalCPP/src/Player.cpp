#include "Player.h"
#include <iostream>
using namespace std;
Player::Player()
{
    x = 1;
    y=1;
}
 void Player::CallInput(){
   char UserInput = ' ';
   //cin>> UserInput;
   UserInput=tolower(getchar());
   //userInput=tolower(UserInput);

   switch(UserInput)
   {
   case 'w':
       lastY =y;
       y=y-1;
       //cout<<"El jugador se mueve arriba"<< endl;
       break;
   case 's':
        lastY =y;
       y=y+1;
       //cout<<"El jugador se mueve abajo"<< endl;
       break;
   case 'd':
       lastX =x;
       x=x+1;
       //cout<<"El jugador se mueve derecha"<< endl;
       break;
   case 'a':
       lastX =x;
       x=x-1;
       //cout<<"El jugador se mueve izquierda"<< endl;
       break;
   }
  //cout<<"Mi jugador está en las coordenadas :"<<x<<","<<y<<endl;
 }
 void Player::ResetToSafePosition()
 {
     x=lastX;
     y=lastY;
 }
