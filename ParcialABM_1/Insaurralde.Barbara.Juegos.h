#ifndef JUEGOS_H__
#define JUEGOS_H__

typedef struct
{
    int id;
    char descripcion[51];
    int importe;
    int idcategoria;
    int isEmpty;

} eJuego;

typedef struct
{
    int id;
    char descripcion[51];

} eCategoria;

void inicializarJuegos (eJuego juegos[], int tam);
eJuego altaUnJuego (int codJuegos, eCategoria categorias [], int tamc);
void altadeJuegos ( eJuego juego [], int tam, int codJuegos, eCategoria categorias [], int tamc);
int buscarJuegoPorCodigoJuego( eJuego juegos [], int tam, int codJuego);
void modificarJuegos (eJuego juegos [], int tam, eCategoria categorias [], int tamc);
void bajaJuegos (eJuego juego [], int tamj,eCategoria categoria[], int tamca);
void cargarJuegos(eJuego juegos[]);
void listarCategorias (eCategoria categorias[]);
void cargarCategorias( eCategoria categorias[]);
void listarJuegos(eJuego juegosinfantiles [], int tamj,  eCategoria categoria [], int tamc );
void listarUnJuegos(eJuego juegosinfantiles, eCategoria categoria [], int tamc );
void obtenerCategoria (eCategoria categoria[], int tamc, int id, char cadena[] );
void obtenerJuego ( eJuego juego [], int tamj,int id, char cadena [] );


#endif




