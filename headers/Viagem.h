#ifndef VIAGEM_H
#define VIAGEM_H

#include <string>
#include <vector>
#include "Cidade.h"
#include "Passageiro.h"
#include "Transporte.h"
#include "Trajeto.h"
using namespace std;

/**
 * @class Viagem
 * @brief Gerencia uma viagem de transporte com passageiros, trajeto e o controle de tempo e distância.
 * 
 * A classe Viagem gerencia uma jornada específica, contendo informações sobre o transporte utilizado, 
 * passageiros a bordo, trajeto a ser seguido, estado atual da viagem e eventuais viagens subsequentes.
 */
class Viagem {
private:
    Transporte* transporte;                /**< Ponteiro para o transporte utilizado na viagem */
    vector<Passageiro*> passageiros;       /**< Vetor de ponteiros para os passageiros que participam da viagem */
    Trajeto* trajeto;                      /**< Ponteiro para o trajeto definido para a viagem */
    Viagem* proxima;                       /**< Ponteiro para a próxima viagem, se houver */
    int horasEmTransito;                   /**< Horas já decorridas em trânsito */
    int distanciaPercorrida;               /**< Distância já percorrida durante a viagem */
    bool emAndamento;                      /**< Indica se a viagem está em andamento */
    bool hasProxima;                       /**< Indica se há uma viagem subsequente */

public:
    /**
     * @brief Construtor da classe Viagem sem próximo trajeto.
     * 
     * Inicializa uma viagem com o transporte, passageiros, trajeto, horas em trânsito, distância percorrida,
     * estado de andamento e informação sobre viagem subsequente.
     * 
     * @param transporte Ponteiro para o transporte utilizado.
     * @param passageiros Vetor de ponteiros para os passageiros.
     * @param trajeto Ponteiro para o trajeto a ser seguido.
     * @param horasEmTransito Horas já em trânsito.
     * @param distanciaPercorrida Distância já percorrida.
     * @param emAndamento Indica se a viagem está em andamento.
     * @param hasProxima Indica se há uma próxima viagem.
     */
    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima);

    /**
     * @brief Construtor da classe Viagem com próximo trajeto.
     * 
     * Além dos parâmetros padrão, aceita um ponteiro para a próxima viagem.
     * 
     * @param transporte Ponteiro para o transporte utilizado.
     * @param passageiros Vetor de ponteiros para os passageiros.
     * @param trajeto Ponteiro para o trajeto a ser seguido.
     * @param horasEmTransito Horas já em trânsito.
     * @param distanciaPercorrida Distância já percorrida.
     * @param emAndamento Indica se a viagem está em andamento.
     * @param hasProxima Indica se há uma próxima viagem.
     * @param proxima Ponteiro para a próxima viagem.
     */
    Viagem(Transporte* transporte, vector<Passageiro*> passageiros, Trajeto* trajeto, int horasEmTransito, int distanciaPercorrida, bool emAndamento, bool hasProxima, Viagem* proxima);

    /**
     * @brief Verifica se a viagem está em andamento.
     * @return true se a viagem está em andamento, false caso contrário.
     */
    bool isEmAndamento();

    /**
     * @brief Verifica se há uma próxima viagem programada.
     * @return true se há uma próxima viagem, false caso contrário.
     */
    bool getHasProxima();

    /**
     * @brief Obtém o número de horas já em trânsito.
     * @return Horas em trânsito.
     */
    int getHorasEmTransito();

    /**
     * @brief Obtém a distância já percorrida durante a viagem.
     * @return Distância percorrida em quilômetros.
     */
    int getDistanciaPercorrida();

    /**
     * @brief Obtém o transporte utilizado na viagem.
     * @return Ponteiro para o transporte.
     */
    Transporte* getTransporte();

    /**
     * @brief Obtém a lista de passageiros na viagem.
     * @return Vetor de ponteiros para os passageiros.
     */
    vector<Passageiro*> getPassageiros();

    /**
     * @brief Obtém o trajeto da viagem.
     * @return Ponteiro para o trajeto.
     */
    Trajeto* getTrajeto();

    /**
     * @brief Obtém a próxima viagem, se houver.
     * @return Ponteiro para a próxima viagem.
     */
    Viagem* getProxima();

    /**
     * @brief Define a distância percorrida durante a viagem.
     * @param distancia Distância percorrida em quilômetros.
     */
    void setDistanciaPercorrida(int distancia);

    /**
     * @brief Inicia a viagem, definindo o estado de "em andamento".
     * @param emTransito Ponteiro para a cidade onde a viagem começa.
     */
    void iniciarViagem(Cidade* emTransito);

    /**
     * @brief Finaliza a viagem, movendo o transporte e os passageiros para a cidade de destino.
     * @param emTransito Ponteiro para a cidade onde a viagem termina.
     */
    void finalizarViagem(Cidade* emTransito);

    /**
     * @brief Avança o tempo da viagem em horas, atualizando o estado do transporte e verificando se a viagem terminou.
     * @param emTransito Ponteiro para a cidade onde o transporte está em trânsito.
     */
    void avancarHoras(Cidade* emTransito);

    /**
     * @brief Relata o estado atual da viagem, incluindo passageiros, transporte e status de descanso.
     */
    void relatarEstado();
};

#endif
