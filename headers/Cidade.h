#ifndef CIDADE_H
#define CIDADE_H

#include <string>
using namespace std;

/**
 * @class Cidade
 * @brief Representa uma cidade no sistema de viagens.
 * 
 * A classe Cidade gerencia o nome e a quantidade de visitantes da cidade. 
 * As cidades são usadas em trajetos e viagens.
 */
class Cidade {
private:
    string nome; ///< Nome da cidade.
    int visitantes; ///< Número de visitantes na cidade.

public:
    /**
     * @brief Construtor padrão da classe Cidade.
     * @param nome Nome da cidade.
     * @param visitantes Número inicial de visitantes na cidade.
     */
    Cidade(string nome, int visitantes = 0);

    /**
     * @brief Obtém o nome da cidade.
     * @return O nome da cidade.
     */
    string getNome();

    /**
     * @brief Obtém o número de visitantes da cidade.
     * @return Número de visitantes.
     */
    int getVisitantes();

    /**
     * @brief Adiciona visitantes à cidade.
     * @param n Número de visitantes a adicionar.
     */
    void addVisitantes(int n);
};

#endif
