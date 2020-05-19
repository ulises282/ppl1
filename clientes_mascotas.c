#include "clientes_mascotas.h"

void mostrarClientesConMascota(eMascota mascotas[], int tamM,eClientes cliente[],int tamD)
{
    int i;
    int j;
    for(i=0;i<tamD;i++)
    {
        if(cliente[i].estado==OCUPADO)
        {
            printf("\n\n----------------------------------------CLIENTE------------------------------------------\n");
            printf(" ID                nombre             apellido                localidad         telefono\n");
            printf("%4d %20s %20s %20s %20s",cliente[i].id
                                            ,cliente[i].nombre
                                            ,cliente[i].apellido
                                            ,cliente[i].localidad
                                            ,cliente[i].telefono);
            printf("\n");
            printf("----------------------------------------MASCOTAS---------------------------------------\n");
            printf(" ID               nombre                  tipo                raza        edad\n");
            for(j=0;j<tamM;j++)
            {
                if(mascotas[j].estado==OCUPADO && cliente[i].id==mascotas[j].idCliente)
                {
                    printf("%4d %20s %20s %20s %8d\n"   ,mascotas[j].id
                                                        ,mascotas[j].nombre
                                                        ,mascotas[j].tipo
                                                        ,mascotas[j].raza
                                                        ,mascotas[j].edad);
                }
            }
        }
    }
    system("pause");
}
/****************************************************************************************/
void eliminarUnCliente(eMascota mascotas[], int tamM,eClientes clientes[], int tamC)
{
    int idCliente;
    int i;
    printf("Ingrese el id del cliente a eliminar: ");
    scanf("%d", &idCliente);
    for(i=0; i<tamC;i++)
    {
        if(idCliente == clientes[i].id)
        {
            printf("Cliente %s eliminado\n",clientes[i].nombre);
            clientes[i].estado=LIBRE;
            break;
        }
    }
    for(i=0; i<tamM;i++)
    {
        if(idCliente == mascotas[i].idCliente)
        {
            eliminarUnaMascota(mascotas, TM, mascotas[i].id);
            printf("Mascota  %s eliminada\n",mascotas[i].nombre);
        }
    }
    system("pause");
}
/****************************************************************************************/
void mascotasPorTipo(eMascota mascotas[], int tamM,eClientes clientes[], int tamC)
{
    int i;
    int j;
    printf("\n----------------------------------------PERROS---------------------------------------\n");
    printf(" ID                nombre                raza             nombre del cliente \n");
    printf("---------------------------------------------------------------------------------------\n");
/**************************PERROS************************************/
    for(i=0;i<tamM;i++)
    {
        if(mascotas[i].estado==OCUPADO && mascotas[i].tipo[0] == 'P')
        {
            for(j=0;j<tamC;j++)
            {
                if(clientes[j].id == mascotas[i].idCliente)
                {
                    break;
                }
            }
            printf("%4d %20s %20s %20s\n"   ,mascotas[i].id
                                            ,mascotas[i].nombre
                                            ,mascotas[i].raza
                                            ,clientes[j].nombre);
        }
    }
/**************************GATOS************************************/

    printf("\n----------------------------------------GATOS---------------------------------------\n");
    printf(" ID                nombre                raza             nombre del cliente \n");
    printf("---------------------------------------------------------------------------------------\n");
    for(i=0;i<tamM;i++)
    {
        if(mascotas[i].estado==OCUPADO && mascotas[i].tipo[0] == 'G')
        {
            for(j=0;j<tamC;j++)
            {
                if(clientes[j].id == mascotas[i].idCliente)
                {
                    break;
                }
            }
            printf("%4d %20s %20s %20s\n"   ,mascotas[i].id
                                            ,mascotas[i].nombre
                                            ,mascotas[i].raza
                                            ,clientes[j].nombre);
        }
    }
/**************************RAROS************************************/
    printf("\n----------------------------------------RAROS---------------------------------------\n");
    printf(" ID                nombre                raza             nombre del cliente \n");
    printf("---------------------------------------------------------------------------------------\n");

    for(i=0;i<tamM;i++)
    {
        if(mascotas[i].estado==OCUPADO && mascotas[i].tipo[0] == 'R')
        {
            for(j=0;j<tamC;j++)
            {
                if(clientes[j].id == mascotas[i].idCliente)
                {
                    break;
                }
            }
            printf("%4d %20s %20s %20s\n"   ,mascotas[i].id
                                            ,mascotas[i].nombre
                                            ,mascotas[i].raza
                                            ,clientes[j].nombre);
        }
    }
    printf("\n\n");
    system("pause");
}
/********************************************************************************************/
void mostrarClientesConMasDeUnaMascota(eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    int i;
    printf("\n\n----------------------------CLIENTES CON MAS DE UNA MASCOTA------------------------------\n");
    printf(" ID                nombre             apellido               localidad          cantidad de mascotas\n");
    printf("----------------------------------------------------------------------------------------\n");
    contarMascota(cliente, tamC, mascotas, tamM);
    for (i=0;i<tamC;i++)
    {
        if (cliente[i].cantidadMascotas>1)
        {
            printf("%4d %20s %20s %20s %20d\n"  ,cliente[i].id
                                                    ,cliente[i].nombre
                                                    ,cliente[i].apellido
                                                    ,cliente[i].localidad
                                                    ,cliente[i].cantidadMascotas);
        }
    }
    printf("\n\n");
    system ("pause");
}
/********************************************************************************************/

