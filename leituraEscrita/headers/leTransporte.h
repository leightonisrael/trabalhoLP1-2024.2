// leTransporte.h

#ifndef LETRANSPORTE_H
#define LETRANSPORTE_H

#include "../../headers/Transporte.h"
#include <vector>
#include <functional>

/**
 * @brief Salva as informações de um transporte em um arquivo.
 * 
 * Esta função escreve o nome do transporte, o tipo, a capacidade, a velocidade, a cidade atual, a distância entre descansos,
 * o tempo de descanso, o tempo de descanso atual e o estado de descanso (se está descansando ou não) no arquivo `transportes.txt`.
 * Se o arquivo não puder ser aberto para escrita, uma mensagem de erro é exibida.
 * 
 * @param transporte Ponteiro para o objeto `Transporte` cujas informações serão salvas.
 */
void salvarTransporte(Transporte *transporte);

/**
 * @brief Carrega os transportes de um arquivo e associa as cidades correspondentes.
 * 
 * Esta função lê o arquivo `transportes.txt` e cria um vetor de objetos `Transporte` com base nas informações
 * lidas do arquivo. O nome da cidade atual do transporte é usado para associar o transporte a um objeto `Cidade`
 * existente. A função `pesquisarCidade` é utilizada para encontrar a cidade correspondente.
 * 
 * @param cidades Ponteiro para um vetor de objetos `Cidade` usados para associar transportes às cidades.
 * @param pesquisarCidade Função que recebe o nome de uma cidade e retorna um ponteiro para o objeto `Cidade` correspondente.
 * 
 * @return Um ponteiro para um vetor de objetos `Transporte` carregados do arquivo e associados às cidades. 
 * O usuário é responsável por liberar a memória alocada para este vetor.
 */
std::vector<Transporte>* carregarTransportes(
    std::vector<Cidade>* cidades, 
    std::function<Cidade*(const std::string&)> pesquisarCidade
);

#endif // LETRANSPORTE_H
