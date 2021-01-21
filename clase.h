struct puntos 
{
    
        int nro_pto;
        float longitud;
        float latitud;
        float altura;
        float delta_dist;
        float distancia_acumulada;
        float pend;
        float pend_rad;
        float pend_grad;
        float dist_km;
        float horaPnto;
        float radiacion_pto;
        float densidadAire;
        float F_rod;
        float F_pend;
        
               
};

extern puntos punto[13723];

void leer_datos();

