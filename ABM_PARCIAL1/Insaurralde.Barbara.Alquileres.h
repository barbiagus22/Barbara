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

} sAlquileres;




void inicializarAlquileres (sAlquileres alquiler[], int tam);
int buscarLibreAlquileres(sAlquileres alquiler[], int tam);
void altaAlquiler (eJuegos juego[], sClientes clientes[] , int tamclientes, sAlquileres alquileres [], int tamalq, int codAlq);
void listarUnAlquiler (sAlquileres  alquileres);
void listarAlquileres (sAlquileres alquileres [], int tam);
