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

void DrawTextoPro(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint)
{
    if (font.texture.id == 0) font = GetFontDefault();  // Security check in case of not valid font

    int size = TextLength(text);    // Total size in bytes of the text, scanned by codepoints in loop

    float textOffsetY = 2;          // Offset between lines (on linebreak '\n')
    float textOffsetX = 0.0f;       // Offset X to next character to draw

    float scaleFactor = fontSize/font.baseSize;         // Character quad scaling factor

    for (int i = 0; i < size;)
    {
        // Get next codepoint from byte string and glyph index in font
        int codepointByteCount = 0;
        int codepoint = GetCodepointNext(&text[i], &codepointByteCount);
        int index = GetGlyphIndex(font, codepoint);

        if (codepoint == '\n')
        {
            // NOTE: Line spacing is a global variable, use SetTextLineSpacing() to setup
            textOffsetY += (fontSize + 2);
            textOffsetX = 0.0f;
        }
        else
        {
            if ((codepoint != ' ') && (codepoint != '\t'))
            {
                DrawTextCodepoint(font, codepoint, (Vector2){ position.x + textOffsetX, position.y + textOffsetY }, fontSize, tint);
            }

            if (font.glyphs[index].advanceX == 0) textOffsetX += ((float)font.recs[index].width*scaleFactor + spacing);
            else textOffsetX += ((float)font.glyphs[index].advanceX*scaleFactor + spacing);
        }

        i += codepointByteCount;   // Move text bytes counter to next codepoint
    }
}

void DrawTextoSimples(const char *text, int posX, int posY, int fontSize, Color color)
{
    // Check if default font has been loaded
    if (GetFontDefault().texture.id != 0)
    {
        Vector2 position = { (float)posX, (float)posY };

        int defaultFontSize = 10;   // Default Font chars height in pixel
        if (fontSize < defaultFontSize) fontSize = defaultFontSize;
        int spacing = fontSize/defaultFontSize;

        DrawTextoPro(GetFontDefault(), text, position, (float)fontSize, (float)spacing, color);
    }
}
