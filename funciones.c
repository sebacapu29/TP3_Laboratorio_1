#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void peliculas_agregar(EMovie* movies, int tam)
{
    FILE* pArchivo;

    char buffer[5000];
    int indiceLibre;

    int cantidad;

    pArchivo = fopen("Movies.dat","ab");///Agrega peliculas al archivo .dat
    indiceLibre = buscarLugarVacio(movies,tam);
    if(pArchivo != NULL)
        {
            if(indiceLibre!=-1)
                {
                system("cls");
                printf("\n|||||||ALTA PELICULAS|||||||\n\n");

                printf("\nIngrese titulo: ");
                capturarCadena(buffer,"\nError. Ingrese titulo valido: ",50);

                //////////////////////////////////////////////
                strcpy(movies[indiceLibre].titulo,buffer);
                //////////////////////////////////////////////
                printf("\nIngrese genero: ");
                capturarCadena(buffer,"\nError. Ingrese genero valido: ",50);
                //////////////////////////////////////////////
                strcpy(movies[indiceLibre].genero,buffer);
                //////////////////////////////////////////////

                printf("\nIngresar duracion: ");
                fflush(stdin);
                gets(buffer);
                while(!esNumeroYPositivo(buffer))
                    {
                        printf("\nError. Ingrese duracion valido: ");
                        fflush(stdin);
                        gets(buffer);
                    }
                //////////////////////////////////////////////
                movies[indiceLibre].duracion = atoi(buffer);
                //////////////////////////////////////////////

                printf("\nIngrese descripcion: ");
               capturarCadena(buffer,"\nError. Ingrese descripcion valido: ",250);
                ////////////////////////////////////////////////
                strcpy(movies[indiceLibre].descripcion,buffer);
                ////////////////////////////////////////////////
                printf("\nIngresar puntaje: ");
                fflush(stdin);
                gets(buffer);
                while(!esNumeroYPositivo(buffer))
                    {
                        printf("\nError. Ingrese puntaje valido: ");
                        fflush(stdin);
                        gets(buffer);
                    }
                //////////////////////////////////////////
                movies[indiceLibre].puntaje =atoi(buffer);
                //////////////////////////////////////////

                printf("\nIngrese link de la Imagen: ");
                fflush(stdin);
                gets(buffer);
                strcpy(movies[indiceLibre].linkImagen,buffer);
                ////////////////////////////////////////
                movies[indiceLibre].estado = HABILITADA;
                ////////////////////////////////////////
                cantidad = fwrite(&movies[indiceLibre],sizeof(EMovie),1,pArchivo);///Sino agrego los datos de la estructura

                if(cantidad<1)
                {
                        printf("Ha ocurrido un error al cargar los datos");
                        exit(1);
                }
                else
                {
                    printf("\n\nSe cargo pelicula con exito!***/\n\n");
                }
            }
            else
            {
                printf("\nNo hay espacio para agregar otra pelicula.\n");
            }
        }
        fclose(pArchivo);
}


