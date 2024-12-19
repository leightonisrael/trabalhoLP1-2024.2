#include "../headers/Rota.h"
#include <limits>
#include <queue>
#include <unordered_map>
#include <algorithm>


struct TrajetoInfo {
    Cidade* cidade;
    Trajeto* trajeto;
    int distancia;

    bool operator>(const TrajetoInfo& other) const {
        return distancia > other.distancia;
    }
};

vector<Trajeto> Rota::calcularMelhorRota(vector<Trajeto>* trajetos, Cidade* origem, Cidade* destino, char tipoTransporte) {
    priority_queue<TrajetoInfo, vector<TrajetoInfo>, greater<>> pq;
    unordered_map<Cidade*, Trajeto*> antecessores;
    unordered_map<Cidade*, int> distancias;
    vector<Trajeto> rotaFinal;

    for (const auto& trajeto : *trajetos) {
        distancias[trajeto.getOrigem()] = numeric_limits<int>::max();
        distancias[trajeto.getDestino()] = numeric_limits<int>::max();
    }

    distancias[origem] = 0;
    pq.push({origem, nullptr, 0});

    while (!pq.empty()) {
        TrajetoInfo atual = pq.top();
        pq.pop();

        Cidade* cidadeAtual = atual.cidade;
        if (cidadeAtual == destino) {
            break;
        }

        for (auto& trajeto : *trajetos) {
            if (trajeto.getOrigem() == cidadeAtual && trajeto.getTipo() == tipoTransporte) {
                Cidade* vizinho = trajeto.getDestino();
                int novaDistancia = distancias[cidadeAtual] + trajeto.getDistancia();

                if (novaDistancia < distancias[vizinho]) {
                    distancias[vizinho] = novaDistancia;
                    antecessores[vizinho] = &trajeto;
                    pq.push({vizinho, &trajeto, novaDistancia});
                }
            }
        }
    }

    Cidade* cidadeAtual = destino;
    while (cidadeAtual != origem && antecessores.find(cidadeAtual) != antecessores.end()) {
        Trajeto* trajeto = antecessores[cidadeAtual];
        rotaFinal.push_back(*trajeto);
        cidadeAtual = trajeto->getOrigem();
    }

    reverse(rotaFinal.begin(), rotaFinal.end());
    return rotaFinal;
}