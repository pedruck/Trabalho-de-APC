
#include <stdio.h>
#include <string.h>
#include "raylib.h"



Texture2D PessoaSprite;
Texture2D PassaporteSprite;
Texture2D PessoaRaioX;


struct Vencimento
{
    int dia;
    int mes;
    int ano;
};

struct Vencimento vencimento;

int IDData;

struct FotoPessoa
{

    Texture2D Foto;


    int FotoID;
    int altura;
    bool Procurado;
    

    

};

int Random;
char Sexo;
int Peso;
int PesoPassaporte;
int alturaPassaporte;
int P, S;
bool alturaErrada;
int dia;
int mes;
int ano;


char Nome[20];

bool PessoaErrada;
bool Vencido;
bool Bombastico;
bool Procurado;


struct FotoPessoa Procurado1;
struct FotoPessoa Procurado1Passaporte;
struct FotoPessoa Procurado2;
struct FotoPessoa Procurado2Passaporte;



//AQUI TIAGO PORRAAAAAAAA
void LoadProcurados()
{

struct FotoPessoa ProcuradoSpriteM0;

    ProcuradoSpriteM0.Foto = LoadTexture("Textures/suspeitoM0.png");
    ProcuradoSpriteM0.altura = 168 + GetRandomValue(-1, 1);
    
struct FotoPessoa ProcuradoPassaportM0;

    ProcuradoPassaportM0.Foto = LoadTexture("Textures/SuspeitoF0.png");
    ProcuradoPassaportM0.altura = 168 + GetRandomValue(-1, 1);

struct FotoPessoa ProcuradoSpriteM1;

    ProcuradoSpriteM1.Foto = LoadTexture("Textures/suspeitoM1.png");
    ProcuradoSpriteM1.altura = 162 + GetRandomValue(-1, 1);
    
struct FotoPessoa ProcuradoPassaportM1;

    ProcuradoPassaportM1.Foto = LoadTexture("Textures/SuspeitoF1.png");
    ProcuradoPassaportM1.altura = 162 + GetRandomValue(-1, 1);

struct FotoPessoa ProcuradoSpriteM2;

    ProcuradoSpriteM2.Foto = LoadTexture("Textures/suspeitoM2.png");
    ProcuradoSpriteM2.altura = 166 + GetRandomValue(-1, 1);
    
struct FotoPessoa ProcuradoPassaportM2;

    ProcuradoPassaportM2.Foto = LoadTexture("Textures/SuspeitoF2.png");
    ProcuradoPassaportM2.altura = 166 + GetRandomValue(-1, 1);

struct FotoPessoa ProcuradoSpriteM3;

    ProcuradoSpriteM3.Foto = LoadTexture("Textures/suspeitoM3.png");
    ProcuradoSpriteM3.altura = 165 + GetRandomValue(-1, 1);
    
struct FotoPessoa ProcuradoPassaportM3;

    ProcuradoPassaportM3.Foto = LoadTexture("Textures/SuspeitoF3.png");
    ProcuradoPassaportM3.altura = 165 + GetRandomValue(-1, 1);

struct FotoPessoa ProcuradosHomem[] = {ProcuradoSpriteM0, ProcuradoSpriteM1, ProcuradoSpriteM2, ProcuradoSpriteM3};
struct FotoPessoa ProcuradosHomemPassaporte[] = {ProcuradoPassaportM0, ProcuradoPassaportM1, ProcuradoPassaportM2, ProcuradoPassaportM3};

int random = GetRandomValue(0,1);
int random2 = GetRandomValue(2,3);

Procurado1 = ProcuradosHomem[random];
Procurado1Passaporte = ProcuradosHomemPassaporte[random];

Procurado2 = ProcuradosHomem[random2];
Procurado2Passaporte = ProcuradosHomemPassaporte[random2];

printf("RANDOM1: %d\n", random);
printf("RANDOM2: %d\n", random2);
}


