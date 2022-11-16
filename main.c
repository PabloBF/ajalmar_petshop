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
    //mostra_pessoa_lista(&minha_lista_pessoas, 0);
    mostra_lista_pessoas(&minha_lista_pessoas);
    return 0;
}
