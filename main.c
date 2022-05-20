#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include "pila.h"
#define registroArchivo "registroAlumnos.bin"

typedef struct {
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

// Extra
void mostrarAlumno(const stAlumno alumno);

void agregarAlArchivo(const stAlumno * elemento);       // Ej 1
void leerArchivo();                                     // Ej 2 -> Leo todo el archivo
int cantidadAlumnos();                                  // Ej 3
void cargarCincoAlumno();                               // Ej 4
void mostrarRegistro();                                 // Ej 5
void cargarAlumno();                                    // Ej 6
void pasarLegajos_adultos(Pila * pilaOutput);           // Ej 7
int alumnosMayoresA(const int edad);                    // Ej 8
int alumnosMenoresA(const int edad);                    // Ej 9
int alumnosEntre(const int edad1, const int edad2);     // Ej 9
stAlumno alumnoVeterano();                              // Ej 10
int cursando_anio(const int anio);                      // Ej 11
void agregarAlumnos_alArchivo(stAlumno alumno[], const int validos);                // Ej 12
void pasarRegistro_Arreglo(stAlumno alumno[], int *validos, const int dim);         // Ej 12
int cantidadRegistros();                                // Ej 13
void buscarAlumno_i(const int index);                   // Ej 14

/** 15.Realice una (o varias) funciones que permitan modificar un registro existente en el
    archivo de alumnos. La misma debe permitir modificar uno o todos los campos de la estructura
    y sobreescribir el registro existente en el archivo. */
int buscarAlumno_legajo(const int legajo)
{
    int posicion = -1;
    stAlumno aux;
    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
        while (fread(&aux, sizeof(stAlumno), 1, archivo) >0)
        {
            if(aux.legajo == legajo)
            {
                posicion = ftell(archivo);
            }

        }
        fclose(archivo);
    } else
    {
        printf("Error: no se pudo cargar el archivo.\n");
    }
    return posicion;
}

void modificarAlumno()
{
    int legajo;
    int posicion;
    printf("\n>> Ingrese el legajo del alumno para modificarlo: ");
    fflush(stdin);
    scanf("%d", &legajo);

     posicion = buscarAlumno_legajo(legajo);

    stAlumno aux;
    FILE * archivo = fopen(registroArchivo, "rb");

    if(archivo !=NULL)
    {
        if(posicion >=0)
        {
            fseek(archivo, posicion*sizeof(stAlumno) , SEEK_SET);
            fread(&aux, sizeof(stAlumno), 1, archivo );
            mostrarAlumno(aux) ;
        } else
        {
            printf("No se encuentra el alumno = -1// %d", posicion);
        }
        fclose(archivo);
    } else
    {
        printf("Error: el archivo no se pudo abrir.\n");
    }
}





