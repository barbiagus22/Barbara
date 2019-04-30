typedef struct
{
    int id;
    char descripcion [51];

} sSector;


typedef struct
{
    int id;
    char name [51];
    char lastname[51];
    float salary ;
    int sector;
    int isEmpty;

} sEmployee;



int menu();
sEmployee altaempleado (int idAut);



void mostrarEmpleado (sEmployee  empleado, sSector sec [], int tams);
void initEmployees ( sEmployee inicio [], int tam);
void printEmployeess (sEmployee empleados [], int tam, sSector sec [], int tams);
int buscarLibre( sEmployee empleados [], int tam);
int findEmployeeById( sEmployee empleados [], int tam, int idAuto );
void addEmployees ( sEmployee empleados [], int tam, int idAut);
void modifyEmployee (sEmployee empleados [], int tam , sSector sec[], int tams);
void removeEmployee (sEmployee empleados [], int tam, sSector sec [], int tams);
void sortEmployees (sEmployee empleados [], int tam, sSector sec[] , int tams);
void ordenarPorApellidoAscendente (sEmployee empleados [], int tam );
void ordenarPorApellidoDescendente(sEmployee empleados [], int tam );
void ordenarPorSectorAscendente(sEmployee empleados [], int tam );
void ordenarPorSectorDecendente(sEmployee empleados [], int tam );
void salariosEmpleados (sEmployee empleados [], int tam);

float getFloat(char msj[]);
int getInt(char msj[] );
char getChar(char msj[]);
int soloNumero(char str[]);
int soloLetras(char str[]);
void getString (char msj[],char input[]);
int getStringLetras(char msj[],char input[]);
int getStringNumeros(char mensaje[],char input[]);


void harcodearEmpleados ( sEmployee empl []);
void harcodearSector ( sSector sector []);

void obtenerSector (sSector sec [], int tam, int id, char cadena);













