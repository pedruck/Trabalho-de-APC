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

    char sexo[200];

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

    struct pessoas cara04; 
    strcpy(cara04.nome, "borabill");
    cara04.peso = 87;
    cara04.pesoPassaporte = 87; 
    cara04.altura = 167;
    cara04.alturaPassaporte = 167;
    strcpy(cara04.sexo, "M");
    //cara04.vencimento.dia = '30';
   // cara04.vencimento.mes = '10';
   // cara04.vencimento.ano = '87';
    cara04.Foto = LoadTexture("Textures/cara04.png");
    cara04.FotoPassaporte = LoadTexture("Textures/ftidcara04.png");
    cara04.RaioXSprite = LoadTexture("Textures/BodyM1.png");

    struct pessoas cara05;
    strcpy(cara05.nome, "amoeldenring");
    cara05.peso = 79;
    cara05.pesoPassaporte = 79; 
    cara05.altura = 163;
    cara05.alturaPassaporte = 163;
    strcpy(cara05.sexo, "M");
    //cara05.vencimento.dia = '30';
   // cara05.vencimento.mes = '10';
   // cara05.vencimento.ano = '87';
    cara05.Foto = LoadTexture("Textures/cara05.png");
    cara05.FotoPassaporte = LoadTexture("Textures/ftidcara05.png");
    cara05.RaioXSprite = LoadTexture("Textures/BodyM1.png");

    struct pessoas cara06;
    strcpy(cara06.nome, "luvadepedreiro");
    cara06.peso = 90;
    cara06.pesoPassaporte = 90; 
    cara06.altura = 190;
    cara06.alturaPassaporte = 192;
    strcpy(cara06.sexo, "M");
    //cara06.vencimento.dia = '30';
   // cara06.vencimento.mes = '10';
   // cara06.vencimento.ano = '87';
    cara06.Foto = LoadTexture("Textures/cara06.png");
    cara06.FotoPassaporte = LoadTexture("Textures/ftidcara06.png");
    cara06.RaioXSprite = LoadTexture("Textures/BodyM1(COMBOMBA).png");

    struct pessoas cara07;
    strcpy(cara07.nome, "scarduabroxa");
    cara07.peso = 96;
    cara07.pesoPassaporte = 96; 
    cara07.altura = 160;
    cara07.alturaPassaporte = 160;
    strcpy(cara07.sexo, "M");
    //cara07.vencimento.dia = '30';
   // cara07.vencimento.mes = '10';
   // cara07.vencimento.ano = '87';
    cara07.Foto = LoadTexture("Textures/cara07.png");
    cara07.FotoPassaporte = LoadTexture("Textures/ftidcara07.png");
    cara07.RaioXSprite = LoadTexture("Textures/BodyM1.png");



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

    struct pessoas mina04;
    strcpy(mina04.nome, "elamesma");
    mina04.peso = 65;
    mina04.pesoPassaporte = 65;
    mina04.altura = 163;
    mina04.alturaPassaporte = 163;
    strcpy(mina04.sexo, "F");
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina00.Foto = LoadTexture("Textures/mina04.png");
    mina00.FotoPassaporte = LoadTexture("Textures/ftidmina04.png");
    mina00.RaioXSprite = LoadTexture("Textures/BodyM1.png");

    struct pessoas mina05;
    strcpy(mina05.nome, "gorda");
    mina05.peso = 80;
    mina05.pesoPassaporte = 80;
    mina05.altura = 165;
    mina05.alturaPassaporte = 165;
    strcpy(mina05.sexo, "F");
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina05.Foto = LoadTexture("Textures/mina05.png");
    mina05.FotoPassaporte = LoadTexture("Textures/ftidmina05.png");
    mina05.RaioXSprite = LoadTexture("Textures/BodyM1.png");

    struct pessoas mina06;
    strcpy(mina06.nome, "erica");
    mina06.peso = 55;
    mina06.pesoPassaporte = 55;
    mina06.altura = 179;
    mina06.alturaPassaporte = 179;
    strcpy(mina06.sexo, "F");
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina06.Foto = LoadTexture("Textures/mina06.png");
    mina06.FotoPassaporte = LoadTexture("Textures/ftidmina06.png");
    mina06.RaioXSprite = LoadTexture("Textures/BodyM1.png");

    struct pessoas mina07;
    strcpy(mina07.nome, "sim");
    mina07.peso = 79;
    mina07.pesoPassaporte = 79;
    mina07.altura = 165;
    mina07.alturaPassaporte = 165;
    strcpy(mina07.sexo, "F");
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina07.Foto = LoadTexture("Textures/mina07.png");
    mina07.FotoPassaporte = LoadTexture("Textures/ftidmina07.png");
    mina07.RaioXSprite = LoadTexture("Textures/BodyM1.png");


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
        PessoaAtual = cara04;
        break;
    case 5:
        PessoaAtual = cara05;
        break;
    case 6:
        PessoaAtual = cara06;
        break;
    case 7:
        PessoaAtual = cara07;
        break;
    case 8:
        PessoaAtual = mina00;
        break;
    case 9:
        PessoaAtual = mina01;
        break;
    case 10:
        PessoaAtual = mina02;
        break;
    case 11:
        PessoaAtual = mina03;
        break;
    case 12:
        PessoaAtual = mina04;
        break;
    case 13:
        PessoaAtual = mina05;
        break;
    case 14:
        PessoaAtual = mina06;
        break;
    case 15:
        PessoaAtual = mina07;
        break;
    }


    PessoaSprite = PessoaAtual.Foto;
    PassaporteSprite = PessoaAtual.FotoPassaporte;
    PessoaRaioX = PessoaAtual.RaioXSprite;

}




