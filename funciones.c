#include "funciones.h"
/***************************************************************/
void menu(void)
{
    system("cls");
    printf("-------VETERINARIA-------\n");
    printf("1. Clientes\n");
    printf("2. Mascotas\n");
    printf("3. Clientes con mascotas\n");
    printf("4. Promedios\n");
    printf("5. Salir\n");
}
/***************************************************************/
bool validarNumero(char opcion[] ,int minimo, int maximo)
{
    if(!(opcion[0]>=minimo && opcion[0]<=maximo))
    {
        return false;
    }
    return true;
}
/***************************************************************/
char validarOpcion(int minimo,int maximo)
{
    bool valido=false;
    char opcion[51];
    char opcionValida;
    int longitud;
    printf("Ingresar una opcion: ");
    scanf("%s", opcion);
    longitud = strlen(opcion);
    if (longitud == 1)
    {
        valido = validarNumero(opcion, minimo, maximo);
    }
    while((valido==false || longitud != 1) || (opcion[0] >  maximo || opcion[0] < minimo))
    {
        printf("Ingresar una opcion valida: ");
        scanf("%s", opcion);
        longitud = strlen(opcion);
        if (longitud == 1)
        {
            valido = validarNumero(opcion, minimo, maximo);
        }
    }
    opcionValida=opcion[0];
    return opcionValida;
}
/***************************************************************/
void menuClientes(void)
{
    system("cls");
    printf("-------CLIENTES-------\n");
    printf("1. Listado de clientes\n");
    printf("2. Alta de clientes\n");
    printf("3. Modificacion de clientes\n");
    printf("4. Baja de clientes\n");
    printf("5. Volver\n");
}
/***************************************************************/
void menuMascotas (void)
{
    system("cls");
    printf("-------MASCOTAS-------\n");
    printf("1. Listado de mascotas\n");
    printf("2. Alta de mascotas\n");
    printf("3. Modificacion de mascotas\n");
    printf("4. Baja de mascotas\n");
    printf("5. Volver\n");
}
/***************************************************************/
void menuClientes_Mascotas(void)
{
    system("cls");
    printf("-------CLIENTES_MASCOTAS-------\n");
    printf("1. Listado de clientes con mascotas\n");
    printf("2. Listado de mascotas por tipo\n");
    printf("3. Lista de clientes con mas de una mascota \n");
    printf("4. Mascotas con mas de 3 anios  \n");
    printf("5. Clientes ordenados por cantidad de mascotas\n");
    printf("6. Clientes ordenados por cantidad de mascotas y nombre\n");
    printf("7. ordenar mascotas por tipo\n");
    printf("8. Volver\n");
}
/***************************************************************/
void menuPromedios(void)
{
    system("cls");
    printf("-------PROMEDIOS-------\n");
    printf("1. Promedio de edad entre las mascotas  \n");
    printf("2. Promedio de edad entre las mascotas por tipo  \n");
    printf("3. Promedio entre clientes varones y mujeres  \n");
    printf("4.  Salir\n");

}
/***************************************************************/
void menuModificacioClientes(void)
{
    printf("Que desea modificar?\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Localidad\n");
    printf("4. Telefono\n");
    printf("5. Edad\n");
    printf("6. Sexo\n");
    printf("7. Salir\n");
}
