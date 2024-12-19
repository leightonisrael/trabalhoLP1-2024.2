/**
 * @file Passageiro.h
 * @brief Declaração e implementação da classe Passageiro.
 *
 * A classe Passageiro representa um passageiro com um nome e uma cidade associada como localização atual.
 */

#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>
#include "Cidade.h"

using namespace std;

/**
 * @class Passageiro
 * @brief Classe que representa um passageiro.
 *
 * Esta classe contém o nome de um passageiro e a cidade onde ele está atualmente localizado.
 */
class Passageiro {
private:
    string nome;          ///< Nome do passageiro.
    Cidade* localAtual;   ///< Ponteiro para a cidade atual do passageiro.

public:
    /**
     * @brief Construtor da classe Passageiro.
     * @param nome Nome do passageiro.
     * @param localAtual Ponteiro para a cidade onde o passageiro está localizado atualmente.
     */
    Passageiro(string nome, Cidade* localAtual);

    /**
     * @brief Retorna o nome do passageiro.
     * @return Uma string contendo o nome do passageiro.
     */
    string getNome();

    /**
     * @brief Retorna a cidade atual do passageiro.
     * @return Um ponteiro para a cidade onde o passageiro está localizado atualmente.
     */
    Cidade* getLocalAtual();

    /**
     * @brief Define a cidade atual do passageiro.
     * @param localAtual Ponteiro para a nova cidade onde o passageiro será localizado.
     */
    void setLocalAtual(Cidade* localAtual);
};

#endif
