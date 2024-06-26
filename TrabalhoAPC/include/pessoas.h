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

struct FotoPessoa
{

    Texture2D Foto;
    

    int FotoID;

};


























struct pessoas
{
    char nome[30];

    float peso;

    float pesoPassaporte;

    float altura;

    float alturaPassaporte;

    char sexo[300];

    int ID;

    struct Vencimento vencimento;

    bool bombado;

    struct FotoPessoa Foto;

    struct FotoPessoa FotoPassaporte;
    
    Texture2D RaioXSprite;
    

};

struct pessoas PessoaAtual;


void LoadPessoas(int PessoaCount)
{

    struct FotoPessoa SpriteM0;
    SpriteM0.Foto = LoadTexture("Textures/cara00.png");
    SpriteM0.FotoID = 0;

    struct FotoPessoa PassaportM0;
    PassaportM0.Foto = LoadTexture("Textures/ftidcara00.png");
    PassaportM0.FotoID = 0;

    struct FotoPessoa SpriteM1;
    SpriteM1.Foto = LoadTexture("Textures/cara01.png");
    SpriteM1.FotoID = 1;

    struct FotoPessoa PassaportM1;
    PassaportM1.Foto = LoadTexture("Textures/ftidcara01.png");
    PassaportM1.FotoID = 1;


    struct FotoPessoa SpriteM2;
    SpriteM2.Foto = LoadTexture("Textures/cara02.png");
    SpriteM2.FotoID = 2;

    struct FotoPessoa PassaportM2;
    PassaportM2.Foto = LoadTexture("Textures/ftidcara02.png");
    PassaportM2.FotoID = 2;

    struct FotoPessoa SpriteM3;
    SpriteM3.Foto = LoadTexture("Textures/cara03.png");
    SpriteM3.FotoID = 3;

    struct FotoPessoa PassaportM3;
    PassaportM3.Foto = LoadTexture("Textures/ftidcara03.png");
    PassaportM3.FotoID = 3;

    struct FotoPessoa SpriteM4;
    SpriteM4.Foto = LoadTexture("Textures/cara04.png");
    SpriteM4.FotoID = 4;

    struct FotoPessoa PassaportM4;
    PassaportM4.Foto = LoadTexture("Textures/ftidcara04.png");
    PassaportM4.FotoID = 4;

    struct FotoPessoa SpriteM5;
    SpriteM5.Foto = LoadTexture("Textures/cara05.png");
    SpriteM5.FotoID = 5;

    struct FotoPessoa PassaportM5;
    PassaportM5.Foto = LoadTexture("Textures/ftidcara05.png");
    PassaportM5.FotoID = 5;

    struct FotoPessoa SpriteM6;
    SpriteM6.Foto = LoadTexture("Textures/cara06.png");
    SpriteM6.FotoID = 6;

    struct FotoPessoa PassaportM6;
    PassaportM6.Foto = LoadTexture("Textures/ftidcara06.png");
    PassaportM6.FotoID = 6;

    struct FotoPessoa SpriteM7;
    SpriteM7.Foto = LoadTexture("Textures/cara07.png");
    SpriteM7.FotoID = 7;

    struct FotoPessoa PassaportM7;
    PassaportM7.Foto = LoadTexture("Textures/ftidcara07.png");
    PassaportM7.FotoID = 7;

    struct FotoPessoa SpriteF0;
    SpriteF0.Foto = LoadTexture("Textures/mina00.png");
    SpriteF0.FotoID = 8;

    struct FotoPessoa PassaportF0;
    PassaportF0.Foto = LoadTexture("Textures/ftidmina00.png");
    PassaportF0.FotoID = 8;

    struct FotoPessoa SpriteF1;
    SpriteF1.Foto = LoadTexture("Textures/mina01.png");
    SpriteF1.FotoID = 9;

    struct FotoPessoa PassaportF1;
    PassaportF1.Foto = LoadTexture("Textures/ftidmina01.png");
    PassaportF1.FotoID = 9;

    struct FotoPessoa SpriteF2;
    SpriteF2.Foto = LoadTexture("Textures/mina02.png");
    SpriteF2.FotoID = 10;

    struct FotoPessoa PassaportF2;
    PassaportF2.Foto = LoadTexture("Textures/ftidmina02.png");
    PassaportF2.FotoID = 10;

    struct FotoPessoa SpriteF3;
    SpriteF3.Foto = LoadTexture("Textures/mina03.png");
    SpriteF3.FotoID = 11;

    struct FotoPessoa PassaportF3;
    PassaportF3.Foto = LoadTexture("Textures/ftidmina03.png");
    PassaportF3.FotoID = 11;

    struct FotoPessoa SpriteF4;
    SpriteF4.Foto = LoadTexture("Textures/mina04.png");
    SpriteF4.FotoID = 13;

    struct FotoPessoa PassaportF4;
    PassaportF4.Foto = LoadTexture("Textures/ftidmina04.png");
    PassaportF4.FotoID = 13;

    struct FotoPessoa SpriteF5;
    SpriteF5.Foto = LoadTexture("Textures/mina05.png");
    SpriteF5.FotoID = 13;

    struct FotoPessoa PassaportF5;
    PassaportF5.Foto = LoadTexture("Textures/ftidmina05.png");
    PassaportF5.FotoID = 13;

    struct FotoPessoa SpriteF6;
    SpriteF6.Foto = LoadTexture("Textures/mina06.png");
    SpriteF6.FotoID = 14;

    struct FotoPessoa PassaportF6;
    PassaportF6.Foto = LoadTexture("Textures/ftidmina06.png");
    PassaportF6.FotoID = 14;

    struct FotoPessoa SpriteF7;
    SpriteF7.Foto = LoadTexture("Textures/mina07.png");
    SpriteF7.FotoID = 15;

    struct FotoPessoa PassaportF7;
    PassaportF7.Foto = LoadTexture("Textures/ftidmina07.png");
    PassaportF7.FotoID = 15;


//------------------------------------------------------------------------------------------------------------------------------------


    struct pessoas cara00;
    strcpy(cara00.nome, "gustavo");
    cara00.peso = 70;
    cara00.pesoPassaporte = 70;
    cara00.altura = 179;
    cara00.alturaPassaporte = 183;
    strcpy(cara00.sexo, "M");
    //cara00.vencimento.dia = '33';
    //cara00.vencimento.mes = '11';
    //cara00.vencimento.ano = '83';
    cara00.Foto = SpriteM0;
    cara00.FotoPassaporte = PassaportM0;
    cara00.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    cara00.ID = 1;
    cara00.bombado = false;



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
    cara01.Foto = SpriteM1;
    cara01.FotoPassaporte = PassaportM1;
    cara01.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    cara01.ID = 2;
    cara01.bombado = false;

    struct pessoas cara02;
    strcpy(cara02.nome, "tiagogostoso");
    cara02.peso = 78;
    cara02.pesoPassaporte = 73;
    cara02.altura = 178;
    cara02.alturaPassaporte = 178;
    strcpy(cara02.sexo, "M");
   // cara03.vencimento.dia = '03';
   // cara03.vencimento.mes = '05';
   // cara03.vencimento.ano = '85';
    cara02.Foto = SpriteM2;
    cara02.FotoPassaporte = PassaportM2;
    cara02.RaioXSprite = LoadTexture("Textures/BodyM1(COMBOMBA).png");
    cara02.ID = 3;
    cara02.bombado = true;


    struct pessoas cara03;
    strcpy(cara03.nome, "heitorinutil");
    cara03.peso = 84;
    cara03.pesoPassaporte = 84; 
    cara03.altura = 177;
    cara03.alturaPassaporte = 177;
    strcpy(cara03.sexo, "M");
    //cara03.vencimento.dia = '30';
   // cara03.vencimento.mes = '10';
   // cara03.vencimento.ano = '87';
    cara03.Foto = SpriteM3;
    cara03.FotoPassaporte = PassaportM6;
    cara03.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    cara03.ID = 3;
    cara03.bombado = false;

    struct pessoas cara04; 
    strcpy(cara04.nome, "borabill");
    cara04.peso = 87;
    cara04.pesoPassaporte = 87; 
    cara04.altura = 177;
    cara04.alturaPassaporte = 177;
    strcpy(cara04.sexo, "M");
    //cara04.vencimento.dia = '30';
   // cara04.vencimento.mes = '10';
   // cara04.vencimento.ano = '87';
    cara04.Foto = SpriteM4;
    cara04.FotoPassaporte = PassaportM4;
    cara04.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    cara04.bombado = false;

    cara04.ID = 4;

    struct pessoas cara05;
    strcpy(cara05.nome, "amoeldenring");
    cara05.peso = 79;
    cara05.pesoPassaporte = 79; 
    cara05.altura = 173;
    cara05.alturaPassaporte = 173;
    strcpy(cara05.sexo, "M");
    //cara05.vencimento.dia = '30';
   // cara05.vencimento.mes = '10';
   // cara05.vencimento.ano = '87';
    cara05.Foto = SpriteM5;
    cara05.FotoPassaporte = PassaportM5;
    cara05.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    cara05.ID = 5;
    cara05.bombado = false;
  

    struct pessoas cara06;
    strcpy(cara06.nome, "luvadepedreiro");
    cara06.peso = 90;
    cara06.pesoPassaporte = 90; 
    cara06.altura = 190;
    cara06.alturaPassaporte = 193;
    strcpy(cara06.sexo, "M");
    //cara07.vencimento.dia = '30';
   // cara07.vencimento.mes = '10';
   // cara07.vencimento.ano = '87';
    cara06.Foto = SpriteM6;
    cara06.FotoPassaporte = PassaportM6;
    cara06.RaioXSprite = LoadTexture("Textures/BodyM1(COMBOMBA).png");
    cara06.ID = 7;
    cara06.bombado = true;


    struct pessoas cara07;
    strcpy(cara07.nome, "scarduabroxa");
    cara07.peso = 97;
    cara07.pesoPassaporte = 97; 
    cara07.altura = 170;
    cara07.alturaPassaporte = 170;
    strcpy(cara07.sexo, "M");
    //cara07.vencimento.dia = '30';
   // cara07.vencimento.mes = '10';
   // cara07.vencimento.ano = '87';
    cara07.Foto = SpriteM7;
    cara07.FotoPassaporte = PassaportM7;
    cara07.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    cara07.ID = 7;
    cara07.bombado = false;



    struct pessoas mina00;
    strcpy(mina00.nome, "erica");
    mina00.peso = 70;
    mina00.pesoPassaporte = 70;
    mina00.altura = 175;
    mina00.alturaPassaporte = 175;
    strcpy(mina00.sexo, "F");
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina00.Foto = SpriteF0;
    mina00.FotoPassaporte = PassaportF0;
    mina00.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    mina00.ID = 8;
    mina00.bombado = false;

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
    mina01.Foto = SpriteF1;
    mina01.FotoPassaporte = PassaportF1;
    mina01.RaioXSprite = LoadTexture("Textures/BodyM1(COMBOMBA).png");
    mina01.ID = 9;
    mina01.bombado = true;

    struct pessoas mina02;
    strcpy(mina02.nome, "Prof Rose");
    mina02.peso = 90;
    mina02.pesoPassaporte = 90;
    mina02.altura = 172;
    mina02.alturaPassaporte = 175;
    strcpy(mina02.sexo, "F");
   // mina02.vencimento.dia = '08';
    //mina02.vencimento.mes = '02';
   // mina02.vencimento.ano = '87';
    mina02.Foto = SpriteF2;
    mina02.FotoPassaporte = PassaportF2;
    mina02.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    mina02.ID = 10;
    mina02.bombado = false;


    struct pessoas mina03;
    strcpy(mina03.nome, "receba");
    mina03.peso = 53;
    mina03.pesoPassaporte = 73;
    mina03.altura = 178;
    mina03.alturaPassaporte = 178;
    strcpy(mina03.sexo, "F");
  //  mina03.vencimento.dia = '10';
   // mina03.vencimento.mes = '11';
  //  mina03.vencimento.ano = '85';
    mina03.Foto = SpriteF3;
    mina03.FotoPassaporte = PassaportF3;
    mina03.RaioXSprite = LoadTexture("Textures/BodyM1(COMBOMBA).png");
    mina03.ID = 11;
    mina03.bombado = true;

    struct pessoas mina04;
    strcpy(mina04.nome, "elamesma");
    mina04.peso = 75;
    mina04.pesoPassaporte = 75;
    mina04.altura = 173;
    mina04.alturaPassaporte = 173;
    strcpy(mina04.sexo, "F");
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina04.Foto = SpriteF4;
    mina04.FotoPassaporte = PassaportF4;
    mina04.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    mina04.ID = 13;
    mina04.bombado = false;

    struct pessoas mina05;
    strcpy(mina05.nome, "gorda");
    mina05.peso = 80;
    mina05.pesoPassaporte = 80;
    mina05.altura = 175;
    mina05.alturaPassaporte = 175;
    strcpy(mina05.sexo, "F");
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina05.Foto = SpriteF5;
    mina05.FotoPassaporte = PassaportF5;
    mina05.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    mina05.ID = 13;
    mina05.bombado = false;

    struct pessoas mina06;
    strcpy(mina06.nome, "erica");
    mina06.peso = 55;
    mina06.pesoPassaporte = 55;
    mina06.altura = 169;
    mina06.alturaPassaporte = 169;
    strcpy(mina06.sexo, "F");
   // mina00.vencimento.dia = '06';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina06.Foto = SpriteF6;
    mina06.FotoPassaporte = PassaportF3;
    mina06.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    mina06.ID = 14;
    mina06.bombado = false;

    struct pessoas mina07;
    strcpy(mina07.nome, "sim");
    mina07.peso = 79;
    mina07.pesoPassaporte = 79;
    mina07.altura = 175;
    mina07.alturaPassaporte = 175;
    strcpy(mina07.sexo, "F");
   // mina00.vencimento.dia = '07';
   // mina00.vencimento.mes = '01';
   // mina00.vencimento.ano = '83';
    mina07.Foto = SpriteF7;
    mina07.FotoPassaporte = PassaportF7;
    mina07.RaioXSprite = LoadTexture("Textures/BodyM1.png");
    mina07.ID = 15;
    mina07.bombado = false;


//--------------------------------------------------------------------------
   


    

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
    case 13:
        PessoaAtual = mina04;
        break;
    case 14:
        PessoaAtual = mina05;
        break;
    case 15:
        PessoaAtual = mina06;
        break;
    case 16:
        PessoaAtual = mina07;
        break;
    }


    PessoaSprite = PessoaAtual.Foto.Foto;
    PassaporteSprite = PessoaAtual.FotoPassaporte.Foto;
    PessoaRaioX = PessoaAtual.RaioXSprite;

}

bool AlturaCheck()
{

    bool saida = false;

    if (PessoaAtual.altura == PessoaAtual.alturaPassaporte)
    {

        saida = true;

    }

    return saida;

}

bool PesoCheck()
{

    bool saida = false;

    if (PessoaAtual.peso == PessoaAtual.pesoPassaporte)
    {

        saida = true;

    }

    return saida;

}

bool ImagemCheck()
{

    bool saida = false;

    if (PessoaAtual.Foto.FotoID == PessoaAtual.FotoPassaporte.FotoID)
    {

        saida = true;

    }

    return saida;

}


bool PessoaBombada()
{

    bool saida = false;

    if (PessoaAtual.bombado == true)
    {

        saida = true;

    }

    return saida;

}



bool PessoaValida(void)
{

    bool saida = false;

    if( ImagemCheck() == true && PessoaBombada() == false && AlturaCheck() == true)
    {

        saida = true;

    }

    return saida;

}




