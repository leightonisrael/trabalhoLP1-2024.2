#include "../headers/leTransporte.h"
#include "../../headers/Cidade.h"
#include <fstream>
#include <iostream>
#include <vector>

void salvarTransporte(Transporte *transporte){
    ofstream arquivoTransporte("memory/transportes.txt", ios::app);
    if (arquivoTransporte.is_open()){
        arquivoTransporte
        << transporte->getNome() << "," 
        << transporte->getTipo() << ","
        << transporte->getCapacidade() << ","
        << transporte->getVelocidade() << ","
        << transporte->getLocalAtual()->getNome() << ","
        << transporte->getDistanciaEntreDescansos() << ","
        << transporte->getTempoDescanso() << ","
        << transporte->getTempoDescansoAtual() << ","
        << (transporte->getDescansando() ? "1" : "0") << endl;
        arquivoTransporte.close();
    } else {
        cerr << "Não foi possível abrir o arquivo transportes.txt para escrita.\n";
    }
}

vector<Transporte>* carregarTransportes(vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade) {
    vector<Transporte>* transportes = new vector<Transporte>;
    ifstream arquivoTransportes("memory/transportes.txt");

    if (arquivoTransportes.is_open()) {
        string linha;
        while (getline(arquivoTransportes, linha)) {
            size_t pos1 = linha.find(",");
            size_t pos2 = linha.find(",", pos1 + 1);
            size_t pos3 = linha.find(",", pos2 + 1);
            size_t pos4 = linha.find(",", pos3 + 1);
            size_t pos5 = linha.find(",", pos4 + 1);
            size_t pos6 = linha.find(",", pos5 + 1);
            size_t pos7 = linha.find(",", pos6 + 1);
            size_t pos8 = linha.find(",", pos7 + 1);

            if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos && pos4 != string::npos && pos5 != string::npos && pos6 != string::npos && pos7 != string::npos && pos8 != string::npos) {
                string nome = linha.substr(0, pos1);
                char tipo = linha[pos1 + 1];
                int capacidade = stoi(linha.substr(pos2 + 1, pos3 - pos2 - 1));
                int velocidade = stoi(linha.substr(pos3 + 1, pos4 - pos3 - 1));
                string nomeCidadeAtual = linha.substr(pos4 + 1, pos5 - pos4 - 1);
                int distanciaEntreDescansos = stoi(linha.substr(pos5 + 1, pos6 - pos5 - 1));
                int tempoDescanso = stoi(linha.substr(pos6 + 1, pos7 - pos6 - 1));
                int tempoDescansoAtual = stoi(linha.substr(pos7 + 1, pos8 - pos7 -1));
                bool descansando = (linha.substr(pos8+1) == "1");

                Cidade* cidadeAtual = pesquisarCidade(nomeCidadeAtual);

                if (cidadeAtual != nullptr) {
                    transportes->emplace_back(nome, tipo, capacidade, velocidade, cidadeAtual, distanciaEntreDescansos, tempoDescanso, tempoDescansoAtual, descansando);
                }
            }
        }
        arquivoTransportes.close();
    } else {
        cerr << "Não foi possível abrir o arquivo transportes.txt para leitura.\n";
    }
    return transportes;
}
