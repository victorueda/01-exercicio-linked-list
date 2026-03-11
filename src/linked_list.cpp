#include "linked_list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaSimplesmenteEncadeada* criaLista()
{
    ListaSimplesmenteEncadeada* lista = (ListaSimplesmenteEncadeada*) malloc(sizeof(ListaSimplesmenteEncadeada));
    lista->cardinalidade = 0;
    lista->inicio = NULL;
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
    
int Return_Cardinalidade (ListaSimplesmenteEncadeada* lista)
{
    return Lista->cardinalidade;
}



