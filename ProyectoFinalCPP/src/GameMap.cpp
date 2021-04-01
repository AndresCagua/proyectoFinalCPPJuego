#include "GameMap.h"
#include <iostream>
#include <fstream>
using namespace std;

GameMap::GameMap()
{
    //ctor
    PlayerCell = NULL;
    LoadMapFromFile();
    isGameOver = false;
}

void GameMap::Draw(){
  for(int i=0;i<15;i++){

    for(int p=0;p<10;p++)
    {
    cout<<cells[i][p].id;

    }
    cout<<endl;
  }

}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    if(cells[PlayerY][PlayerX].IsBlocked()==false)
    {
        if(cells[PlayerY][PlayerX].id=='$')
        {
            DrawVictory();
            isGameOver=true;
            return true;
        }
        else{

              if(PlayerCell !=NULL)
    {
        PlayerCell->id=0; //PlayerCell->id='0';

    }
        PlayerCell =&cells[PlayerY][PlayerX];
        PlayerCell->id=3;//layerCell->id='3';
        }


        return true;
    }
    else
    {
        return false;
    }

    //cout<< "Las coordenadas del jugador estan en:"<<PlayerX<<","<<PlayerY;
}
void GameMap::DrawIntro()
{
    string line;
   ifstream MyFile("Intro.txt");

   if(MyFile.is_open())
   {
       //cout<<"prueba de dibujado: "<< endl;
       while(getline(MyFile,line))
       {
           cout<<line <<endl;
       }
       cin >> line;
   }
   else{
    cout<<"FATAL ERROR: INTRO COULD NOT BE LOADED!"<<endl;
   }
}
void GameMap::DrawVictory()
{
    string line;
   ifstream MyFile("Victory.txt");

   if(MyFile.is_open())
   {
       //cout<<"prueba de dibujado: "<< endl;
       while(getline(MyFile,line))
       {
           cout<<line <<endl;
       }
       cin >> line;
   }
   else{
    cout<<"FATAL ERROR: VICTORY COULD NOT BE LOADED!"<<endl;
   }
}
void GameMap::LoadMapFromFile()
{
   /*ofstream FileCreated("Map.txt");
   if(FileCreated.is_open())
   {

   }
   else{
    cout<<"FATAL ERROR: MAP FILE COULD NOT BE CREATED!"<< endl;
   }*/

   string line;
   int row=0;
   ifstream MyFile("Map.txt");

   if(MyFile.is_open())
   {
       //cout<<"prueba de dibujado: "<< endl;
       while(getline(MyFile,line))
       {
           for(int p=0; p<line.length();p++)
           {
               if(line[p]=='0')
               cells[row][p].id=0;
               else{
                cells[row][p].id=line[p];
               }
           }
           row++;
       }
       //cout<<"final prueba de dibujado: "<<endl;
   }
   else{
    cout<<"FATAL ERROR: MAP FILE COULD NOT BE LOADED!"<<endl;
   }

}
