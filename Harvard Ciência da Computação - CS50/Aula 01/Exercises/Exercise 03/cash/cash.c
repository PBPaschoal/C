#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float valor;
    int centavos = 0;

    do
    {
        valor = get_float("Troco devido: ");
    } while (valor < 0);

    // Converte o valor em centavos
    centavos = round(valor * 100);

    int moedas = 0;

    // Calcula o número mínimo de moedas
    while (centavos >= 25)
    {
        centavos -= 25;
        moedas++;
    }
    while (centavos >= 10)
    {
        centavos -= 10;
        moedas++;
    }
    while (centavos >= 5)
    {
        centavos -= 5;
        moedas++;
    }
    while (centavos >= 1)
    {
        centavos -= 1;
        moedas++;
    }

    printf("%i\n", moedas);

    return 0;
}
