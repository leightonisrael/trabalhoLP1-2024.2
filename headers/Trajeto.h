#ifndef TRAJETO_H
#define TRAJETO_H

#include <string>
#include "Cidade.h"
using namespace std;

/**
 * @class Trajeto
 * @brief Representa um trajeto entre duas cidades, incluindo o tipo de transporte e a distância.
 * 
 * A classe Trajeto encapsula informações sobre um trajeto específico, como a cidade de origem, a cidade
 * de destino, o tipo de transporte (aquático ou terrestre) e a distância do trajeto.
 */
class Trajeto {
private:
    Cidade* origem;     /**< Cidade de origem do trajeto */
    Cidade* destino;    /**< Cidade de destino do trajeto */
    char tipo;          /**< Tipo de transporte: 'A' para aquático, 'T' para terrestre */
    int distancia;      /**< Distância do trajeto em quilômetros */

public:
    /**
     * @brief Construtor da classe Trajeto.
     * 
     * Inicializa um trajeto com as cidades de origem e destino, o tipo de transporte e a distância.
     * 
     * @param origem Ponteiro para a cidade de origem do trajeto.
     * @param destino Ponteiro para a cidade de destino do trajeto.
     * @param tipo Tipo de transporte: 'A' para aquático, 'T' para terrestre.
     * @param distancia Distância do trajeto em quilômetros.
     */
    Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia);
    
    /**
     * @brief Obtém a cidade de origem do trajeto.
     * @return Ponteiro para a cidade de origem.
     */
    Cidade* getOrigem() const;

    /**
     * @brief Obtém a cidade de destino do trajeto.
     * @return Ponteiro para a cidade de destino.
     */
    Cidade* getDestino() const;

    /**
     * @brief Obtém o tipo de transporte do trajeto.
     * @return Caractere que indica o tipo de transporte ('A' para aquático, 'T' para terrestre).
     */
    char getTipo() const;

    /**
     * @brief Obtém a distância do trajeto.
     * @return Distância em quilômetros.
     */
    int getDistancia() const;

    /**
     * @brief Define a cidade de origem do trajeto.
     * @param origem Ponteiro para a cidade de origem.
     */
    void setOrigem(Cidade* origem);

    /**
     * @brief Define a cidade de destino do trajeto.
     * @param destino Ponteiro para a cidade de destino.
     */
    void setDestino(Cidade* destino);

    /**
     * @brief Define o tipo de transporte do trajeto.
     * @param tipo Caractere que indica o tipo de transporte ('A' para aquático, 'T' para terrestre).
     */
    void setTipo(char tipo);

    /**
     * @brief Define a distância do trajeto.
     * @param distancia Distância em quilômetros.
     */
    void setDistancia(int distancia);
};

#endif
