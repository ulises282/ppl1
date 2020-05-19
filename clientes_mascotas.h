#include "clientes.c"
#include "mascotas.c"
#define TM 20

void mostrarClientesConMascota(eMascota mascota[], int tamM,eClientes cliente[],int tamD);
void eliminarUnCliente(eMascota mascotas[], int tamM,eClientes clientes[], int tamC);
void mascotasPorTipo(eMascota mascotas[], int tamM,eClientes clientes[], int tamC);
void mostrarClientesConMasDeUnaMascota(eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
void mostrarClientesConMasDeTresAnios(eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
void ordenarPorCantidadMascotas (eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
void ordenarPorCantidadMascotasYNombre (eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
void mostrarClientes(eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
float promedioEdadMascotas(eMascota mascotas[], int tamM);
void contarMascota(eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
void ordenarMascotasPorTipo (eClientes cliente[],int tamC, eMascota mascotas[], int tamM);
void mostrarMascotas(eMascota mascotas[],int tamM, eClientes cliente[],int tamC);