int main()
{
    setlocale(LC_ALL, "");
    // Genero un elemento para usar.
    stAlumno alumno;
    alumno.legajo = 12702;
    strcpy(alumno.nombreYapellido, "Pablo");
    alumno.anio = 1;
    alumno.edad = 42;

    ///////////////////////////////////////////////////// Ejercicio 1 ////////////////////////////////////////////
//    agregarAlArchivo(&alumno);

    ///////////////////////////////////////////////////// Ejercicio 2 ////////////////////////////////////////////
//    leerArchivo();
//
    ///////////////////////////////////////////////////// Ejercicio 3 ////////////////////////////////////////////
//    printf("El archivo contiene %d registros de alumnos guardados",cantidadAlumnos());

    ///////////////////////////////////////////////////// Ejercicio 4 ////////////////////////////////////////////

//    cargarCincoAlumno();
//    leerArchivo();
    ///////////////////////////////////////////////////// Ejercicio 5 ////////////////////////////////////////////

//    mostrarRegistro();

    ///////////////////////////////////////////////////// Ejercicio 6 ////////////////////////////////////////////

//   cargarAlumno();

    ///////////////////////////////////////////////////// Ejercicio 7 ////////////////////////////////////////////
//    Pila pilaEj7;
//    inicpila(&pilaEj7);
//
//    pasarLegajos_adultos(&pilaEj7);
//    mostrar(&pilaEj7);
    ///////////////////////////////////////////////////// Ejercicio 8 ////////////////////////////////////////////
//    alumnosMayoresA(18);


    ///////////////////////////////////////////////////// Ejercicio 9 ////////////////////////////////////////////


//    leerArchivo();
//    printf("La cantidad de alumnos entre las edades 18 y 40 son: %d", alumnosEntre(42,20));
//

    ///////////////////////////////////////////////////// Ejercicio 10 ////////////////////////////////////////////

//    mostrarAlumno(alumnoVeterano());

    ///////////////////////////////////////////////////// Ejercicio 11 ////////////////////////////////////////////

//    cursando_anio(1);

    ///////////////////////////////////////////////////// Ejercicio 12 ////////////////////////////////////////////

//    stAlumno arregloAlumnoEj12[3];
//    arregloAlumnoEj12[0].legajo = 30;
//    strcpy(arregloAlumnoEj12[0].nombreYapellido, "Alumno extra 1");
//    arregloAlumnoEj12[0].anio = 1;
//    arregloAlumnoEj12[0].edad = 14;
//
//    arregloAlumnoEj12[1].legajo = 31;
//    strcpy(arregloAlumnoEj12[1].nombreYapellido, "Alumno extra 2");
//    arregloAlumnoEj12[1].anio = 1;
//    arregloAlumnoEj12[1].edad = 12;
//
//    arregloAlumnoEj12[2].legajo = 32;
//    strcpy(arregloAlumnoEj12[2].nombreYapellido, "Alumno extra 3");
//    arregloAlumnoEj12[2].anio = 1;
//    arregloAlumnoEj12[2].edad = 77;
//
//    int validos_ej12 = 3;
//
//    agregarAlumnos_alArchivo(arregloAlumnoEj12,validos_ej12);
//
//    mostrarRegistro();
//
//    stAlumno arregloEj12[30];
//    int dim_ej12 = 30;
//    int validosEj12 = 0;
//
//    pasarRegistro_Arreglo(&arregloEj12, &validosEj12, dim_ej12);
//
//    printf("\n\n                        El array contiene los alumnos: \n\n");
//    for(int i=0; i<validosEj12;i++)
//    {
//        mostrarAlumno(arregloEj12[i]);
//    }

    ///////////////////////////////////////////////////// Ejercicio 13 ////////////////////////////////////////////

//    mostrarRegistro();
//    printf("\n\n                Cantidad de registros: %i.\n\n",cantidadRegistros());

    ///////////////////////////////////////////////////// Ejercicio 14 ////////////////////////////////////////////

//    buscarAlumno_i(12);
//    printf("\n\n                        Registro de alumnos: \n\n\n");
//    mostrarRegistro();

    ///////////////////////////////////////////////////// Ejercicio 15 ////////////////////////////////////////////


    mostrarRegistro();
    modificarAlumno();


    printf("\n\n>>>                             Fin programa. !\n");
    return 0;
}



// Extra
void mostrarAlumno(const stAlumno alumno)
{
    printf("................................... \n");
    printf("Nombre: %s\n", alumno.nombreYapellido);
    printf("Legajo: %d\n", alumno.legajo);
    printf("Edad: %d\n", alumno.edad);
    printf("Cursando el año: %d\n", alumno.anio);
    printf("................................... \n");
}


/** 1. Hacer una función que agregue un elemento al final de un archivo. */
void agregarAlArchivo(const stAlumno * elemento)
{
    // Crear un archivo.
    FILE * archivo = fopen(registroArchivo, "a" );

    // Ver que existe el archivo, si es nulo significa que no existe.
    if (archivo !=NULL)
    {
        fwrite(elemento, sizeof(stAlumno), 1, archivo);
        printf("Se cargo con éxito en el archivo. \n");
        //NOOOO olvidar de cerrar el archivo
        fclose(archivo);
    } else
    {
        printf("Error: no se puede cargar el archivo. \n");
    }
}

/** 2. Hacer una función que muestre por pantalla el contenido de un archivo. */
void leerArchivo()
{
    stAlumno alumnoAux;
    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&alumnoAux, sizeof(stAlumno), 1,archivo) > 0)
        {
            printf("................................... \n");
            printf("Nombre: %s\n", alumnoAux.nombreYapellido);
            printf("Legajo: %d\n", alumnoAux.legajo);
            printf("Edad: %d\n", alumnoAux.edad);
            printf("Cursando el año: %d\n", alumnoAux.anio);
            printf("................................... \n");
        }
        fclose(archivo);
    }else
    {
        printf("Error: no se puede cargar el archivo. \n");
    }
}

