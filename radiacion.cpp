#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h> 
#include <cmath>
#include <vector>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include "ambiente.h"
using namespace std;


float radiacion(float Hora, float lon, float latitud, float altitud) {
  std::string::size_type sz;
  int numero = 0;
  int beta_planos[] = {0};
  int N_planos = sizeof(beta_planos)/sizeof(beta_planos[0]);
  int AZp_planos[] = {0};
  float time = 60*t_sim;
  string str = to_string(time);
  


  double lat = 3.14 * latitud/180.0;

    int beta = beta_planos[0];
    int AZp = AZp_planos[0];
    double delta = decl(N); /* declinacion solar */
    //cout << delta << endl;
    double omega = omega_0(delta, lat);
    double ts_am_LCT = 12 - omega/15.0;
    double ts_pm_LCT = 12 + omega/15.0;
    float hora_am = LCT(ts_am_LCT,N,lon,long_st,D);
    float hora_at=  LCT(ts_pm_LCT,N,lon,long_st,D);
    /***********************************************/
  
    int x = (hora_at - hora_am)/(t_sim), pasos;
    pasos = floor(x) + 1;
    

      double ts = tsolar(Hora,N,lon,long_st,D);
      double angulo_Horario_solar = 15*(ts-12);
      double alfa = altura(delta, lat, angulo_Horario_solar);
      double AZs = azimut_sol(delta,lat,angulo_Horario_solar,alfa);
      
      double theta = cos(beta*3.1415/180.0)*sin(alfa*3.1415/180.0) + sin(beta*3.1415/180.0)*cos(alfa*3.1415/180.0)*cos((AZs-AZp)*3.1415/180.0);
      /*****************ACA EMPIEZA EL SOL*****************/
      
      
      
      float cenital= 90-alfa;
      
      float Tmax=21; // Podria variar
      float Tmin=1; // Podria variar
      //float altitud = 0; // Tiene que variar
      float hoy = 0; 
      float ayer = 0; 
      int I0 = 1353; 
      double calculo = (360*N)/(365);
      double angle = Deg_to_rad(calculo);
      float IE = I0*(1 + 0.034 * cos((360*N/365.25)*3.1415/180.0));
      
      float m = masa_aire(altitud,cenital);
      //FORMULA GOOGLE 
      float tau = transmitancia_atmosferica(0.73, 15, 150); 
      //hr=humedad relativa, tamb=temp. ambiente, dist= distancia emisor recepto
      double IB = IE*pow(0.7, m); // %W/m^2, rad directa 
      double ID = rad_difusa(0.7, cenital, m, IE);
      double Ibeam = rad_beam(IB, theta);
      double IG = rad_global(Ibeam, ID);
      //cout << IG + i << endl;
      //cout << "3\n";
      return IG;
      





}



/*  
     ID = 0.3*(1-(tau).^m)*IE.*cosd(cenital); %W/m^2, rad difusa

     Ibeam = rad_pos(IB.*cos_theta); %Comprobacion de que ambas radiaciones sean positivas
     
     IG = Ibeam + rad_pos(ID); %W/m^2, RAD GLOBAL
     
     %IG=(100-sombrap2(i))/100.*Ibeam+rad_pos(ID); %W/m^2, RAD GLOBAL
     %arriba sería IG=(100-sombra)./100.*Ibeam+rad_pos(ID);
     %L(1,:) = hora;
     %L(i+1,:)=IG;
     L(i,:)=IG;
     disp(IG)
     disp('paso')
     %plot(hora,IG,hora,ID,hora,Ibeam); grid on

    */













