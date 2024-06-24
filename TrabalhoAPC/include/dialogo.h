#include "raylib.h"

char * MensagemInicial;

void LoadDialogo (int PessoaCount)
{



 switch (PessoaCount)
    {

    case 0:
        MensagemInicial = "Fila tava muito longa meu deus.\nSe tu n me aprovar agr eu vo ficar bem chateado!";
        break;
    case 1:
        MensagemInicial = "Alguém soltou um peidão na fila, quase morri.\nEu acho q foi aquele tal de Erick la";
        break;
    case 2:
        MensagemInicial = "Fiquei 5 horas esperando, faça valer a pena";
        break;
    case 3:
        MensagemInicial = "Não vejo minha filha a 5 anos! Hoje é o grande dia...";       
        break;
    case 4:
        MensagemInicial = "Esse Heitor é muito vagabundo... ta maluco"; 
        break;
    case 5:
        MensagemInicial = "Não deixe o cara que está antes de mim passar...\nele é perigoso";        
        break;
    case 6:
        MensagemInicial = "Seja rapido por favor, tenho compromissos...";              
        break;
    case 7:
        MensagemInicial = "Estou o dia inteiro na fila, não me faça\nvoltar pra casa...";         
        break;

    }

    


}