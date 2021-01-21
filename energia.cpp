#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h> 
#include <cmath>
#include <vector>
#include <fstream>
#include "energia.h"
using namespace std;

float energia(){

float ei, ee, es;

cout << "Energía inicial: ";
cin >> ei;

float ht = hd*d;
cout << "Horas totales: " << ht << "\n";

cout << "Al ingresar energías entrantes y salientes, considerar lo siguiente: \n";
cout << "-----------------------------------\n";
cout << "|Rango horario|Día correspondiente|\n";
cout << "-----------------------------------\n";
cout << "|     1-8     |       Día 1       |\n";
cout << "-----------------------------------\n";
cout << "|     8-16    |       Día 2       |\n";
cout << "-----------------------------------\n";
cout << "|    16-24    |       Día 3       |\n";
cout << "-----------------------------------\n";
cout << "|    24-32    |       Día 4       |\n";
cout << "-----------------------------------\n";
cout << "|    32-40    |       Día 5       |\n";
cout << "-----------------------------------\n";

for(int i=0;i<ht;i++){
  cout << "Energía entrante hora " << i+1 << ": " ;
  cin >> ee;

  cout << "Energía saliente hora " << i+1 << ": " ;
  cin >> es; 

  int cp;
  cout << "Checkpoint (S=1 N=0): ";
  cin >> cp;
  if(cp == 1){
    es = es/2;
  }

  float e = e + ei + ee - es;
  if(i<=8){
  cout << "Energía hora " << i+1 << " día 1: " << e << "\n";
  }
  if(i>8 && i<=16){
  float cd2 = 100;
  e = e + cd2;
  cout << "Energía hora " << i-7 << " día 2: " << e << "\n";
  cd2 = 0;
  }
  if(i>16 && i<=24){
  float cd3 = 120;
  e = e + cd3;
  cout << "Energía hora " << i-15 << " día 3: " << e << "\n";
  cd3 = 0;
  }
  if(i>24 && i<=32){
  float cd4 = 210;
  e = e + cd4;
  cout << "Energía hora " << i-23 << " día 4: " << e << "\n";
  cd4 = 0;
  }
  if(i>32 && i<=40){
  float cd5 = 300;
  e = e + cd5;
  cout << "Energía hora " << i-31 << " día 5: " << e << "\n";
  cd5 = 0;
  }
  ei = 0;
}

}

