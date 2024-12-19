// leTrajeto.h

#ifndef LETRAJETO_H
#define LETRAJETO_H

#include "../../headers/Trajeto.h"
#include <vector>
#include <functional>

/**
 * @brief Salva as informações de um trajeto em um arquivo.
 * 
 * Esta função escreve o nome da cidade de origem, o nome da cidade de destino, o tipo de trajeto e a distância
 * no arquivo `trajetos.txt`. Se o arquivo não puder ser aberto para escrita, uma mensagem de erro é exibida.
 * 
 * @param trajeto Ponteiro para o objeto `Trajeto` cujas informações serão salvas.
 */
void salvarTrajeto(Trajeto *trajeto);

/**
 * @brief Carrega os trajetos de um arquivo e associa as cidades correspondentes.
 * 
 * Esta função lê o arquivo `trajetos.txt` e cria um vetor de objetos `Trajeto` com base nas informações
 * lidas do arquivo. O nome das cidades de origem e destino é usado para associar o trajeto a objetos `Cidade`
 * existentes. A função `pesquisarCidade` é utilizada para encontrar as cidades correspondentes.
 * 
 * @param cidades Ponteiro para um vetor de objetos `Cidade` usados para associar trajetos às cidades.
 * @param pesquisarCidade Função que recebe o nome de uma cidade e retorna um ponteiro para o objeto `Cidade` correspondente.
 * 
 * @return Um ponteiro para um vetor de objetos `Trajeto` carregados do arquivo e associados às cidades. 
 * O usuário é responsável por liberar a memória alocada para este vetor.
 */
std::vector<Trajeto>* carregarTrajetos(
    std::vector<Cidade>* cidades, 
    std::function<Cidade*(const std::string&)> pesquisarCidade
);

#endif // LETRAJETO_H
