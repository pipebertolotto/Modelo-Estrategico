#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h> 
#include <cmath>
#include <vector>


float F_aerodinamica(float velocidad_auto, float velocidad_viento, float densidad_aire, float coef_arrastre_aero, float area_frontal, float area_trasera)//Función que calcula la fuerza aerodinamica 
{

  if(velocidad_auto + velocidad_viento > 0)
  {
    float x  = 0.5 * densidad_aire * coef_arrastre_aero * area_frontal * pow((velocidad_auto + velocidad_viento),2); 
    return x;
  }

  else
  {
    return 0.5 * densidad_aire * abs(velocidad_viento) * area_trasera * pow((velocidad_auto + velocidad_viento),2);
  }
}


float F_rodadura(float velocidad_auto, float masa, float g, float coef_rod){
  return coef_rod*(1+velocidad_auto/161)*(masa*g);
}

float F_pendiente(float masa, float g, float pendiente){
  float fp = masa*g*sin(pendiente);
  return fp;
}



double HNSA(float lat, float lat_sol){
  float hnsa = lat-lat_sol;
  return hnsa;
}

double PHI(float hnsa, float hora, float hora_am, float light_hours){
  float phi = 90-(90-hnsa) * sin(180*((hora-hora_am)/light_hours));
  return phi;
}

double densidad_aire(float altura){
  float dens = ((-3.64*(pow(10,-14)))*(pow(altura,3))) + ((3.88*pow(10,-9))*pow(altura,2)) - ((1.18*pow(10,-4))*altura)+1.17;
  return dens;
}

double energia_disponible(float energia_inicial, float delta_tiempo, float radiacion_captada, float perdidas_parasitas, float potencia_total, float eficiencia_motor){
  float ed = energia_inicial+((delta_tiempo/3600)*(radiacion_captada-perdidas_parasitas-potencia_total/eficiencia_motor));
  return ed;
}

double potencia_total(float fuerza_total, float velocidad){
  float pt = fuerza_total*velocidad/3.6;
  return pt;
}




