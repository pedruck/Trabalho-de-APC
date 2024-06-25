#include <raylib.h>
#include <stdio.h>
#include <string.h>




Texture2D PessoaSprite;
Texture2D PassaporteSprite;
Texture2D PessoaRaioX;


struct Vencimento
{
    char dia;
    char mes;
    char ano;
};

int IDData;


struct pessoas
{
    char nome[20];

    float peso;

    float pesoPassaporte;

    float altura;

    float alturaPassaporte;

    char * sexo;

    int ID;

    struct Vencimento vencimento;


    Texture2D Foto;

    Texture2D FotoPassaporte;
    
    Texture2D RaioXSprite;
    

};

struct pessoas PessoaAtual;


void LoadPessoas(int PessoaCount)
{
    struct pessoas cara00;
    strcpy(cara00.nome, "gustavo");
    cara00.peso = 70;
    cara00.pesoPassaporte = 70;
    cara00.altura = 169;
    cara00.alturaPassaporte = 182;
    strcpy(cara00.sexo, "M");
    //cara00.vencimento.dia = '22';
    //cara00.vencimento.mes = '11';
    //cara00.vencimento.ano = '82';
    cara00.Foto = LoadTexture("Textures/cara00.png");
    cara00.FotoPassaporte = LoadTexture("Textures/ftidcara00.png");
    cara00.RaioXSprite = LoadTexture("Textures/BodyM1.png");


    struct pessoas cara01;
    strcpy(cara01.nome, "druckbaitola");
    cara01.peso = 80;
    cara01.pesoPassaporte = 80;
    cara01.altura = 158;
    cara01.alturaPassaporte = 158;
    strcpy(cara01.sexo, "M");
    // cara01.vencimento.dia = '10';
    //cara01.vencimento.mes = '05';
    //cara01.vencimento.ano = '79';
    cara01.Foto = LoadTexture("Textures/cara01.png");
    cara01.FotoPassaporte = LoadTexture("Textures/ftidcara03.png");
    cara01.RaioXSprite = LoadTexture("Textures/BodyM1.png");

    struct pessoas cara02;
    strcpy(cara02.nome, "tiagogostoso");
    cara02.peso = 78;
    cara02.pesoPassaporte = 73;
    cara02.altura = 168;
    cara02.alturaPassaporte = 168;
    strcpy(cara02.sexo, "M");
   // cara02.vencimento.dia = '03';
   // cara02.vencimento.mes = '05';
   // cara02.vencimento.ano = '85';
    cara02.Foto = LoadTexture("Textures/cara02.png");
    cara02.FotoPassaporte = LoadTexture("Textures/ftidcara02.png");
    cara02.RaioXSprite = LoadTexture("Textures/BodyM1(COMBOMBA).png");

    struct pessoas cara03;
    strcpy(cara03.nome, "heitorinutil");
    cara03.peso = 84;
    cara03.pesoPassaporte = 84; 
    cara03.altura = 167;
    cara03.alturaPassaporte = 167;
    strcpy(cara03.sexo, "M");
    //cara03.vencimento.dia = '30';
   // cara03.vencimento.mes = '10';
   // cara03.vencimento.ano = '87';
    cara03.Foto = LoadTexture("Textures/cara03.png");
    cara03.FotoPassaporte = LoadTexture("Textures/ftidcara03.png");
    cara03.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    

    struct pessoas mina00;
    strcpy(mina00.nome, "erica");
    mina00.peso = 60;
    mina00.pesoPassaporte = 60;
    mina00.altura = 165;
    mina00.alturaPassaporte = 165;
    strcpy(mina00.sexo, "F");
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina00.Foto = LoadTexture("Textures/mina00.png");
    mina00.FotoPassaporte = LoadTexture("Textures/ftidmina00.png");
    mina00.RaioXSprite = LoadTexture("Textures/BodyM1.png");

    struct pessoas mina01;
    strcpy(mina01.nome, "thaiscarla");
    mina01.peso = 40;
    mina01.pesoPassaporte = 45;
    mina01.altura = 157;
    mina01.alturaPassaporte = 157;
    strcpy(mina01.sexo, "F");
   // mina01.vencimento.dia = '09';
   // mina01.vencimento.mes = '03';
    //mina01.vencimento.ano = '85';
    mina01.Foto = LoadTexture("Textures/mina01.png");
    mina01.FotoPassaporte = LoadTexture("Textures/ftidmina01.png");
    mina01.RaioXSprite = LoadTexture("Textures/BodyM1(COMBOMBA).png");

    struct pessoas mina02;
    strcpy(mina02.nome, "Prof Rose");
    mina02.peso = 90;
    mina02.pesoPassaporte = 90;
    mina02.altura = 162;
    mina02.alturaPassaporte = 175;
    strcpy(mina02.sexo, "F");
   // mina02.vencimento.dia = '08';
    //mina02.vencimento.mes = '02';
   // mina02.vencimento.ano = '86';
    mina02.Foto = LoadTexture("Textures/mina02.png");
    mina02.FotoPassaporte = LoadTexture("Textures/ftidmina00.png");
    mina02.RaioXSprite = LoadTexture("Textures/BodyM1.png");

    struct pessoas mina03;
    strcpy(mina03.nome, "receba");
    mina03.peso = 52;
    mina03.pesoPassaporte = 62;
    mina03.altura = 168;
    mina03.alturaPassaporte = 168;
    strcpy(mina03.sexo, "F");
  //  mina03.vencimento.dia = '10';
   // mina03.vencimento.mes = '11';
  //  mina03.vencimento.ano = '85';
    mina03.Foto = LoadTexture("Textures/mina03.png");
    mina03.FotoPassaporte = LoadTexture("Textures/ftidmina03.png");
    mina03.RaioXSprite = LoadTexture("Textures/BodyM1(COMBOMBA).png");


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
    PessoaRaioX = PessoaAtual.RaioXSprite;

}




