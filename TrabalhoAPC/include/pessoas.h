#include <raylib.h>






struct vencimento
{
    int dia;
    int mes;
    int ano;
}Vencimento;





struct pessoa
{
    char nome[20];

    int ID;

    struct Vencimento;

    Texture2D Foto;

};



void LoadPessoas(void)
{



}