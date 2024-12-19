#ifndef ROTA_H
#define ROTA_H

#include <vector>
#include "Trajeto.h"
#include "Cidade.h"

using namespace std;

/**
 * @class Rota
 * @brief Classe responsável por calcular a melhor rota entre duas cidades com base em trajetos disponíveis.
 * 
 * Esta classe oferece uma função estática que utiliza o algoritmo de Dijkstra para determinar a rota ótima
 * entre uma cidade de origem e uma cidade de destino, levando em consideração o tipo de transporte desejado.
 */
class Rota {
public:
    /**
     * @brief Calcula a melhor rota entre duas cidades.
     * 
     * A função utiliza o algoritmo de Dijkstra para encontrar a rota com menor distância entre a cidade de origem
     * e a cidade de destino. Considera apenas os trajetos que correspondem ao tipo de transporte especificado.
     * 
     * @param trajetos Vetor de trajetos disponíveis para serem considerados no cálculo.
     * @param origem Ponteiro para a cidade de origem da rota.
     * @param destino Ponteiro para a cidade de destino da rota.
     * @param tipoTransporte Tipo de transporte desejado ('A' para aquático, 'T' para terrestre).
     * @return Vetor contendo os trajetos na ordem correta que compõem a melhor rota.
     * 
     * @note Se não houver rota disponível entre a origem e o destino, o vetor retornado estará vazio.
     */
    static vector<Trajeto> calcularMelhorRota(vector<Trajeto>* trajetos, Cidade* origem, Cidade* destino, char tipoTransporte);
};

#endif
