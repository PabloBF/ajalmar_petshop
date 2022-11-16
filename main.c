/*
 *
 * Faça um programa em linguagem C para cadastrar pessoas e seus pets.
Variáveis para cada pessoa:
- código* (da pessoa)
- nome*
- RG
- CPF*
- endereço
- data nascimento* (dd/mm/yyyy)
- rendimento (R$)
Variáveis para cada pet:
- código* (do pet)
- código da pessoa*
- tipo* (cão/gato/cobra/passarinho/etc...)
- nome (do pet)*
- data nascimento*
O asteristo "*" acima indica que o campo é obrigatório, ou seja, deve ser informado no
cadastro.
As funcionalidades para pessoa são:
- inserir uma nova pessoa
- alterar uma pessoa existente
- excluir uma pessoa
- mostrar/imprimir dados de uma pessoa com base no código
- mostrar/imprimir dados de pessoas que tenham um tipo de pet (cão, por exemplo)
- mostrar/imprimir todas as pessoas
- mostrar/imprimir todas as pessoas om ordem alfabética pelo nome
Outros requisitos para pessoa:
- o código da pessoa não pode estar repetido, ou seja, duas pessoas não podem ter o
mesmo código. Logo, verifique se já há uma pessoa com esse código ao tentar inserir.
- o CPF da pessoa não pode estar repetido. Faça como descrito acima.
- as variáveis com "*" não podem estar vazios ou em branco para uma pessoa.

As funcionalidades para pet são:
- inserir um novo pet
- alterar um pet existente
- excluir um pet
- mostrar/imprimir dados de um pet com base no código do pet
- mostrar/imprimir todos os pets de uma pessoa com base no código da pessoa
- mostrar/imprimir todos os pets em ordem alfabética pelo nome
Outros requisitos para pet:
- o código do pet não pode estar repetido, ou seja, dois pets não podem ter o mesmo
código. Logo, verifique se já há um pet com esse código ao tentar inserir.
- dois pets de uma mesma pessoa não podem ter o mesmo nome.
- as variáveis com "*" não podem estar vazios ou em branco para um pet.

Outros requisitos para o programa são:
- crie um menu no programa para usar as funcionalidades acima
- implemente as funcionalidades de pessoa usando um par de arquivos pessoa.h e
pessoa.c.
- implemente as funcionalidades de pet usando um par de arquivos pet.h e pet.c.
- use as funções implementadas nos arquivos um arquivo principal (main.c)

Opcionais (não é obrigatório):
- implementar uma maneira de definição automática dos valores de código para uma
pessoa no momento da inserção. O mesmo pode ser feito para código do pet.
 * */

#include <stdio.h>
#include <locale.h>
#include "pessoa.h"

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    pessoa p0 = cria_pessoa("Pablo", "980020", 03327400000L, "Rua Senador Pompeu, 2610", 25, 5, 1989, 1000000);
    pessoa p1 = cria_pessoa("Margarete", "980020", 03327400000L, "Rua Senador Pompeu, 2610", 22, 12, 1957, 1000000);
    lista_pessoas minha_lista_pessoas;
    inicializa_lista_pessoas(&minha_lista_pessoas);
    insere_pessoa_lista(&minha_lista_pessoas, p0);
    insere_pessoa_lista(&minha_lista_pessoas, p1);
    mostra_pessoa(&minha_lista_pessoas, 0);
    return 0;
}
