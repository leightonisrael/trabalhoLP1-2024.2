# Projeto de Controle de Viagens - IMD0030

Um sistema de gerenciamento de viagens entre cidades que permite simular rotas, transportar passageiros e monitorar o estado de transportes e viagens.

---

## Índice

1. [Visão Geral](#visão-geral)
2. [Estrutura de Arquivos](#estrutura-de-arquivos)
3. [Como Compilar](#como-compilar)
4. [Como Executar o Programa](#como-executar-o-programa)
5. [Limitações Conhecidas](#limitações-conhecidas)
6. [Melhorias Futuras](#melhorias-futuras)
7. [Contribuição](#contribuição)

---

## Visão Geral

Este programa oferece um sistema de gerenciamento de viagens com funcionalidades como:

- Cadastro e gerenciamento de *cidades, **trajetos* e *transportes*.
- Administração de viagens em andamento, incluindo descanso de transportes e cálculo de tempo e distância percorridos.
- Gera relatórios detalhados sobre:
  - Estado das viagens.
  - Status dos passageiros.
  - Condição dos transportes.
  - As 5 cidades mais visitadas.

---

## Estrutura de Arquivos

O projeto é organizado em quatro diretórios principais:

- **classes**: Contém os arquivos .cpp das seguintes classes:

  - Cidade
  - Controlador
  - Passageiro
  - Rota
  - Trajeto
  - Transporte
  - Viagem

- **headers**: Contém os arquivos .h correspondentes às classes acima.

- **leituraEscrita**: Contém as classes responsáveis pela leitura e escrita dos dados de Cidade, Passageiro, Trajeto, Transporte e Viagem.

- **memory**: Guarda os arquivos de dados e as modificações feitas durante a execução.

---

## Como Compilar

Para compilar o projeto usando o g++, siga estas instruções:

1. Navegue até o diretório raiz do projeto.

2. Utilize o comando abaixo no terminal:

   bash
   make
   

3. Após a compilação, um binário será gerado.

---

## Como Executar o Programa

Após compilar, execute o programa com o comando:

bash
./main


Ao iniciar, uma interface textual será exibida. Utilize os comandos fornecidos para interagir com as funcionalidades do sistema, como:

- Iniciar uma nova viagem.
- Carregar dados de cidades, passageiros e trajetos.
- Gerar relatórios de status.

---

## Limitações Conhecidas

1. *Persistência de Dados*:

   - Os dados são armazenados em arquivos de texto.
   - Devido à volatilidade dos endereços de memória, as viagens são reatribuídas ao serem carregadas.

2. *Escalabilidade*:

   - O sistema foi projetado para um número limitado de cidades, transportes e passageiros.
   - Em grandes volumes de dados, a eficiência pode ser reduzida.

3. *Manuseio de Indireções*:

   - O gerenciamento de viagens indiretas depende da ordem correta de leitura dos dados.

4. *Interface Textual*:

   - A interação é feita via terminal, o que pode ser menos intuitivo para alguns usuários.

---

## Melhorias Futuras

- *Otimização de Busca*:

  - Melhorar os algoritmos de busca para trajetos e cidades em grandes volumes de dados.

- *Interface Gráfica*:

  - Desenvolver uma interface mais amigável para facilitar a interação com o sistema.

- *Persistência Aprimorada*:

  - Implementar um sistema mais eficiente para gerenciar dados entre execuções.

---

## Contribuição

Este projeto é aberto a contribuições! Sinta-se à vontade para enviar *sugestões, **correções* ou *melhorias*.

Para contribuir:

1. Fork o repositório.
2. Crie uma branch para suas alterações.
3. Envie um Pull Request.

---

*Agradecemos sua colaboração!*
