#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p printf
#define s scanf

typedef struct nodo_nodo{
    char cancion[35];
    struct nodo_nodo *pS;
    struct nodo_nodo *pA;
}nododo;

typedef nododo *nodoNodo;

void insertar(nodoNodo *, char[]);
void imprimirNormal(nodoNodo *);
void imprimirInverso(nodoNodo *);
void reproducir(nodoNodo *, nodoNodo *, int);
void eliminar(nodoNodo *);

int main(){
    nodoNodo lista=NULL, kancion=NULL;
    int op, n=2;
    char nom[35];

    do{
        p("\n\tPROGRAMA DOS\n\nElige una opcion:\n\n");
        p("1.Agregar cancion\n2.Mostrar la lista en orden inicial\n3.Mostrar");
        p(" la lista en orden inverso\t\t\t\tCancion en reproduccion:\n4.Cambiar");
        p(" forma de reproduccion\n5.Reproducir siguiente cancion\t\t\t\t\t");
        if(kancion==NULL) p("Ninguna\n");
        else puts(kancion->cancion);
        p("6.Salir\t");
        fflush(stdin);
        s("%i", &op);
        switch(op){
        case 1:
            p("\nNombre: ");
            fflush(stdin);
            gets(nom);
            insertar(&lista, nom);
            break;
        case 2:
            if(lista!=NULL) imprimirNormal(&lista);
            else p("\n\t***No hay canciones que repdroducir***");
            fflush(stdin);
            getchar();
            break;
        case 3:
            if(lista!=NULL) imprimirInverso(&lista);
            else p("\n\t***No hay canciones que repdroducir***");
            fflush(stdin);
            getchar();
            break;
        case 4:
            n++;
            break;
        case 5:
            if(lista!=NULL) reproducir(&lista, &kancion, n);
            else{
                p("\n\t***No hay canciones que repdroducir***");
                fflush(stdin);
                getchar();
            }
            break;
        case 6:
            if(lista!=NULL) eliminar(&lista);
            return 6;
        default:
            p("\n\t***Opcion no valida***");
            fflush(stdin);
            getchar();
            break;
        }
    system("cls");
    }while(op!=6);

    return 2;
}

void insertar(nodoNodo *lista, char n[]){
    nodoNodo nuevo;
    nuevo=(nodoNodo)malloc(sizeof(nododo));
    if(nuevo!=NULL){
        strcpy(nuevo->cancion, n);
        if(*lista==NULL)
            nuevo->pA=nuevo->pS=nuevo;
        else{
            nuevo->pS=*lista;
            nuevo->pA=(*lista)->pA;
            ((*lista)->pA)->pS=nuevo;
            (*lista)->pA=nuevo;
        }
        *lista=nuevo;
    }else p("\nNo hubo suficiente espacio en memoria");
}

void imprimirNormal(nodoNodo *lista){
    nodoNodo aux=(*lista)->pA;
    int i=1;
    p("\nCanciones en reproduccion:\n");
    do{
        p("\t%i.", i);
        puts(aux->cancion);
        aux=aux->pA;
        i++;
    }while(aux!=(*lista)->pA);
}

void imprimirInverso(nodoNodo *lista){
    nodoNodo aux=*lista;
    int i=1;
    p("\nCanciones en orden inverso:\n");
    do{
        p("\t%i.", i);
        puts(aux->cancion);
        aux=aux->pS;
        i++;
    }while(aux!=*lista);
}

void reproducir(nodoNodo *lista, nodoNodo *kancion, int n){
    if(*kancion==NULL) *kancion=(*lista)->pA;
    else
        if(n%2==0)*kancion=(*kancion)->pA;
        else *kancion=(*kancion)->pS;
}

void eliminar(nodoNodo *lista){
    nodoNodo aux;
    ((*lista)->pA)->pS=NULL;
    while(*lista!=NULL){
        aux=*lista;
        *lista=(*lista)->pS;
        free(aux);
    }
}

