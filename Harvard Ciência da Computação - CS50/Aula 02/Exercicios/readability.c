#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

// Função para calcular o índice Coleman-Liau
int coleman_liau_index(int letters, int sentences, int words);

int main(void) {
    char text[1000];
    printf("Texto: ");
    fgets(text, sizeof(text), stdin);

    int letters = 0, sentences = 0, words = 0;

    // Contar letras, sentenças e palavras no texto
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            letters++;
        } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        } else if (isspace(text[i])) {
            words++;
        }
    }

    // Ajustar o número de palavras (o último período não é uma sentença)
    if (sentences > 0) {
        words++;
    }

    // Calcular o índice Coleman-Liau
    int index = coleman_liau_index(letters, sentences, words);

    // Determinar o nível de leitura
    if (index < 1) {
        printf("Antes da série 1\n");
    } else if (index >= 16) {
        printf("Pós-graduação\n");
    } else {
        printf("Série %d\n", index);
    }

    return 0;
}

int coleman_liau_index(int letters, int sentences, int words) {
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    int index = (int)(0.0588 * L - 0.296 * S - 15.8);
    return index;
}