void contarMascota(eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    int i;
    int j;
    for(i=0;i<tamC;i++)
    {
        if(cliente[i].estado==OCUPADO)
        {
            cliente[i].cantidadMascotas=0;
            for(j=0;j<tamM;j++)
            {
                if(cliente[i].id==mascotas[j].idCliente)
                {
                    cliente[i].cantidadMascotas++;
                }
            }
        }
    }
}
/********************************************************************************************/
void mostrarClientesConMasDeTresAnios(eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    int i;
    int j;
    printf("\n\n----------------------------MASCOTAS CON MAS DE 3 ANIOS-----------------------------------------------\n");
    printf(" ID              nombre                   tipo               raza             cliente          anios \n");
    printf("------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<tamM;i++)
    {
        if(mascotas[i].estado==OCUPADO && mascotas[i].edad>3)
        {
            for(j=0;j<tamC;j++)
            {
                if(cliente[j].id==mascotas[i].idCliente)
                {
                    printf("%4d %20s %20s %20s %20s %8d\n"  ,mascotas[i].id
                                                            ,mascotas[i].nombre
                                                            ,mascotas[i].tipo
                                                            ,mascotas[i].raza
                                                            ,cliente[j].nombre
                                                            ,mascotas[i].edad);
                }
            }
        }
    }
    printf("\n\n");
    system ("pause");
}
/********************************************************************************************/
void ordenarPorCantidadMascotas (eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    int i;
    int j;
    eClientes aux;
    contarMascota(cliente, tamC, mascotas, tamM);
    for(i=0; i<tamC-1; i++)
    {
        for(j=i+1; j<tamC; j++)
        {
            if(cliente[i].cantidadMascotas<cliente[j].cantidadMascotas)
            {
                aux = cliente[i];
                cliente[i] = cliente[j];
                cliente[j] = aux;
            }
        }

    }
}
/********************************************************************************************/
void ordenarPorCantidadMascotasYNombre (eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    int i;
    int j;
    eClientes aux;

    for(i=0; i<tamC-1; i++)
    {
        for(j=i+1; j<tamC; j++)
        {
            if(cliente[i].cantidadMascotas<cliente[j].cantidadMascotas)
            {
                aux = cliente[i];
                cliente[i] = cliente[j];
                cliente[j] = aux;
            }
            else
            {
               if(cliente[i].cantidadMascotas==cliente[j].cantidadMascotas)
               {
                   if(strcmp(cliente[i].nombre,cliente[j].nombre)>0)
                   {
                        aux = cliente[i];
                        cliente[i] = cliente[j];
                        cliente[j] = aux;
                   }
               }
            }
        }

    }
}
/********************************************************************************************/
void mostrarClientes(eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    contarMascota(cliente, tamC, mascotas, tamM);
    int i;
    printf("\n\n----------------------------------------CLIENTES-------------------------------------------------------------\n");
    printf(" ID                nombre             apellido               localidad          telefono      cant. mascotas\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<tamC;i++)
    {
        if(cliente[i].estado==OCUPADO)
        {
            printf("%4d %20s %20s %20s %20s %10d\n"  ,cliente[i].id
                                                ,cliente[i].nombre
                                                ,cliente[i].apellido
                                                ,cliente[i].localidad
                                                ,cliente[i].telefono
                                                ,cliente[i].cantidadMascotas);
        }
    }
    printf("\n\n");
    system ("pause");
}
/********************************************************************************************/
float promedioEdadMascotas(eMascota mascotas[], int tamM)
{
    int i;
    int contador=0 ;
    int acumulador= 0;
    float promedio;
    for (i=0; i<tamM ; i++)
    {
        if(mascotas[i].estado==OCUPADO)
        {
            contador++;
            acumulador=acumulador+mascotas[i].edad;
        }
    }
    promedio=(float)acumulador/contador;

    return promedio;
}
/********************************************************************************************/

/********************************************************************************************/
void ordenarMascotasPorTipo (eClientes cliente[],int tamC, eMascota mascotas[], int tamM)
{
    int i;
    int j;
    eMascota aux;

    for(i=0; i<tamM-1; i++)
    {
        for(j=i+1; j<tamM; j++)
        {
            if(strcmp(mascotas[i].tipo,mascotas[j].tipo)>0)
            {
                aux = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = aux;
            }
        }
    }

}
/********************************************************************************************/
void mostrarMascotas(eMascota mascotas[],int tamM, eClientes cliente[],int tamC)
{
    int i;
    int j;
    printf("\n----------------------------------------Mascotas---------------------------------------\n");
    printf(" ID              nombre                 tipo              raza        nombre Cliente \n");
    printf("---------------------------------------------------------------------------------------\n");
    for(i=0;i<tamM;i++)
    {
        if(mascotas[i].estado==OCUPADO)
        {
            for(j=0;j<tamC;j++)
            {
                if (mascotas[i].idCliente==cliente[j].id)
                {
                    printf("%4d %20s %20s %20s %17s\n"  ,mascotas[i].id
                                                        ,mascotas[i].nombre
                                                        ,mascotas[i].tipo
                                                        ,mascotas[i].raza
                                                        ,cliente[j].nombre);
                }
            }


        }
    }
    printf("\n\n");
    system("pause");
}


