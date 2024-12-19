// leCidade.h

#ifndef LECIDADE_H
#define LECIDADE_H

#include "../../headers/Cidade.h"
#include <vector>

/**
 * @brief Salva as informações de uma cidade em um arquivo.
 * 
 * Esta função escreve o nome e o número de visitantes de uma cidade no arquivo `cidades.txt`.
 * Se o arquivo não puder ser aberto para escrita, uma mensagem de erro é exibida.
 * 
 * @param cidade Ponteiro para o objeto `Cidade` cujas informações serão salvas.
 */
void salvarCidade(Cidade *cidade);

/**
 * @brief Carrega as cidades de um arquivo.
 * 
 * Esta função lê o arquivo `cidades.txt` e cria um vetor de objetos `Cidade` com base nas informações
 * lidas do arquivo. Cada linha do arquivo deve conter o nome da cidade e o número de visitantes, separados
 * por uma vírgula.
 * 
 * @return Um ponteiro para um vetor de objetos `Cidade` carregados do arquivo. 
 * O usuário é responsável por liberar a memória alocada para este vetor.
 */
std::vector<Cidade>* carregarCidades();

#endif // LECIDADE_H
