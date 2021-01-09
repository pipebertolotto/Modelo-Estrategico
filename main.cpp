#include <iostream>
#include <iomanip>
#include "funciones.h"



int main() {
  float vel_auto, vel_viento, altura, pendiente, energia_inicial, tiempo;
  cout << "Velocidad del auto: ";
  cin >> vel_auto;
  
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

  float ed = energia_disponible(energia_inicial, tiempo, radiacion_captada, perdidas_parasitas, potencia_total, eficiencia_motor);
  cout.precision(10);
  cout << "Energia Disponible: " << ed
}
