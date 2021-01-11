#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>
#include "funciones.h"
#include "clase.h"




int main() {
  leer_datos();
  double hora;

  cout << "Hora: ";
  cin >> hora;

  float rad = radiacion(hora, punto[0].longitud, punto[0].latitud, punto[0].altura);// esta es una prueba con el pto 1, la idea es automatizar esta parte 
 cout << rad << endl;

  time_t seconds;

  seconds = time (NULL);
  float vel_auto, vel_viento, altura, pendiente, tiempo ;
  
  cout << "Velocidad del auto: ";
  cin >> vel_auto;
  posiciones_carrera(73.614, 0,  11, 1);
  cout << punto[1973].horaPnto << endl; 

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
  cout << "Fuerza Motor: " << fm << "\n";

  //float ed = energia_disponible(energia_inicial, tiempo, radiacion_captada, perdidas_parasitas, potencia_total, eficiencia_motor);
  //cout.precision(10);
  //cout << "Energia Disponible: " << ed;
}
