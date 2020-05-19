#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes_mascotas.c"
#include "funciones.c"
#define TC 10
#define TM 20
#define TR 10

int main()
{

    eClientes clientes[TC];
    eMascota mascotas[TM];
    eRaza razas[TR];
    char opcion;
    char opcionSecundaria;
    float promedio;

    inicializarCliente(clientes, TC);
    inicializarMascota(mascotas, TM);

    hardcodeoClientes(clientes, TC);
    hardcodeoMascotas(mascotas, TM, razas, TR);
    do
    {
        menu();
        opcion = validarOpcion(49, 53);

        switch(opcion)/*MENU PRINCIPAL*/
        {
            case 49/*1*/:
                menuClientes();
                opcionSecundaria = validarOpcion(49, 53);
                switch(opcionSecundaria)/*MENU CLIENTES*/
                {
                    case 49/*1*/:
                        mostrarClientes(clientes, TC,mascotas, TM);
                        break;

                    case 50/*2*/:
                        cargarUnCliente(clientes, TC);
                        break;

                    case 51/*3*/:
                        mostrarClientes(clientes, TC,mascotas, TM);
                        modificarUnCliente(clientes, TC);
                        break;

                    case 52/*4*/:
                        mostrarClientes(clientes, TC,mascotas, TM);
                        eliminarUnCliente(mascotas, TM, clientes, TC);
                        break;

                    case 53/*5*/:
                        break;
                }
                break;

            case 50/*2*/:
                menuMascotas();
                opcionSecundaria = validarOpcion(49, 53);
                switch(opcionSecundaria)/*MENU MASCOTAS*/
                {
                    case 49/*1*/:
                        mostrarMascotas(mascotas, TM, clientes, TC);
                        break;

                    case 50/*2*/:
                        printf("\n\n--------------------------------CLIENTES DISPONIBLES--------------------------------------\n");
                        mostrarClientes(clientes, TC, mascotas, TM);
                        cargarUnaMascota(mascotas, TM);
                        break;

                    case 51/*3*/:
                        mostrarMascotas(mascotas, TM, clientes, TC);
                        modificarUnaMascota(mascotas, TM);
                        break;

                    case 52/*4*/:
                        mostrarMascotas(mascotas, TM, clientes, TC);
                        eliminarUnaMascotaPorID(mascotas, TM);
                        break;

                    case 53/*5*/:

                        break;
                }
                break;

            case 51/*3*/:
                menuClientes_Mascotas();
                opcionSecundaria = validarOpcion(49, 56);
                switch(opcionSecundaria)/*MENU CLIENTES_MASCOTAS*/
                {
                    case 49/*1*/:
                        mostrarClientesConMascota(mascotas, TM, clientes, TC);
                        break;

                    case 50/*2*/:
                        mascotasPorTipo(mascotas, TM, clientes, TC);
                        break;

                    case 51/*3*/:
                        mostrarClientesConMasDeUnaMascota(clientes, TC, mascotas, TM);
                        break;

                    case 52/*4*/:
                        mostrarClientesConMasDeTresAnios(clientes, TC, mascotas, TM);
                        break;

                    case 53/*5*/:
                        ordenarPorCantidadMascotas(clientes, TC, mascotas, TM);
                        mostrarClientes(clientes, TC, mascotas, TM);
                        break;

                    case 54/*6*/:
                        ordenarPorCantidadMascotas(clientes, TC, mascotas, TM);
                        ordenarPorCantidadMascotasYNombre(clientes, TC, mascotas, TM);
                        mostrarClientes(clientes, TC, mascotas, TM);
                        break;

                    case 55/*7*/:
                        ordenarMascotasPorTipo(clientes, TC, mascotas, TM);
                        mostrarMascotas(mascotas, TM, clientes, TC);
                        break;

                    case 56/*8*/:
                        break;
                }
                break;

            case 52/*4*/:
                menuPromedios();
                opcionSecundaria = validarOpcion(49, 52);
                switch(opcionSecundaria)/*MENU PROMEDIOS*/
                {
                    case 49/*1*/:
                        promedio=promedioEdadMascotas(mascotas, TM);
                        printf("El promedio de edad de las mascotas es de: %.2f\n", promedio);
                        system("pause");
                        break;

                    case 50/*2*/:
                        promedioEdadMascotasPorTipo(mascotas, TM);
                        break;

                    case 51/*3*/:
                        promedioClientes(clientes, TC);
                        porcentajeClientes(clientes, TC);
                        break;

                    case 52/*4*/:
                        break;
                }
                break;

            case 53/*5*/:
                break;
        }
    }while  (opcion != 53);
    return 0;
}
