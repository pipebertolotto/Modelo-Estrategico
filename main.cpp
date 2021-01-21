#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>
#include "funciones.h"
#include "clase.h"
#include "energia.h"




int main() {
  leer_datos();



  float vel_auto, vel_viento, altura, pendiente, tiempo ;
  
  cout << "Velocidad del auto: ";
  cin >> vel_auto;
  posiciones_carrera(vel_auto, 0,  11, 1);
  cout << punto[1973].horaPnto << endl; 
/*
  cout << "Velocidad del viento: ";
  cin >> vel_viento;

  cout << "Altura: ";
  cin >> altura;
  
  cout << "Pendiente: ";
  cin >> pendiente;

  cout << "Energía inicial: ";
  cin >> energia_inicial;

  cout << "Tiempo a proyectar: ";
  cin >> tiempo;

  float dens = densidad_aire(altura);
  cout.precision(10);
  cout <<"Densidad del aire: " << dens << "\n";


  float fa = F_aerodinamica(vel_auto, vel_viento, dens, coef_arrastre_aero, area_frontal, area_trasera);
  cout.precision(10);
  cout << "Fuerza Aerodinámica: " << fa << "\n";

  float fr = F_rodadura(vel_auto, masa_auto, g, coef_rod);
  cout.precision(10);
  cout << "Fuerza de Rodadura: " << fr << "\n";

  float fp = F_pendiente(masa_auto, g, pendiente);
  cout.precision(10);
  cout << "Fuerza Pendiente: " << fp << "\n";

  float fm = fa+fr+fp;
  cout.precision(10);
  cout << "Fuerza Motor: " << fm << "\n"; */

  for(int i = 0; i <= ptos_totales; i++)
  {
    punto[i].radiacion_pto = radiacion(punto[i].horaPnto, punto[i].longitud, punto[i].latitud, punto[i].altura);
    punto[i].F_pend = F_pendiente(masa_auto, g, punto[i].pend_rad);
    punto[i].F_rod = F_rodadura(masa_auto, g, punto[i].pend_rad , coef_rod);
    punto[i].densidadAire = densidad_aire(punto[i].altura);
  }




  //float ed = energia_disponible(energia_inicial, tiempo, radiacion_captada, perdidas_parasitas, potencia_total, eficiencia_motor);
  //cout.precision(10);
  //cout << "Energia Disponible: " << ed;
}
