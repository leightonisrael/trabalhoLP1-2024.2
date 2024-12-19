// leCidade.cpp

#include "leCidade.h"
#include <fstream>
#include <iostream>

using namespace std;

void salvarCidade(Cidade *cidade){
    ofstream arquivoCidades("memory/cidades.txt", ios::app);
    if (arquivoCidades.is_open()){
        arquivoCidades
        << cidade->getNome() << ","
        << cidade->getVisitantes() << endl;
        arquivoCidades.close();
    } else {
        cerr << "Não foi possível abrir o arquivo cidades.txt para escrita." << endl;
    }
}

vector<Cidade>* carregarCidades() {
    vector<Cidade>* cidades = new vector<Cidade>;
    ifstream arquivoCidades("memory/cidades.txt");

    if (arquivoCidades.is_open()){

        string linha;
        while (getline(arquivoCidades, linha)){
            size_t pos = linha.find(",");
            if (pos!= string::npos){
                string nome = linha.substr(0,pos);
                int visitantes = stoi(linha.substr(pos+1));

                //Cidade* cidade = new Cidade(nome, visitantes);
                cidades->emplace_back(nome, visitantes);
            }
        }
        arquivoCidades.close();
    } else {
        cerr << "Não foi possível abrir o arquivo cidades.txt para leitura." << endl;
    }

    return cidades;
}