/** 3. Hacer una función que retorne la cantidad de registros que contiene un archivo. */
int cantidadAlumnos()
{
    int contador = 0;
    stAlumno aux; // preguntar si es necesario el la creacion de esta variable o puedo tirar ese dato...
    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&aux, sizeof(stAlumno), 1 ,archivo))
        {
            contador++;
        }
        fclose(archivo);
    }
    return contador;
}


/** 4. Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar
    si el archivo ya está creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la función    */
void cargarCincoAlumno()
{
    FILE * archivo = fopen(registroArchivo, "ab"); // al usar ab estoy añadiendo datos al final
    stAlumno aux;
    char nombre[30];
    if(archivo!= NULL)
    {
        for(int i = 1; i<=5; i++)
        {
            // Cargo un alumno con todos los campos que tiene.
            printf("            Carga alumnos [%i] / 5\n\n",i);
            printf("> Ingrese su nombre y apellido: \n");
            fflush(stdin);
            gets(nombre);
            strcpy(aux.nombreYapellido, nombre);
            fflush(stdin);
            printf("> Ingrese su legajo:\n");
            fflush(stdin);
            scanf("%i", &aux.legajo);
            printf("> Ingrese su edad:\n");
            fflush(stdin);
            scanf("%i", &aux.edad);
            printf("> Ingrese que año cursa:\n");
            fflush(stdin);
            scanf("%i", &aux.anio);

            // Ahora cargo ese alumno al archivo.
            fwrite(&aux, sizeof(stAlumno), 1 , archivo);

        }
        fclose(archivo); // no olvidar cerrar el archivo.
    } else
    {
        printf("Error, no se pudo abrir el archivo.\n");
    }
}

/** 5. Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.*/
void mostrarRegistro()
{
    stAlumno aux;
    FILE * archivo = fopen("registroAlumnos.bin", "rb");
    if(archivo != NULL)
    {
        while(fread(&aux, sizeof(stAlumno), 1, archivo) > 0)
        {
            mostrarAlumno(aux);
        }
        fclose(archivo);
    } else
    {
        printf("Error: no se pudo cargar el archivo.\n");

    }
}

/** 6. Crear una función que permita agregar de a un elemento al final del archivo.
    O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo
    struct alumno), se escribe en el archivo y se cierra.*/
    // Igual al 4 pero cargando solo uno???
void cargarAlumno()
{
    FILE * archivo = fopen(registroArchivo, "ab"); // al usar ab estoy añadiendo datos al final
    stAlumno aux;
    char nombre[30];
    if(archivo!= NULL)
    {
        // Cargo un alumno con todos los campos que tiene.
        printf("            Cargar un alumno \n\n");
        printf("> Ingrese su nombre y apellido: \n");
        fflush(stdin);
        gets(nombre);
        strcpy(aux.nombreYapellido, nombre);
        fflush(stdin);
        printf("> Ingrese su legajo:\n");
        fflush(stdin);
        scanf("%i", &aux.legajo);
        printf("> Ingrese su edad:\n");
        fflush(stdin);
        scanf("%i", &aux.edad);
        printf("> Ingrese que año cursa:\n");
        fflush(stdin);
        scanf("%i", &aux.anio);

        // Ahora cargo ese alumno al archivo.
        fwrite(&aux, sizeof(stAlumno), 1 , archivo);

        fclose(archivo); // no olvidar cerrar el archivo.
    } else
    {
        printf("Error, no se pudo abrir el archivo.\n");
    }
}


/** 7. Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad. */
void pasarLegajos_adultos(Pila * pilaOutput)
{
    stAlumno aux;
    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&aux, sizeof(stAlumno),1, archivo))
        {
            if(aux.edad >=18)
            {
                apilar(pilaOutput, aux.legajo);
            }
        }
        fclose(archivo);
    } else
    {
        printf("Error, no se pudo cargar el archivo.");
    }

}

/** 8. Dado un archivo de alumnos, hacer una función que cuente la cantidad
    de alumnos mayores a edad específica que se envía por parámetro.*/

int alumnosMayoresA(const int edad)
{
    int contador = 0;
    stAlumno aux;
    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&aux, sizeof(stAlumno),1, archivo))
        {
            if(aux.edad >= edad)
            {
                contador++;
            }
        }
        fclose(archivo);
    } else
    {
        printf("Error, no se pudo cargar el archivo.\n");
    }
    return contador;
}

/** 9.Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos
    entre un rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe
    recibirse por parámetro. Modularizar*/

