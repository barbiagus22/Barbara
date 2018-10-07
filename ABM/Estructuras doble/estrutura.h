typedef struct
{
    int codCliente;
    char nombre [20];
    char apellido [20];
    char telefono[21];
    char domicilio[30];

} sClientes;

typedef struct
{
    int codJuegos;
    char descripcion[51];
    float importe;
    int isEmpty;

} sJuegos;

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


int getStringNumeros(char mensaje[],char input[]);
int getStringLetras(char msj[],char input[]);
int getStringNumeros_limminimo(char mensaje[],char input[], int limm);
void getString (char msj[],char input[]);
int soloLetras(char str[]);
int esNumerico(char str[]);
char getChar(char msj[]);
int getInt(char msj[] );
int getInt(char msj[] );
