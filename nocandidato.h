#ifndef NOCANDIDATO_H
#define NOCANDIDATO_H
#include<sstream>
#include<cstring>
#include<candidato.h>
using namespace std;
class NoCandidato{
public:
    //string str[] = {"_"};
    Candidato* conteudo;
    NoCandidato* next;
    NoCandidato(Candidato* _conteudo, NoCandidato* _next){
        this->conteudo = _conteudo;
        this->next = _next;
    }

    string toString(){
       NoCandidato* aux = this;
       stringstream stream;
       while(aux != NULL){
           stream << aux->conteudo->toString() << " -> ";
           aux = aux->next;

       }
       stream << "0";
       return stream.str();
    }
};

#endif // NOCANDIDATO_H
