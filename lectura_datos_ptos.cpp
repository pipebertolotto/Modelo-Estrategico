#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h> 
#include <cmath>
#include <vector>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "clase.h"
using namespace std;



puntos punto[13723];

void leer_datos()
{
    std::ifstream Datos("datos.csv");

    if(!Datos.is_open()) cout << "ERROR!!!!!\n";

    std::string line;
    std::string nro_pto;
    std::string longitud;
    std::string latitud;
    std::string altura;
    std::string delta_dist;
    std::string distancia_acumulada;
    std::string pend;
    std::string pend_rad;
    std::string pend_grad;
    std::string dist_km;

    int current = 0;



    while(std::getline(Datos, line, '\n'))
    {
        std::istringstream iss(line);
        getline(iss,nro_pto,',');
        getline(iss,longitud,',');
        getline(iss,latitud,',');
        getline(iss,altura,',');
        getline(iss,delta_dist,',');
        getline(iss,distancia_acumulada,',');
        getline(iss,pend,',');
        getline(iss,pend_rad,',');
        getline(iss,pend_grad,',');
        getline(iss,dist_km,',');

        punto[current].nro_pto = stod(nro_pto);
        punto[current].longitud = stod(longitud);
        punto[current].latitud = stod(latitud);
        punto[current].altura = stod(altura);
        punto[current].delta_dist = stod(delta_dist);
        punto[current].distancia_acumulada = stod(distancia_acumulada);
        punto[current].pend = stod(pend);
        punto[current].pend_rad = stod(pend_rad);
        punto[current].pend_grad = stod(pend_grad);
        punto[current].dist_km = stod(dist_km);

        current++; 

    }
}