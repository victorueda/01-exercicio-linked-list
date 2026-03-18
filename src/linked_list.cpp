#include "linked_list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaSimplesmenteEncadeada* criaLista()
{
    ListaSimplesmenteEncadeada* lista = (ListaSimplesmenteEncadeada*) malloc(sizeof(ListaSimplesmenteEncadeada));
    lista->cardinalidade = 0;
    lista->inicio = NULL;
    lista->Fim = NULL;
    return lista;
}

void destroiLista(ListaSimplesmenteEncadeada &lista)
{
    Node* temp;
    while (lista.inicio != NULL) {
        temp = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        free(temp);
    }
    lista.cardinalidade = 0;
}

void insere(ListaSimplesmenteEncadeada &lista, int conteudo)
{
    Node* novoNode = (Node*) malloc(sizeof(Node));
    if (novoNode == NULL) {
        cerr << "Erro na alocação de memória" << endl;
    }

    novoNode->conteudo = conteudo;
    novoNode->proximo = lista.inicio;
    novoNode->anterior = nullptr;

     if (lista.inicio != nullptr)
      {
        lista.inicio->anterior = novoNode;
    }else{
        lista.Fim = novoNode;
    }


    lista.inicio = novoNode;
    lista.cardinalidade++;
}

bool Lista_Vazia(ListaSimplesmenteEncadeada* Lista){

     return (Lista->inicio == nullptr);

}

void Mostra_Lista (ListaSimplesmenteEncadeada* Lista)
    {
        Node* atual = Lista -> inicio;
        while (atual != nullptr)
        {
            cout << atual -> conteudo << " ";
            atual = atual -> proximo;
        }
        
    cout << endl;
    }
    
int Return_Cardinalidade (ListaSimplesmenteEncadeada* Lista)
{
    return Lista->cardinalidade;
}



void Insere_Especifico(ListaSimplesmenteEncadeada* lista, int n, int valor)
{
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->conteudo = valor;

      if (n == 0 || lista->inicio == nullptr)
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->cardinalidade++;
        return;
    }

    Node* atual = lista->inicio;

    int i = 0;

    while (i < n-1 && atual != nullptr)
    {
        atual = atual->proximo;
        i++;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
    lista->cardinalidade ++;
}
//incompleto. Atualize para duplamente encadeada
void Remove_Elemento (ListaSimplesmenteEncadeada* Lista,Node* valor)
{
    Node* atual = Lista-> inicio;
    

    while (atual != nullptr && atual -> conteudo != valor)
    {
        atual->anterior = atual;
        atual = atual -> proximo;
    }

    if(atual == nullptr)
    {
        cout << "Valor não encontrado na lista" << endl;
        return;
    }else if( atual->anterior == nullptr)
    {
        Lista->inicio = atual->proximo;
       
    }
    else
    {
        atual->anterior->proximo = atual -> proximo;   
       
    }

     free(atual);
     Lista->cardinalidade--;
}

void Inverter_Lista(ListaSimplesmenteEncadeada* Lista)
{
    Node* anterior = nullptr;
    Node* atual = Lista->inicio;
    Node* proximo = nullptr;

    while (atual != nullptr)
    {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    Lista->inicio = anterior;
}