void LoadInfoRandom()
{

    

char * PrimeiroNome;
char * SegundoNome;

char PrimeirosNomesMasculinos[11][10] = {"Erick", "Pedro","Mateus", "Felipe", "Fernando", "Mario", "Rafael", "Lucas", "Hugo", "Cezar", "Caio"};
char SegundosNomesMasculinos[10][12] = {" Xavier", " Pereira"," Diniz", " Bittencourt", " Druck", " Reis", " Moura", " Oliveira", " Sampaio", " Lemez"};

char PrimeirosNomesFemininos[10][10] = {"Emanuely", "Sara", "Angela", "Rose", "Evelyn", "Sophia", "Beatriz", "Isabela", "Maria", "Giovanna"};
char SegundosNomesFemininos[10][12] = {" Silva", " Alves", " Santos", " Shimizu", " Abade", " Antunes", " Morgental", " Saboia", " Eduarda", " Mendes"};

    Random = GetRandomValue(0, 100);

    if (Random >= 50)
    {
    
    Sexo = 'M';
    
    }
    else if (Random < 50)
    {

    Sexo = 'F';

    }

    if(Sexo == 'F')
    {

    P = GetRandomValue(0, 9);
    PrimeiroNome = PrimeirosNomesFemininos[P];

    S = GetRandomValue(0, 9);
    SegundoNome = SegundosNomesFemininos[S];

    }

    else if (Sexo == 'M')
    {

    P = GetRandomValue(0, 9);
    PrimeiroNome = PrimeirosNomesMasculinos[P];

    S = GetRandomValue(0, 9);
    SegundoNome = SegundosNomesMasculinos[S];

    }

    strcpy(Nome, strncat(PrimeiroNome, SegundoNome, 12));

  
    int NumeroRandom;
    int NumeroRandom2;
    int NumeroRandom3;
    int NumeroRandom4;
    int NumeroRandom5;

    Procurado = false;
    bool PesoErrado = false;
    Bombastico = false;
    Vencido = false;


    alturaErrada = false;      

    NumeroRandom = GetRandomValue(0, 10);
    NumeroRandom2 = GetRandomValue(0, 10);
    NumeroRandom3 = GetRandomValue(0, 10);
    NumeroRandom4 = GetRandomValue(0, 10);
    NumeroRandom5 = GetRandomValue(0, 10);


    if (NumeroRandom5 >= 0 && Sexo == 'M'){
        
        Procurado = true;
        
    }

    if (NumeroRandom3 >= 9 && Procurado == false){
        
        alturaErrada = true;
        
    }

    if (NumeroRandom >= 8 && Procurado == false)
    {

        PesoErrado = true;

    }


    Peso = GetRandomValue(58, 78);


    if(PesoErrado == false ){

        PesoPassaporte = Peso;

    }
    else if (PesoErrado == true)
    {

        PesoPassaporte = Peso - GetRandomValue(4, 10);

        if (NumeroRandom2 >= 5)
        {

            Bombastico = true;

        }
    }
    
    if (NumeroRandom4 >= 9 && Procurado == false)
    {
        Vencido = true;
        vencimento.dia = 27 - GetRandomValue(1, 26);
        vencimento.mes = 11 - GetRandomValue(1, 10);
        vencimento.ano = 1982;
    }
    if (Vencido == false)
    {
        vencimento.dia = GetRandomValue(1, 30);
        vencimento.mes = GetRandomValue(1, 12);
        vencimento.ano = 1982 + GetRandomValue(1, 3);
    }
    
    


    




}



struct pessoas
{
    char nome [20];

    float peso;

    float pesoPassaporte;

    int altura;

    int alturaPassaporte;

    char sexo;

    int ID;

    struct Vencimento vencimento;

    struct FotoPessoa Foto;

    struct FotoPessoa FotoPassaporte;

    
    Texture2D Raioxsprite;
    

};

struct pessoas PessoaAtual;

struct FotoPessoa Procurado1;
struct FotoPessoa Procurado1Passaporte;
struct FotoPessoa Procurado2;
struct FotoPessoa Procurado2Passaporte;


int RandomProcurado;











