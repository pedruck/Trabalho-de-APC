
#include "include/raylib.h"
#include "include/lbasic.h"
#include "include/pessoas.h"
#include "include/dialogo.h"
#include "stdlib.h"


#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


const int screenWidth = 1680;
const int screenHeight = 720; 

int Count;
int framesCounter;

char * estadoemprego;
int pontuacao;


bool passaporteAberto;
bool drag;

bool raioxIconeAberto;
bool ScanFeito;


Vetor2D LocalizacaoMouse;
Texture2D IconePassaporte;
Texture2D IconeRaioX;
Texture2D raioxtext;
Texture2D bg1;
Texture2D division;
Texture2D bg1bar;
Texture2D passaporteText;
Texture2D CrosshairText;
Texture2D passaporteIcone;
Texture2D raioxIcone;
char * peso;
char * pesoPassaporte;

int comissao;


    

Vector2 NomeLocation;

Vetor2D Crosshair;

Vector2 PessoaPosition;

Retangulo passaporte;
Retangulo passaporteIconeRec;

Retangulo raiox;
Retangulo raioxIconeRec;
Font font;

Retangulo deter;
Retangulo aprovar;
Retangulo rejeitar;
Retangulo scan;

bool AvalicaoFoiFeita;





void UpdateFrames(void)
{

    if(AvalicaoFoiFeita == false)
    {

        passaporteText = LoadTexture("Textures/passport-blank.png");
        raioxtext = LoadTexture("Textures/BodyM1.png");
    }


   

}






void UpdateDrawFrame(void);     // Update 


