#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "letra.h"
#include "ArrayList.h"
#include "parser.h"

int main()
{
    ArrayList* lista = al_newArrayList();
    ArrayList* filtradaContiene = al_newArrayList();
    ArrayList* filtradaNoContiene = al_newArrayList();
    int opcion;
    char string[20];

    do
    {
        printf("MENU:\n");
        printf("1.-Parsear\n");
        printf("2.-Completar\n");
        printf("3.-Listar\n");
        printf("4.-Guardar\n");
        printf("5.-Salir\n");

        scanf("%d", &opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                lectura(lista);
                imprimirTodos(lista);
                break;

            case 2:
                completarLetra(lista);
                imprimirTodos(lista);
                break;
            case 3:
                printf("Ingrese una palabra: ");
                fflush(stdin);
                fgets(string, 20, stdin);

                filtrarContiene(lista, filtradaContiene, string);
                filtradaContiene->sort(filtradaContiene, comparar, 1);
                imprimirTodos(filtradaContiene);

                getchar();

                filtrarNoContiene(lista, filtradaNoContiene, string);
                filtradaNoContiene->sort(filtradaNoContiene, comparar, 0);
                imprimirTodos(filtradaNoContiene);
                break;
            case 4:
                escritura(lista, "completado.csv");
                escritura(filtradaContiene, "contenidos.csv");
                escritura(filtradaContiene, "no_contenidos.csv");
                break;
            case 5:
                printf("Programa finalizado\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }
    while(opcion != 5);


    return 0;
}
