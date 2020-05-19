#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char localidad[51];
    char telefono[15];
    int edad;
    char sexo;
    int estado;
    int cantidadMascotas;

}eClientes;

/** \brief hardcodea los datos de los clientes
 *
 * \param clientes[] eClientes el array de clientes que va a ser hardcodeado
 * \param tamClientes int el tama�o del array de clientes
 * \return void
 *
 */
void hardcodeoClientes (eClientes clientes[], int tamClientes);


/** \brief inicializa el array de clientes con estado == LIBRE
 *
 * \param cliente[] eClientes el array de clientes que va a ser inicializado
 * \param tam int el tama�o del array de clientes
 * \return void
 *
 */
void inicializarCliente(eClientes cliente[],int tam);


/** \brief busca un espacio LIBRE dentro del array de clientes
 *
 * \param clientes[] eClientes el array de clientes dode va a buscar espacio
 * \param tamC int el tama�o del array de clientes
 * \return int retorna el indice del espacio libre
 *
 */
int buscarLibreCliente(eClientes clientes[],int tamC);


/** \brief carga los datos de un nuevo cliente proveniente de la funcion crearUnCliente al array si hay espacio
 *
 * \param clientes[] eClientes el array de clientes en donde se van a cargar los datos
 * \param tamC int el tama�o del array donde se van a cargar los datos
 * \return void
 *
 */
void cargarUnCliente(eClientes clientes[], int tamC);


/** \brief crea un nuevo cliente paara luego cargarlo
 *
 * \param void
 * \param void
 * \return el nuevo cliente ya creado
 *
 */
eClientes crearUnCliente (void);


/** \brief modifica el nombre de un cliente existenete en el array
 *
 * \param clientes[] eClientes el array en el que esta cargado el cliente a modificar
 * \param tam int el tama�o del array
 * \return void
 *
 */
void modificarUnClienteNombre(eClientes clientes[], int tam);


/** \brief modifica el apellido de un cliente existenete en el array
 *
 * \param clientes[] eClientes el array en el que esta cargado el cliente a modificar
 * \param tam int el tama�o del array
 * \return void
 *
 */
void modificarUnClienteApellido(eClientes clientes[], int tam);


/** \brief modifica la localidad de un cliente existenete en el array
 *
 * \param clientes[] eClientes el array en el que esta cargado el cliente a modificar
 * \param tam int el tama�o del array
 * \return void
 *
 */
void modificarUnClienteLocalidad(eClientes clientes[], int tam);


/** \brief modifica el telefono de un cliente existenete en el array
 *
 * \param clientes[] eClientes el array en el que esta cargado el cliente a modificar
 * \param tam int el tama�o del array
 * \return void
 *
 */
void modificarUnClienteTelefono(eClientes clientes[], int tam);


/** \brief modifica la edad de un cliente existenete en el array
 *
 * \param clientes[] eClientes el array en el que esta cargado el cliente a modificar
 * \param tam int el tama�o del array
 * \return void
 *
 */
void modificarUnClienteEdad(eClientes clientes[], int tam);


/** \brief modifica el sexo de un cliente existenete en el array
 *
 * \param clientes[] eClientes el array en el que esta cargado el cliente a modificar
 * \param tam int el tama�o del array
 * \return void
 *
 */
void modificarUnClienteSexo(eClientes clientes[], int tam);


/** \brief promedia la cantidad de hombres por cada mujer y viceversa
 *
 * \param cliente[] eClientes el array de clientes para promediar
 * \param tamC int  el tama�o del array de clientes
 * \return void
 *
 */
void promedioClientes(eClientes cliente[], int tamC);
//void porcentajeClientes(eClientes cliente[], int tamC);
