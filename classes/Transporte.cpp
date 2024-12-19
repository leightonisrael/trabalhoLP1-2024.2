#include "../headers/Transporte.h"

Transporte::Transporte(string nome, char tipo, int capacidade, int velocidade,  Cidade* localAtual, int distanciaEntreDescanso, int tempoDescanso, int tempoDescansoAtual, bool descansando) {
    this->nome = nome;
    this->tipo = tipo;
    this->capacidade = capacidade;
    this->velocidade = velocidade;
    this->localAtual = localAtual;
    this->distanciaEntreDescanso = distanciaEntreDescanso;
    this->tempoDescanso = tempoDescanso;
    this->tempoDescansoAtual = tempoDescansoAtual;
    this->descansando = descansando;
}

string Transporte::getNome() {
    return this->nome;
}

char Transporte::getTipo(){
    return this->tipo;
}

int Transporte::getCapacidade(){
    return this->capacidade;
}

int Transporte::getVelocidade(){
    return this->velocidade;
}

int Transporte::getDistanciaEntreDescansos(){
    return this->distanciaEntreDescanso;
}

int Transporte::getTempoDescanso(){
    return this->tempoDescanso;
}

int Transporte::getTempoDescansoAtual(){
    return this->tempoDescansoAtual;
}

Cidade* Transporte::getLocalAtual(){
    return this->localAtual;
}

bool Transporte::getDescansando(){
    return this->descansando;
}

void Transporte::zerarDescanso(){
    this->tempoDescansoAtual = 0;
    this->setDescansando(false);
}

void Transporte::aumentarTempoDescansoAtual(){
    this->tempoDescansoAtual = this->tempoDescansoAtual + 1;
}

void Transporte::setLocalAtual(Cidade* novoLocal){
    this->localAtual = novoLocal;
}

void Transporte::setDescansando(bool descansando){
    this->descansando = descansando;
}