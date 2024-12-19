// leViagem.h

#ifndef LEVIAGEM_H
#define LEVIAGEM_H

#include "../../headers/Viagem.h"
#include <vector>
#include <functional>

using namespace std;
/**
 * @brief Salva as informações de uma viagem em um arquivo.
 * 
 * Esta função escreve o nome do transporte, o nome das cidades de origem e destino, a quantidade de passageiros,
 * os nomes dos passageiros, o número de horas em trânsito, a distância percorrida, o status de andamento e se há uma próxima viagem
 * no arquivo `viagens.txt`. Se o arquivo não puder ser aberto para escrita, uma mensagem de erro é exibida.
 * 
 * @param viagem Ponteiro para o objeto `Viagem` cujas informações serão salvas.
 */
void salvarViagem(Viagem *viagem);

/**
 * @brief Carrega as viagens de um arquivo e associa os transportes, trajetos, passageiros e cidades correspondentes.
 * 
 * Esta função lê o arquivo `viagens.txt` e cria um vetor de objetos `Viagem` com base nas informações lidas do arquivo.
 * Os nomes dos transportes, trajetos, passageiros e cidades são usados para associar cada viagem aos seus respectivos objetos.
 * As funções fornecidas como parâmetros são usadas para encontrar os objetos correspondentes.
 * 
 * @param cidades Ponteiro para um vetor de objetos `Cidade` usados para associar trajetos às cidades.
 * @param pesquisarCidade Função que recebe o nome de uma cidade e retorna um ponteiro para o objeto `Cidade` correspondente.
 * @param passageiros Ponteiro para um vetor de objetos `Passageiro` usados para associar passageiros às viagens.
 * @param pesquisarPassageiro Função que recebe o nome de um passageiro e retorna um ponteiro para o objeto `Passageiro` correspondente.
 * @param transportes Ponteiro para um vetor de objetos `Transporte` usados para associar transportes às viagens.
 * @param pesquisarTransporte Função que recebe o nome de um transporte e retorna um ponteiro para o objeto `Transporte` correspondente.
 * @param trajetos Ponteiro para um vetor de objetos `Trajeto` usados para associar trajetos às viagens.
 * @param pesquisarTrajeto Função que recebe o nome das cidades de origem e destino e o tipo de trajeto, e retorna um ponteiro para o objeto `Trajeto` correspondente.
 * 
 * @return Um ponteiro para um vetor de objetos `Viagem` carregados do arquivo e associados aos transportes, trajetos, passageiros e cidades. 
 * O usuário é responsável por liberar a memória alocada para este vetor.
 */

vector<Viagem>* carregarViagens(
    vector<Cidade>* cidades,
    function<Cidade*(const string&)> pesquisarCidade,
    vector<Passageiro>* passageiros,
    function<Passageiro*(const string&)> pesquisarPassageiro,
    vector<Transporte>* transportes,
    function<Transporte*(const string&)> pesquisarTransporte,
    vector<Trajeto>* trajetos,
    function<Trajeto*(const string&, const string&, const char&)> pesquisarTrajeto
);

#endif // LEVIAGEM_H
