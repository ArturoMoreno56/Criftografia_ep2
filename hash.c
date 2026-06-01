#include <stdio.h>
#include <string.h>

int valorDeCaracter(char c);
long calcularHash(char *frase);

int main()
{
    char frase[50];

    printf("Ingrese la frase que desea hashear: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    long hash = calcularHash(frase);

    printf("\n");
    printf("Frase original : %s\n", frase);
    printf("Hash numerico  : %d\n", hash);

    return 0;
}

int valorDeCaracter(char c)
{

    char alfabeto[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,;:!?-_()[]{}\"'@#$%&*+/=";
    int i;
    for (i = 0; alfabeto[i] != '\0'; i++)
    {
        if (alfabeto[i] == c)
            return i + 1;
    }
    return 0;
}

long calcularHash(char *frase)
{
    long hash = 1, primo = 7;
    int i;
    for (i = 0; frase[i] != '\0'; i++)
    {
        int valor = valorDeCaracter(frase[i]);
        hash = hash * primo + valor;
        hash = hash % 1000007;
    }

    return hash;
}