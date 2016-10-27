#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"


int main()
{
    char seguir='s';
    int opcion=0;

    EMovie movies[TAM_PELICULAS];
    ///LINKS DE IMAGENES PARA PROBAR///
    //https://jhonantony.wikispaces.com/file/view/karate_kid_poster6.jpg/178352987/karate_kid_poster6.jpg (KARATE KID)
    //https://i.ytimg.com/vi/EDj6EtOrPlE/hqdefault.jpg (TONTO Y RE TONTO)
    //http://image.tmdb.org/t/p/w396/r93YGoEY16PdSjSQGrDRJsVhCTB.jpg (LA FAMILIA DEL FUTURO)
    //https://www.uphe.com/sites/default/files/styles/scale__344w_/public/Warcraft_PosterArt.jpg?itok=WyhZZIv6(WARCRAFT)

    peliculas_inicializar(movies, TAM_PELICULAS);
    peliculas_carga(movies,TAM_PELICULAS);
    generar_idMovie(movies,TAM_PELICULAS);
    system("cls");
    while(seguir=='s')
    {
        printf("*|||||||MENU PRINCIPAL||||||*\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                peliculas_agregar(movies,TAM_PELICULAS);
                break;
            case 2:
                peliculas_borrar(movies,TAM_PELICULAS);
                break;
            case 3:
                peliculas_editar(movies, TAM_PELICULAS);
               break;
            case 4:
                peliculas_generarWeb(movies,"Movies.html",TAM_PELICULAS);
                break;
            case 5:
                printf("\nSaliendo de la aplicacion...\n\n");
                seguir = 'n';
                break;
            default:
                printf("\n%d No es una opcion valida",opcion);
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
