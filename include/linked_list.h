#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int conteudo;
    Node* proximo;
};

struct ListaSimplesmenteEncadeada {
    int cardinalidade;
    Node* inicio;
};

ListaSimplesmenteEncadeada* criaLista();
void destroiLista(ListaSimplesmenteEncadeada &lista);
void insere(ListaSimplesmenteEncadeada &lista, int conteudo);
bool Lista_Vazia(ListaSimplesmenteEncadeada* Lista);
#endif // LINKED_LIST_
