#include <raylib.h>
#include <stdio.h>
#include <string.h>




Texture2D PessoaSprite;
Texture2D PassaporteSprite;

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

    Texture2D FotoPassaporte;

};

struct pessoas PessoaAtual;


void LoadPessoas(int PessoaCount)
{
    struct pessoas cara00;
    strcpy(cara00.nome, "gustavo");
    cara00.ID = 1;
    //cara00.vencimento.dia = '22';
    //cara00.vencimento.mes = '11';
    //cara00.vencimento.ano = '82';
    cara00.Foto = LoadTexture("Textures/cara00.png");
    cara00.FotoPassaporte = LoadTexture("Textures/ftidcara00.png");


    struct pessoas cara01;
    strcpy(cara01.nome, "druckbaitola");
    cara01.ID = 2;
   // cara01.vencimento.dia = '10';
    //cara01.vencimento.mes = '05';
    //cara01.vencimento.ano = '79';
    cara01.Foto = LoadTexture("Textures/cara01.png");
    cara01.FotoPassaporte = LoadTexture("Textures/ftidcara03.png");

    struct pessoas cara02;
    strcpy(cara02.nome, "tiagogostoso");
    cara02.ID = 3;
   // cara02.vencimento.dia = '03';
   // cara02.vencimento.mes = '05';
   // cara02.vencimento.ano = '85';
    cara02.Foto = LoadTexture("Textures/cara02.png");
    cara02.FotoPassaporte = LoadTexture("Textures/ftidcara02.png");

    struct pessoas cara03;
    strcpy(cara03.nome, "heitorinutil");
    cara03.ID = 4;
    //cara03.vencimento.dia = '30';
   // cara03.vencimento.mes = '10';
   // cara03.vencimento.ano = '87';
    cara03.Foto = LoadTexture("Textures/cara03.png");
    cara03.FotoPassaporte = LoadTexture("Textures/ftidcara01.png");

    struct pessoas mina00;
    strcpy(mina00.nome, "erica");
    mina00.ID = 5;
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina00.Foto = LoadTexture("Textures/mina00.png");
    mina00.FotoPassaporte = LoadTexture("Textures/ftidmina02.png");

    struct pessoas mina01;
    strcpy(mina01.nome, "thaiscarla");
    mina01.ID = 1;
   // mina01.vencimento.dia = '09';
   // mina01.vencimento.mes = '03';
    //mina01.vencimento.ano = '85';
    mina01.Foto = LoadTexture("Textures/mina01.png");
    mina01.FotoPassaporte = LoadTexture("Textures/ftidcara01.png");

    struct pessoas mina02;
    strcpy(mina02.nome, "Prof Rose");
    mina02.ID = 1;
   // mina02.vencimento.dia = '08';
    //mina02.vencimento.mes = '02';
   // mina02.vencimento.ano = '86';
    mina02.Foto = LoadTexture("Textures/mina02.png");
    mina02.FotoPassaporte = LoadTexture("Textures/ftidcara00.png");

    struct pessoas mina03;
    strcpy(mina03.nome, "receba");
    mina03.ID = 1;
  //  mina03.vencimento.dia = '10';
   // mina03.vencimento.mes = '11';
  //  mina03.vencimento.ano = '85';
    mina03.Foto = LoadTexture("Textures/mina03.png");
    mina03.FotoPassaporte = LoadTexture("Textures/ftidcara03.png");


    //------------------------------------------------------------------

    

    switch (PessoaCount)
    {

    case 0:
        PessoaAtual = cara00;
        break;
    case 1:
        PessoaAtual = cara01;
        break;
    case 2:
        PessoaAtual = cara02;
        break;
    case 3:
        PessoaAtual = cara03;
        break;
    case 4:
        PessoaAtual = mina00;
        break;
    case 5:
        PessoaAtual = mina01;
        break;
    case 6:
        PessoaAtual = mina02;
        break;
    case 7:
        PessoaAtual = mina03;
        break;

    }

    PessoaSprite = PessoaAtual.Foto;
    PassaporteSprite = PessoaAtual.FotoPassaporte;

}




