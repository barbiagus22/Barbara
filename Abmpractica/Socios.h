typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;


typedef struct
{
    int id;
    char lastname[31];
    char name [31];
    char sexo[5];
    char telefono[16];
    char mail [31];
    eFecha fecha;
    int isEmpty;


} eSocio;


void initSocios ( eSocio socios  [], int tam);
int buscarLibreSocios(eSocio socios [], int tam);
eSocio altaSocio (int codigoSocio);
void addSocio ( eSocio socio [], int tam, int idAut);
void cargarSocios(eSocio socios[], int tam);
void listarUnSocio (eSocio socio);
void printSocios (eSocio socios [], int tam);
int findSocios( eSocio socios [], int tam, int idAuto);
void modifySocios (eSocio socios [], int tam );
void removeSocio (eSocio socios [], int tam);
void listarSociosOrdenados (eSocio socios [], int tam);
void obtenerSocio (eSocio socio[], int tams, int id, char cadena[] );
