#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Define o número máximo de candidatos
#define MAX 9

// Define uma estrutura de candidato
typedef struct
{
    string name;
    int votes;
} candidate;

// Array de candidatos
candidate candidates[MAX];

// Número de candidatos na eleição
int candidate_count;

// Protótipos de funções
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verifica o número correto de argumentos na linha de comando
    if (argc < 2)
    {
        printf("Usage: %s candidate1 candidate2 ... candidateN\n", argv[0]);
        return 1;
    }

    // Preenche o array de candidatos com os nomes fornecidos na linha de comando
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Max number of candidates is %d\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Solicita o número de eleitores
    int voter_count = get_int("Number of voters: ");

    // Loop para registrar os votos dos eleitores
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Verifica se o voto é válido e registra-o
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Imprime o(s) vencedor(es)
    print_winner();
}

// Implementação da função de voto
bool vote(string name)
{
    // Percorre a lista de candidatos e verifica se o nome corresponde a um candidato válido
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Incrementa o número de votos para o candidato escolhido
            candidates[i].votes++;
            return true;
        }
    }
    // Se o nome não corresponder a nenhum candidato, retorna falso (voto inválido)
    return false;
}

// Implementação da função para imprimir o(s) vencedor(es)
void print_winner(void)
{
    int max_votes = 0;

    // Encontra o número máximo de votos entre todos os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Imprime todos os candidatos que têm o número máximo de votos (pode haver empate)
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
