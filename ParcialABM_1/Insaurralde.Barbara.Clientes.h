#ifndef CLIENTES_H__
#define CLIENTES_H__

typedef struct
{
    int codCliente;
    char nombre [51];
    char sexo[10];
    char telefono[21];
    int isEmpty;

} sCliente;

int menu();
void inicializarClientes (sCliente clientes[], int tam);
int buscarEspacioClientes(sCliente clientes[], int tam);
sCliente altacliente (int codigoCliente);
void altaClientes ( sCliente clientes [], int tam, int codCliente);
void listarUnCliente (sCliente  clientes);
void listarClientes (sCliente clientes [], int tam);
int buscarclienteporCodCliente( sCliente clientes [], int tam, int codigoCliente);
void modificarCliente (sCliente clientes [], int tam );
void listarClientesOrdenados (sCliente clientes [], int tam);
void bajadeCliente (sCliente clientes [], int tam);
void cargarClientes( sCliente clientes []);
void obtenerTefono ( sCliente clientes [], int tamc,int id, char cadena [] );
int esHombre (sCliente clientes [],int tam, int idCliente );
int esMujer (sCliente clientes [],int tam, int idCliente );
void obtenerCliente ( sCliente clientes [], int tamc ,int id , char cadena [] );

#endif
