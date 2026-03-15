#include <cassert>
#include <iostream>
#include "../include/linked_list.h"

using namespace std;

// ===== TESTES DA FUNÇÃO criaLista =====
void teste_criaLista() {
    cout << "Testando criaLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "criaLista() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO insere (inserção no início) =====
void teste_insere() {
    cout << "Testando insere()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere primeiro elemento
    insere(*lista, 10);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio != NULL);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo == NULL);

    // Insere segundo elemento (deve ficar no início)
    insere(*lista, 20);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 20);
    assert(lista->inicio->proximo->conteudo == 10);

    // Insere terceiro elemento
    insere(*lista, 30);
    assert(lista->cardinalidade == 3);
    assert(lista->inicio->conteudo == 30);
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->inicio->proximo->proximo->conteudo == 10);

    destroiLista(*lista);
    free(lista);
    cout << "insere() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO destroiLista =====
void teste_destroiLista() {
    cout << "Testando destroiLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere elementos
    insere(*lista, 1);
    insere(*lista, 2);
    insere(*lista, 3);

    // Destrói a lista
    destroiLista(*lista);

    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "destroiLista() passou em todos os testes" << endl;
}

// Testa se lista esta vazia
void teste_Lista_Vazia() {
    cout << "Testando Lista_Vazia()..." << endl;

  
    ListaSimplesmenteEncadeada* lista = criaLista();

    
    assert(Lista_Vazia(lista));

    free(lista);
    cout << "Lista_Vazia() passou em todos os testes" << endl;
}

// Testa mostra Lista
void  teste_Mostra_lista()
{
     cout << "Testando Demonstração de Lista()..." << endl;

     ListaSimplesmenteEncadeada* Lista = criaLista();
     insere(*Lista,10);
     insere(*Lista,20);
     insere(*Lista,30);
     Mostra_Lista(Lista);
     
     destroiLista(*Lista);
    
    free(Lista);
    }   

// Testa Return Cardinalidade
void teste_Return_Cardinalidade()
{
    cout << "Testando Return_Cardinalidade()... " << endl;
    ListaSimplesmenteEncadeada* Lista = criaLista();
    insere(*Lista,10);
    insere(*Lista,20);
    insere(*Lista,30);
    assert(Return_Cardinalidade(Lista) == 3);
    cout << "Return_Cardinalidade() passou em todos os testes" << endl;

    destroiLista(*Lista);
    free(Lista);}

void teste_insere_Especifico()
{
  cout << "Testando Insere_Especifico()... " << endl;
    ListaSimplesmenteEncadeada* Lista = criaLista();   
    insere(*Lista,10);

    Insere_Especifico(Lista,1,20);
    Insere_Especifico(Lista,1,15);

    assert(Lista->inicio->conteudo == 10);
    assert(Lista->inicio->proximo->conteudo == 15);
    assert(Lista->inicio->proximo->proximo->conteudo == 20);
      cout << "Insere_Especifico() passou em todos os testes" << endl;
}

void teste_Remove_Elemento()
{
    cout << "Testando Remove_Elemento()... " << endl;
    ListaSimplesmenteEncadeada* Lista = criaLista();   
    insere(*Lista,10);
    insere(*Lista,20);
    insere(*Lista,30);

    Mostra_Lista(Lista);

    Remove_Elemento(Lista,20);

    
    Mostra_Lista(Lista);
    assert(Lista->inicio->conteudo == 30);
    assert(Lista->inicio->proximo->conteudo == 10);

      cout << "Remove_Elemento() passou em todos os testes";
}

void teste_Inverter_Lista()
{
        cout << "Testando Inverter_Lista()... " << endl;
    ListaSimplesmenteEncadeada* Lista = criaLista();
    insere(*Lista, 40);
    insere(*Lista, 30);
    insere(*Lista, 20);
    insere(*Lista, 10);
    Mostra_Lista(Lista);
    Inverter_Lista(Lista);
    Mostra_Lista(Lista);
    assert(Lista->inicio->conteudo == 10);
    assert(Lista->inicio->proximo->conteudo == 20);
    assert (Lista->inicio->proximo->proximo->conteudo == 30);
    assert (Lista->inicio->proximo->proximo->proximo->conteudo == 40);
        cout << "Inverter_Lista() passou em todos os testes";
}
// ===== FUNÇÃO PRINCIPAL =====
int main() {

    cout << "\n=========================================" << endl;
    cout << "  INICIANDO TESTES DE LINKED LIST" << endl;
    cout << "=========================================" << endl << endl;

    try {
        teste_criaLista();
        teste_insere();
        teste_destroiLista();
        teste_Lista_Vazia();
        teste_Mostra_lista();
        teste_Return_Cardinalidade();
        teste_insere_Especifico();
        teste_Remove_Elemento();
        teste_Inverter_Lista();
        cout << "\n=========================================" << endl;
        cout << "  TODOS OS TESTES PASSARAM COM SUCESSO!" << endl;
        cout << "=========================================" << endl << endl;

        return 0;
    } catch (const exception& e) {
        cout << "\nErro durante os testes: " << e.what() << endl;
        return 1;
    } catch (const char* e) {
        cout << "\nErro durante os testes: " << e << endl;
        return 1;
    }
}

