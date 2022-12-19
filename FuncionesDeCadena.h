/* 
 * Proyecto: CadenasDeCaracteres
 * Archivo:  FuncionesDeCadena.h
 * Autor:    Johan Carlo Amador Egoavil
 * Codigo:   20203350
 * 
 * Creado el 6 de junio de 2022, 08:29 AM
 */

#ifndef FUNCIONESDECADENA_H
#define FUNCIONESDECADENA_H

FILE *abrirArchivo(const char *, const char *);
void leerLibros(int *, char **, double *, int *);
void leerNombre(FILE *, char *);
char *leerCadena(FILE *);
int verificarUltimaPalabra(char *);
void modificarPalabra(char *);
char convertirMayusc(char c);
char convertirMinusc(char c);
void imprimirLibros(int *, char **, double *, int);

#endif /* FUNCIONESDECADENA_H */

