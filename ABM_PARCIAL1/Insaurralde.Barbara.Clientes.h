
typedef struct
{
    int codCliente;
    char nombre [51];
    char sexo[10];
    char telefono[21];
    int isEmpty;

} sClientes;

int menu();
void inicializarClientes (sClientes clientes[], int tam);
int buscarEspacioClientes(sClientes clientes[], int tam);
sClientes altacliente (int codigoCliente);
void altaClientes ( sClientes clientes [], int tam, int codCliente);
void listarUnCliente (sClientes  clientes);
void listarClientes (sClientes clientes [], int tam);
int buscarclienteporCodCliente( sClientes clientes [], int tam, int codigoCliente);
void modificarCliente (sClientes clientes [], int tam );
void listarClientesOrdenados (sClientes clientes [], int tam);
void bajadeCliente (sClientes clientes [], int tam);

void listarClientesCargados(sClientes clientescargados[]);
void cargarClientes( sClientes clientes []);