int WinMain(void)
{
    Count = 0;

    pontuacao = 110;
    
    // Inicializacao
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    
    

    bg1 = LoadTexture("Textures/p-p-bg1_scaled.png");
    division = LoadTexture("Textures/p-p-division_scaled.png");
    bg1bar = LoadTexture("Textures/p-p-bar1_scaled.png");
    font = LoadFont("Textures/BMmini.TTF");
    CrosshairText = LoadTexture("Textures/Cursor.png");
    passaporteIcone = LoadTexture("Textures/passaporteicone0.png");
    passaporteAberto = false;
    drag = false;
    raioxIcone = LoadTexture("Textures/raioxicone0.png");
    raioxIconeAberto = false;
    drag = false;


    framesCounter = 0;
    
    

    //DisableCursor();
   
    UpdateFrames();

    AvalicaoFoiFeita = false;

    passaporte.x = 900;
    passaporte.y = 350;

    PessoaPosition.x = -50;
    PessoaPosition.y = 38;

    passaporte.largura = passaporteText.width;
    passaporte.altura = passaporteText.height;


    passaporteIconeRec.x = 660;
    passaporteIconeRec.y = 40;
    passaporteIconeRec.largura = passaporteIcone.width;
    passaporteIconeRec.altura = passaporteIcone.height;
    
    raiox.x= 800;
    raiox.y = 350;

    raiox.largura = raioxtext.width;
    raiox.altura = raioxtext.height;
    
    raioxIconeRec.x = 660;
    raioxIconeRec.y = 220;
    raioxIconeRec.largura = raioxIcone.width;
    raioxIconeRec.altura = raioxIcone.height;

    deter.x = 200;
    deter.y = 652;
    deter.altura = 50;
    deter.largura = 224;

    aprovar.x = 20;
    aprovar.y = 652;
    aprovar.altura = 48;
    aprovar.largura = 146;

    rejeitar.x = 458;
    rejeitar.y = 652;
    rejeitar.altura = 48;
    rejeitar.largura = 146;

    scan.x = 0;
    scan.y = 560;
    scan.altura = 50;
    scan.largura = 50;


    
    
    LoadPessoas(Count);
    LoadDialogo(Count);
    

    

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

#endif

// Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    { 
        if (IsKeyPressed(KEY_F11))
            ToggleFullscreen();
        
        UpdateDrawFrame();

        framesCounter++;

         if (pontuacao > 100)
    {

        estadoemprego = "Estável";

    }
    else if (pontuacao < 100 && pontuacao > 60)
    {

        estadoemprego = "Médio";    

    }
    else if (pontuacao < 60 && pontuacao > 30)
    {

        estadoemprego = "Preucupante";    

    }
    else if (pontuacao < 30 && pontuacao > 15)
    {

        estadoemprego = "Crítico";    

    }
    else if (pontuacao < 15)
    {

        estadoemprego = "Demitido";

    }


    

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void)
{
    
    // Update
    //----------------------------------------------------------------------------------
    
    if (GetMouseX() < screenWidth-1 && GetMouseY() < screenHeight-1)
        {
            LocalizacaoMouse.x = GetMouseX();
            LocalizacaoMouse.y = GetMouseY();
        }


    NomeLocation.x = passaporte.x + 30;
    NomeLocation.y = passaporte.y + 340;

    


    

    // comeco da logica do passaporte

    
    

        if (ChecagemColisaoPontoRetangulo(LocalizacaoMouse, passaporteIconeRec) == true && IsMouseButtonPressed(1) == true && passaporteAberto == false)
        {
            
        passaporteAberto = true;



        }

        else if (ChecagemColisaoPontoRetangulo(LocalizacaoMouse, passaporteIconeRec) == true && IsMouseButtonPressed(1) == true && passaporteAberto == true)
        {
            
        passaporteAberto = false;



        }

        if (MouseDown(0) == true)
        {

            drag = true;

        }
        else if (MouseDown(0) == false)
        {

            drag = false;

        }

        if (passaporteAberto == true && drag == true)
        {
            
            passaporte.x = LocalizacaoMouse.x - passaporte.largura/2;
            
            passaporte.y = LocalizacaoMouse.y - passaporte.altura/2;

           

        }

        if(IsMouseButtonPressed(1) == true && passaporteAberto == true && ChecagemColisaoPontoRetangulo(LocalizacaoMouse, passaporteIconeRec) == false)
        {

        passaporteAberto = false;


        }

        if (passaporteAberto == false)
        {

            passaporte.x = -1000;
            
            passaporte.y = -1000;
            
        }

    

    if(IsMouseButtonPressed(1))
    {

            if (passaporteAberto == true)
            {

                passaporteIcone = LoadTexture("Textures/passaporteicone1.png");

                 passaporte.x = 900;
            
                 passaporte.y = 100;



            }

            else if (passaporteAberto == false)
            {

            passaporteIcone = LoadTexture("Textures/passaporteicone0.png");

        

            }
            

    }    

    // fim da logica do passaporte

//------------------------- ---------------------------------------------------------------//
    
    //comeco da logica raiox
   
    if (ChecagemColisaoPontoRetangulo(LocalizacaoMouse, raioxIconeRec) == true && IsMouseButtonPressed(1) == true && raioxIconeAberto == false)
        {
            
        raioxIconeAberto = true;



        }

        else if (ChecagemColisaoPontoRetangulo(LocalizacaoMouse, raioxIconeRec) == true && IsMouseButtonPressed(1) == true && raioxIconeAberto == true)
        {
            
        raioxIconeAberto = false;



        }

        if (MouseDown(0) == true)
        {

            drag = true;

        }
        else if (MouseDown(0) == false)
        {

            drag = false;

        }

        if (raioxIconeAberto == true && drag == true)
        {
            
            raiox.x = LocalizacaoMouse.x - raiox.largura/2;
            
            raiox.y = LocalizacaoMouse.y - raiox.altura/2;

           

        }

        if(IsMouseButtonPressed(1) == true && raioxIconeAberto == true && ChecagemColisaoPontoRetangulo(LocalizacaoMouse, raioxIconeRec) == false)
        {

        raioxIconeAberto = false;


        }

        if (raioxIconeAberto == false)
        {

            raiox.x = -1000;
            
            raiox.y = -1000;
            
        }

    

    if(IsMouseButtonPressed(1))
    {

            if (raioxIconeAberto == true)
            {

                raioxIcone = LoadTexture("Textures/raioxicone1.png");

                 raiox.x = 900;
            
                 raiox.y = 100;



            }

            else if (raioxIconeAberto == false)
            {

            raioxIcone = LoadTexture("Textures/raioxicone0.png");

        

            }

    //fim do raiox

    }
    //------------------------- CODIGO TEMPORARIO (DEBUG) -----------------------------

    if(IsKeyPressed(KEY_C))
        {
            framesCounter = 0;
            Count++;
            LoadPessoas(Count);
            LoadDialogo(Count);

            passaporteAberto = false;
            raioxIconeAberto = false;
            
            passaporteIcone = LoadTexture("Textures/passaporteicone0.png");
            raioxIcone = LoadTexture("Textures/raioxicone0.png");;


        }

    //----------------------------------------------------------------------------------



    //----------------------------------------------------------------------------------


    




    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(BLACK);

        
  
        DrawTexture(bg1, 0, 0, WHITE);
        DrawTextoSimples(TextFormat("%4.f kg", PessoaAtual.peso), 500, 230, 21, BLACK);
        DrawTextureEx(PessoaSprite, PessoaPosition, 0.0, 1.18, WHITE);
 
        DrawTexture(bg1bar, 0, 0, WHITE);
        DrawTexture(division, 0, 0, WHITE);
        DrawTextureEx(raioxIcone, (Vector2) {raioxIconeRec.x , raioxIconeRec.y}, 0.0, 0.7, WHITE);
        DrawTextureEx(passaporteIcone, (Vector2){660, 40}, 0.0, 0.7, WHITE);
        
        DrawTexture(passaporteText, passaporte.x, passaporte.y, WHITE);

       // DrawTexture(CrosshairText, LocalizacaoMouse.x - CrosshairText.width/2, LocalizacaoMouse.y - CrosshairText.height/2, WHITE);
       
        DrawText(TextFormat("%4.f cm", PessoaAtual.altura), passaporte.x + 50, passaporte.y + 350, 20, BLACK);
        //DrawText(TextFormat("%dkg", PessoaAtual.peso), passaporte.x, passaporte.y, 20, BLACK);
        DrawTextoSimples(PessoaAtual.sexo, passaporte.x + 30, passaporte.y + 330, 20, BLACK);
        DrawTextoSimples(PessoaAtual.nome, passaporte.x + 30, passaporte.y + 340 , 20, BLACK);
        
        DrawTextureEx(PassaporteSprite, (Vector2) {passaporte.x +16, passaporte.y + 416}, 0.0, 0.28, WHITE);
        DrawTextureEx(PessoaRaioX, (Vector2) {raiox.x, raiox.y}, 0.0, 1.7, WHITE);    
        //DrawRectangle(passaporteIconeRec.x, passaporteIconeRec.y, passaporteIconeRec.largura,passaporteIconeRec.altura ,RED);


        DrawRectangle(aprovar.x, aprovar.y, aprovar.largura, aprovar.altura, RED);
        DrawRectangle(deter.x, deter.y, deter.largura, deter.altura, RED);
        DrawRectangle(rejeitar.x, rejeitar.y, rejeitar.largura, rejeitar.altura, RED);
        DrawRectangle(scan.x, scan.y, scan.altura, scan.largura, RED);


        DrawTextoSimples(TextSubtext(MensagemInicial, 0, framesCounter/1.2), 50, 550, 21, WHITE);
        DrawTextoSimples("DATA: 21/02/1982", 0, 0, 20, WHITE ); 
        //DrawText("DATA: ", 0, 0, 20, LIGHTGRAY);
        
        DrawTextoSimples("Estado do emprego:", 0, 40, 20, WHITE );    //pedro druck mama rola
        DrawTextoSimples(estadoemprego, 200, 40, 20, WHITE);
      
    EndDrawing();
    //----------------------------------------------------------------------------------


    
}


