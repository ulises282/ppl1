#include "clientes.h"
#include "funciones.h"
/***********************************************************************/
void hardcodeoClientes (eClientes clientes[], int tamClientes)
{
    int id[20] = {100,101,102,103,104};
    char nombre[20][51] = {"Ludmila","Juan","Florencia","Pepe","Roberto"};
    char apellido[20][51] = {"Garcia","Fernandez","Gomez","Paredes","Castillo"};
    char localidad[20][51] = {"CABA","Lomas","Caballito","Avellaneda","Lomas"};
    char telefono[20][15] = {"1574895","5484234","5418233","84554246","15784622"};
    int edad[20] = {20,40,18,18,45};
    char sexo[20] = {'F','M','F','M','M'};
    int estado[20] = {1,1,1,1,1};

    int i;
    for(i=0; i<tamClientes; i++)
    {
        clientes[i].id=id[i];
        strcpy(clientes[i].nombre,nombre[i]);
        strcpy(clientes[i].apellido,apellido[i]);
        strcpy(clientes[i].localidad,localidad[i]);
        strcpy(clientes[i].telefono,telefono[i]);
        clientes[i].edad=edad[i];
        clientes[i].sexo=sexo[i];
        clientes[i].estado=estado[i];
    }
}
/***********************************************************************/
void inicializarCliente(eClientes cliente[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cliente[i].estado=LIBRE;
        cliente[i].id=0;
    }
}
/***********************************************************************/

