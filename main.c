#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include "pessoa.h"

int main() {
    int opcao, codigo_pessoa;
    lista_pessoas minha_lista_pessoas;

    setlocale(LC_ALL, "Portuguese_Brazil");
    inicializa_lista_pessoas(&minha_lista_pessoas);

    //pessoas de exemplo
    pessoa p0 = cria_pessoa("Pablo", "980020", 03327400000L, "Rua Senador Pompeu, 2610", 25, 5, 1989, 1000000);
    pessoa p1 = cria_pessoa("Margarete", "980020", 03327400000L, "Rua Senador Pompeu, 2610", 22, 12, 1957, 5300012);
    insere_pessoa_lista(&minha_lista_pessoas, p0);
    insere_pessoa_lista(&minha_lista_pessoas, p1);

    // menu inicial
    do
    {
        opcao = -1;
        wprintf(L"Escolha a opção desejada:\n");

        wprintf(L" 1 - Cadastrar pessoa\n");
        wprintf(L" 2 - Alterar cadastro de pessoa\n");
        wprintf(L" 3 - Excluir cadastro de pessoa\n");
        wprintf(L" 4 - Mostrar pessoa por código\n");
        wprintf(L"*5 - Mostrar pessoas por pet\n");
        wprintf(L" 6 - Mostrar todas as pessoas cadastradas\n");
        wprintf(L"*7 - Mostrar todas as pessoas por ordem alfabética\n");
        wprintf(L" * - Não implementado\n\n");
        wprintf(L" 0 - Sair\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
            case 0:
                wprintf(L"FIM\n");
                break;
            case 4:
                wprintf(L"Insira o código da pessoa que deseja exibir:\n");
                scanf("%i", &codigo_pessoa);
                fflush(stdin);
                mostra_pessoa_lista(&minha_lista_pessoas, codigo_pessoa);
                wprintf(L"Aperte qualquer tecla para continuar.\n");
                scanf("%x", &opcao);
                break;
            case 6:
                mostra_lista_pessoas(&minha_lista_pessoas);
                wprintf(L"Aperte qualquer tecla para continuar.\n");
                scanf("%x", &opcao);
                break;
            default:
                wprintf(L"Você informou o caractere\'%c\'. Opção inválida.\n", opcao);
        }
    } while(opcao != 0);

    return 0;
}
