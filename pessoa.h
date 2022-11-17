/*
 * As funcionalidades para pessoa são:
 * - inserir uma nova pessoa // feito, insere_pessoa_lista();
 * - alterar uma pessoa existente //
 * - excluir uma pessoa // feito, exclui_pessoa_lista();
 * - mostrar/imprimir dados de uma pessoa com base no_pessoa código //
 * - mostrar/imprimir dados de pessoas que tenham um tipo de pet (cão, por exemplo)
 * - mostrar/imprimir todas as pessoas
 * - mostrar/imprimir todas as pessoas om ordem alfabética pelo nome
 * Outros requisitos para pessoa:
 * - o código da pessoa não pode estar repetido, ou seja, duas pessoas não podem ter o mesmo código. Logo, verifique se já há uma pessoa com esse código ao tentar inserir.
 * - o CPF da pessoa não pode estar repetido. Faça como descrito acima.
 * - as variáveis com "*" não podem estar vazios ou em branco para uma pessoa.
 * */

#ifndef PETSHOP_PESSOA_H
#define PETSHOP_PESSOA_H

#include "pet.h"
#define NOME_MAX 51
#define RG_MAX 21
#define CPF_MAX 15
#define ENDERECO_MAX 76

static int total_pessoas;

typedef struct pessoa
{
    int codigo;
    char nome[NOME_MAX];
    char rg[RG_MAX];
    char cpf[CPF_MAX];
    char endereco[ENDERECO_MAX];
    int nascimento_dia;
    int nascimento_mes;
    int nascimento_ano;
    int rendimento; // em centavos de real.
} pessoa;

typedef struct no_pessoa
{
    pessoa pessoa;
    struct no_pessoa* proximo;
} no_pessoa;

typedef struct lista_pessoas
{
    no_pessoa* primeiro_no;
    int numero_nos;
} lista_pessoas;

void inicializa_lista_pessoas(lista_pessoas*);

void insere_pessoa_lista(lista_pessoas*, pessoa);

int exclui_pessoa_lista(lista_pessoas*, int);

pessoa* busca_pessoa(lista_pessoas*, int);

void mostra_pessoa_lista(lista_pessoas*, int);

void altera_pessoa_lista(lista_pessoas*, int);

void mostra_lista_pessoas(lista_pessoas*);

//void mostra_pessoa_tipo(lista_pessoas*, pet);

int set_nome(pessoa*);

int set_rg(pessoa*);

int set_cpf(pessoa*);

int set_endereco(pessoa*);

int set_nascimento(pessoa*);

int set_rendimento(pessoa*);

void set_nome_looping(pessoa*);

void set_rg_looping(pessoa*);

void set_cpf_looping(pessoa*);

void set_endereco_looping(pessoa*);

void set_nascimento_looping(pessoa*);

void set_rendimento_looping(pessoa*);

void cadastra_pessoa(lista_pessoas*, pessoa*);

pessoa cria_pessoa_void();

pessoa cria_pessoa(char*, char*, char*, char*, int, int, int, int);

#endif //PETSHOP_PESSOA_H