/***********************************************************************/
int buscarLibreCliente(eClientes clientes[],int tamC)
{
    int i;
    int index = -1;
    for(i=0; i<tamC; i++)
    {
        if(clientes[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/***********************************************************************/
void cargarUnCliente(eClientes clientes[], int tamC)
{
    int index;

    index = buscarLibreCliente(clientes, tamC);

    if(index!=-1)
    {
        clientes[index] = crearUnCliente();
        clientes[index].id = index +100;
        printf("Cliente cargado con exito\n");
        system("pause");
    }
    else
    {
        printf("No hay mas espacio para clientes\n");
        system("pause");
    }

}
/***********************************************************************/
eClientes crearUnCliente (void)
{
    eClientes clientes;

    printf ("Ingrese nombre: ");
    fflush (stdin);
    fgets(clientes.nombre,51,stdin);
    clientes.nombre[strlen(clientes.nombre)-1]='\0';

    printf ("Ingrese apellido: ");
    fflush (stdin);
    fgets(clientes.apellido,51,stdin);
    clientes.apellido[strlen(clientes.apellido)-1]='\0';

    printf ("Ingrese localidad: ");
    fflush (stdin);
    fgets(clientes.localidad,51,stdin);
    clientes.localidad[strlen(clientes.localidad)-1]='\0';

    printf ("Ingrese telefono: ");
    fflush (stdin);
    fgets(clientes.telefono,51,stdin);
    clientes.telefono[strlen(clientes.telefono)-1]='\0';

    printf ("Ingrese edad: ");
    scanf ("%d", &clientes.edad);

    printf ("Ingrese sexo (F o M): ");
    scanf ("%s", &clientes.sexo);

    while(clientes.sexo!='M' && clientes.sexo!='F')
    {
        printf ("ERROR!! Ingrese sexo (F o M): ");
        scanf ("%s", &clientes.sexo);
    }

    clientes.estado = OCUPADO;

  return clientes;
}
/***********************************************************************/
void modificarUnCliente(eClientes clientes[], int tam)
{
    char opcion;
    menuModificacioClientes();
    opcion = validarOpcion(49, 55);

    switch(opcion)
    {
        case 49:
            modificarUnClienteNombre(clientes, tam);
            break;

        case 50:
            modificarUnClienteApellido(clientes, tam);
            break;

        case 51:
            modificarUnClienteLocalidad(clientes, tam);
            break;

        case 52:
            modificarUnClienteTelefono(clientes, tam);
            break;

        case 53:
            modificarUnClienteEdad(clientes, tam);
            break;

        case 54:
            modificarUnClienteSexo(clientes, tam);
            break;

        case 55:
            break;
    }
    system("pause");
}
/********************************************************************************************/
void modificarUnClienteNombre(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag =0;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag = 1;
            printf("Reingrese Nombre:");
            fflush(stdin);
            fgets(clientes[i].nombre,40,stdin);
            clientes[i].nombre[strlen(clientes[i].nombre)-1]='\0';

            break;
        }
    }
    if(flag == 0)
    {
        printf("Cliente no encontrada\n");
    }

}
/********************************************************************************************/
void modificarUnClienteApellido(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag =0;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag=1;
            printf("Reingrese apellido:");
            fflush(stdin);
            fgets(clientes[i].apellido,40,stdin);
            clientes[i].apellido[strlen(clientes[i].apellido)-1]='\0';
        }
    }
    if(flag == 0)
    {
        printf("cliente no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnClienteLocalidad(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag = 1;
            printf("Reingrese localidad:");
            fflush(stdin);
            fgets(clientes[i].localidad,40,stdin);
            clientes[i].localidad[strlen(clientes[i].localidad)-1]='\0';

            break;
        }
    }
    if(flag == 0)
    {
        printf("cliente no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnClienteTelefono(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag = 0;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag = 1;
            printf("Reingrese telefono:");
            fflush(stdin);
            fgets(clientes[i].telefono,40,stdin);
            clientes[i].telefono[strlen(clientes[i].telefono)-1]='\0';

            break;
        }
    }
    if(flag == 0)
    {
        printf("cliente no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnClienteEdad(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag =0;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            flag = 1;
            printf ("reingrese edad: ");
            scanf ("%d", &clientes[i].edad);

            break;
        }
    }
    if(flag == 0)
    {
        printf("cliente no encontrada\n");
    }
}
/********************************************************************************************/
void modificarUnClienteSexo(eClientes clientes[], int tam)
{
    int id;
    int i;
    int flag =0 ;
    printf("Ingrese el ID del cliente a modificar: ");
    scanf("%d", &id);
    for(i=0; i<tam;i++)
    {
        if(id == clientes[i].id)
        {
            printf ("Reingrese sexo (F o M): ");
            scanf ("%s", &clientes[i].sexo);

            while(clientes[i].sexo!='M' && clientes[i].sexo!='F')
            {
                printf ("ERROR!! Reingrese sexo (F o M): ");
                scanf ("%s", &clientes[i].sexo);
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
void promedioClientes(eClientes cliente[], int tamC)
{
    int i;
    int contadorMasculino=0 ;
    int contadorFemenino= 0;
    float promedioMasculino;
    float promedioFemenino;
    for (i=0; i<tamC ; i++)
    {
        if(cliente[i].estado==OCUPADO && cliente[i].sexo=='M')
        {
            contadorMasculino++;
        }
        else
        {
            if(cliente[i].estado==OCUPADO && cliente[i].sexo=='F')
            {
                contadorFemenino++;
            }
        }
    }
    promedioMasculino=(float)contadorMasculino/(contadorMasculino+contadorFemenino);
    promedioFemenino=(float)contadorFemenino/(contadorMasculino+contadorFemenino);

    printf("Hay %.2f hombres por cada mujer\n", promedioMasculino);
    printf("Hay %.2f mujeres por cada hombre\n", promedioFemenino);

    system("pause");
}
/********************************************************************************************/
void porcentajeClientes(eClientes cliente[], int tamC)
{
    int i;
    int contadorMasculino=0 ;
    int contadorFemenino=0 ;
    int contadorTotal=0 ;
    float promedioMasculino;
    float promedioFemenino;
    for (i=0; i<tamC ; i++)
    {
        if(cliente[i].estado==OCUPADO&&cliente[i].sexo=='M')
        {
            contadorMasculino++;
        }
        else
        {
            if(cliente[i].estado==OCUPADO&&cliente[i].sexo=='F')
            {
                contadorFemenino++;
            }
        }
    }
    contadorTotal=contadorMasculino+contadorFemenino;
    promedioMasculino =(float)contadorMasculino*100/contadorTotal;

    promedioFemenino = (float)contadorFemenino*100/contadorTotal;+


    printf("un %.2f porciento de los clientes es hombre y el otro %.2f porciento son mujeres\n",promedioMasculino, promedioFemenino);
    system("pause");
}
