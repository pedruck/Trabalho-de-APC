
#include "include/raylib.h"
#include "include/lbasic.h"

//#define PLATFORM_WEB

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


const int screenWidth = 1680;
const int screenHeight = 720;



Vetor2D LocalizacaoMouse;

Texture2D bg1;
Texture2D division;
Texture2D bg1bar;
Texture2D passaporteText;
Texture2D CrosshairText;

Vector2 NomeLocation;

Retangulo Crosshair;
Retangulo passaporte;

Font font;

bool AvalicaoFoiFeita;



void UpdateFrames(void)
{

     if(AvalicaoFoiFeita == false)
    {

        passaporteText = LoadTexture("Textures/passport-blank.png");
        
    }

}





//----------------------------------------------------------------------------------
// Module functions declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void);     // Update and Draw one frame

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int WinMain(void)
{
    
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    bg1 = LoadTexture("Textures/p-p-bg1_scaled.png");
    division = LoadTexture("Textures/p-p-division_scaled.png");
    bg1bar = LoadTexture("Textures/p-p-bar1_scaled.png");
    font = LoadFont("Textures/BMmini.TTF");
   
    UpdateFrames();

    AvalicaoFoiFeita = false;

    passaporte.x = 900;
    passaporte.y = 350;
    passaporte.largura = passaporteText.width;
    passaporte.altura = passaporteText.height;
    

    

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

    LocalizacaoMouse.x = GetMouseX();
    LocalizacaoMouse.y = GetMouseY();

    NomeLocation.x = passaporte.x + 30;
    NomeLocation.y = passaporte.y + 340;



    

    // comeco da logica do passaporte

    if (ChecagemColisaoPontoRetangulo(LocalizacaoMouse, passaporte) == true && MouseDown(0) == true && LocalizacaoMouse.x > 850 && (LocalizacaoMouse.y < screenHeight && LocalizacaoMouse.y > 0) && LocalizacaoMouse.x < screenWidth)
    {
        
        passaporte.x = LocalizacaoMouse.x - passaporte.largura/2;
        passaporte.y = LocalizacaoMouse.y - passaporte.altura/2;

    }

    // fim da logica do passaporte


    
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(BLACK);

        Crosshair.x = LocalizacaoMouse.x+CrosshairText.width/2;
        Crosshair.y = LocalizacaoMouse.y+CrosshairText.height/2;
        CrosshairText = LoadTexture("Textures/Cursor.png");
        DrawTexture(bg1, 0, 0, WHITE);
        DrawTexture(bg1bar, 0, 0, WHITE);
        DrawTexture(division, 0, 0, WHITE);
        DrawTexture(passaporteText, passaporte.x, passaporte.y, WHITE);
        DrawTexture(CrosshairText, Crosshair.x, Crosshair.y, WHITE);
        DrawText("Nome do cara", passaporte.x + 30, passaporte.y + 340 , 20, BLACK);


        
        
        DrawText("DATA:", 0, 0, 20, LIGHTGRAY);
      //  DrawText(" DATA:", 0, 0, 20, LIGHTGRAY);
        

    EndDrawing();
    //----------------------------------------------------------------------------------
}


