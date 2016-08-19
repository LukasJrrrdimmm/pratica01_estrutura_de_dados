#ifndef LISTACANDIDATO_H
#define LISTACANDIDATO_H
#include <sstream>
#include <cstring>
#include <fstream>
#include <iostream>
#include <nocandidato.h>
#include <candidato.h>
using namespace std;
class ListaCandidatos
{
public:
    NoCandidato* head;
    ListaCandidatos(){
        this->head = NULL;
    }
    ListaCandidatos(string file){
        this->head = NULL;
        ifstream fcin(file.c_str());

        string dados;
        getline(fcin,dados);
        cout << "criacao da lista de candidatos de: " << dados << endl;
        while(getline(fcin,dados)){
            Candidato *c = new Candidato(dados);
            adicioneComoHead(c);
        }
    }

    void adicioneComoHead(Candidato *c){
        NoCandidato* no = new NoCandidato(c, head);
        head = no;
    }
    int tamanho(){
        int tam = 0;
        NoCandidato *aux = head;
        while(aux != NULL){
            tam++;
            aux = aux->next;
        }
        return tam;
    }
    string toString(){

        string a = head->toString();
        return a;

    }

    bool estaVasia(){
        if(head != NULL){
            return false;
        }else{
            return true;
        }
    }
    bool remover(string nome, string sobrenome)
    {
        NoCandidato* it = head;
        if(head != NULL)                                //lista nao eh vazia
        {
            if(it->conteudo->igual(nome, sobrenome))    //Candidato se encontra no inicio da lista
            {
                head = head->next;
                delete it;
                return true;
            }
            else
            {

               NoCandidato * anterior = it;
                while(it != NULL )
                {
                    if(!(it->conteudo->igual(nome, sobrenome)))
                    {
                        anterior = it;
                        it = it->next;
                    }
                    else
                    {
                        anterior->next = it->next;
                        delete it;
                        return true;
                    }
                }
            }
        }
        else
            return false;
    }
    public void filtrarCandidatosNota(int nota){
        //it = iterador
        NoCandidato* it = head;
        NoCandidato* aux;
        while(it != NULL){
            if(it->conteudo->nota <= nota){
                aux = it->next;
                remover(it->conteudo->nome, it->conteudo->sobrenome);
            }
            it = aux;
        }
    }
};

#endif // LISTACANDIDATO_H
