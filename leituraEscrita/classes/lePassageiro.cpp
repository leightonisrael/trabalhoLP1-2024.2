#include "../headers/lePassageiro.h"
#include "../../headers/Cidade.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void salvarPassageiro(Passageiro *passageiro){
    ofstream arquivoPassageiros("memory/passageiros.txt", ios::app);
    if (arquivoPassageiros.is_open()){
        arquivoPassageiros
        << passageiro->getNome() << ","
        << passageiro->getLocalAtual()->getNome() << endl;
        arquivoPassageiros.close();
    } else {
        cerr << "Não foi possível abrir o arquivo passageiros.txt para escrita." << endl;
    }
}

vector<Passageiro>* carregarPassageiros(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade) {
    vector<Passageiro>* passageiros = new vector<Passageiro>;
    ifstream arquivoPassageiros("memory/passageiros.txt");

    if (arquivoPassageiros.is_open()){
        string linha;
        while (getline(arquivoPassageiros, linha)){
            size_t pos = linha.find(",");
            if (pos != string::npos){
                string nome = linha.substr(0, pos);
                string nomeCidade = linha.substr(pos+1);

                Cidade* cidadeEncontrada = pesquisarCidade(nomeCidade); 
                if (!cidadeEncontrada->getNome().empty() && !nome.empty()){
                    passageiros->emplace_back(nome, cidadeEncontrada);
                } 
            }
        }
        arquivoPassageiros.close();
    } else {
        cerr << "Não foi possível abrir o arquivo passageiros.txt para leitura." << endl;
    }
    return passageiros;
}