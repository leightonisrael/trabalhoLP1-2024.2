#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <string>
#include "Cidade.h"
using namespace std;

/**
 * @class Transporte
 * @brief Representa um meio de transporte que pode ser utilizado em viagens entre cidades.
 * 
 * A classe Transporte gerencia informações sobre veículos de transporte, como seu nome, tipo
 * (aquático ou terrestre), capacidade de passageiros, velocidade e estado atual (em movimento ou descansando).
 */
class Transporte {
private:
    string nome;                   /**< Nome do transporte */
    char tipo;                     /**< Tipo do transporte: 'A' para aquático, 'T' para terrestre */
    int capacidade;                /**< Capacidade de passageiros */
    int velocidade;                /**< Velocidade em km/h */
    int distanciaEntreDescanso;    /**< Distância percorrida antes de necessitar descanso (em km) */
    int tempoDescanso;             /**< Tempo necessário para descanso (em horas) */
    int tempoDescansoAtual;        /**< Tempo de descanso atual (em horas) */
    Cidade* localAtual;            /**< Localização atual do transporte */
    bool descansando;              /**< Estado do transporte: true se estiver descansando, false caso contrário */

public:
    /**
     * @brief Construtor da classe Transporte.
     * 
     * Inicializa um transporte com nome, tipo, capacidade, velocidade, localização atual, distância entre descansos, 
     * tempo de descanso, tempo de descanso atual e estado de descanso.
     * 
     * @param nome Nome do transporte.
     * @param tipo Tipo do transporte ('A' para aquático, 'T' para terrestre).
     * @param capacidade Capacidade de passageiros.
     * @param velocidade Velocidade do transporte em km/h.
     * @param localAtual Ponteiro para a cidade onde o transporte está localizado.
     * @param distanciaEntreDescanso Distância em quilômetros antes de ser necessário descansar.
     * @param tempoDescanso Tempo de descanso em horas.
     * @param tempoDescansoAtual Tempo atual de descanso em horas (padrão é 0).
     * @param descansando Indica se o transporte está descansando ou não (padrão é false).
     */
    Transporte(string nome, char tipo, int capacidade, int velocidade, Cidade* localAtual, int distanciaEntreDescanso, int tempoDescanso, int tempoDescansoAtual = 0, bool descansando = false);

    /**
     * @brief Obtém o nome do transporte.
     * @return Nome do transporte.
     */
    string getNome();

    /**
     * @brief Obtém o tipo de transporte.
     * @return Tipo do transporte ('A' para aquático, 'T' para terrestre).
     */
    char getTipo();

    /**
     * @brief Obtém a capacidade de passageiros do transporte.
     * @return Capacidade de passageiros.
     */
    int getCapacidade();

    /**
     * @brief Obtém a velocidade do transporte.
     * @return Velocidade em km/h.
     */
    int getVelocidade();

    /**
     * @brief Obtém a distância que o transporte pode percorrer antes de precisar descansar.
     * @return Distância em quilômetros.
     */
    int getDistanciaEntreDescansos();

    /**
     * @brief Obtém o tempo de descanso necessário.
     * @return Tempo de descanso em horas.
     */
    int getTempoDescanso();

    /**
     * @brief Obtém o tempo de descanso atual.
     * @return Tempo atual de descanso em horas.
     */
    int getTempoDescansoAtual();

    /**
     * @brief Obtém a cidade onde o transporte está localizado.
     * @return Ponteiro para a cidade atual.
     */
    Cidade* getLocalAtual();

    /**
     * @brief Verifica se o transporte está descansando.
     * @return true se estiver descansando, false caso contrário.
     */
    bool getDescansando();

    /**
     * @brief Zera o tempo de descanso e atualiza o estado do transporte para não descansando.
     */
    void zerarDescanso();

    /**
     * @brief Aumenta o tempo de descanso atual em 1 hora.
     */
    void aumentarTempoDescansoAtual();

    /**
     * @brief Define a cidade onde o transporte está localizado.
     * @param novoLocal Ponteiro para a nova cidade.
     */
    void setLocalAtual(Cidade* novoLocal);

    /**
     * @brief Define o estado de descanso do transporte.
     * @param descansando Indica se o transporte está descansando (true) ou não (false).
     */
    void setDescansando(bool descansando);
};

#endif
