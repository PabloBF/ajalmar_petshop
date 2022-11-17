#include "pessoa.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

pessoa cria_pessoa(char nome[NOME_MAX], char rg[RG_MAX], char cpf[CPF_MAX], char endereco[ENDERECO_MAX], int nascimento_dia, int nascimento_mes, int nascimento_ano, int rendimento)
{
    pessoa nova_pessoa;
    nova_pessoa.codigo = total_pessoas++;
    strcpy(nova_pessoa.nome, nome);
    strcpy(nova_pessoa.rg, rg);
    strcpy(nova_pessoa.cpf, cpf);
    strcpy(nova_pessoa.endereco, endereco);
    nova_pessoa.nascimento_dia = nascimento_dia;
    nova_pessoa.nascimento_mes = nascimento_mes;
    nova_pessoa.nascimento_ano = nascimento_ano;
    nova_pessoa.rendimento = rendimento;
    return nova_pessoa;
}

void inicializa_lista_pessoas(lista_pessoas* l)
{
    l->primeiro_no = NULL;
    l->numero_nos = 0;
}

void insere_pessoa_lista(lista_pessoas* l, pessoa p)
{
    no_pessoa* novo_no = (no_pessoa*) malloc(sizeof(no_pessoa));
    novo_no->pessoa = p;
    novo_no->proximo = l->primeiro_no;
    l->primeiro_no = novo_no;
    l->numero_nos++;
}

int exclui_pessoa_lista(lista_pessoas* l, int codigo)
{
    int i;
    no_pessoa* apagar;
    no_pessoa* p;

    if(codigo < 0 || codigo >= l->numero_nos) return 0;
    if(codigo == 0)
    {
        apagar = l->primeiro_no;
        l->primeiro_no = apagar->proximo;
    } else {
        p = l->primeiro_no;
        for(i = 0; i < codigo - 1; i++)
            p = p->proximo;
        apagar = p->proximo;
        p->proximo = apagar->proximo;
    }
    free(apagar);
    l->numero_nos--;
    return 1;
}

pessoa* busca_pessoa(lista_pessoas* l, int codigo)
{
    int i;
    no_pessoa* p;

    if(codigo < 0 || codigo >= l->numero_nos) return NULL;
    p = l->primeiro_no;
    for(i = p->pessoa.codigo; i > codigo; i--)
       p = p->proximo;
    return &p->pessoa;
}

void mostra_pessoa(pessoa p)
{
    wprintf(L"Código: %-3d", p.codigo);
    wprintf(L" | ");
    wprintf(L"Nome: %-*s", NOME_MAX - 1, p.nome);
    wprintf(L" | ");
    wprintf(L"RG: %-*s", RG_MAX - 1, p.rg);
    wprintf(L" | ");
    wprintf(L"CPF: %-*s", CPF_MAX - 1, p.cpf);
    wprintf(L" | ");
    wprintf(L"Endereço: %-*s", ENDERECO_MAX - 1, p.endereco);
    wprintf(L" | ");
    wprintf(L"Nasc. %02d/%02d/%d", p.nascimento_dia, p.nascimento_mes, p.nascimento_ano);
    wprintf(L" | ");
    wprintf(L"Rendimento: R$ %10.2lf", (double) (p.rendimento/100.0));
    wprintf(L"\n");
}

void mostra_pessoa_lista(lista_pessoas* l, int codigo)
{
    pessoa* p = busca_pessoa(l, codigo);
    if(p != NULL)
        mostra_pessoa(*p);
    else
        wprintf(L"Código inválido.\n");
}

void mostra_lista_pessoas(lista_pessoas* l)
{
    no_pessoa* p;
    for(p = l->primeiro_no; p != NULL; p = p->proximo)
        mostra_pessoa(p->pessoa);
}

int set_nome(pessoa* p)
{
    wprintf(L"Nome:\n");
    fflush(stdin);
    fgets(p->nome, NOME_MAX, stdin);
    p->nome[strcspn(p->nome, "\n")] = 0;
    return strcmp(p->nome, "");
}

int set_rg(pessoa* p)
{
    wprintf(L"RG:\n");
    fflush(stdin);
    fgets(p->rg, RG_MAX, stdin);
    p->rg[strcspn(p->rg, "\n")] = 0;
    return strcmp(p->rg, "");
}

int set_cpf(pessoa* p)
{
    wprintf(L"CPF:\n");
    fflush(stdin);
    fgets(p->cpf, CPF_MAX, stdin);
    p->cpf[strcspn(p->cpf, "\n")] = 0;
    return strcmp(p->cpf, "");
}

int set_endereco(pessoa* p)
{
    wprintf(L"Endereço:\n");
    fflush(stdin);
    fgets(p->endereco, NOME_MAX, stdin);
    p->endereco[strcspn(p->endereco, "\n")] = 0;
    return 1;
}

int set_nascimento(pessoa* p)
{
    wprintf(L"Dia, mes e ano de nascimento (dd mm aaaa):\n");
    fflush(stdin);
    wscanf(L"%d %d %d", &p->nascimento_dia, &p->nascimento_mes, &p->nascimento_ano);
    if(p->nascimento_dia > 0 && p->nascimento_mes > 0 && p->nascimento_dia <= 31 && p->nascimento_mes <= 12)
    {
        switch (p->nascimento_mes)
        {
            case 2:
                if(p->nascimento_dia > 29) return 0;
            case 4:
            case 6:
            case 9:
            case 11:
                if(p->nascimento_dia > 30) return 0;
        }
        return 1;
    } else return 0;
}

int set_rendimento(pessoa* p)
{
    float rendimento = 0;
    wprintf(L"Rendimento (R$):\n");
    fflush(stdin);
    wscanf(L"%f", rendimento);
    p->rendimento = (int) (rendimento*100);
}