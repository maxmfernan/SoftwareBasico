#include "operacaoListas.h"

int adicionaItemConstPool(ConstantPoolItem **inicio, ConstantPoolItem *novoItem)
{
    if((*inicio) == NULL)
    {
       (*inicio) = novoItem;
       (*inicio)->proxItem = NULL;
       return 0;
    }
    
    ConstantPoolItem *constAux;
    constAux = (*inicio);
    ConstantPoolItem *constAuxAntigo;
    constAuxAntigo = (*inicio);
    
    while(constAux != NULL)
    {
       constAuxAntigo = constAux;
       constAux = constAux->proxItem;
    }
    
    if(constAuxAntigo == NULL) {
        printf("Erro ao trabalhar com a lista.\n");
        getchar();
        return 1;
    }
    
    constAuxAntigo->proxItem = novoItem;
    novoItem->proxItem = NULL;
    
    return 0;

}

void insereItemVetor(ITEM_VECTOR **inicio, ITEM_VECTOR *newItem){
	
	if ((*inicio) == NULL) {
		(*inicio) = newItem;
	}
	else {
		int index_item = newItem->index_item;
		
		ITEM_VECTOR *vectorAux = (*inicio);
		ITEM_VECTOR *vectorAntigo = (*inicio);
		while (vectorAux != NULL) {
			if (vectorAux->index_item == index_item) {
				if (vectorAux == (*inicio)) {
					newItem->prox = (*inicio)->prox;
					(*inicio) = newItem;
				}
				else {
					vectorAntigo->prox = newItem;
					newItem->prox = vectorAux->prox;
					vectorAux = newItem;
				}
				break;
			}
			
			if (vectorAux->index_item > index_item) {
				vectorAntigo->prox = newItem;
				newItem->prox = vectorAux;
			}
			else {
			     vectorAntigo = vectorAux;
			     vectorAux = vectorAux->prox;
              }
		}
		
		if (vectorAux == NULL) {
			vectorAntigo->prox = newItem;
		}
	}
	
}

ITEM_VECTOR* procuraItemVetor(ITEM_VECTOR **vector, unsigned int index_item){
	ITEM_VECTOR *iniVetor = (*vector);
	while (iniVetor != NULL) {
		if (iniVetor->index_item == index_item) {
			return iniVetor;
		}
		
		iniVetor = iniVetor->prox;
	}
	
	return NULL;
}

void insereClasse(CLASS *novaclasse, char *novaclassepath){
    ClassFileList *aux, *aux1;
    aux = malloc(sizeof(ClassFileList));
    aux->classPath = novaclassepath;
    aux->classFile = novaclasse;
    aux->prox = NULL;
    
    if(ListaClasses == NULL){
        ListaClasses = aux;
    }
    else{
        aux1 = ListaClasses;
        while(aux1->prox != NULL){
            aux1 = aux1->prox;
        }
        aux1->prox = aux;
    }
}
