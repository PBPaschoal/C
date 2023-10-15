#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int start_size, end_size;

    // Solicitar o tamanho inicial da população
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Solicitar o tamanho final da população
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    int years = 0;

    // Calcular o número de anos necessário para atingir o tamanho final
    while (start_size < end_size)
    {
        int births = start_size / 3;
        int deaths = start_size / 4;
        start_size = start_size + births - deaths;
        years++;
    }

    // Imprimir o número de anos necessário
    printf("Years: %i\n", years);

    return 0;
}
