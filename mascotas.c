#include "mascotas.h"

/********************************************************************************************/
void hardcodeoRaza(eRaza razas[],int tamRaza)
{
    int id[10]= {300,301,302,303,304,305,306};
    char nombre[10][51]= {"Bulldog","pitbull","Labrador","Escino","Lagarto Overo","Angora","Gato"};
    char pais[10][51]= {"Aleman","Siberiano","Argentino","Argelino","Argentina","Turco","Persa"};
    int i;

    for(i=0; i<tamRaza; i++)
    {
        razas[i].id=id[i];
        strcpy(razas[i].nombre,nombre[i]);
        strcpy(razas[i].pais,pais[i]);
    }
}
/********************************************************************************************/
void hardcodeoMascotas(eMascota mascotas[],int tamMascotas, eRaza razas[],int tamRaza)
{
    hardcodeoRaza(razas, tamRaza);
    int id[20]= {200,201,202,203,204,205,206,207,208,209,210};
    int idCliente[20]= {100,100,101,101,101,102,102,103,104,104,104};
    int idRaza[20] = {305,306,300,301,305,301,304,302,305,306,300};
    char nombre[20][40]= {"Michi","MichiSegunda","Tutuca","Potter","michifusi","Brutus","pepe","Manchita","Michooox","Micheeex","Tyson"};
    //char tipo[20][51]= {"","","","","","","","","","",""};
    //char raza[20][51]= {"","","","","","","","","","",""};
    int edad[20]= {3,3,2,1,2,5,7,8,5,2,3};
    float peso[20]= {4.75,3.55,4.37,7.10,6.75,3.64,15.23,3.85,9.43,8.86,3.19};
    char sexo[20]= {'F','F','M','M','M','M','F','M','M','M','M'};
    int estado[20]= {1,1,1,1,1,1,1,1,1,1,1};
    int i;


    for(i=0; i<tamMascotas; i++)
    {
        mascotas[i].id=id[i];
        mascotas[i].idCliente=idCliente[i];
        mascotas[i].idRaza=idRaza[i];
        strcpy(mascotas[i].nombre,nombre[i]);
        mascotas[i].edad=edad[i];
        mascotas[i].peso=peso[i];
        mascotas[i].sexo=sexo[i];
        mascotas[i].estado=estado[i];
        int j;
        for(j=0;j<tamRaza;j++)
        {
            if (mascotas[i].idRaza == razas[j].id && razas[j].id!=0)
            {
                int opcion;
                opcion = razas[j].id;
                switch(opcion)
                {
                    case 300:
                        strcpy(mascotas[i].tipo,"Bulldog" );
                        strcpy(mascotas[i].raza, "Aleman");
                        break;

                    case 301:
                        strcpy(mascotas[i].tipo, "pitbull" );
                        strcpy(mascotas[i].raza, "Siberiano");
                        break;

                    case 302:
                        strcpy(mascotas[i].tipo, "Labrador");
                        strcpy(mascotas[i].raza, "Argentino");
                        break;

                    case 303:
                        strcpy(mascotas[i].tipo, "Escino");
                        strcpy(mascotas[i].raza, "Argelino");
                        break;

                    case 304:
                        strcpy(mascotas[i].tipo, "Lagarto Overo");
                        strcpy(mascotas[i].raza, "Argentina");
                        break;

                    case 305:
                        strcpy(mascotas[i].tipo, "Angora");
                        strcpy(mascotas[i].raza, "Turco");
                        break;

                    case 306:
                        strcpy(mascotas[i].tipo, "Gato");
                        strcpy(mascotas[i].raza, "Persa");
                        break;

                }
            }
        }


    }
}
/********************************************************************************************/
void inicializarMascota(eMascota mascota[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        mascota[i].estado=LIBRE;
        mascota[i].id=0;
    }
}
/********************************************************************************************/
void menuModificacioMascota(void)
{
    printf("Que desea modificar?\n");
    printf("1.Nombre\n");
    printf("2.Tipo\n");
    printf("3.Raza\n");
    printf("4.Edad\n");
    printf("5.Tipo\n");
    printf("6.Sexo\n");
    printf("7.salir\n");
}
/********************************************************************************************/
void promedioEdadMascotasPorTipo(eMascota mascotas[], int tamM)
{
    int i;
    int contadorPerro=0 ;
    int acumuladorPerro= 0;
    int contadorGato=0 ;
    int acumuladorGato= 0;
    int contadorRaro=0 ;
    int acumuladorRaro= 0;
    float promedioPerro;
    float promedioGato;
    float promedioRaro;
    for (i=0; i<tamM ; i++)
    {
        if(mascotas[i].estado==OCUPADO)
        {
            switch(mascotas[i].tipo[0])
            {
                case 'P':
                    contadorPerro++;
                    acumuladorPerro=acumuladorPerro+mascotas[i].edad;
                    break;

                case 'G':
                    contadorGato++;
                    acumuladorGato=acumuladorGato+mascotas[i].edad;
                    break;

                case 'R':
                    contadorRaro++;
                    acumuladorRaro=acumuladorRaro+mascotas[i].edad;
                    break;
            }
        }
    }
    promedioPerro=(float)acumuladorPerro/contadorPerro;
    promedioGato=(float)acumuladorGato/contadorGato;
    promedioRaro=(float)acumuladorRaro/contadorRaro;

    printf("El promedio de edad de los perros es de: %.2f\n",promedioPerro);
    printf("El promedio de edad de los gatos es de: %.2f\n",promedioGato);
    printf("El promedio de edad de los raros es de: %.2f\n",promedioRaro);
    system("pause");
}
/********************************************************************************************/
int buscarLibreMascota(eMascota mascotas[],int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(mascotas[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/********************************************************************************************/
void cargarUnaMascota(eMascota mascotas[], int tam)
{
    int index;

    index = buscarLibreMascota(mascotas, tam);

    if(index!=-1)
    {
        mascotas[index] = crearUnaMascota();
        mascotas[index].id = index +200;
        printf("Carga con exito");
        system("pause");
    }
    else
    {
        printf("No hay espacio para mas mascotas");
    }
}
/********************************************************************************************/

eMascota crearUnaMascota (void)
{
    eMascota mascota;
    char opcionTipo;

    printf ("Ingrese nombre a la mascota: ");
    fflush (stdin);
    fgets(mascota.nombre,51,stdin);
    mascota.nombre[strlen(mascota.nombre)-1]='\0';
    printf ("Ingrese tipo de mascota:\n");
    printf ("1. Bulldog\n");
    printf ("2. pitbull \n");
    printf ("3. Labrador \n");
    printf ("4. Escino \n");
    printf ("5. Lagarto Overo \n");
    printf ("6. Angora \n");
    printf ("7. Gato \n");
    opcionTipo = validarOpcion(49, 55);

    switch(opcionTipo)
    {
        case 49:
            strcpy(mascota.tipo,"Bulldog" );
            strcpy(mascota.raza, "Aleman");
            break;

        case 50:
            strcpy(mascota.tipo, "pitbull" );
            strcpy(mascota.raza, "Siberiano");
            break;

        case 51:
            strcpy(mascota.tipo, "Labrador");
            strcpy(mascota.raza, "Argentino");
            break;

        case 52:
            strcpy(mascota.tipo, "Escino");
            strcpy(mascota.raza, "Argelino");
            break;

        case 53:
            strcpy(mascota.tipo, "Lagarto Overo");
            strcpy(mascota.raza, "Argentina");
            break;

        case 54:
            strcpy(mascota.tipo, "Angora");
            strcpy(mascota.raza, "Turco");
            break;

        case 55:
            strcpy(mascota.tipo, "Gato");
            strcpy(mascota.raza, "Persa");
            break;

    }

    printf ("Ingrese edad: ");
    scanf ("%d", &mascota.edad);

    printf ("Ingrese peso: ");
    scanf ("%f", &mascota.peso);

    printf ("Ingrese sexo (F o M): ");
    scanf ("%s", &mascota.sexo);

    while(mascota.sexo!='M' && mascota.sexo!='F')
    {
        printf ("ERROR!! Ingrese sexo (F o M): ");
        scanf ("%s", &mascota.sexo);
    }

    printf ("Ingrese id del cliente: ");
    scanf ("%d", &mascota.idCliente);

    mascota.estado = OCUPADO;

  return mascota;
}
/********************************************************************************************/


void eliminarUnaMascotaPorID(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    printf("Ingrese el id de la mascota a eliminar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            mascotas[i].estado=LIBRE;
            break;
        }
    }
    printf("no se encontro la mascota");
}
/********************************************************************************************/
void eliminarUnaMascota(eMascota mascotas[], int tam,int index)
{
    int i;
    for(i=0; i<tam;i++)
    {
        if(index == mascotas[i].id)
        {
            mascotas[i].estado=LIBRE;
            break;
        }
    }
}
/********************************************************************************************/
void modificarUnaMascota(eMascota mascotas[], int tam)
{
    char opcion;
    menuModificacioMascota();
    opcion = validarOpcion(49, 55);

    switch(opcion)
    {
        case 49:
            modificarUnaMascotaNombre(mascotas, tam);
            break;

        case 50:
            modificarUnaMascotaTipo(mascotas, tam);
            break;

        case 51:
            //modificarUnaMascotaRaza(mascotas, tam);
            break;

        case 52:
            modificarUnaMascotaEdad(mascotas, tam);
            break;

        case 53:
            modificarUnaMascotaPeso(mascotas, tam);
            break;

        case 54:
            modificarUnaMascotaSexo(mascotas, tam);
            break;

        case 55:
            break;
    }
    system("pause");
}
/********************************************************************************************/
void modificarUnaMascotaNombre(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag =0;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag = 1;
            printf("Reingrese Nombre:");
            fflush(stdin);
            fgets(mascotas[i].nombre,40,stdin);
            mascotas[i].nombre[strlen(mascotas[i].nombre)-1]='\0';

            break;
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }

}
/********************************************************************************************/
void modificarUnaMascotaTipo(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    char opcionTipo;
    int flag =0;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);

    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag=1;
            system("cls");
            printf ("Ingrese tipo de mascota:\n");
            printf ("1. Bulldog\n");
            printf ("2. pitbull \n");
            printf ("3. Labrador \n");
            printf ("4. Escino \n");
            printf ("5. Lagarto Overo \n");
            printf ("6. Angora \n");
            printf ("7. Gato \n");
            opcionTipo = validarOpcion(49, 55);

            switch(opcionTipo)
            {
                case 49:
                    strcpy(mascotas[i].tipo,"Bulldog" );
                    strcpy(mascotas[i].raza, "Aleman");
                    break;

                case 50:
                    strcpy(mascotas[i].tipo, "pitbull" );
                    strcpy(mascotas[i].raza, "Siberiano");
                    break;

                case 51:
                    strcpy(mascotas[i].tipo, "Labrador");
                    strcpy(mascotas[i].raza, "Argentino");
                    break;

                case 52:
                    strcpy(mascotas[i].tipo, "Escino");
                    strcpy(mascotas[i].raza, "Argelino");
                    break;

                case 53:
                    strcpy(mascotas[i].tipo, "Lagarto Overo");
                    strcpy(mascotas[i].raza, "Argentina");
                    break;

                case 54:
                    strcpy(mascotas[i].tipo, "Angora");
                    strcpy(mascotas[i].raza, "Turco");
                    break;

                case 55:
                    strcpy(mascotas[i].tipo, "Gato");
                    strcpy(mascotas[i].raza, "Persa");
                    break;

            }

        }
    }

    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
