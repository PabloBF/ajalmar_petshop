#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "pessoa.h"

int main() {
    int opcao, opcao_2, codigo_pessoa;
    char nome[NOME_MAX], rg[RG_MAX], cpf[CPF_MAX], endereco[ENDERECO_MAX];
    int dia, mes, ano;
    float rendimento;
    pessoa p;

    lista_pessoas minha_lista_pessoas;

    setlocale(LC_ALL, "Portuguese_Brazil");
    inicializa_lista_pessoas(&minha_lista_pessoas);

    //pessoas de exemplo
    pessoa p0 = cria_pessoa("Pablo", "980020", "033.274.000-00", "Rua Senador Pompeu, 2610", 25, 5, 1989, 1000000);
    pessoa p1 = cria_pessoa("Margarete", "980020", "033.274.000-01", "Rua Senador Pompeu, 2610", 22, 12, 1957, 200000051);
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
            case 1:
                p = cria_pessoa_void();
                cadastra_pessoa(&minha_lista_pessoas, &p);
                insere_pessoa_lista(&minha_lista_pessoas, p);
                fflush(stdin);
                break;
            case 4:
                do
                {
                    opcao_2 = -1;
                    wprintf(L"Insira o código da pessoa que deseja exibir:\n");
                    scanf("%i", &codigo_pessoa);
                    fflush(stdin);
                    mostra_pessoa_lista(&minha_lista_pessoas, codigo_pessoa);
                    wprintf(L"Aperte 0 para sair ou outra tecla para continuar.\n");
                    scanf("%x", &opcao_2);
                    fflush(stdin);
                } while(opcao_2 != 0);
                break;
            case 6:
                opcao_2 = -1;
                mostra_lista_pessoas(&minha_lista_pessoas);
                wprintf(L"Aperte qualquer tecla para continuar.\n");
                scanf("%x", &opcao_2);
                fflush(stdin);
                break;
            default:
                wprintf(L"Opção inválida.\n", opcao);
        }
    } while(opcao != 0);

    return 0;
}
