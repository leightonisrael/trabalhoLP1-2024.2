#include "../headers/leTrajeto.h"
#include "../../headers/Cidade.h"
#include <fstream>
#include <iostream>
#include <vector>

void salvarTrajeto(Trajeto *trajeto){
    ofstream arquivoTrajetos("memory/trajetos.txt", ios::app);
    if (arquivoTrajetos.is_open()){
        arquivoTrajetos
        << trajeto->getOrigem()->getNome() << ","
        << trajeto->getDestino()->getNome() << ","
        << trajeto->getTipo() << ","
        << trajeto->getDistancia() << endl;
        arquivoTrajetos.close();
    } else{
        cerr << "Não foi possível abrir o arquivo trajetos.txt para escrita.\n";
    }
}

vector<Trajeto>* carregarTrajetos(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade){
    vector<Trajeto>* trajetos = new vector<Trajeto>;
    ifstream arquivoTrajetos("memory/trajetos.txt");

    if (arquivoTrajetos.is_open()) {
        string linha;
        while (getline(arquivoTrajetos, linha)) {
            size_t pos1 = linha.find(",");
            size_t pos2 = linha.find(",", pos1 + 1);
            size_t pos3 = linha.find(",", pos2 + 1);

            if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
                string nomeOrigem = linha.substr(0, pos1);
                string nomeDestino = linha.substr(pos1 + 1, pos2 - pos1 - 1);
                char tipo = linha[pos2 + 1];
                int distancia = stoi(linha.substr(pos3 + 1));

                Cidade* origem = pesquisarCidade(nomeOrigem);
                Cidade* destino = pesquisarCidade(nomeDestino);

                if (origem != nullptr && destino != nullptr) {
                    trajetos->emplace_back(origem, destino, tipo, distancia);
                }
            }
        }
        arquivoTrajetos.close();
    } else {
        cerr << "Não foi possível abrir o arquivo trajetos.txt para leitura." << endl;
    }
    return trajetos;
}
