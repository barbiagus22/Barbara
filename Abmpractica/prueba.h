
typedef struct
{
    int id;
    char name [31];
    char lastname[31];
    int isEmpty;

} eAutores;

int menu();

void cargarAutores(eAutores autores[], int tam);

void initAutores ( eAutores autores  [], int tam);
int buscarLibre(eAutores autores[], int tam);
eAutores altaAutor (int idAut);
void addAutor ( eAutores autores [], int tam, int idAut);

void mostrarAutor (eAutores  autor);
void printAutores (eAutores autores [], int tam);
int findAutores( eAutores autores [], int tam, int idAuto);
void modifyAutores (eAutores autores [], int tam );
void removeAutor (eAutores autores [], int tam);
void listarAutoresOrdenados (eAutores autores [], int tam);