int  alumnosMenoresA(const int edad)
{
    int contador = 0;
    stAlumno aux;
    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&aux, sizeof(stAlumno),1, archivo))
        {
            if(aux.edad < edad)
            {
                contador++;
            }
        }
        fclose(archivo);
    } else
    {
        printf("Error, no se pudo cargar el archivo.\n");
    }
    return contador;
}

int alumnosEntre(const int edad1, const int edad2)
{
    int cantidad = 0;
    if(edad1<edad2)
    {
        cantidad = alumnosMenoresA(edad2+1) - alumnosMenoresA(edad1); // le sumo 1 para que cuente el tope de edad mayor y menor
    } else
    {
        cantidad = alumnosMenoresA(edad1+1) - alumnosMenoresA(edad2);
    }
    return cantidad;

}

/** 10. Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.*/
stAlumno alumnoVeterano()
{
    stAlumno aux;
    stAlumno veterano;
    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
        fread(&veterano, sizeof(stAlumno), 1, archivo);
        while(fread(&aux, sizeof(stAlumno),1, archivo))
        {
            if(aux.edad > veterano.edad)
            {
                veterano = aux;
            }
        }
        fclose(archivo);
    } else
    {
        printf("Error: no se pudo abrir el archivo.\n");
    }
    return veterano;
}


/** 11. Crear una función que retorne la cantidad de alumnos que cursan
    un determinado año. El año buscado se pasa por parámetro. */

int cursando_anio(const int anio)
{
    int contador;
    stAlumno aux;
    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
        while(fread(&aux, sizeof(stAlumno),1, archivo))
        {
            if(aux.anio == anio)
            {
                contador++;
            }
        }
        fclose(archivo);
    } else
    {
        printf("Error: no se pudo abrir el archivo.\n");
    }
    return contador;
}

/** 12. Crear una función que reciba como parámetro un arreglo de tipo alumno y
    lo copie en el archivo. Asimismo, realice otra función que pase los elementos del
    archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.*/

void agregarAlumnos_alArchivo(stAlumno alumno[], const int validos)
{

    FILE * archivo = fopen(registroArchivo, "ab");
    if(archivo != NULL)
    {
        for(int i=0; i<validos; i++)
        {
            fwrite(&alumno[i], sizeof(stAlumno), 1, archivo);
        }
        fclose(archivo);
    } else
    {
        printf("Error: el archivo no se pudo cargar.\n");
    }

}

void pasarRegistro_Arreglo(stAlumno alumno[], int *validos, const int dim)
{
    stAlumno aux;

    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
       int i=0;
       while(fread(&aux,sizeof(stAlumno),1, archivo)>0 && *validos<dim)
       {
           alumno[*validos] = aux;
           *validos += 1;
       }
        fclose(archivo);
    } else
    {
        printf("Error: el archivo no se pudo cargar.\n");
    }

}

/** 13.Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y
    ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de
    registros de cualquier archivo.*/
int cantidadRegistros()
{
    int bytes;
    int cantidad;
    FILE * archivo = fopen(registroArchivo,"rb");
    if(archivo != NULL)
    {
        fseek(archivo,0,SEEK_END); // fseek(archivoquetrabajo, lugares que me corro, donde me paro )
        bytes = ftell(archivo); // retorna los bytes que recorrio hasta donde esta parado el puntero
        cantidad = bytes / sizeof(stAlumno);
        fclose(archivo);
    } else
    {
        printf("Error: no se pudo cargar el archivo.\n");
    }
    return cantidad;
}


/** 14.Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una
    función que muestre el contenido de un registro, cuyo número (entre 0 y 9)
    se pase por parámetro. Controlar no sobrepasar los límites del archivo.*/
void buscarAlumno_i(const int index)
{
    stAlumno aux;
    FILE * archivo = fopen(registroArchivo, "rb");
    if(archivo != NULL)
    {
        if(index<10 && index>=0 && cantidadRegistros(archivo)>=10)
        {
            fseek(archivo, sizeof(stAlumno)*index,SEEK_SET);
            fread(&aux, sizeof(stAlumno), 1, archivo);
            mostrarAlumno(aux);
        }else
        {
            printf("Error, el registro no cuenta con 10 alumnos o el indice no es de 0 a 9");
        }
        fclose(archivo);
    } else
    {
        printf("Error: no se pudo cargar el archivo.\n");
    }
}
