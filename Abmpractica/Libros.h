
typedef struct
{
    int id;
    char titulo [51];
    int codAutor;
    int isEmpty;

} eLibros;

int menu();
void initLibros ( eLibros libros  [], int tam);
int buscarLibreLibros(eLibros libros[], int tam);
void cargarLibros(eLibros libros[], int tam);
void mostrarUnLibro (eLibros libro);
void printLibros (eLibros libros [], int tam);
int findLibros( eLibros libros [], int tam, int idAuto);
void modifyLibro ( eLibros libros [], int tam , eAutores autores [],int tama  );
void removeLibro (eLibros libro [], int tam);
void listarLibrosOrdenadosPorTitulo (eLibros libros [], int tam);