void LoadPessoas(int PessoaCount)
{
    LoadInfoRandom();

    struct FotoPessoa SpriteM0;
    SpriteM0.Foto = LoadTexture("Textures/cara00.png");
    SpriteM0.FotoID = 0;
    SpriteM0.altura = 171 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportM0;
    PassaportM0.Foto = LoadTexture("Textures/ftidcara00.png");
    PassaportM0.FotoID = 0;
    //SpriteM0.altura = 158 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteM1;
    SpriteM1.Foto = LoadTexture("Textures/cara01.png");
    SpriteM1.FotoID = 1;
    SpriteM0.altura = 159 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportM1;
    PassaportM1.Foto = LoadTexture("Textures/ftidcara01.png");
    PassaportM1.FotoID = 1;
    //SpriteM1.altura = 159  + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteM2;
    SpriteM2.Foto = LoadTexture("Textures/cara02.png");
    SpriteM2.FotoID = 2;
    SpriteM2.altura = 168 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportM2;
    PassaportM2.Foto = LoadTexture("Textures/ftidcara02.png");
    PassaportM2.FotoID = 2;
   // SpriteM2.altura = 168 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteM3;
    SpriteM3.Foto = LoadTexture("Textures/cara03.png");
    SpriteM3.FotoID = 3;
    SpriteM3.altura = 167 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportM3;
    PassaportM3.Foto = LoadTexture("Textures/ftidcara03.png");
    PassaportM3.FotoID = 3;
   // SpriteM3.altura = 167 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteM4;
    SpriteM4.Foto = LoadTexture("Textures/cara04.png");
    SpriteM4.FotoID = 4;
    SpriteM4.altura = 165 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportM4;
    PassaportM4.Foto = LoadTexture("Textures/ftidcara04.png");
    PassaportM4.FotoID = 4;
   // SpriteM4.altura = 165 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteM5;
    SpriteM5.Foto = LoadTexture("Textures/cara05.png");
    SpriteM5.FotoID = 5;
    SpriteM5.altura = 164 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportM5;
    PassaportM5.Foto = LoadTexture("Textures/ftidcara05.png");
    PassaportM5.FotoID = 5;
  //  SpriteM5.altura = 164 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteM6;
    SpriteM6.Foto = LoadTexture("Textures/cara06.png");
    SpriteM6.FotoID = 6;
    SpriteM6.altura = 169 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportM6;
    PassaportM6.Foto = LoadTexture("Textures/ftidcara06.png");
    PassaportM6.FotoID = 6;
  //  SpriteM6.altura = 169 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteM7;
    SpriteM7.Foto = LoadTexture("Textures/cara07.png");
    SpriteM7.FotoID = 7;
    SpriteM7.altura = 170 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportM7;
    PassaportM7.Foto = LoadTexture("Textures/ftidcara07.png");
    PassaportM7.FotoID = 7;
   // SpriteM7.altura = 170 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteF0;
    SpriteF0.Foto = LoadTexture("Textures/mina00.png");
    SpriteF0.FotoID = 8;
    SpriteF0.altura = 166 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportF0;
    PassaportF0.Foto = LoadTexture("Textures/ftidmina00.png");
    PassaportF0.FotoID = 8;
 //   SpriteF0.altura = 166 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteF1;
    SpriteF1.Foto = LoadTexture("Textures/mina01.png");
    SpriteF1.FotoID = 9;
    SpriteF1.altura = 157 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportF1;
    PassaportF1.Foto = LoadTexture("Textures/ftidmina01.png");
    PassaportF1.FotoID = 9;
   // SpriteF1.altura = 157 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteF2;
    SpriteF2.Foto = LoadTexture("Textures/mina02.png");
    SpriteF2.FotoID = 10;
    SpriteF2.altura = 168 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportF2;
    PassaportF2.Foto = LoadTexture("Textures/ftidmina02.png");
    PassaportF2.FotoID = 10;
  //  SpriteF2.altura = 168 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteF3;
    SpriteF3.Foto = LoadTexture("Textures/mina03.png");
    SpriteF3.FotoID = 11;
    SpriteF3.altura = 163 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportF3;
    PassaportF3.Foto = LoadTexture("Textures/ftidmina03.png");
    PassaportF3.FotoID = 11;
   // SpriteF3.altura = 163 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteF4;
    SpriteF4.Foto = LoadTexture("Textures/mina04.png");
    SpriteF4.FotoID = 12;
    SpriteF4.altura = 164 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportF4;
    PassaportF4.Foto = LoadTexture("Textures/ftidmina04.png");
    PassaportF4.FotoID = 12;
 //   SpriteF4.altura = 164 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteF5;
    SpriteF5.Foto = LoadTexture("Textures/mina05.png");
    SpriteF5.FotoID = 13;
    SpriteF5.altura = 165 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportF5;
    PassaportF5.Foto = LoadTexture("Textures/ftidmina05.png");
    PassaportF5.FotoID = 13;
  //  SpriteF5.altura = 165 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteF6;
    SpriteF6.Foto = LoadTexture("Textures/mina06.png");
    SpriteF6.FotoID = 14;
    SpriteF6.altura = 163 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportF6;
    PassaportF6.Foto = LoadTexture("Textures/ftidmina06.png");
    PassaportF6.FotoID = 14;
  //  SpriteF6.altura = 163 + GetRandomValue(-1, 1);

    struct FotoPessoa SpriteF7;
    SpriteF7.Foto = LoadTexture("Textures/mina07.png");
    SpriteF7.FotoID = 15;
    SpriteF7.altura = 168 + GetRandomValue(-1, 1);

    struct FotoPessoa PassaportF7;
    PassaportF7.Foto = LoadTexture("Textures/ftidmina07.png");
    PassaportF7.FotoID = 15;
  //  SpriteF7.altura = 168 + GetRandomValue(-1, 1);


   
    
    















//-----------------INCIALIZAÇÃO DAS STRUCTS POR MEIO DE UMA ARRAY--------------------------------------------------------------------------



struct FotoPessoa HomemSprite[] = {SpriteM0, SpriteM1, SpriteM2, SpriteM3, SpriteM4, SpriteM5, SpriteM6, SpriteM7};

struct FotoPessoa PassaporteHomem[] = {PassaportM0, PassaportM1, PassaportM2, PassaportM3, PassaportM4, PassaportM5, PassaportM6, PassaportM7};

struct FotoPessoa MulherSprite[] = {SpriteF0, SpriteF1, SpriteF2, SpriteF3, SpriteF4, SpriteF5, SpriteF6, SpriteF7};

struct FotoPessoa PassaporteMulher[] = {PassaportF0, PassaportF1, PassaportF2, PassaportF3, PassaportF4, PassaportF5, PassaportF6, PassaportF7};

//-----------------------------------------------------------------------------------------------------------------------------------------

    strcpy(PessoaAtual.nome, Nome);






    int Sorteio = GetRandomValue(0, 7);

    if (Sorteio < 2) PessoaErrada = true;
    else PessoaErrada = false;

    struct FotoPessoa PessoaAgrSprite;
    struct FotoPessoa PessoaAgrPassaporte;



    if (Sexo == 'M' && PessoaErrada == false && Procurado == false)
    {

        PessoaAgrSprite = HomemSprite[Sorteio];
        PessoaAgrPassaporte = PassaporteHomem[Sorteio];

    }
    else if (Sexo == 'M' && PessoaErrada == true && Procurado == false)
    {

        PessoaAgrSprite = HomemSprite[Sorteio];
        PessoaAgrPassaporte = PassaporteHomem[Sorteio + GetRandomValue(1, 3)];

    }

    if (Sexo == 'F' && PessoaErrada == false && Procurado == false)
    {

        PessoaAgrSprite = MulherSprite[Sorteio];
        PessoaAgrPassaporte = PassaporteMulher[Sorteio];

    }
    else if (Sexo == 'F' && PessoaErrada == true && Procurado == false)
    {

        PessoaAgrSprite = MulherSprite[Sorteio];
        PessoaAgrPassaporte = PassaporteMulher[Sorteio + GetRandomValue(1, 3)];

    }

    RandomProcurado = GetRandomValue(0,1);

    if (Procurado == true && RandomProcurado == 0)
    {

        PessoaAgrSprite = Procurado1;
        PessoaAgrPassaporte = Procurado1Passaporte;

    }
    else if (Procurado == true && RandomProcurado == 1)
    {

        PessoaAgrSprite = Procurado2;
        PessoaAgrPassaporte = Procurado2Passaporte;

    }

    

int RandomAltura = GetRandomValue(0, 10);






    strcpy(PessoaAtual.nome, Nome);
    PessoaAtual.peso = Peso;
    PessoaAtual.pesoPassaporte = PesoPassaporte;
    PessoaAtual.altura = PessoaAgrSprite.altura;

    
    if (alturaErrada == true && RandomAltura > 5) PessoaAtual.alturaPassaporte = PessoaAtual.altura - GetRandomValue(10, 15);
    else if (alturaErrada == true && RandomAltura < 5) PessoaAtual.alturaPassaporte = PessoaAtual.altura + GetRandomValue(10, 15);
    else if (alturaErrada == false) PessoaAtual.alturaPassaporte = PessoaAtual.altura;


    PessoaAtual.sexo = Sexo;

    PessoaAtual.Foto = PessoaAgrSprite;

    PessoaAtual.FotoPassaporte = PessoaAgrPassaporte;

    if (Bombastico == false) PessoaAtual.Raioxsprite = LoadTexture("Textures/BodyM1.png");

    else if (Bombastico == true) PessoaAtual.Raioxsprite = LoadTexture("Textures/BodyM1(COMBOMBA).png");


    PessoaSprite = PessoaAtual.Foto.Foto;
    PassaporteSprite = PessoaAtual.FotoPassaporte.Foto;
    PessoaRaioX = PessoaAtual.Raioxsprite;

}

bool AlturaCheck()
{

    bool saida = false;

    int diferenca = PessoaAtual.altura - PessoaAtual.alturaPassaporte;

    if (diferenca > -2 && diferenca < 2)
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

bool VencimentoCheck()
{
    bool saida = false;

    if (Vencido == false)
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

    if (Bombastico == true)
    {

        saida = true;

    }

    return saida;

}


bool PessoaValida(void)
{

    bool saida = false;

    if(ImagemCheck() == true && PessoaBombada() == false && AlturaCheck() == true && VencimentoCheck() == true && Procurado == false)
    {

        saida = true;

    }

    return saida;

}




