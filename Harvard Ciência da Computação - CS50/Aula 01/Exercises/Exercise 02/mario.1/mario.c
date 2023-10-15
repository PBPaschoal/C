#include <stdio.h>
#include <cs50.h>

int main()
{
    int tamanho;

    do
    {
        tamanho = get_int("Altura: ");
    } while (tamanho < 1 || tamanho > 8);

    for (int i = 1; i <= tamanho; i++)
    {
        // Imprime espaços em branco antes de cada linha
        for (int j = 1; j <= tamanho - i; j++)
        {
            printf(" ");
        }

        // Imprime a primeira sequência de '#'
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        // Imprime o espaço entre as sequências de '#'
        printf(" ");

        // Imprime a segunda sequência de '#'
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        // Imprime uma nova linha
        printf("\n");
    }

    return 0;
}
