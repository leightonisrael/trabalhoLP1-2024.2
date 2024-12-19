// lePassageiro.h

#ifndef LEPASSAGEIRO_H
#define LEPASSAGEIRO_H

#include "../../headers/Passageiro.h"
#include <vector>
#include <functional>

/**
 * @brief Salva as informações de um passageiro em um arquivo.
 * 
 * Esta função escreve o nome do passageiro e a cidade onde ele está atualmente no arquivo `passageiros.txt`.
 * Se o arquivo não puder ser aberto para escrita, uma mensagem de erro é exibida.
 * 
 * @param passageiro Ponteiro para o objeto `Passageiro` cujas informações serão salvas.
 */
void salvarPassageiro(Passageiro *passageiro);

/**
 * @brief Carrega os passageiros de um arquivo e associa as cidades correspondentes.
 * 
 * Esta função lê o arquivo `passageiros.txt` e cria um vetor de objetos `Passageiro` com base nas informações
 * lidas do arquivo. O nome da cidade atual do passageiro é usado para associar o passageiro a um objeto `Cidade`
 * existente. A função `pesquisarCidade` é utilizada para encontrar a cidade correspondente.
 * 
 * @param cidades Ponteiro para um vetor de objetos `Cidade` usados para associar passageiros às cidades.
 * @param pesquisarCidade Função que recebe o nome de uma cidade e retorna um ponteiro para o objeto `Cidade` correspondente.
 * 
 * @return Um ponteiro para um vetor de objetos `Passageiro` carregados do arquivo e associados às cidades. 
 * O usuário é responsável por liberar a memória alocada para este vetor.
 */
std::vector<Passageiro>* carregarPassageiros(
    std::vector<Cidade>* cidades, 
    std::function<Cidade*(const std::string&)> pesquisarCidade
);

#endif // LEPASSAGEIRO_H
