#include "raylib.h"

char Mensagem[100];

void LoadDialogo (int PessoaCount)
{


char MensagemRandom[8][100] = {"Fila tava muito longa meu deus.\nSe tu n me aprovar agr eu vo ficar bem chateado!",
                                "Só quero voltar pra casa logo.\nFiquei horas nessa fila gigante...",
                                "Fiquei 5 horas esperando, faça valer a pena",
                                "Não vejo minha filha a 5 anos! Hoje é o grande dia...",
                                "Não demore muito. Se eu me atrasar o meu chefe\n me mata!",
                                "Não deixe o cara que está depois de mim passar...\nele é perigoso",
                                "Seja rapido por favor, tenho compromissos...",
                                "Estou o dia inteiro na fila, não me faça\nvoltar pra casa..."};



int Randomizador = GetRandomValue(0, 7);

strcpy(Mensagem, MensagemRandom[Randomizador]);


}

    


