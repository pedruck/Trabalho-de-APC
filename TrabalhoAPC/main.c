
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
bool ScanSemNecessidade;

bool regrasIconeAberto;
bool raioxIconeAberto;
bool ScanFeito;

bool pause;

bool TransicaoPessoa;



Vetor2D LocalizacaoMouse;
Texture2D IconePassaporte;
Texture2D IconeRaioX;
Texture2D raioxtext;
Texture2D regrastext;
Texture2D bg1;
Texture2D division;
Texture2D bg1bar;
Texture2D passaporteText;
Texture2D CrosshairText;
Texture2D passaporteIcone;
Texture2D raioxIcone;
Texture2D regrasIcone;

char * peso;
char * pesoPassaporte;

int comissao;

bool ScanFeito;

int AnimFrameCounter;

int AnimFrameCounter2;

Vetor2D JanelaPosicao;
Texture2D Janela;
    

Vector2 NomeLocation;

Vetor2D Crosshair;

Vector2 PessoaPosition;

Retangulo passaporte;
Retangulo passaporteIconeRec;

Retangulo regras;
Retangulo raiox;
Retangulo regrasIconeRec;
Retangulo raioxIconeRec;
Font font;

Retangulo deter;
Retangulo aprovar;
Retangulo rejeitar;
Retangulo scan;
Sound ProximaPessoaSound;

bool AvalicaoFoiFeita;

void ProximaPessoa()
{
    
            
            framesCounter = 0;
            
            Count++;
            LoadPessoas(Count);
            LoadDialogo(Count);

            passaporteAberto = false;
            raioxIconeAberto = false;
            
            passaporteIcone = LoadTexture("Textures/passaporteicone0.png");
            raioxIcone = LoadTexture("Textures/raioxicone0.png");
            regrasIcone = LoadTexture("Textures/regrasIconeOk.png");

            ScanFeito = false;
            ScanSemNecessidade = false;
            


}





void UpdateFrames(void)
{

    if(AvalicaoFoiFeita == false)
    {

        passaporteText = LoadTexture("Textures/passport-blank.png");
        raioxtext = LoadTexture("Textures/BodyM1.png");
        //regrastext = LoadTexture("")

        

    }

}



void UpdateDrawFrame(void);     // Update 


