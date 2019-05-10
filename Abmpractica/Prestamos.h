typedef struct
{
    int dia;
    int mes;
    int anio;

} eFechas;

typedef struct
{
    int codigoDePrestamo;
    int codigoDeLibro;
    int codigoDeSocio;
    eFechas fecha;
    int isEmpty;


} ePrestamo;


int menuPrestamo();
void initPrestamos ( ePrestamo prestamos  [], int tam);
int buscarLibrePrestamos (ePrestamo prestamo[], int tam);
ePrestamo altaPrestamo (int idAut, eLibros libros[], int taml, eSocio socios [], int tams );
void addPrestamo ( ePrestamo prestamos [], int tam, int idAut, eLibros libros [], int taml, eSocio socios [], int tams);
void mostrarPrestamo (ePrestamo prestamo, eSocio socio[], int tams );
void printPrestamos (ePrestamo prestamos[], int tam, eSocio socio [],int tams);
