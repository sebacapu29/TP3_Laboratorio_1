#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "validaciones.h"

#define TAM_PELICULAS 10

#define VACIO 0
#define HABILITADA 1
#define INHABILITADA 2

#define MAX_DESCRIPCION 700
typedef struct{

    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[120];
    int estado;
    int idMovie;
}EMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movies Array de estructuras a ser agregada al archivo
 *  @return retorna vacio
 */
void peliculas_agregar(EMovie* movies, int tam);


/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int peliculas_borrar(EMovie* movie, int tamMovies);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void peliculas_generarWeb(EMovie* lista, char* nombre, int tamMovies);

/** \brief Carga los valores del Array de estructuras en VACIO (0)
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 * \return vacio.
 *
 */

void peliculas_inicializar(EMovie* movies, int tamMovies);

/** \brief Se encarga de leer los datos del archivo binario y agregarlos a la estructura vacia.
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 * \return vacio
 *
 */

void peliculas_carga(EMovie* movies, int tamMovies);

/** \brief Muestra el Array de peliculas que estan HABILITADAS (1)
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 * \return vacio.
 *
 */

void peliculas_mostrar(EMovie* movies,int tamMovies);

/** \brief Se encarga de buscar el Id solicitado en el Array de estructura, peliculas
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 * \param  id, Entero que representa el id a buscar.
 * \return Un Entero, distinto de -1 si lo encontro o -1 si no lo encontro.
 *
 */

int peliculas_buscar(EMovie* movies, int tamMovies, int id);

/** \brief Se encarga de modificar algun campo del Array de estructuras, peliculas.
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 * \return vacio.
 *
 */

void peliculas_editar(EMovie* movies, int tamMovies);

/** \brief Genera los campos id del Array de peliculas
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 * \return Vacio.
 *
 */

void generar_idMovie(EMovie* movies,int tamMovies);

/** \brief Busca en el campo estado del Array de estructuras peliculas el valor 0 (VACIO)
 *
 * \param movies, Array de estructuras peliculas
 * \param tamMovies, Entero que representa la cantidad de peliculas
 * \return Un Entero, indicando el indice encontrado o -1 si no lo encontro.
 *
 */

int buscarLugarVacio(EMovie* movies, int tam);


#endif // FUNCIONES_H_INCLUDED
