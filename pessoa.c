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

pessoa cria_pessoa_void()
{
    return cria_pessoa("", "", "", "", 1, 1, 1, 0);
}

void cadastra_pessoa(lista_pessoas* l, pessoa* p)
{
    set_rendimento_looping(p);
    set_nome_looping(p);
    set_rg_looping(p);
    set_cpf_looping(p);
    set_endereco_looping(p);
    set_nascimento_looping(p);
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
    int centavos;
    wprintf(L"Rendimento (R$, e.g. 0,00):\n");
    wscanf(L"%f", &rendimento);
    fflush(stdin);
    rendimento = rendimento * 100;
    centavos = (int) rendimento;
    p->rendimento = centavos;
    return (p->rendimento >= 0);
}

void set_nome_looping(pessoa* p)
{
    int flag;
    do
    {
        flag = set_nome(p);
        if(flag) wprintf(L"Nome cadastrado com sucesso.\n");
        else wprintf(L"Entrada inválida, tente novamente.\n");
    } while(!flag);
}

void set_rg_looping(pessoa* p)
{
    int flag;
    do
    {
        flag = set_rg(p);
        if(flag) wprintf(L"RG cadastrado com sucesso.\n");
        else wprintf(L"Entrada inválida, tente novamente.\n");
    } while(!flag);
}

void set_cpf_looping(pessoa* p)
{
    int flag;
    do
    {
        flag = set_cpf(p);
        if(flag) wprintf(L"CPF cadastrado com sucesso.\n");
        else wprintf(L"Entrada inválida, tente novamente.\n");
    } while(!flag);
}

void set_endereco_looping(pessoa* p)
{
        set_endereco(p);
        wprintf(L"Endereço cadastrado com sucesso.\n");
}

void set_nascimento_looping(pessoa* p)
{
    int flag;
    do
    {
        flag = set_nascimento(p);
        if(flag) wprintf(L"Data de nascimento cadastrada com sucesso.\n");
        else wprintf(L"Entrada inválida, tente novamente.\n");
    } while(!flag);
}

void set_rendimento_looping(pessoa* p)
{
    int flag;
    do
    {
        flag = set_rendimento(p);
        if(flag) wprintf(L"Rendimento cadastrado com sucesso.\n");
        else wprintf(L"Entrada inválida, tente novamente.\n");
    } while(!flag);
}