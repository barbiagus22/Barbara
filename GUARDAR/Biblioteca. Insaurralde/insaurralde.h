
typedef struct
{
    int codJuegos;
    char descripcion[51];
    float importe;
    int isEmpty;

} sJuegos;

typedef struct
{
    int id;
    char name [51];
    char lastname[51];
    float salary ;
    int sector;
    int isEmpty;

} sEmployee;

/**< -----------------------------------------------------MENU --------------------------------------------------------------------------------- */


int menu();


/**< ---------------------- ------------------------------FUNCIONES ESTRUCTURAS------------------------------------------------------------------ */

typedef struct

{
    int legajo;
    char nombre [30];
    int edad;
    int nota;
    float promedio;

} sAlumno;

/**< ---------------------------------------------ALTA ------------------------------------------------------- */
void initEmployees ( sEmployee empleados [], int tam);
int buscarLibre(sJuegos juegos[], int tam);
sEmployee altaempleado (int idAut);
void addEmployees ( sEmployee empleados [], int tam, int idAut);
/**< ---------------------------------------------LISTAR ------------------------------------------------------- */

void listarUnjuego (sJuegos  juego);
void mostrarEmpleado (sEmployee  empleado);
void printEmployeess (sEmployee empleados [], int tam);


/**< ---------------------------------------------MODIFICAR  ------------------------------------------------------- */
int findEmployeeById( sEmployee empleados [], int tam, int idAuto);
void modifyEmployee (sEmployee empleados [], int tam );


/**< ---------------------------------------------BAJA ------------------------------------------------------- */

void removeEmployee (sEmployee empleados [], int tam);


/**< ---------------------------------------------ORDENAMIENTO ------------------------------------------------------- */
void listarjuegosOrdenados (sJuegos juego [], int tam);


/**< ------------------------------------------------   VALIDACIONES ------------------------------------------------------------------------- */

int getInt_Validado (char mensaje [], char mensajerError [], int lmim, int lsup);
float getfloat (char mensaje [], char mensajerError [], float lmim, float lsup);
int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char msj[],char input[]);

/**< ---------------------------------------------- FUNCIONES CALCULOS ---------------------------------------------------------------------- */

float ingresarOperando1 ( float operando1);
float ingresarOperando2 ( float operando2);
float suma ( float operando1, float operando2);
float resta (float operando1, float operando2);
float division(float operando1, float operando2);
float multiplicacion(float operando1, float operando2);
float factorialUno (float operando1);
float factorialDos (float operando2);

/**< ----------------------------------------------------------------------------------------------------------------------------------------- */
