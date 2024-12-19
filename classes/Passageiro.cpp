#include "../headers/Passageiro.h"

Passageiro::Passageiro(string nome, Cidade* localAtual) {
    this->nome = nome;
    this->localAtual = localAtual;
}

string Passageiro::getNome() {
    return this->nome;
}

Cidade* Passageiro::getLocalAtual(){
    return this->localAtual;
}

void Passageiro::setLocalAtual(Cidade* localAtual){
    this->localAtual = localAtual;
}