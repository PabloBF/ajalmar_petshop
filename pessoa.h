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

static int total_pessoas;

typedef struct pessoa
{
    int codigo;
    char *nome;
    char *rg;
    long int cpf;
    char *endereco;
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

void mostra_lista_pessoas(lista_pessoas*);

//void mostra_pessoa_tipo(lista_pessoas*, pet);

pessoa cria_pessoa(char*, char*, long int, char*, int, int, int, int);

#endif //PETSHOP_PESSOA_H