int buscarLugarVacio(EMovie* movies, int tam)
{
    int i;
    int indice=-1;

    for(i=0; i<tam; i++)
    {
        if(movies[i].estado == VACIO)////Encuentra libre lugar
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void peliculas_mostrar(EMovie* movies,int tamMovies)
{
    int i;

    for(i=0; i<tamMovies; i++)
    {
        if(movies[i].estado==HABILITADA)
        {
            printf("->Titulo : %s \n",movies[i].titulo);
            printf("->Genero : %s \n",movies[i].genero);
            printf("->Duracion : %d \n",movies[i].duracion);
            printf("->Descripcion : %s \n",movies[i].descripcion);
            printf("->Puntaje : %d \n",movies[i].puntaje);
            printf("->Link imagen : %s \n",movies[i].linkImagen);
            printf("->Id: %d\n\n",movies[i].idMovie);
        }
    }
}

void peliculas_inicializar(EMovie* movies, int tamMovies)
{
     int i;
     for(i=0;i<tamMovies;i++)
     {
        movies[i].estado = VACIO;
     }
}



void peliculas_generarWeb(EMovie* movies, char* nombre, int tamMovies)
{
    FILE* pArchivo;
    int i;

    pArchivo = fopen(nombre,"w");

        for(i=0;i<tamMovies;i++)
        {
            if(movies[i].estado == 1)
            {
                fprintf(pArchivo, "<article class='col-md-4 article-intro'> \n <a href='#'> \n");
                fprintf(pArchivo, "<img class='img-responsive img-rounded' src='%s' alt=''> \n",movies[i].linkImagen);
                fprintf(pArchivo, "</a> \n <h3> \n <a href='#'> %s </a> \n ",movies[i].titulo);
                fprintf(pArchivo," </h3> \n <ul> \n <li>Género: %s </li> \n ",movies[i].genero);
                fprintf(pArchivo,"<li>Puntaje: %d </li> \n ",movies[i].puntaje);
                fprintf(pArchivo,"<li>Duración: %d </li> \n </ul> \n",movies[i].duracion);
                fprintf(pArchivo, "<p> %s </p></article> \n",movies[i].descripcion);
            }
        }
        printf("\n\n***Pagina web Generada con exito!!***\n\n");

        fclose(pArchivo);
}
int peliculas_borrar(EMovie* movies, int tamMovies)///MOSTRAR
{
    int id;
    int indiceEncontrado;
    int retorno=0;
    system("cls");
    printf("\n|****BAJA DE PELICULAS****|\n\n");

    peliculas_mostrar(movies,tamMovies);
    printf("\n->Ingrese el id de la pelicula: ");
    scanf("%d", &id);
    indiceEncontrado = peliculas_buscar(movies,TAM_PELICULAS,id);

    if(indiceEncontrado!=-1)
    {
        movies[indiceEncontrado].estado=INHABILITADA;
        retorno =1;
        printf("\nOperacion realizada con Exito!\n\n");
    }
    else
    {
        printf("\nNo se encontro abonado solicitado\n");
    }
    return retorno;
}
void peliculas_carga(EMovie* movies, int tamMovies)
{
    int i=0;
    FILE* pArchivo;

    pArchivo = fopen("Movies.dat","rb");
    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            fread(&movies[i],sizeof(EMovie),tamMovies,pArchivo);
            i++;
        }
        printf("\n\n***|Carga de peliculas con exitos***|\n\n");
    }
    else
    {
        printf("\n\n***|No existe archivo, se creara un archivo nuevo al cargar pelicula***|\n\n");
    }
    system("pause");
    fclose(pArchivo);
}

int peliculas_buscar(EMovie* movies, int tamMovies, int id)
{
    int i;
    int idEncontrado=-1;
    for(i=0;i<tamMovies;i++)
    {
        if(movies[i].idMovie == id)
        {
            idEncontrado = i;
            break;
        }
    }
    return idEncontrado;
}

void peliculas_editar(EMovie* movies, int tamMovies)///incompleta
{
    int idMovie;
    int indiceEncontrado;
    int opcion;
    char cadAux[200];
    system("cls");
    printf("\n\n|****EDITAR DATOS DE PELICULAS****|\n\n");
    peliculas_mostrar(movies,tamMovies);
    printf("\n->Ingrese id de pelicula a modificar: ");
    scanf("%d",&idMovie);
    indiceEncontrado = peliculas_buscar(movies,TAM_PELICULAS,idMovie);
    if(indiceEncontrado!=-1 && movies[indiceEncontrado].estado==HABILITADA)
    {
        printf("\n/****Seleccione opcion a modificar****/ ");
        printf("\n1)Titulo\n");
        printf("\n2)Genero\n");
        printf("\n3)Descripcion\n");
        printf("\n4)Duracion\n");
        printf("\n5)Link Imagen\n->");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("\nIngrese titulo: ");
                fflush(stdin);
                gets(cadAux);
                strcpy(movies[indiceEncontrado].titulo,cadAux);
                printf("\n\nOperacion realizada con exito!\n\n");
                break;
            case 2:
                printf("\nIngrese Genero: ");
                fflush(stdin);
                gets(cadAux);
                strcpy(movies[indiceEncontrado].genero,cadAux);
                 printf("\n\nOperacion realizada con exito!\n\n");
                break;
            case 3:
                printf("\nIngrese Descripcion: ");
                fflush(stdin);
                gets(cadAux);
                strcpy(movies[indiceEncontrado].descripcion,cadAux);
                printf("\n\nOperacion realizada con exito!\n\n");
                break;
            case 4:
                printf("\nIngrese Duracion: ");
                scanf("%d", &movies[indiceEncontrado].duracion);
                printf("\n\nOperacion realizada con exito!\n\n");
                break;
            case 5:
                printf("\nLink Imagen: ");
                fflush(stdin);
                gets(cadAux);
                strcpy(movies[indiceEncontrado].linkImagen,cadAux);
                printf("\n\nOperacion realizada con exito!\n\n");
                break;
            default:
                printf("\n%d no es una opcion valida \n", opcion);
                break;
        }
    }
    else
    {
        printf("\nNo se encontro pelicula con ese Id\n");
    }
}
void generar_idMovie(EMovie* movies,int tamMovies)
{
    int i;
    for(i=1; i<tamMovies;i++)
    {
        if(movies[0].estado==VACIO)
        {
            movies[0].idMovie=5000;
        }
        else
        {
            movies[i].idMovie= (movies[i-1].idMovie)+1;
        }
    }
}

