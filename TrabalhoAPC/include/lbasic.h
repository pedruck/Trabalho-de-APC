#include "raylib.h"


typedef struct Vetor2D {
    float x;                
    float y;                
} Vetor2D;

typedef struct Retangulo{
    float x;                // x e y sao as posições do ponto superior esquerdo do retangulo
    float y;                
    float largura;            
    float altura;           
} Retangulo;

bool ChecagemColisaoPontoRetangulo(Vetor2D point, Retangulo rec)
{
    bool colisao = false;

    if ((point.x >= rec.x) && (point.x < (rec.x + rec.largura)) && (point.y >= rec.y) && (point.y < (rec.y + rec.altura)))
    {
        colisao = true;
    } 

    return colisao;

    //checa se um ponto especifico esta dentro do retangulo em questao no momento da execução
}

bool MouseDown(int input)
{
    bool isDown = false;
    if (IsMouseButtonDown(input) == true) isDown = true;

    return isDown;

    //checa se o botao do mouse em questao esta sendo pressionado no momento da execução

}