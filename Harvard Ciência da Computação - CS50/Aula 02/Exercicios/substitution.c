#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Verifique se o número correto de argumentos foi fornecido
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Verifique se a chave fornecida tem o comprimento correto
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Verifique se a chave contém apenas caracteres alfabéticos e únicos
    int used[26] = {0}; // Array para rastrear caracteres usados na chave
    for (int i = 0; i < 26; i++)
    {
        char c = argv[1][i];
        if (!isalpha(c))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }

        c = tolower(c); // Converter para minúsculas para evitar problemas de caso
        if (used[c - 'a'])
        {
            printf("Key must contain each letter exactly once.\n");
            return 1;
        }

        used[c - 'a'] = 1;
    }

    // Solicite ao usuário para inserir o texto a ser cifrado
    printf("plaintext: ");
    char plaintext[100]; // Suponha que o texto tenha no máximo 100 caracteres
    fgets(plaintext, sizeof(plaintext), stdin);

    // Cifre o texto
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A'; // Base dependendo do caso
            int index = tolower(c) - 'a';       // Índice da letra na chave
            char encrypted = argv[1][index];    // Substitua pela letra correspondente na chave
            if (isupper(c))
            {
                encrypted = toupper(encrypted); // Mantenha o caso original
            }
            printf("%c", encrypted);
        }
        else
        {
            printf("%c", c); // Mantenha caracteres não alfabéticos inalterados
        }
    }

    printf("\n");

    return 0;
}
