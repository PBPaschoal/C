#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // Verifique se o número correto de argumentos foi fornecido
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Converta a chave de string para inteiro
    int key = atoi(argv[1]);

    // Solicite ao usuário para inserir o texto a ser criptografado
    printf("plaintext: ");
    char plaintext[100]; // Suponha que o texto tenha no máximo 100 caracteres
    fgets(plaintext, sizeof(plaintext), stdin);

    // Criptografe o texto
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            char encrypted = (((c - base) + key) % 26) + base;
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
