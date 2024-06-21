#include "raylib.h"

char * MensagemInicial;

void LoadDialogo (int PessoaCount ,int FrameCounter)
{

 FrameCounter =  0;

 switch (PessoaCount)
    {

    case 0:
        MensagemInicial = "Fila tava muito longa meu deus. Se tu n me aprovar agr eu vo ficar bem chateado!";
        break;
    case 1:
        MensagemInicial = "Alguém soltou um peidão na fila, quase morri. Eu acho q foi aquele tal de Erick la";
        break;
    case 2:
        MensagemInicial = "Fiquei 5 horas esperando, faça valer a pena";
        break;
    case 3:
        MensagemInicial = "Não vejo a minha filha a 5 anos! Hoje é o grande dia...";       
        break;
    case 4:
        MensagemInicial = "Esse Heitor é muito vagabundo... ta maluco"; 
        break;
    case 5:
        MensagemInicial = "Não deixe o cara que está antes de mim passar... ele é perigoso";        
        break;
    case 6:
        MensagemInicial = "Seja rapido por favor, tenho compromissos...";              
        break;
    case 7:
        MensagemInicial = "Estou o dia inteiro na fila, não me faça voltar pra casa...";         
        break;

    }


}