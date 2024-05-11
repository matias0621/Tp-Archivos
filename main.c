#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

const char nombreDeArchivo[] = {"Archivito"};
const char nombreDeArchivoAlumno[] = {"ArchivitoAlumno"};

typedef struct
{
    int legajo;
    char nombreYApellido[30];
    int edad;
    int anio;
} strAlumno;

int cargarNumero();
void cargarArchivito(int dato);
void mostrarArchivo();
int cantidadDeRegistros();
strAlumno cargarAlumnos(strAlumno alumno);
void cargarArchivoDeAlumnos();
void mostrarAlumnos(strAlumno alumno);
void mostrarArchivoDeAlumno();
void cargarAlFinalArchivoDeAlumno();
void pasarDeUnArchivoAUnaPila(Pila* A);

int main()
{
    /*
    int dato = cargarNumero();
    cargarArchivito(dato);
    dato = cargarNumero();
    cargarArchivito(dato);
    */
    //mostrarArchivo();

    //int registros = cantidadDeRegistros();

    //printf("La cantidad de registros es de: %d", registros);

    //cargarArchivoDeAlumnos();

    //cargarAlFinalArchivoDeAlumno();
    //mostrarArchivoDeAlumno();

    Pila A;
    inicpila(&A);

    pasarDeUnArchivoAUnaPila(&A);
    mostrar(&A);

    return 0;
}

int cargarNumero()
{
    int dato = 0;
    printf("Que numero queries cargar?\n");
    scanf("%d", &dato);
    return dato;
}

void cargarArchivito(int dato)
{
    FILE* buff;

    buff = fopen(nombreDeArchivo, "ab");

    if (buff)
    {
        fwrite(&dato, sizeof(int), 1, buff);
    }


    fclose(buff);
    printf("Se cerro\n");
}

void mostrarArchivo()
{
    FILE* buff;
    int aux;
    buff = fopen("Archivito", "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(int), 1, buff)) > 0)
        {
            printf("Contenido del archivo: %d\n", aux);
        }
    }

    fclose(buff);
}

int cantidadDeRegistros()
{
    FILE* buff;
    int aux;
    int registros = 0;
    buff = fopen(nombreDeArchivo, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(int), 1, buff)) > 0)
        {
            registros++;
        }
    }

    fclose(buff);
    return registros;
}

strAlumno cargarAlumnos(strAlumno alumno)
{

    printf("Ingrese el legajo del alumno\n");
    scanf("%d", &alumno.legajo);
    fflush(stdin);

    printf("Ingrese el nombre y apellido del alumno\n");
    gets(alumno.nombreYApellido);
    fflush(stdin);

    printf("Ingrese la edad del alumnos\n");
    scanf("%d", &alumno.edad);
    fflush(stdin);

    printf("Ingrese el anio del alumnos\n");
    scanf("%d", &alumno.anio);
    fflush(stdin);

    return alumno;
}

void cargarArchivoDeAlumnos()
{
    FILE* buff;
    int i = 0;
    strAlumno a;

    buff = fopen(nombreDeArchivoAlumno, "ab");

    if (buff){
        while(i < 5){
            a = cargarAlumnos(a);
            fwrite(&a, sizeof(strAlumno), 1, buff);
            i++;
        }
    }

    fclose(buff);
}

void mostrarAlumnos(strAlumno alumno){
    printf("/--------------------------------------------------------------/\n");
    printf("Nombre y Apellido: %s\n", alumno.nombreYApellido);
    printf("Anio del alumno en la carrera: %d\n", alumno.anio);
    printf("Edad: %d\n", alumno.edad);
    printf("Legajo: %d\n", alumno.legajo);
    printf("/--------------------------------------------------------------/\n");
}

void mostrarArchivoDeAlumno()
{
    FILE* buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            mostrarAlumnos(aux);
        }
    }

    fclose(buff);
}

void cargarAlFinalArchivoDeAlumno()
{
    FILE* buff;
    char control = 's';
    strAlumno a;

    buff = fopen(nombreDeArchivoAlumno, "ab");

    if (buff){
        while(control == 's'){
            a = cargarAlumnos(a);
            fwrite(&a, sizeof(strAlumno), 1, buff);

            printf("Queres seguir cargando alumnos? presione s para seguir");
            fflush(stdin);
            scanf("%c", &control);
        }
    }

    fclose(buff);
}

void pasarDeUnArchivoAUnaPila(Pila* A){
    FILE* buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            if (aux.edad > 18){
                apilar(A, aux.legajo);
            }
        }
    }

    fclose(buff);
}
