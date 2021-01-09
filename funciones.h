#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h> 
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

float g = 9.81;
float area_frontal = 1;
float area_trasera = 1.5;
float coef_arrastre_aero = 0.11;
float masa_auto = 250.00;
float coef_rod = 0.0015; //(una rueda)
float eficiencia_motor = 0.95;
float energia_inicial = 5100.00;

float F_aerodinamica(float velocidad_auto, float velocidad_viento, float densidad_aire, float coef_arrastre_aero, float area_frontal, float area_trasera);
float F_rodadura(float masa, float g, float pendiente, float coef_rod);
float F_pendiente(float masa, float g, float pendiente);
double HNSA(float lat, float lat_sol);
double PHI(float hnsa, float hora, float hora_am, float light_hours);
double densidad_aire(float altura);
double energia_disponible(float energia_inicial, float delta_tiempo, float radiacion_captada, float perdidas_parasitas, float potencia_total, float eficiencia_motor);
double potencia_total(float fuerza_total, float velocidad);

