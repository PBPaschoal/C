#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    long long card_number;

    // Solicita ao usuário o número do cartão de crédito
    card_number = get_long("Número: ");

    // Converte o número do cartão para uma string
    char card_string[17];
    snprintf(card_string, sizeof(card_string), "%lld", card_number);

    // Obtém o primeiro dígito do cartão
    int first_digit = card_string[0] - '0';

    // Verifica se é um cartão American Express (começa com 34 ou 37) e se possui 15 dígitos
    if ((first_digit == 3) && (card_string[1] == '4' || card_string[1] == '7') && (strlen(card_string) == 15))
    {
        printf("AMEX\n");
    }
    // Verifica se é um cartão MasterCard (começa com 51, 52, 53, 54 ou 55) e se possui 16 dígitos
    else if ((first_digit == 5) && (card_string[1] >= '1' && card_string[1] <= '5') && (strlen(card_string) == 16))
    {
        printf("MASTERCARD\n");
    }
    // Verifica se é um cartão Visa (começa com 4) e se possui 13 ou 16 dígitos
    else if ((first_digit == 4) && ((strlen(card_string) == 13) || (strlen(card_string) == 16)))
    {
        printf("VISA\n");
    }
    // Caso contrário, o cartão é inválido
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
