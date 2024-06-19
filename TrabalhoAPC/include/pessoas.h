#include <raylib.h>
#include <stdio.h>
#include <string.h>


struct Vencimento
{
    char dia;
    char mes;
    char ano;
};


struct pessoas
{
    char nome[20];

    int ID;

    struct Vencimento vencimento;

    Texture2D Foto;

};



void LoadPessoas(void)
{
    struct pessoas cara00;
    strcpy(cara00.nome, "gustavo");
    cara00.ID = 1;
    cara00.vencimento.dia = '22';
    cara00.vencimento.mes = '11';
    cara00.vencimento.ano = '82';
    cara00.Foto = LoadTexture("cara00.png");

    struct pessoas cara01;
    strcpy(cara01.nome, "druckbaitola");
    cara01.ID = 2;
    cara01.vencimento.dia = '10';
    cara01.vencimento.mes = '05';
    cara01.vencimento.ano = '79';
    cara01.Foto = LoadTexture("cara01.png");

    struct pessoas cara02;
    strcpy(cara02.nome, "tiagogostoso");
    cara02.ID = 3;
    cara02.vencimento.dia = '03';
    cara02.vencimento.mes = '05';
    cara02.vencimento.ano = '85';
    cara02.Foto = LoadTexture("cara02.png");

    struct pessoas cara03;
    strcpy(cara03.nome, "heitorinutil");
    cara03.ID = 4;
    cara03.vencimento.dia = '30';
    cara03.vencimento.mes = '10';
    cara03.vencimento.ano = '87';
    cara03.Foto = LoadTexture("cara03.png");

    struct pessoas mina00;
    strcpy(mina00.nome, "erica");
    mina00.ID = 5;
    mina00.vencimento.dia = '07';
    mina00.vencimento.mes = '01';
    mina00.vencimento.ano = '83';
    mina00.Foto = LoadTexture("mina00.png");

    struct pessoas mina01;
    strcpy(mina01.nome, "thaiscarla");
    mina01.ID = 1;
    mina01.vencimento.dia = '09';
    mina01.vencimento.mes = '03';
    mina01.vencimento.ano = '85';
    mina01.Foto = LoadTexture("mina01.png");

    struct pessoas mina02;
    strcpy(mina02.nome, "fodase");
    mina02.ID = 1;
    mina02.vencimento.dia = '08';
    mina02.vencimento.mes = '02';
    mina02.vencimento.ano = '86';
    mina02.Foto = LoadTexture("mina02.png");

    struct pessoas mina03;
    strcpy(mina03.nome, "receba");
    mina03.ID = 1;
    mina03.vencimento.dia = '10';
    mina03.vencimento.mes = '11';
    mina03.vencimento.ano = '85';
    mina03.Foto = LoadTexture("mina03.png");

}