
#include "include/raylib.h"
#include "include/lbasic.h"
#include "include/pessoas.h"
#include "include/dialogo.h"


#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


const int screenWidth = 1680;
const int screenHeight = 720; 

int Count;
int framesCounter;
bool passaporteAberto;
bool drag;


Vetor2D LocalizacaoMouse;
Texture2D IconePassaporte;
Texture2D IconeRaioX;

Texture2D bg1;
Texture2D division;
Texture2D bg1bar;
Texture2D passaporteText;
Texture2D CrosshairText;
Texture2D passaporteIcone;




    

Vector2 NomeLocation;

Vetor2D Crosshair;

Vector2 PessoaPosition;

Retangulo passaporte;
Retangulo passaporteIconeRec;

Font font;

bool AvalicaoFoiFeita;



void UpdateFrames(void)
{

    if(AvalicaoFoiFeita == false)
    {

        passaporteText = LoadTexture("Textures/passport-blank.png");
        
    }

    

}






void UpdateDrawFrame(void);     // Update 


int WinMain(void)
{
    Count = 0;
    
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

    
    //------------------------- CODIGO TEMPORARIO (DEBUG) -----------------------------

    if(IsMouseButtonPressed(0))
        {
            framesCounter = 0;
            Count++;
            LoadPessoas(Count);
            LoadDialogo(Count);


        }

    //---------------------------------------------------------------------------------



    //----------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(BLACK);
  
        DrawTexture(bg1, 0, 0, WHITE);
        DrawTextoSimples("peso aq", 500, 230, 21, BLACK);
        DrawTextureEx(PessoaSprite, PessoaPosition, 0.0, 1.18, WHITE);
 
        DrawTexture(bg1bar, 0, 0, WHITE);
        DrawTexture(division, 0, 0, WHITE);

        DrawTextureEx(passaporteIcone, (Vector2){660, 40}, 0.0, 0.7, WHITE);
        
        DrawTexture(passaporteText, passaporte.x, passaporte.y, WHITE);

       // DrawTexture(CrosshairText, LocalizacaoMouse.x - CrosshairText.width/2, LocalizacaoMouse.y - CrosshairText.height/2, WHITE);
       
        DrawText(PessoaAtual.nome, passaporte.x + 30, passaporte.y + 340 , 20, BLACK);
        DrawTextureEx(PassaporteSprite, (Vector2) {passaporte.x +16, passaporte.y + 416}, 0.0, 0.28, WHITE);
        DrawTextureEx(PessoaRaioX, (Vector2) {screenWidth/2, screenHeight/2}, 0.0, 1, WHITE);

        //DrawRectangle(passaporteIconeRec.x, passaporteIconeRec.y, passaporteIconeRec.largura,passaporteIconeRec.altura ,RED);

        DrawTextoSimples(TextSubtext(MensagemInicial, 0, framesCounter/1.2), 50, 550, 21, WHITE);

        DrawText("DATA:", 0, 0, 20, LIGHTGRAY);
      
    EndDrawing();
    //----------------------------------------------------------------------------------
}


