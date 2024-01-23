#include <stdio.h>
#include <string.h>

struct InformacionAlumnos {
    int matricula;
    char nombre[50];
    char direccion[50];
    char materia[50];
    float nota;
};

void ingresarInformacion(struct InformacionAlumnos alumnos[], int *CantAlumnos);
void mostrarInformacion(struct InformacionAlumnos alumnos[], int CantAlumnos);


int main() {
    struct InformacionAlumnos alumnos[50];
    int CantAlumnos = 0;
    int opcion;

    do {
        printf("\nMenu De Seleccion:\n");
        printf("1. Ingresar estudiantes\n");
        printf("2. Mostrar guardados\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        fflush(stdin);

        switch (opcion) {
            case 1:
                ingresarInformacion(alumnos, &CantAlumnos);
                break;
            case 2:
                mostrarInformacion(alumnos, CantAlumnos);
                break;
            case 3:
                printf("Finalizando el programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}

void ingresarInformacion(struct InformacionAlumnos alumnos[], int *CantAlumnos) {
    if (*CantAlumnos < 50) {
        printf("Nombre: ");
        fflush(stdin);
        fgets(alumnos[*CantAlumnos].nombre, 50, stdin);
        alumnos[*CantAlumnos].nombre[strcspn(alumnos[*CantAlumnos].nombre, "\n")] = '\0';

        printf("\nMatricula: ");
        scanf("%d", &alumnos[*CantAlumnos].matricula);
        fflush(stdin);

        printf("Direccion: ");
        fflush(stdin);
        fgets(alumnos[*CantAlumnos].direccion, 50, stdin);
        alumnos[*CantAlumnos].direccion[strcspn(alumnos[*CantAlumnos].direccion, "\n")] = '\0';

        printf("Carrera: ");
        fflush(stdin);
        fgets(alumnos[*CantAlumnos].materia, 50, stdin);
        alumnos[*CantAlumnos].materia[strcspn(alumnos[*CantAlumnos].materia, "\n")] = '\0';
        
        printf("Nota: ");
        scanf("%f", &alumnos[*CantAlumnos].nota);

        (*CantAlumnos)++;
        printf("\tDatos guardados.\n");
    } else {
        printf("No se pueden añadir mas datos.\n");
    }
}

void mostrarInformacion(struct InformacionAlumnos alumnos[], int CantAlumnos) {
    if (CantAlumnos > 0) {
        // Imprimir títulos
        printf("\n%-20s %-20s %-20s %-20s %-20s\n", "Nombre", "Matricula", "Direccion", "Materia, Nota");

        for (int i = 0; i < CantAlumnos; i++) {
            // Imprimir datos del alumno en formato tabular
            printf("%-20s %-20d %-20s %-20s %-20f\n",alumnos[i].nombre, alumnos[i].matricula,alumnos[i].direccion, alumnos[i].materia,alumnos[i].nota);
        }
    } else {
        printf("No hay datos para mostrar.\n");
    }

    FILE *archivo;
    char nombreArchivo[] = "Informacion.txt";  // Nombre del archivo

    archivo = fopen(nombreArchivo, "a");

    if (archivo != NULL) {
        // Imprimir títulos en el archivo
        fprintf(archivo, "%s ; %s;%s;%s;%f\n", "Nombre", "Matricula", "Direccion", "Carrera", "Nota");

        for (int i = 0; i < CantAlumnos; i++) {
            // Imprimir datos del alumno en formato tabular
            fprintf(archivo, "%s;%d;%s;%s;%.2f\n",
                    alumnos[i].nombre, alumnos[i].matricula,
                    alumnos[i].direccion, alumnos[i].materia,
                    alumnos[i].nota);
        }

        fclose(archivo);
        printf("Datos guardados en el archivo \"%s\".\n", nombreArchivo);
    } else {
        printf("Error al abrir el archivo para escritura.\n");
    }
}


