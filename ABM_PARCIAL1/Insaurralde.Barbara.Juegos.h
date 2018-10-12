typedef struct
{
    int id;
    char descripcion[51];
    int importe;
    int idcategoria;

} eJuegos;

typedef struct
{
    int id;
    char descripcion[51];

} eCategoria;

void cargarJuegos(eJuegos juegos[]);
void listarJuegos(eJuegos juegosinfantiles[]);
void listarCategorias (eCategoria categorias[]);
void cargarCategorias( eCategoria categorias[]);


