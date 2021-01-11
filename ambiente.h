#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h> 
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

/*IMPORTANTE*/
int N = 285;
//double latitud = -12.4952;
//double lat = 3.14 * latitud/180.0;
//double lon = 131.1501;
double long_st = 142.5; //9,5*15
int D = 0;
double t_sim = 1;
/**************************************************/
/*DECLARACION DE FUNCIONES****************************************/
int coseno(int x);

double Deg_to_rad(double deg);

double Rad_to_deg(double rad);

double decl(int dia);

double omega_0(double d, double l);

double LCT(double tiempo_solar, int N, double longitud_loc, double longitud_std, double horario);

double tsolar(double hora_local, int N, double longitud_loc,double long_std, double horario);

double altura(double delta, double phi, double omega);

double azimut_sol(double delta, double phi, double omega, double alfa);

double transmitancia_atmosferica(double hr, double tamb, double dist);

double masa_aire(float altitud, float cenital);

double rad_difusa(float tau, float cenital, float m, float IE);

double rad_pos(float I);

double rad_beam(float IB, float theta);

double rad_global(float Ibeam, float ID);
/***************************************************/

