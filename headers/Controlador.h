#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <string>
#include <vector>
#include "Cidade.h"
#include "Passageiro.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Viagem.h"
using namespace std;

/**
 * Classe responsável por gerenciar a lógica principal do sistema de viagens.
 */
class Controlador {
private:
    vector<Cidade>* cidades;         /**< Vetor dinâmico de cidades cadastradas. */
    vector<Passageiro>* passageiros; /**< Vetor dinâmico de passageiros cadastrados. */
    vector<Trajeto>* trajetos;       /**< Vetor dinâmico de trajetos disponíveis. */
    vector<Transporte>* transportes; /**< Vetor dinâmico de transportes cadastrados. */
    vector<Viagem>* viagens;         /**< Vetor dinâmico de viagens em andamento ou concluídas. */

public:
    /**
     * Construtor da classe Controlador.
     * Inicializa os vetores de cidades, passageiros, trajetos, transportes e viagens a partir dos arquivos.
     */
    Controlador();

    /**
     * Destrutor da classe Controlador.
     * Libera a memória alocada para os objetos gerenciados.
     */
    ~Controlador();

    /**
     * Cadastra uma nova cidade.
     * @param nome Nome da cidade a ser cadastrada.
     */
    void cadastrarCidade(string nome);

    /**
     * Pesquisa uma cidade pelo nome.
     * @param nome Nome da cidade a ser pesquisada.
     * @return Ponteiro para a cidade encontrada, ou nullptr se não for encontrada.
     */
    Cidade* pesquisarCidade(string nome);

    /**
     * Exibe um relatório de todas as cidades cadastradas.
     */
    void relatarCidades();

    /**
     * Cadastra um novo passageiro.
     * @param nome Nome do passageiro.
     * @param nomeCidade Nome da cidade onde o passageiro está localizado.
     */
    void cadastrarPassageiro(string nome, string nomeCidade);

    /**
     * Pesquisa um passageiro pelo nome.
     * @param nome Nome do passageiro a ser pesquisado.
     * @return Ponteiro para o passageiro encontrado, ou nullptr se não for encontrado.
     */
    Passageiro* pesquisarPassageiro(string nome);

    /**
     * Exibe um relatório de todos os passageiros cadastrados e suas localizações.
     */
    void relatarPassageiros();

    /**
     * Cadastra um novo trajeto entre duas cidades.
     * @param nomeOrigem Nome da cidade de origem.
     * @param nomeDestino Nome da cidade de destino.
     * @param tipo Tipo do trajeto ('A' para aquático, 'T' para terrestre).
     * @param distancia Distância do trajeto em quilômetros.
     */
    void cadastrarTrajeto(string nomeOrigem, string nomeDestino, char tipo, int distancia);

    /**
     * Pesquisa um trajeto entre duas cidades, considerando o tipo.
     * @param nomeOrigem Nome da cidade de origem.
     * @param nomeDestino Nome da cidade de destino.
     * @param tipo Tipo do trajeto ('A' para aquático, 'T' para terrestre).
     * @return Ponteiro para o trajeto encontrado, ou nullptr se não for encontrado.
     */
    Trajeto* pesquisarTrajeto(string nomeOrigem, string nomeDestino, char tipo);

    /**
     * Cadastra um novo transporte.
     * @param nome Nome do transporte.
     * @param tipo Tipo do transporte ('A' para aquático, 'T' para terrestre).
     * @param capacidade Capacidade máxima de passageiros.
     * @param velocidade Velocidade média do transporte em km/h.
     * @param nomeLocalAtual Nome da cidade onde o transporte está localizado.
     * @param distanciaEntreDescansos Distância que o transporte percorre antes de precisar descansar.
     * @param tempoDescanso Tempo de descanso necessário após percorrer a distância definida.
     */
    void cadastrarTransporte(string nome, char tipo, int capacidade, int velocidade, string nomeLocalAtual, int distanciaEntreDescansos, int tempoDescanso);

    /**
     * Pesquisa um transporte pelo nome.
     * @param nome Nome do transporte a ser pesquisado.
     * @return Ponteiro para o transporte encontrado, ou nullptr se não for encontrado.
     */
    Transporte* pesquisarTransporte(string nome);

    /**
     * Exibe um relatório de todos os transportes cadastrados e suas informações.
     */
    void relatarTransportes();

    /**
     * Inicia uma nova viagem com o transporte especificado, levando os passageiros entre as cidades de origem e destino.
     * @param nomeTransporte Nome do transporte a ser utilizado.
     * @param nomesPassageiros Vetor com os nomes dos passageiros que participarão da viagem.
     * @param nomeOrigem Nome da cidade de origem.
     * @param nomeDestino Nome da cidade de destino.
     */
    void iniciarViagem(string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino);

    /**
     * Avança o tempo da simulação, fazendo com que as viagens em andamento progridam.
     */
    void avancarHoras();

    /**
     * Salva o estado atual das cidades, passageiros, trajetos, transportes e viagens nos arquivos correspondentes e encerra o programa.
     */
    void salvarSair();

    /**
     * Exibe um relatório geral das viagens em andamento, passageiros e transportes, além das 5 cidades mais visitadas.
     */
    void relatarEstados();
};

#endif // CONTROLADOR_H
