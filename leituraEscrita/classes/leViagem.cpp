#include "../headers/leViagem.h"
#include <fstream>
#include <iostream>
#include <sstream>

void salvarViagem(Viagem *viagem){
    ofstream arquivoViagem("memory/viagens.txt", ios::app);
    if (arquivoViagem.is_open()){
        arquivoViagem
        << viagem->getTransporte()->getNome() << ","
        << viagem->getTrajeto()->getOrigem()->getNome() << ","
        << viagem->getTrajeto()->getDestino()->getNome() << ","
        << viagem->getPassageiros().size() << ",";

        for (auto& passageiro: viagem->getPassageiros()){
            arquivoViagem
            << passageiro->getNome() << ",";
        }

        arquivoViagem
        << viagem->getHorasEmTransito() << ","
        << viagem->getDistanciaPercorrida() << ","
        << viagem->isEmAndamento() << ","
        << viagem->getHasProxima() << endl;
        //<< viagem->getProxima() << endl;
        arquivoViagem.close();
    } else {
        cerr << "Não foi possível abrir o arquivo viagens.txt para escrita.\n";
    }
}

vector<Viagem>* carregarViagens(
    vector<Cidade>* cidades, function<Cidade*(const string&)> pesquisarCidade,
    vector<Passageiro>* passageiros, function<Passageiro*(const string&)> pesquisarPassageiro,
    vector<Transporte>* transportes, function<Transporte*(const string&)> pesquisarTransporte,
    vector<Trajeto>* trajetos, function<Trajeto*(const string&, const string&, const char&)> pesquisarTrajeto
    ){
    
    vector <Viagem>* viagens = new vector<Viagem>;
    ifstream arquivoViagens("memory/viagens.txt");

    if(arquivoViagens.is_open()){
        string linha;
        while(getline(arquivoViagens, linha)){
            
            stringstream ss(linha);
            string nomeTransporte, nomeOrigem, nomeDestino, nomePassageiro;
            int quantidadePassageiros, horasEmTransito, distanciaPercorrida;
            bool emAndamento, hasProxima;
            vector<Passageiro*> passageirosViagem;

            getline(ss, nomeTransporte, ',');
            Transporte* transporte = pesquisarTransporte(nomeTransporte);

             // Ler o nome do transporte
            if (transporte == nullptr) {
                cerr << "Erro: Transporte não encontrado (" << nomeTransporte << ").\n";
                break;
            }
             // Ler as cidades de origem e destino
            getline(ss, nomeOrigem, ',');
            getline(ss, nomeDestino, ',');
            Trajeto* trajeto = pesquisarTrajeto(nomeOrigem, nomeDestino, transporte->getTipo());

            if (trajeto == nullptr) {
                cerr << "Erro: Trajeto não encontrado (" << nomeOrigem << " -> " << nomeDestino << ").\n";
                break;
            }

            // Ler a quantidade de passageiros
            ss >> quantidadePassageiros;
            ss.ignore(); // Ignorar a vírgula

            // Ler os nomes dos passageiros e buscar seus objetos
            for (int i = 0; i < quantidadePassageiros; ++i) {
                getline(ss, nomePassageiro, ',');
                Passageiro* passageiro = pesquisarPassageiro(nomePassageiro);

                if (passageiro != nullptr) {
                    passageirosViagem.push_back(passageiro);
                } else {
                    cerr << "Erro: Passageiro não encontrado (" << nomePassageiro << ").\n";
                }
            }

            // Ler as demais informações
            ss >> horasEmTransito;
            ss.ignore();
            ss >> distanciaPercorrida;
            ss.ignore();
            ss >> emAndamento;
            ss.ignore();
            ss >> hasProxima;

            // Criar o objeto Viagem e adicionar ao vetor
            Viagem* endProxima;
            if (hasProxima){
                //acessar o último valor do vetor e pegar o endereco de seu ultimo valor
                endProxima = &viagens->back();
            } else {
                endProxima = nullptr;
            }

            Viagem* novaViagem = new Viagem(transporte, passageirosViagem, trajeto, horasEmTransito, distanciaPercorrida, emAndamento, hasProxima, endProxima);
            viagens->push_back(*novaViagem);
        }
        arquivoViagens.close();
    } else {
        cerr << "Não foi possível abrir o arquivo viagens.txt para leitura.\n";

    }
    return viagens;
}