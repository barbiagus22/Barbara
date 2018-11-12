#ifndef ALQUILERES_H__
#define ALQUILERES_H__


typedef struct
{
    int dia;
    int mes;
    int anio;

} sFecha;


typedef struct
{
    int codAlquiler;
    int codJuegos;
    int codClientes;
    sFecha fecha;
    int isEmpty;

} sAlquiler;


void inicializarAlquileres (sAlquiler alquiler[], int tam);
int buscarLibreAlquileres(sAlquiler alquiler[], int tam);
void altaAlquiler (eJuego juego[], int tam , sCliente clientes[], int tamclientes, sAlquiler alquileres [], int tamalq, int codAlq, eCategoria categoria [], int tamc);
void listarUnAlquilerDetallado (sAlquiler  alquileres, sCliente cliente [], int tamc, eJuego juego [], int tamj);
void listarAlquileresDetallados(sAlquiler alquileres [], int tam, sCliente clientes [], int tamc, eJuego juego [], int tamj);
void modificarAlquileres (sAlquiler alquileres [], int tam, sCliente cliente [], int tamc,  eJuego juego [], int tamj, eCategoria categorias [],int tamcg);
int buscarAlquilerPorCodigodeAlquiler( sAlquiler alquiler [], int tam, int codAlquiler);
void bajaAlquileres (sAlquiler alquileres [], int tam, sCliente cliente [], int tamc, eJuego juego [], int tamj);
void cargarAlquileres(sAlquiler alquileres[]);
int compararFecha (sFecha fecha1 , sFecha fecha2);


#endif
