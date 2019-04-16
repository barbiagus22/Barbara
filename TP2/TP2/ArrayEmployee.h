 typedef struct
 {
     int id;
     char name[51];
     char lastName[51];
     float salary;
     int sector;
     int isEmpty;
 }eEmployee;

int menu();
void initEmployees ( eEmployee employee [], int len);
void hardCodearEmpleado ( eEmployee employee[], int len  );
void printOneEmployee ( eEmployee employee);
int printEmployees ( eEmployee employee [] , int len);





float getFloat(char msj[]);
int getInt(char msj[] );
char getChar(char msj[]);
int soloNumero(char str[]);
int soloLetras(char str[]);
void getString (char msj[],char input[]);
int getStringLetras(char msj[],char input[]);
int getStringNumeros(char msj[],char input[]);