/********************************************************************************************/
/*void modificarUnaMascotaRaza(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag = 1;
            printf("Reingrese raza:");
            fflush(stdin);
            fgets(mascotas[i].raza,40,stdin);
            mascotas[i].raza[strlen(mascotas[i].raza)-1]='\0';

            break;
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnaMascotaEdad(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag = 0;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag = 1;
            printf ("Ingrese edad: ");
            scanf ("%d", &mascotas[i].edad);

            break;
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnaMascotaPeso(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag =0;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag = 1;
            printf ("reingrese peso: ");
            scanf ("%d", &mascotas[i].edad);

            break;
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnaMascotaSexo(eMascota mascotas[], int tam)
{
    int idMascota;
    int i;
    int flag =0 ;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);
    for(i=0; i<tam;i++)
    {
        if(idMascota == mascotas[i].id)
        {
            flag= 1;
            printf ("Reingrese sexo (F o M): ");
            scanf ("%s", &mascotas[i].sexo);

            while(mascotas[i].sexo!='M' && mascotas[i].sexo!='F')
            {
                printf ("ERROR!! Reingrese sexo (F o M): ");
                scanf ("%s", &mascotas[i].sexo);
            }
            break;
        }
    }
    if(flag == 0)
    {
        printf("Mascota no encontrada\n");
    }
}
/********************************************************************************************/

