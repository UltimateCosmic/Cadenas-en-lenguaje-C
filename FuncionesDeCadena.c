/* 
 * Proyecto: CadenasDeCaracteres
 * Archivo:  FuncionesDeCadena.c
 * Autor:    Johan Carlo Amador Egoavil
 * Codigo:   20203350
 * 
 * Creado el 6 de junio de 2022, 08:29 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesDeCadena.h"

FILE *abrirArchivo(const char *nombreDeArchivo, const char *modoDeApertura){
    FILE *arch = fopen(nombreDeArchivo,modoDeApertura);
    if(arch==NULL){
        printf("ERROR: No se pudo abrir el archivo %s\n",nombreDeArchivo);
        exit(1);
    }
    return arch;
}

void leerLibros(int *arrLibro, char **arrNombre, double *arrPrecio, int *i){    
    FILE *arch = abrirArchivo("Libros.txt","r");
    int nc;
    char nombreAux[60];
    while(1){
        fscanf(arch,"%d",&arrLibro[*i]);
        if(feof(arch)) break;
        leerNombre(arch,nombreAux);        
        nc=strlen(nombreAux);
        arrNombre[*i]=(char*)malloc(sizeof(char)*(nc+1));        
        strcpy(arrNombre[*i],nombreAux);
        fscanf(arch,"%lf",&arrPrecio[*i]);
        (*i)++;
    }   
    fclose(arch);
}

void leerNombre(FILE *arch, char *arrNombre){    
    int nc, condicion=1;
    char palabra[20], nombre[60]={};        
    while(condicion){
        fscanf(arch,"%s",palabra);  
        if(verificarUltimaPalabra(palabra)) condicion=0;
        modificarPalabra(palabra);
        strcat(nombre,palabra);
    }
    strcpy(arrNombre,nombre);    
}

/*char *leerCadena(FILE *arch){
    char *pt, palabra[20];
    int nc;
    fscanf(arch,"%s",palabra);
    nc=strlen(palabra);
    pt=(char*)malloc(sizeof(char)*(nc+1));
    strcpy(pt,palabra);
    return pt;
}*/

int verificarUltimaPalabra(char *palabra){
    int i;
    for(i=0; palabra[i]; i++);
    if(palabra[i-1]==',') return 1;
    else return 0;
}

void modificarPalabra(char *palabra){    
    for(int i=0; palabra[i]; i++){
        if(i==3) palabra[i]=0;
        else if(i==0) palabra[i]=convertirMayusc(palabra[i]);
        else if(palabra[i]==0) palabra[i]='X';
        else palabra[i]=convertirMinusc(palabra[i]);
    }
}

char convertirMayusc(char c){
    return c-=(c>='a'&&c<='z'?'a'-'A':0);   
}

char convertirMinusc(char c){
    return c+=(c>='A'&&c<='Z'?'a'-'A':0);   
}

void imprimirLibros(int *arrLibro, char **arrNombre, double *arrPrecio,
                    int cantLibros){    
    for(int i=0; i<cantLibros; i++)      
        printf("%03d) - %03d | %-35s S/. %.2lf\n",i+1,arrLibro[i],arrNombre[i],
                arrPrecio[i]);  
}