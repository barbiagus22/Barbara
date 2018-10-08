typedef struct
{
    int codigoCliente;
    char nombre [51];
    char apellido [51];
    char telefono[21];
    char domicilio[51];
    int isEmpty;

} sClientes;

typedef struct
{
    int codJuegos;
    char descripcion[51];
    float importe;
    int isEmpty;

} sJuegos;

typedef struct
{
    int codAlquiler;
    sJuegos juegos;
    sClientes clientes;

    int isEmpty;

} sAlquileres;

typedef struct
{
    int dia;
    int mes;
    int anio;

} sFecha;

int menu();
void inicializarJuegos (sJuegos juegos[], int tam);
int buscarLibre(sJuegos juegos[], int tam);
sJuegos altaUnJuego (int codJuegos);
void altadeJuegos ( sJuegos juego [], int tam, int codJuegos);
void listarUnjuego (sJuegos  juego);
void listarjuegos (sJuegos juego [], int tam);
int buscarJuego( sJuegos juego [], int tam, int codJuegos);
void bajadeJuego (sJuegos juego [], int tam);
void modificarJuegos (sJuegos juego [], int tam);
void listarjuegosOrdenados (sJuegos juego [], int tam);


void inicializarClientes (sClientes clientes[], int tam);
int buscarEspacioClientes(sClientes clientes[], int tam);
sClientes altacliente ();
void altaClientes ( sClientes clientes [], int tam, int codCliente);
void listarUnCliente (sClientes  clientes);
void listarClientes (sClientes clientes [], int tam);
int buscarclienteporCodCliente( sClientes clientes [], int tam, int codigoCliente);
void modificarCliente (sClientes clientes [], int tam );
void bajadeCliente (sClientes clientes [], int tam);
void listarClientesOrdenados (sClientes clientes [], int tam);


void inicializarAlquileres (sAlquileres alquiler[], int tam);
int buscarLibreAlquileres(sAlquileres alquiler[], int tam);
void altaAlquiler (sJuegos juegos [], int tamjuegos, sClientes clientes[] , int tamclientes, sAlquileres alquileres [], int tamalq, int codAlq);



int getStringNumeros(char mensaje[],char input[]);
int getStringLetras(char msj[],char input[]);
int getStringNumeros_limminimo(char mensaje[],char input[], int limm);
void getString (char msj[],char input[]);
int soloLetras(char str[]);
int esNumerico(char str[]);
char getChar(char msj[]);
int getInt(char msj[] );
int getInt(char msj[] );
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
