#include "pessoa.h"
#include <stdlib.h>
#include <stdio.h>

pessoa cria_pessoa(char* nome, char* rg, long int cpf, char* endereco, int nascimento_dia, int nascimento_mes, int nascimento_ano, int rendimento)
{
    pessoa nova_pessoa;
    nova_pessoa.codigo = total_pessoas++;
    nova_pessoa.nome = nome;
    nova_pessoa.rg = rg;
    nova_pessoa.cpf = cpf;
    nova_pessoa.endereco = endereco;
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

void mostra_pessoa(lista_pessoas* l, int codigo)
{
    pessoa* p = busca_pessoa(l, codigo);
    if(p != NULL)
        wprintf(L"Nome: %s (nasc. %02d/%02d/%d).\n", p->nome, p->nascimento_dia, p->nascimento_mes, p->nascimento_ano);
    else
        wprintf(L"Código inválido.\n");
}