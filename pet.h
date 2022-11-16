/*
 * As funcionalidades para pet são:
 * - inserir um novo pet
 * - alterar um pet existente
 * - excluir um pet
 * - mostrar/imprimir dados de um pet com base no código do pet
 * - mostrar/imprimir todos os pets de uma pessoa com base no código da pessoa
 * - mostrar/imprimir todos os pets em ordem alfabética pelo nome
 *
 * Outros requisitos para pet:
 * - o código do pet não pode estar repetido, ou seja, dois pets não podem ter o mesmo código. Logo, verifique se já há um pet com esse código ao tentar inserir.
 * - dois pets de uma mesma pessoa não podem ter o mesmo nome.
 * - as variáveis com "*" não podem estar vazios ou em branco para um pet.
 */

#ifndef PETSHOP_PET_H
#define PETSHOP_PET_H

#include "pessoa.h"
typedef struct pet
{
    int codigo;
    pessoa dono;
    enum tipos {outro, cao, gato, passaro, cobra} tipo;
    char *nome;
    int nascimento_dia;
    int nascimento_mes;
    int nascimento_ano;
} pet;

void add_pet();

#endif //PETSHOP_PET_H