int WinMain(void)
{
    Count = 0;
    JanelaPosicao.x = 0;
    JanelaPosicao.y = -625;

    pontuacao = 110;
    
    // Inicializacao
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    
     InitAudioDevice();

    bg1 = LoadTexture("Textures/p-p-bg1_scaled.png");
    division = LoadTexture("Textures/p-p-division_scaled.png");
    bg1bar = LoadTexture("Textures/p-p-bar1_scaled.png");
    font = LoadFont("Textures/BMmini.TTF");
    CrosshairText = LoadTexture("Textures/Cursor.png");
    passaporteIcone = LoadTexture("Textures/passaporteicone0.png");
    passaporteAberto = false;
    drag = false;
    regrasIcone = LoadTexture("Textures/regrasIcone.png");
    raioxIcone = LoadTexture("Textures/raioxicone0.png");
    regrasIconeAberto = false;
    raioxIconeAberto = false;
    drag = false;
    ScanFeito = false;
    ScanSemNecessidade = false;
    Music music = LoadMusicStream("Textures/Vento.mp3");
    ProximaPessoaSound = LoadSound("Textures/proximapessoa.mp3");
    Janela = LoadTexture("Textures/next_scaled.png");
    TransicaoPessoa = false;

PlayMusicStream(music);


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

    regras.x = 700;
    regras.y = 200;

    regras.largura = regrastext.width;
    regras.altura = regrastext.height;
    regrasIconeRec.largura = regrasIcone.width;
    regrasIconeRec.altura = regrasIcone.height;

    




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
        UpdateMusicStream(music);


        // Logica das Animações------------------------------------------------------------
        framesCounter++;
        if (AnimFrameCounter > 121) AnimFrameCounter = 0;
        else AnimFrameCounter++;

        if (AnimFrameCounter == 60) PessoaPosition.y += 5;
        else if (AnimFrameCounter == 120) PessoaPosition.y -= 5;

        if(AnimFrameCounter2 > 250 && TransicaoPessoa == true)
        {

            AnimFrameCounter2 = 0;
            TransicaoPessoa = false;

        } 
        else if (TransicaoPessoa == true)
        {
        AnimFrameCounter2++;

        }

        if (TransicaoPessoa == true && AnimFrameCounter2 < 120 && JanelaPosicao.y < -10 ) JanelaPosicao.y += 14; 

        if (AnimFrameCounter2 == 120) ProximaPessoa();

        if (TransicaoPessoa == true && AnimFrameCounter2 > 140 && JanelaPosicao.y > -625 ) JanelaPosicao.y -= 14; 

        //printf("%d\n", AnimFrameCounter2);
        
        //-----------------------------------------------------------------------------------



         if (pontuacao > 100)
    {

        estadoemprego = "Estável";

    }
    else if (pontuacao < 100 && pontuacao >= 70)
    {

        estadoemprego = "Médio";    

    }
    else if (pontuacao < 70 && pontuacao >= 40)
    {

        estadoemprego = "Preocupante";    

    }
    else if (pontuacao < 40 && pontuacao >= 15)
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
    UnloadMusicStream(music);
     CloseAudioDevice();
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

    if (ScanFeito == true)
    {

            raioxIconeRec.x = 660;
            raioxIconeRec.y = 220;

    }
    else if (ScanFeito == false)
    {

            raioxIconeRec.x = -1000;
            raioxIconeRec.y = -1000;

    }

    if (ScanFeito == true){
            regrasIconeRec.x = 550;
            regrasIconeRec.y = 330;

    }

    else if(ScanFeito == true){
            regrasIconeRec.x  = -1000;
            regrasIconeRec.y = -1000;


    }




   
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
        

        //logica das rgras 

        
        















































    //fim do raiox

    }
    //------------------------- CODIGO TEMPORARIO (DEBUG) -----------------------------

        

    //---------------------------------(CODIGO BOTOES)-------------------------------------------------

    if (ChecagemColisaoPontoRetangulo(LocalizacaoMouse, aprovar) == true && IsMouseButtonPressed(0) == true)
    {

        if (PessoaValida() == false) pontuacao -= 15;

        if (ScanSemNecessidade == true) pontuacao -= 10;

        PlaySound(ProximaPessoaSound);
        TransicaoPessoa = true;
      
       
        
        


    }

    if (ChecagemColisaoPontoRetangulo(LocalizacaoMouse, rejeitar) == true && IsMouseButtonPressed(0) == true)
    {

        if (PessoaValida() == true) pontuacao -= 15;
        
        if (ScanSemNecessidade == true) pontuacao -= 10;
        PlaySound(ProximaPessoaSound);
        TransicaoPessoa = true;
        


    }

   if (ChecagemColisaoPontoRetangulo(LocalizacaoMouse, scan) == true && IsMouseButtonPressed(0) == true)
    {

        if (PesoCheck() == true) ScanSemNecessidade = true;

        ScanFeito = true;
    
        


    }


    if (ChecagemColisaoPontoRetangulo(LocalizacaoMouse, deter) == true && IsMouseButtonPressed(0) == true)
    {

        if (PessoaBombada() == false) pontuacao -= 30;
        PlaySound(ProximaPessoaSound);
        TransicaoPessoa = true;
        
        


    }   




  

    //printf("%d\n", pontuacao);

    //-------------------------------------------------------------------------------------------------


    




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
       
        DrawText(TextFormat("%d cm", PessoaAtual.alturaPassaporte), passaporte.x + 250, passaporte.y + 375, 20, BLACK);
        DrawTextoSimples(TextFormat("%4.fkg", PessoaAtual.pesoPassaporte), passaporte.x + 240, passaporte.y + 465, 20, BLACK);
        DrawTextoSimples(TextFormat("%c",PessoaAtual.sexo), passaporte.x + 260, passaporte.y + 400, 20, BLACK);
        DrawTextoSimples(PessoaAtual.nome, passaporte.x + 30, passaporte.y + 340 , 20, BLACK);
        DrawTextoSimples(TextFormat("%d/%d/%d", vencimento.dia, vencimento.mes, vencimento.ano), passaporte.x + 260, passaporte.y + 433, 20, BLACK);
        
        DrawTextureEx(PassaporteSprite, (Vector2) {passaporte.x +16, passaporte.y + 416}, 0.0, 0.28, WHITE);
        DrawTextureEx(PessoaRaioX, (Vector2) {raiox.x, raiox.y}, 0.0, 1.7, WHITE);    
        //DrawRectangle(passaporteIconeRec.x, passaporteIconeRec.y, passaporteIconeRec.largura,passaporteIconeRec.altura ,RED);


      //  DrawRectangle(aprovar.x, aprovar.y, aprovar.largura, aprovar.altura, RED);
     //   DrawRectangle(deter.x, deter.y, deter.largura, deter.altura, RED);
     //   DrawRectangle(rejeitar.x, rejeitar.y, rejeitar.largura, rejeitar.altura, RED);
      //  DrawRectangle(scan.x, scan.y, scan.altura, scan.largura, RED);


        DrawTextoSimples(TextSubtext(Mensagem, 0, framesCounter/1.2), 50, 550, 21, WHITE);
        DrawTextoSimples("DATA: 27/11/1982", 0, 0, 20, WHITE ); 
        //DrawText("DATA: ", 0, 0, 20, LIGHTGRAY);
        
        DrawTextoSimples("Estado do emprego:", 0, 20, 20, WHITE );    //pedro druck mama rola
        DrawTextoSimples(estadoemprego, 210, 20, 20, WHITE);

        DrawTexture(Janela, JanelaPosicao.x, JanelaPosicao.y, WHITE);


      
    EndDrawing();
    //----------------------------------------------------------------------------------
    
    
}


