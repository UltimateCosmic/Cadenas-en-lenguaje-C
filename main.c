/* 
 * Proyecto: CadenasDeCaracteres
 * Archivo:  main.c
 * Autor:    Johan Carlo Amador Egoavil
 * Codigo:   20203350
 * 
 * Creado el 6 de junio de 2022, 08:29 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesDeCadena.h"
#define MAX_LIBROS 300

int main(int argc, char** argv) {
    
    int arrLibro[MAX_LIBROS], cantLibros=0;
    char *arrNombre[MAX_LIBROS]={};
    double arrPrecio[MAX_LIBROS];
    leerLibros(arrLibro,arrNombre,arrPrecio,&cantLibros);
    imprimirLibros(arrLibro,arrNombre,arrPrecio,cantLibros);
    
    return (EXIT_SUCCESS);
}

