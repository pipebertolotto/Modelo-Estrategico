#include <iostream>
#include <iomanip>
#include "clase.h"
using namespace std;

double hora_final[5] = {17, 17, 17, 17, 17}; // ojo con las horas finales
//revisar si es necesario este array, sino lo hacemos como  17

// esta func nos permite sacar a que hr vamos a estar en que punto de la carrera
// este se carga cada vez que se corre el programa, y se utilizan los input reales 
void posiciones_carrera(float velocidad, int pto_actual, float hora_actual, int dia_carrera)
{
    int x = 0;
    double hora_pto = hora_actual;
    for(int i = 0; i < 6 - dia_carrera; i++)
    {
        
        while(hora_pto < 17)
        {
            
            if(pto_actual == 13723)
            {
                punto[pto_actual].horaPnto = hora_pto + (punto[pto_actual].dist_km/velocidad);
                x = 1;
                break;
            }
            
            
            
            punto[pto_actual].horaPnto = hora_pto + (punto[pto_actual + 1].dist_km/velocidad);
            
           

           
           hora_pto = punto[pto_actual].horaPnto;
           pto_actual++;

        }
         hora_pto =  8;
         cout << pto_actual << endl;
        if(x == 1) break;

    }

    

}

