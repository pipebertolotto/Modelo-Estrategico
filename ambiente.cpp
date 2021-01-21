#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h> 
#include <cmath>
#include <vector>
using namespace std;

/*FUNCIONES*******************************************/
double coseno(int x){
  if(x>M_PI){
    x=x-2*M_PI;  //transformamos [0, 2pi] a [-pi, pi]
  }
    return 1-((x^2)/2)+((x^4)/24)-((x^6)/720)+((x^8)/40320)-((x^10)/3628800)+((x^12)/479001600); //Serie de Taylor
}

double Deg_to_rad(double deg){
  double rad = M_PI * deg/180.0;
  return rad;
}

double Rad_to_deg(double rad){
  double deg = (rad*180)/M_PI;
  return deg;
}

double decl(int N){
  /* dia juliano */
  double calculo = 360*(284+N)/(365);
  double angle = Deg_to_rad(calculo); 
  double delta = 23.45*sin(angle);
  return delta;
}

double omega_0(double delta, double lat){
  double rad_delta = Deg_to_rad(delta);
  double calculo = -1*tan(rad_delta)*tan(lat);
  double calculo2 = Deg_to_rad(calculo);
  double omega_0 = acos(calculo);
  double prueba = omega_0*180.0/M_PI;
  return prueba;
}

double LCT(double tiempo_solar, int N, double longitud_loc, double longitud_std, double horario){
    float LC = (longitud_std - longitud_loc)/15;
    float x = 360*(N-1)/365.242; 
    float eot = 0.258*cos(x*M_PI/180.0) - 7.416*sin(x*M_PI/180.0)-3.648*cos(2*x*M_PI/180.0)-9.228*sin(2*x*M_PI/180.0);
    float treal = tiempo_solar - eot/60 + LC + horario;
    return treal;
}

double tsolar(double hora_local, int N, double longitud_loc,double long_std, double horario){
    float LC = (long_std-longitud_loc)/15; 
    float x = 360*(N-1)/365.242; 
    float eot = 0.258*cos(x*M_PI/180.0)-7.416*sin(x*M_PI/180.0)-3.648*cos(2*x*M_PI/180.0)-9.228*sin(2*x*M_PI/180.0);
    float ts = hora_local + eot/60 - LC - horario; 
    return ts;
}

double altura(double delta, double phi, double omega){
  double alfa = asin(sin(M_PI * delta/180.0)*sin(phi)+cos(M_PI * delta/180.0)*cos(phi)*cos(M_PI * omega/180.0));
  return alfa*180.0/M_PI;
}


double azimut_sol(double delta, double phi, double omega, double alfa){
  double AZs0 = ((sin(M_PI * delta/180.0)*cos(phi) - cos(M_PI * delta/180.0)*sin(phi)*cos(M_PI * omega/180.0))/
  (cos(M_PI * alfa/180.0)));
  double AZs = acos(AZs0)*180.0/M_PI; 
  int signo = 1;
  if (omega < 0) {
    signo = -1;
  }
  AZs = AZs * signo;
  return AZs;
}
//hr=humedad relativa, tamb=temp. ambiente, dist= distancia emisor receptor
double transmitancia_atmosferica(double hr, double tamb, double dist){
  double pw = 101325*hr*(pow(2.7182,(14.4114-(5328/(tamb+273.5)))));
  float transmitancia = 2.02*pow((pw*dist),-0.09);
  return transmitancia;
}

double masa_aire(float altitud, float cenital){
  double pa = 101.3*pow(2.7182,(-altitud/8200));
  float cenital2;
  if(cenital > 88.7){
    cenital2 = 88.69;
  }
  else{
    cenital2 = cenital;
  }
  float m = pa/(101.3*cos(M_PI * cenital2/180.0));
  return m;
}

double rad_difusa(float tau, float cenital, float m, float IE){
  double ID = 0.3*(1-(pow(tau,m)))*IE*cos(Deg_to_rad(cenital));
  return ID;
}

double rad_pos(float I){
  float rad;
  if(I >= 0){
    rad = I;
  }
  else{
    rad = 0;
  }
  return rad;
}

double rad_beam(float IB, float theta){
  double IBeam = rad_pos(IB*theta);
  return IBeam;
}

double rad_global(float Ibeam, float ID){
  double IG = Ibeam + rad_pos(ID);
  return IG;
}


//IG = Ibeam + rad_pos(ID); %W/m^2, RAD GLOBAL
/* Pa = 101.3*exp(-altitud/8200);

largo=length(cenital);
for n=1:1:largo
 if(abs(cenital(n))>88.7)
 cenital2(n)=88.69; 
 else
 cenital2(n)=cenital(n);
 end
end
m= Pa./(101.3*cosd(cenital2));
 */
