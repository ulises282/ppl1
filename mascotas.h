#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

typedef struct
{
    int id;
    int idCliente;
    int idRaza;
    char nombre[51];
    char tipo[51];
    char raza[51];
    int edad;
    float peso;
    char sexo;
    int estado;


}eMascota;

typedef struct
{
    int id;
    char nombre[51];
    char pais[51];
}eRaza;

void hardcodeoRaza(eRaza razas[],int tamRaza);

void hardcodeoMascotas(eMascota mascotas[],int tamMascotas, eRaza razas[],int tamR);
void inicializarMascota(eMascota mascota[],int tam);
int buscarLibreMascota(eMascota mascotas[],int tam);
void cargarUnaMascota(eMascota mascotas[], int tam);
eMascota crearUnaMascota (void);
void eliminarUnaMascotaPorID(eMascota mascotas[], int tam);
void modificarUnaMascotaNombre(eMascota mascotas[], int tam);
void modificarUnaMascotaTipo(eMascota mascotas[], int tam);
void modificarUnaMascotaRaza(eMascota mascotas[], int tam);
void modificarUnaMascotaEdad(eMascota mascotas[], int tam);
void modificarUnaMascotaPeso(eMascota mascotas[], int tam);
void modificarUnaMascotaSexo(eMascota mascotas[], int tam);
void eliminarUnaMascota(eMascota mascotas[], int tam,int index);
void promedioEdadMascotasPorTipo(eMascota mascotas[], int tamM);
