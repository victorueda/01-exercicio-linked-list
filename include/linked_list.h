#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int conteudo;
    Node* proximo;
    Node* anterior;
};

struct ListaSimplesmenteEncadeada {
    int cardinalidade;
    Node* inicio;
    Node* Fim;
};

ListaSimplesmenteEncadeada* criaLista();
void destroiLista(ListaSimplesmenteEncadeada &lista);
void insere(ListaSimplesmenteEncadeada &lista, int conteudo);
bool Lista_Vazia(ListaSimplesmenteEncadeada* Lista);
void Mostra_Lista(ListaSimplesmenteEncadeada* Lista);
int Return_Cardinalidade (ListaSimplesmenteEncadeada* Lista);
void Insere_Especifico (ListaSimplesmenteEncadeada* Lista,int n, int valor);
void Remove_Elemento (ListaSimplesmenteEncadeada* Lista, int valor);
void Inverter_Lista(ListaSimplesmenteEncadeada* Lista);
#endif // LINKED_LIST_H
