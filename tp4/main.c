#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "empleados.h"

int main()
{
    Employee* auxEmpl=NULL;
    int tam;
    int id=2000;
    int indice;
    LinkedList* lista= ll_newLinkedList();
    LinkedList* nuevaLista;
    LinkedList* listaClonada;
    Employee empleados[12][128]={
                                {{1,"Lou",120,10000}},
                                {{2,"Ulrike",180,25000}},
                                {{3,"Brade",325,20000}},
                                {{4,"Kimbell",120,50000}},
                                {{5,"Sheelagh",220,18000}},
                                {{15,"Megen",180,10000}},
                                {{16,"Iver",90,12000}},
                                {{17,"Ernesta",60,37000}},
                                {{18,"Cirillo",88,50000}},
                                {{19,"Park",120,30000}},
                                {{20,"Bellanca",88,15000}},
                                {{21,"Bobbye",180,15000}},
                                };

    //recorrer los empleados para agregarlos a la linkedlist
    for(int i=0;i<12;i++)
    {
        ll_add(lista, empleados[i]);
    }
    if(!ll_isEmpty(lista))//si la lista NO esta vacia muestra los empleados
    {
        printf("SE CREO LA LISTA:\n");
        printf("-------------------\n");
        mostrarListaEmpleados(lista);
    }
    //Reviso tamaño de la linkedList
    tam = ll_len(lista);
    printf("tamanio de lista: %d\n\n", tam);
    system("pause");
    //agregar un nuevo empleado
    auxEmpl = employee_newParametros("6","Gayle","120","30000");
    if(!ll_push(lista, 2, auxEmpl))//inserto el nuevo empleado en el indice 2 y si funciono muestro lista actualizada
    {
        printf("SE INSERTO NUEVO EMPLEADO EN INDICE 2\n");
        printf("-------------------------\n");
        mostrarListaEmpleados(lista);
    }
    auxEmpl = NULL;
    system("pause");
    tam=ll_len(lista);
    //tomo todos los empleados y les modifico el id autoincremental
    for(int i=0;i<tam;i++)
    {
        auxEmpl=ll_get(lista, i);
        auxEmpl->id = id;
        id++;
        auxEmpl=NULL;
    }
    printf("SE CAMBIO EL ID A AUTOINCREMENTAL\n");
    printf("-----------------------------\n");
    mostrarListaEmpleados(lista);
    system("pause");
    system("cls");
    auxEmpl = employee_newParametros("2006","Kimberlee","60","33000");
    //cambio un empleado por uno nuevo en la posicion 3
    ll_set(lista, 3, auxEmpl);
    //elimino un empleado del indice 4
    ll_remove(lista, 4);
    tam=ll_len(lista);
    printf("CAMBIO EMPLEADO POSICION 3 Y SE ELIMINO EN POSICION 4\n");
    mostrarListaEmpleados(lista);
    system("pause");
    system("cls");
    //busco un empleado y obtengo el indice
    for(int i=0;i<tam;i++)
    {
        auxEmpl = ll_get(lista, i);
        if(!strcmp(auxEmpl->nombre, "Gayle"))
        {
            indice = ll_indexOf(lista, auxEmpl);//con esto obtengo el indice
        }
    }
    printf("Indice del empleado Gayle: %d\n\n", indice);
    system("pause");
    system("cls");
    //Elimino un empleado y obtengo el puntero
    auxEmpl = ll_pop(lista, 6);
    //creo nueva lista con los primeros 3 empleados
    nuevaLista=ll_subList(lista, 0, 4);
    printf("SE CREO UNA NUEVA LISTA\n");
    mostrarListaEmpleados(nuevaLista);
    system("pause");
    //confirmo que la lista nueva tenga o no el empleado Gayle
    auxEmpl = ll_get(lista, indice);
    if(ll_contains(nuevaLista, auxEmpl))
    {
        printf("Gayle pertenece a la lista\n\n");
    }
    else
    {
        printf("Gayle no pertenece a la nueva lista\n\n");
    }
    //Reviso que todos los elementos de la nueva lista estan en la lista original
    if(!ll_containsAll(nuevaLista, lista))
    {
        printf("Todos los elementos de la lista nueva se encuentran en la lista original\n\n");
    }
    system("pause");
    system("cls");
    //Elimino la lista nueva creada
    if(!ll_deleteLinkedList(nuevaLista))
    {
        printf("Se elimino la lista nueva creada\n\n");
    }
    //clono la lista original y muestro la clonada
    listaClonada = ll_clone(lista);
    printf("LISTA CLONADA\n");
    printf("--------------\n");
    mostrarListaEmpleados(listaClonada);
    printf("LISTA ORIGINAL\n");
    printf("--------------\n");
    mostrarListaEmpleados(lista);
    system("pause");
    system("cls");
    //elimino todos los elementos de la lista clonada y confirmo tamaño
    ll_clear(listaClonada);
    tam=ll_len(listaClonada);
    printf("SE ELIMINARON LOS ELEMENTOS DE LA LISTA CLONADA\n");
    printf("Tamanio lista clonada: %d\n", tam);
    system("pause");
    system("cls");
    //ordenamos listado por horas trabajadas
    printf("LISTA ORDENADA POR HORAS TRABAJADAS\n");
    printf("----------------------------------\n");
    ll_sort(lista, ordenarEmpleadosHorasTrabajadas, 1);
    mostrarListaEmpleados(lista);
    //ordenar lista por nombre descendente
    printf("LISTA ORDENADA POR NOMBRE\n");
    printf("----------------------------------\n");
    ll_sort(lista, ordenarEmpleadosNombre, 0);
    mostrarListaEmpleados(lista);

    return 0;
}
