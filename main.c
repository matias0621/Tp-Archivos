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
int cantidadDeAlumnosPorEdad(int edad);
void mostrarAlumnosPorMargenDeEdad(int edadMinima, int edadMaxima);
int cantidadDeAlumnosPorAnio(int anio);
void mostrarAlumnoDeMayorEdad();
void buscarAlumnoDeMayorEdad();
void mostrarDatorDelAlumnoMayor(int edadDelMayor);
void cantidadDeRegistrosPorSeek();
void mostrarPorRegistro(int registro);
void sobreEscribirAlumno(int posicion);

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

    /*
    Pila A;
    inicpila(&A);

    pasarDeUnArchivoAUnaPila(&A);
    mostrar(&A);
    */

    /*
    int edad = cargarNumero();

    int cantidad = cantidadDeAlumnosPorEdad(edad);

    printf("La cantidad de alumnos de %d de edad es de %d", edad, cantidad);
    */

    /*
    int edadMinima = cargarNumero();
    int edadMaxima = cargarNumero();

    mostrarAlumnosPorMargenDeEdad(edadMinima, edadMaxima);
    */

    /*
    int anio = cargarNumero();

    int cantidad = cantidadDeAlumnosPorAnio(anio);

    printf("La cantidad de alumnos del anio %d es de %d", anio, cantidad);
    */

    //buscarAlumnoDeMayorEdad();

    //cantidadDeRegistrosPorSeek();

    /*
    int registro = cargarNumero();
    mostrarPorRegistro(registro);
    */
    /*
    int posicion = cargarNumero();
    sobreEscribirAlumno(posicion);
    */
    //mostrarArchivoDeAlumno();
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

    if (buff)
    {
        while(i < 5)
        {
            a = cargarAlumnos(a);
            fwrite(&a, sizeof(strAlumno), 1, buff);
            i++;
        }
    }

    fclose(buff);
}

void mostrarAlumnos(strAlumno alumno)
{
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

    if (buff)
    {
        while(control == 's')
        {
            a = cargarAlumnos(a);
            fwrite(&a, sizeof(strAlumno), 1, buff);

            printf("Queres seguir cargando alumnos? presione s para seguir");
            fflush(stdin);
            scanf("%c", &control);
        }
    }

    fclose(buff);
}

void pasarDeUnArchivoAUnaPila(Pila* A)
{
    FILE* buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            if (aux.edad > 18)
            {
                apilar(A, aux.legajo);
            }
        }
    }

    fclose(buff);
}

int cantidadDeAlumnosPorEdad(int edad)
{
    int cantidadDeAlumnosDeXEdad = 0;
    FILE* buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            if (aux.edad > 18)
            {
                cantidadDeAlumnosDeXEdad++;
            }
        }
    }

    return cantidadDeAlumnosDeXEdad;
}

void mostrarAlumnosPorMargenDeEdad(int edadMinima, int edadMaxima)
{
    FILE* buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            if (aux.edad > edadMinima && aux.edad < edadMaxima)
            {
                mostrarAlumnos(aux);
            }
        }
    }
}

int cantidadDeAlumnosPorAnio(int anio)
{
    int cantidadDeAlumnosDeXAnio = 0;
    FILE* buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            if (aux.anio == anio)
            {
                cantidadDeAlumnosDeXAnio++;
            }
        }
    }

    return cantidadDeAlumnosDeXAnio;
}

void buscarAlumnoDeMayorEdad()
{
    int edadDelMayor = 0;
    FILE* buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            if (edadDelMayor < aux.edad)
            {
                edadDelMayor = aux.edad;
            }
        }
    }
    fclose(buff);
    mostrarDatorDelAlumnoMayor(edadDelMayor);
}

void mostrarDatorDelAlumnoMayor(int edadDelMayor)
{

    FILE* buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff)
    {
        while((fread(&aux, sizeof(strAlumno), 1, buff)) > 0)
        {
            if (edadDelMayor == aux.edad)
            {
                mostrarAlumnos(aux);
            }
        }
    }

    fclose(buff);
}

void cantidadDeRegistrosPorSeek(){
    FILE * buff = fopen(nombreDeArchivoAlumno, "rb");

    int cant = 0;

    if (buff != NULL){
        fseek(buff, 0, SEEK_END);

        cant = ftell(buff);

        cant = cant/sizeof(strAlumno);

        printf("La cantidad de registros es de: %d", cant);
    }

    fclose(buff);
}

void mostrarPorRegistro(int registro){
    FILE * buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "rb");

    if (buff){
        rewind(buff);
        fseek(buff, 0, SEEK_SET);
        fread(&aux, sizeof(strAlumno)*registro,1,buff);
        mostrarAlumnos(aux);
    }
    fclose(buff);
}

void sobreEscribirAlumno(int posicion){
    FILE * buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "r+b");

    if (buff){
        rewind(buff);
        fseek(buff, sizeof(strAlumno) * posicion, SEEK_SET);
        cargarAlumnos(aux);
        fwrite(&aux, sizeof(strAlumno), 1, buff);
    }
    fclose(buff);
}

void modificarRegistro(int pos){
    FILE * buff;
    strAlumno aux;
    buff = fopen(nombreDeArchivoAlumno, "r+b");

    if (buff){
        fseek(buff, sizeof(aux)*(pos-1), SEEK_SET);
        fread(&aux, sizeof(strAlumno),1,buff);

        aux = cargarAlumnos(aux);

        fseek(buff, sizeof(alumno) * (-1), SEEK_CUR);
        fwrite(&a, sizeof(alumno), 1, buff);
    }
    fclose(buff);
}

void invertirArchivo(){
    FILE * buff;
    strAlumno aux, aux1, auxFinal;
    int inicio = 0, fin = 0, cantidad = 0;
    buff = fopen(nombreDeArchivoAlumno, "r+b");

    if (buff){
        fseek(buff, 0, SEEK_END);
        cantidad = ftell(buff)/ sizeof(strAlumno);
        fin = cantidad - 1;

        while(inicio < fin){
            fseek(archi, inicio * sizeof(strAlumno), SEEK_SET);
            fread(&aux, sizeof(strAlumno), 1, buff);

            fseek(buff, fin*sizeof(strAlumno), SEEK_SET);
            fread(&aux2, sizeof(strAlumno), 1, buff);

            fseek(archi, inicio * sizeof(strAlumno), SEEK_SET);
            fwrite(&aux2, sizeof(strAlumno), 1, buff);

            fseek(archi, fin * sizeof(strAlumno), SEEK_SET);
            fwrite(&aux, sizeof(strAlumno), 1, buff);

            inicio++;
            fin--;
        }
    }
    fclose(buff);
}
