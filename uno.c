#include <stdio.h>
#include <stdlib.h>
#define p printf
#define s scanf

typedef struct elNodo{
    int piso;
    struct elNodo *pSig;
    struct elNodo *pAnt;
}nodoNodo;

typedef nodoNodo *tipoNodo;

void insertar(tipoNodo *, int);
void imprime(tipoNodo *, tipoNodo *);
int quePisoIniciar(tipoNodo *, tipoNodo *);
void subir(tipoNodo *, tipoNodo *, int);
void bajar(tipoNodo *, tipoNodo *, int);
void eliminar(tipoNodo *);

int main(){
    tipoNodo lista=NULL, apPiso=NULL;
    int tam, i, op, nu;

    p("\n\tPROGRAMA UNO");
    p("\n\nDe cuantos pisos quieres tu edificio? ");
    s("%i", &tam);
    for(i=0; i<tam; i++)
        insertar(&lista, i);
    imprime(&lista, &apPiso);

    if(quePisoIniciar(&lista, &apPiso)==1){
        eliminar(&lista);
        return 99;
    }
    do{
        system("cls");
        imprime(&lista, &apPiso);
        p("\n\nElige una opcion:\n1.Subir\n2.Bajar\n3.Salir");
        s("%i", &op);
        switch(op){
            case 1:
                p("\n\nCuantos pisos?");
                s("%i", &nu);
                subir(&lista, &apPiso, nu);
                break;
            case 2:
                p("\n\nCuantos pisos?");
                s("%i", &nu);
                bajar(&lista, &apPiso, nu);
                break;
            case 3:
                eliminar(&lista);
                return 3;
                break;
            default:
                p("\n\n***Opcion no valida");
                break;
        }
    }while(op!=3);

    fflush(stdin);
    getchar();
    return 1;
}

void insertar(tipoNodo *lista, int pis){
    tipoNodo nuevo;
    nuevo=(tipoNodo)malloc(sizeof(nodoNodo));
    if(nuevo!=NULL){
        nuevo->piso=pis;
        if(*lista==NULL)
            nuevo->pSig=NULL;
        else{
            nuevo->pSig=*lista;
            (*lista)->pAnt=nuevo;
        }
        nuevo->pAnt=NULL;
        *lista=nuevo;
    }else p("\n\nMemoria insuficiente");
}

void imprime(tipoNodo *lista, tipoNodo *apPiso){
    tipoNodo aux;
    aux=*lista;
    p("\n\tPiso:\n");
    while(aux!=NULL){
        p("\n\t%i", aux->piso);
        if(aux==*lista) p("--Planta Alta");
        if(aux->piso==0) p("--Planta Baja");
        if(aux==*apPiso) p("--Te encuentras aqui");
        aux=aux->pSig;
    }
}

int quePisoIniciar(tipoNodo *lista, tipoNodo *apPiso){
    tipoNodo aux=*lista;
    int op;
    p("\n\nEn que piso deseas iniciar? ");
    s("%i", &op);
    while(aux!=NULL && aux->piso!=op)
        aux=aux->pSig;
    if(aux==NULL){
        p("\nEse piso no existe que!");
        fflush(stdin);
        getchar();
        return 1;
    }else *apPiso=aux;
    return 0;
}

void subir(tipoNodo *lista, tipoNodo *apPiso, int num){
    int i;
    for(i=0; i<num && (*apPiso)->pAnt!=NULL; i++)
        *apPiso=(*apPiso)->pAnt;
}

void bajar(tipoNodo *lista, tipoNodo *apPiso, int num){
    int i;
    for(i=0; i<num && (*apPiso)->pSig!=NULL; i++)
        *apPiso=(*apPiso)->pSig;
}

void eliminar(tipoNodo *lista){
    tipoNodo nodo;
    while(*lista!=NULL){
        nodo=*lista;
        *lista=(*lista)->pSig;
        free(nodo);
    }
}

