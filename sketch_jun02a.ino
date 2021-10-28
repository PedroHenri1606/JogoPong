//----------------------------------------------------------
//HARDWARE BIBLIOTECA
#include <Adafruit_GFX.h>
#include <EEPROM.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <avr/eeprom.h>
#define TFT_CS  10 
#define TFT_DC 9 
#define TFT_RST 8
//----------------------------------------------------------
//CORES
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define OUTRA 0xa8a8
#define BLUE1 0xa9a9a9
#define BLUE2 0x6868   
#define BLUE3 0x8888
#define BLUE4 0xa8a8
#define YELLOW1 0xe7e7
#define LARANJA 0xe5e5
#define YELLOW2 0xe6e6
//----------------------------------------------------------
//VARIAVEIS GLOBAIS
int maxScore = 10;
int nivel = 0;
char jogador1[6];
char jogador2[6];
char jogador3[6];
int rank[3];
int o = 0;
char nome1[6];
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
//----------------------------------------------------------
//FUNÇÕES
void menu();
void jogos();
void dificuldade();
void creditos();
void sobre();
void game();
void desenharScore(int player1Score, int player2Score);
void ranking();
void loading();
void player2();
void freemode();
int voltar = 0;
struct teste
{
  char nome[10];
  int ponto;
};
  void setup()
  {
    tft.init(240, 240, SPI_MODE2);
    SPI.begin();
    tft.setRotation(2);

    pinMode(A0,INPUT);
    pinMode(3,INPUT_PULLUP); //botao para selecionar.
    pinMode(4,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
    pinMode(A0,INPUT_PULLUP);
    pinMode(2,INPUT_PULLUP);
    pinMode(A1,INPUT_PULLUP);
    eeprom_read_block(&jogador1, 0, 6);
    eeprom_read_block(&jogador2, 20, 6);
    eeprom_read_block(&jogador3, 500, 6);
    
    
    
    rank[0] = EEPROM[50];
    rank[1] = EEPROM[51];
    rank[2] = EEPROM[52];
    
     
   loading();
  }
//------------------------------------------------------------------------------------------
//menu inicial
  void loop(){
    voltar = 0;
    
    
   tft.fillRect(0,0,240,30,BLUE4);
   tft.fillRect(0,30,240,60,BLUE3);
   tft.fillRect(0,60,240,90,BLUE2);

   tft.fillRect(0,150,240,180,BLUE2);
   tft.fillRect(0,180,240,210,BLUE3);
   tft.fillRect(0,210,240,240,BLUE4);
   //PILAR1
   tft.fillRect(0,0,240,5,WHITE);
   tft.fillRect(0,235,240,5,WHITE);
   tft.fillRect(0,175,240,5,WHITE);
   tft.fillRect(0,115,240,5,WHITE);
   tft.fillRect(0,55,240,5,WHITE);

   tft.fillRect(20,0,5,55,WHITE);
   tft.fillRect(120,0,5,55,WHITE);
   tft.fillRect(220,0,5,55,WHITE);
   
   tft.fillRect(70,60,5,55,WHITE);
   tft.fillRect(170,60,5,55,WHITE);

   tft.fillRect(10,180,5,55,WHITE);
   tft.fillRect(110,180,5,55,WHITE);
   tft.fillRect(210,180,5,55,WHITE);

   tft.fillRect(40,120,5,55,WHITE);
   tft.fillRect(140,120,5,55,WHITE);
   tft.fillRect(235,120,5,55,WHITE);

  
  
 


   
   //PonG
   tft.fillRect(60,10,125,50,BLACK);
   tft.fillRect(65,15,115,40,YELLOW);
   //JOGAR
   tft.fillRect(85,80,80,30,BLACK);
   //Ranking
    tft.fillRect(75,135,100,30,BLACK);
   //CREDITOS
   tft.fillRect(70,195,115,30,BLACK);
        
       do{
            static int posicao = 0;
            if(digitalRead(5) == LOW)
            {
              
              posicao--;
              delay(200);
            }
            if(digitalRead(4) == LOW)
            {
              posicao++;
              delay(200);
            }
            if(posicao < 0)
            {
              posicao = 2;
            }
            if(posicao > 2)
            {
              posicao = 0;
            }
          
          
          
            tft.setTextSize(4);
            tft.setTextColor(BLACK);
            tft.setCursor(78,20);
            tft.print("PonG");
          
          
          
           
              if(posicao == 0)
              {
                
                
                tft.drawRect(85,80,80,30,YELLOW2);
                tft.drawRect(86,81,80,30,YELLOW2);
                tft.drawRect(87,82,80,30,YELLOW2);
                tft.setTextSize(2);
                tft.setTextColor(YELLOW2);
                tft.setCursor(95,88);
                tft.print("Jogar");
                delay(50);
              }
              else 
              { 
                
                tft.drawRect(85,80,80,30,WHITE);
                tft.drawRect(86,81,80,30,WHITE);
                tft.drawRect(87,82,80,30,WHITE);
                tft.setTextSize(2);
                tft.setTextColor(WHITE);
                tft.setCursor(95,88);
                tft.print("Jogar");
                delay(50);
              }
            
              
              if(posicao == 1)
              {
                
                tft.drawRect(75,135,100,30,YELLOW2);
                tft.drawRect(76,136,100,30,YELLOW2);
                tft.drawRect(77,137,100,30,YELLOW2);
                tft.setTextSize(2);
                tft.setTextColor(YELLOW2);
                tft.setCursor(85,142);
                tft.print("Ranking");
                delay(50);
              }
              else
              {
                
                tft.drawRect(75,135,100,30,WHITE);
                tft.drawRect(76,136,100,30,WHITE);
                tft.drawRect(77,137,100,30,WHITE);
                tft.setTextSize(2);
                tft.setTextColor(WHITE);
                tft.setCursor(85,142);
                tft.print("Ranking");
                delay(50);
              }
            
            
              if(posicao == 2)
              {
                
                tft.drawRect(70,195,115,30,YELLOW2);
                tft.drawRect(71,196,115,30,YELLOW2);
                 tft.drawRect(72,197,115,30,YELLOW2);
                
                tft.setTextSize(2);
                tft.setCursor(80,200);
                tft.setTextColor(YELLOW2);
                tft.print("Creditos");
                delay(50);
              }
              else
              {
                
                tft.drawRect(70,195,115,30,WHITE);
                tft.drawRect(71,196,115,30,WHITE);
                tft.drawRect(72,197,115,30,WHITE);
            
                tft.setTextSize(2);
                tft.setCursor(80,200);
                tft.setTextColor(WHITE);
                tft.print("Creditos");
                delay(50);
              }
            
            if(digitalRead(3) == LOW && posicao == 0)
            {         
              jogos();
              return;
            }
            if(digitalRead(3) == LOW && posicao == 1)
            {
              ranking();
              return;
            }
            if(digitalRead(3) == LOW && posicao == 2)
            {
              creditos();
              return;
            }
      }while(true);
  
  }
  
    
//-----------------------------------------------------------------------------------------
//escolha de dificuldade
void jogos()
{   
          voltar = 0;
         tft.fillRect(0,0,240,30,BLUE4);
   tft.fillRect(0,30,240,60,BLUE3);
   tft.fillRect(0,60,240,90,BLUE2);

   tft.fillRect(0,150,240,180,BLUE2);
   tft.fillRect(0,180,240,210,BLUE3);
   tft.fillRect(0,210,240,240,BLUE4);
   //PILAR1
   tft.fillRect(0,0,240,5,WHITE);
   tft.fillRect(0,235,240,5,WHITE);
   tft.fillRect(0,175,240,5,WHITE);
   tft.fillRect(0,115,240,5,WHITE);
   tft.fillRect(0,55,240,5,WHITE);

   tft.fillRect(20,0,5,55,WHITE);
   tft.fillRect(120,0,5,55,WHITE);
   tft.fillRect(220,0,5,55,WHITE);
   
   tft.fillRect(70,60,5,55,WHITE);
   tft.fillRect(170,60,5,55,WHITE);

   tft.fillRect(10,180,5,55,WHITE);
   tft.fillRect(110,180,5,55,WHITE);
   tft.fillRect(210,180,5,55,WHITE);

   tft.fillRect(40,120,5,55,WHITE);
   tft.fillRect(140,120,5,55,WHITE);
   tft.fillRect(235,120,5,55,WHITE);

      //Jogos
        tft.fillRect(55,15,130,50,WHITE);
        tft.fillRect(60,20,120,40,BLACK);
      //VS. I.A
       tft.fillRect(65,90,100,30,BLACK); 
      //2Player
        tft.fillRect(55,140,120,30,BLACK);
      //FreeMode
         tft.fillRect(55,190,120,30,BLACK);
      

        tft.setCursor(90,33);
        tft.print("Jogos");
      
           do
           {
              if(digitalRead(2) == LOW)
              {
                delay(100);
                voltar = 1;
                return;
              }  
              static int posicao = 0;
              if(digitalRead(5) == LOW)
              {
                
                posicao--;
                delay(200);
              }
              if(digitalRead(4) == LOW)
              {
                posicao++;
                delay(200);
              }
              if(posicao < 0)
              {
                posicao = 2;
              }
              if(posicao > 2)
              {
                posicao = 0;
              }
              
                if(posicao == 0)
                {

                  
                  tft.drawRect(65,90,100,30,YELLOW2);
                  tft.drawRect(66,91,100,30,YELLOW2); 
                  tft.drawRect(67,92,100,30,YELLOW2);   
                  tft.setTextSize(2);
                  tft.setTextColor(YELLOW2);
                  tft.setCursor(80,100);            
                  tft.print("VS I.A"); 
                  delay(50);
                }
                else
                {
                  
                  
                  tft.drawRect(65,90,100,30,WHITE);
                  tft.drawRect(66,91,100,30,WHITE); 
                  tft.drawRect(67,92,100,30,WHITE);
                  tft.setTextSize(2);
                  tft.setTextColor(WHITE);
                  tft.setCursor(80,100);             
                  tft.print("VS I.A");
                  delay(50);
                }
                
                
                if(posicao == 1)
                {
                  
                  tft.drawRect(55,140,120,30,YELLOW2);
                  tft.drawRect(56,141,120,30,YELLOW2);
                  tft.drawRect(57,142,120,30,YELLOW2);
                  tft.setTextSize(2);
                  tft.setCursor(70,150);
                  tft.setTextColor(YELLOW2);
                  tft.print("2Plazer");
                  
                  delay(50);
                }
                else
                {
                  
                  tft.drawRect(55,140,120,30,WHITE);
                  tft.drawRect(56,141,120,30,WHITE);
                  tft.drawRect(57,142,120,30,WHITE);
                  tft.setTextSize(2);
                  tft.setCursor(70,150);
                  tft.setTextColor(WHITE);
                  tft.print("2Plazer");
                  delay(50);
                }
                
                if(posicao == 2)
                {
                  
                  tft.drawRect(55,190,120,30,YELLOW2);
                  tft.drawRect(56,191,120,30,YELLOW2);
                  tft.drawRect(57,192,120,30,YELLOW2);
                  tft.setTextSize(2);
                  tft.setCursor(70,200);
                  tft.setTextColor(YELLOW2);
                  tft.print("FreeMode");
                  
                  delay(50);
              
                }
                else
                {
                  
                  
                  tft.drawRect(55,190,120,30,WHITE);
                  tft.drawRect(56,191,120,30,WHITE);
                  tft.drawRect(57,192,120,30,WHITE);
                  tft.setTextSize(2);
                  tft.setCursor(70,200);
                  tft.setTextColor(WHITE);
                  tft.print("FreeMode");
                  
                  delay(50);
                 
                }
              if(digitalRead(3) == LOW && posicao == 0)
              {
                
                delay(200);
                
                dificuldade();
                if(voltar == 1)
                {
                  return;
                }
                
                nome();
                game();
                return;
              }
              
              if(digitalRead(3) == LOW && posicao == 1)
              {
                delay(200);
                dificuldade();
                if(voltar == 1)
                {
                  return;
                }
                player2();
                return;
              }
              
            if(digitalRead(3) == LOW && posicao == 2)
              {
                delay(200);
                dificuldade();
                if(voltar == 1)
                {
                  return;
                }
                freemode();
                return;
              }
           }while(true);
                
                
}
//-----------------------------------------------------------------------
  void dificuldade()
  {
         tft.fillRect(0,0,240,30,BLUE4);
         tft.fillRect(0,30,240,60,BLUE3);
         tft.fillRect(0,60,240,90,BLUE2);
      
         tft.fillRect(0,150,240,180,BLUE2);
         tft.fillRect(0,180,240,210,BLUE3);
         tft.fillRect(0,210,240,240,BLUE4);
         //PILAR1
         tft.fillRect(0,0,240,5,WHITE);
         tft.fillRect(0,235,240,5,WHITE);
         tft.fillRect(0,175,240,5,WHITE);
         tft.fillRect(0,115,240,5,WHITE);
         tft.fillRect(0,55,240,5,WHITE);
      
         tft.fillRect(20,0,5,55,WHITE);
         tft.fillRect(120,0,5,55,WHITE);
         tft.fillRect(220,0,5,55,WHITE);
         
         tft.fillRect(70,60,5,55,WHITE);
         tft.fillRect(170,60,5,55,WHITE);
      
         tft.fillRect(10,180,5,55,WHITE);
         tft.fillRect(110,180,5,55,WHITE);
         tft.fillRect(210,180,5,55,WHITE);
      
         tft.fillRect(40,120,5,55,WHITE);
         tft.fillRect(140,120,5,55,WHITE);
         tft.fillRect(235,120,5,55,WHITE);



          //DIFICULDADE
          
          tft.fillRect(10,10,220,40,BLACK);
          tft.drawRect(10,10,220,40,RED);
          tft.drawRect(11,11,220,40,RED);
          tft.drawRect(12,12,220,40,RED);
          //FACIL
          
          tft.fillRect(70,80,100,30,BLACK);

          //MEDIO
          
          tft.fillRect(70,140,100,30,BLACK);

          //DIFICIL
          
          tft.fillRect(70,190,100,30,BLACK);
          
          
                 tft.setTextSize(3);
                 tft.setTextColor(WHITE);
                 tft.setCursor(25,20);
                 tft.print("DIFICULDADE");
           do
           {

              if(digitalRead(2) == LOW)
              {
                delay(100);
                voltar = 1;
                return;
              }  
              static int posicao = 0;
              if(digitalRead(5) == LOW)
              {
                
                posicao--;
                delay(200);
              }
              if(digitalRead(4) == LOW)
              {
                posicao++;
                delay(200);
              }
              if(posicao < 0)
              {
                posicao = 2;
              }
              if(posicao > 2)
              {
                posicao = 0;
              }
              
              
                if(posicao == 0)
                {
                  tft.drawRect(70,80,100,30,YELLOW2);
                  tft.drawRect(71,81,100,30,YELLOW2);
                  tft.drawRect(72,82,100,30,YELLOW2);
                  tft.setTextSize(2);
                  tft.setTextColor(YELLOW2);
                  tft.setCursor(90,90);             
                  tft.print("FACIL");
                }
                else
                {
                  tft.drawRect(70,80,100,30,WHITE);
                  tft.drawRect(71,81,100,30,WHITE);
                  tft.drawRect(72,82,100,30,WHITE);
                  tft.setTextSize(2);
                  tft.setTextColor(WHITE);
                  tft.setCursor(90,90);             
                  tft.print("FACIL");
                }
                
                
                
                if(posicao == 1)
                {
                  tft.drawRect(70,140,100,30,YELLOW2);
                  tft.drawRect(71,141,100,30,YELLOW2);
                  tft.drawRect(72,142,100,30,YELLOW2);
                  tft.setTextColor(YELLOW2);
                  tft.setTextSize(2);
                  tft.setCursor(90,150);
                  tft.print("MEDIO");
                }
                else
                {
                  tft.drawRect(70,140,100,30,WHITE);
                  tft.drawRect(71,141,100,30,WHITE);
                  tft.drawRect(72,142,100,30,WHITE);
                  tft.setTextColor(WHITE);
                  tft.setTextSize(2);
                  tft.setCursor(90,150);
                  tft.print("MEDIO");
                }
                
              
                if(posicao == 2)
                {
                  tft.drawRect(70,190,100,30,YELLOW2);
                  tft.drawRect(71,191,100,30,YELLOW2);
                  tft.drawRect(72,192,100,30,YELLOW2);
                  tft.setTextColor(YELLOW2);
                  tft.setTextSize(2);
                  tft.setCursor(80,200);
                  tft.print("DIFICIL");
                }
                else
                {
                  tft.drawRect(70,190,100,30,WHITE);
                  tft.drawRect(71,191,100,30,WHITE);
                  tft.drawRect(72,192,100,30,WHITE);
                  tft.setTextColor(WHITE);
                  tft.setTextSize(2);
                  tft.setCursor(80,200);
                  tft.print("DIFICIL");
                }
            if(digitalRead(3) == LOW && posicao == 0)
              {
                nivel = 1;
                delay(200);
                return;
              }
              
            if(digitalRead(3) == LOW && posicao == 1)
              { 
                nivel = 2;
                delay(200);
                return;
              }
              
            if(digitalRead(3) == LOW && posicao == 2)
              {
                nivel = 3;
                delay(200);
                return;
              }
           }while(true);
                
                
        
}
  
  //---------------------------------------------------------------------------------------------------
  //creditos do jogo
  void creditos()
  {
        tft.fillRect(0,0,240,60,BLUE4);
        tft.fillRect(0,60,240,120,BLUE3);
        tft.fillRect(0,120,240,180,BLUE2);
        tft.fillRect(0,180,240,240,BLUE1);

        //CREDITOS
        tft.fillRect(35,5,170,50,WHITE);
        tft.fillRect(40,10,160,40,BLACK);

        //EQUIPE
        tft.fillRect(10,70,220,160,WHITE);
        tft.fillRect(15,75,210,150,BLACK);       
        
   do{
        tft.setTextSize(3);
        tft.setTextColor(WHITE);
        tft.setCursor(50,20);
        tft.print("CREDITOS");
        
        tft.setTextSize(2);
        tft.setCursor(25,80);
        tft.print("Eduardo de Souza");
        tft.setCursor(25,120);
        tft.print("Pedro Henrique V");
        tft.setCursor(25,160);
        tft.print("Gabriel Martins");
        tft.setCursor(55,200);
        tft.print("Vinicios.E");
        
        
          if(digitalRead(2) == LOW)
          {
            delay(100);
            return;
          }  
        }while(true);
}
  //--------------------------------------------------------------------------------------------
  //codigo do jogo em si
  void game()
  
    {

      tft.fillRect(0,0,240,240,WHITE);
      tft.fillRect(5,40,230,195,BLUE4);
      int player1Score = 0;
      int player2Score = 0;
      int posicaoraquetex = 180;
      int posicaoraquetey = 120;
      desenharScore(player1Score, player2Score);
      do
      {
                 if(digitalRead(2) == LOW)
                  {
                   if(o==0)
                   {
                    EEPROM[50] = rank[0];
                   }
                   if(o==1)
                   {
                    EEPROM[51] = rank[1];
                   }
                   if(o==2)
                   {
                    EEPROM[52] = rank[2];
                   }
                    delay(200);
                    o++;
                    return;
                  }
                 tft.drawLine(120,40,120,240,WHITE);
                 static int direcaoball = 5 + nivel;
                 static int direcaobally = 5;
                 static int posicaox = 120;
                 static int posicaoy = 120;
                 static int posicaoraquetex = 220;
                 static int posicaoraquetey = 120;
                 static int posicaoraquete2x= 15;
                 static int posicaoraquete2y= 120;
                 int oldposicaoraquetex;
                 int oldposicaoraquetey;
                 oldposicaoraquetex = posicaoraquetex;
                 oldposicaoraquetey = posicaoraquetey;
                 int oldposicaoraquete2x = posicaoraquete2x;
                 int oldposicaoraquete2y = posicaoraquete2y;
                 int oldposicaox;
                 int oldposicaoy;
                 int oldplayer1Score = player1Score;
                 int oldplayer2Score = player2Score;
                 int habilidade = 3 + nivel;
                 
                 if(digitalRead(5) == LOW)
                 {
                  posicaoraquetey = posicaoraquetey - 7 - nivel;
                 }
                 else if(digitalRead(4) == LOW)
                 {
                  posicaoraquetey = posicaoraquetey + 7 + nivel;
                 }
                  if(posicaoraquetey > 195)
                   {
                    posicaoraquetey = 195;
                   }
                   if(posicaoraquetey < 45)
                   {
                    posicaoraquetey = 45;
                   }
                 
                 if(oldposicaoraquetex != posicaoraquetex || oldposicaoraquetey != posicaoraquetey )
                   {
                    tft.fillRect(oldposicaoraquetex,oldposicaoraquetey,5,40,BLUE4);
                   }
                        
                  if(posicaoraquete2y > posicaoy - 10 && posicaoraquete2y != 0)
                   {
                    posicaoraquete2y = posicaoraquete2y - habilidade;
                   }
                 else if(posicaoraquete2y < posicaoy + 10 && posicaoraquete2y != 240)
                     {
                      posicaoraquete2y = posicaoraquete2y + habilidade;
                     }
                     
                  if(posicaoraquete2y > 195)
                   {
                    posicaoraquete2y = 195;
                   }
                   if(posicaoraquete2y < 45)
                   {
                    posicaoraquete2y = 45;
                   }


                     
                 if(oldposicaoraquete2x != posicaoraquete2x || oldposicaoraquete2y != posicaoraquete2y )
                   {
                    tft.fillRect(oldposicaoraquete2x,oldposicaoraquete2y,5,40,BLUE4);
                    
                   } 
                   
                 oldposicaox =  posicaox;
                 oldposicaoy = posicaoy;
                 posicaox = posicaox + direcaoball;
                 posicaoy = posicaoy + direcaobally;
                 
                 if(oldposicaox != posicaox || oldposicaoy != posicaoy)
                   {
                    tft.fillRect(oldposicaox,oldposicaoy,5,5,BLUE4);
                   }
                   tft.fillRect(posicaoraquetex, posicaoraquetey,5,40,BLACK);
                   tft.fillRect(posicaoraquete2x, posicaoraquete2y, 5,40, BLACK);
                 
                 tft.fillRect(posicaox, posicaoy,5,5, YELLOW);
                 delay(25);
                 
                 if(posicaox >= posicaoraquetex -5 && posicaoy >= posicaoraquetey && posicaoy <= posicaoraquetey + 50)
                 {
                    direcaoball = -direcaoball;
                 }
                 if(posicaox <= posicaoraquete2x +5 && posicaoy >= posicaoraquete2y && posicaoy <= posicaoraquete2y + 50)
                 {
                    direcaoball = -direcaoball;
                 }
                 
                 if(posicaox >= 230)
                 {
                        direcaoball = -direcaoball;
                        player1Score = player1Score + 1;
                        

                        delay(1000);
                        posicaoraquetey = 120;
                        posicaox = 160;
                        posicaoy = 160;
                        posicaoraquetey = 120;
                        posicaoraquete2y = 120;
                        
                     
                      tft.fillScreen(BLACK);
                      tft.fillRect(55,105,130,50,WHITE);
                      tft.fillRect(60,110,120,40,BLUE4);
                      
                     
                      tft.setCursor(80,120);
                      tft.setTextColor(WHITE);
                      tft.setTextSize(3);
                      tft.print("PONTO");
                        delay(2000);
                       tft.fillRect(0,0,240,240,WHITE);
                       tft.fillRect(5,40,230,195,BLUE4);
                        desenharScore(player1Score, player2Score);

                 }
               
                  if(posicaox <= 5)
                   {
                      direcaoball = -direcaoball;
                      player2Score = player2Score + 1;
                      
                   if(o==0)
                   {
                    rank[0] = rank[0] + 1;
                    EEPROM[50] = rank[0];
                   }
                   if(o==1)
                   {
                     rank[1] = rank[1] + 1;
                     EEPROM[51] = rank[1];
                   }
                   if(o==2)
                   {
                     rank[2] = rank[2] + 1;
                     EEPROM[52] = rank[2];
                   }
                   

                      delay(1000);
                      posicaoraquetey = 120;
                      posicaox = 80;
                      posicaoy = 80;
                      posicaoraquetey = 120;
                      posicaoraquete2y = 120;
  
                      tft.fillScreen(BLACK);
                      tft.fillRect(55,105,130,50,WHITE);
                      tft.fillRect(60,110,120,40,RED);
                      
                     
                      tft.setCursor(80,120);
                      tft.setTextColor(WHITE);
                      tft.setTextSize(3);
                      tft.print("PONTO");
                      delay(2000);
                            tft.fillRect(0,0,240,240,WHITE);
                            tft.fillRect(5,40,230,195,BLUE4);
                      desenharScore(player1Score, player2Score);
                  }
                 if(posicaoy >=230)
                   {
                    direcaobally = -direcaobally;
                   }
                 if(posicaoy <= 40)
                   {
                    direcaobally = -direcaobally;
                   }
               
               if(player1Score >= 10)
               {
                  endfinalplayer1Score();
                  delay(100);
                  return;
               }
               if(player2Score >= 10)
               {
                  endfinalplayer2Score();
                  delay(100);
                  return;
               }
      }while(true);
    }
//------------------------------------------------------------------------------------------------
//pontos do jogodor
  void desenharScore(int player1Score, int player2Score)
   {
     tft.setTextSize(3);
     tft.fillRect(0,0,240,35,BLACK);
     if(player1Score > player2Score)
     {
      tft.drawRect(0,0,240,35,BLUE);
      tft.drawRect(1,1,240,35,BLUE);
     }
     if(player2Score > player1Score)
     {
      tft.drawRect(0,0,240,35,RED);
      tft.drawRect(1,1,240,35,RED);
     }
     if(player2Score == player1Score)
     {
      tft.drawRect(0,0,240,35,WHITE);
      tft.drawRect(1,1,240,35,WHITE);
     }
     tft.setTextColor(BLUE);
     tft.setCursor(40, 5);  
     tft.print(player1Score);
     tft.setTextColor(RED);
     tft.setCursor(200, 5);
     tft.print(player2Score);
   }
//---------------------------------------------------------------------------------------------------
//caso o jogador azul ganhe
  void endfinalplayer1Score()
    {
       tft.fillScreen(BLACK);

       tft.fillRect(35,45,170,130,WHITE);
       tft.fillRect(25,85,190,50,WHITE);
       
       tft.fillRect(40,50,160,40,BLUE4);
       tft.fillRect(30,90,180,40,BLUE4);
       tft.fillRect(40,130,160,40,BLUE4);
       
       tft.setTextColor(WHITE);
       tft.setCursor(60,60);
       tft.setTextSize(3);
       tft.print("Jogador ");
       tft.setCursor(85,100);
       tft.print("Azul");
       tft.setCursor(65,140);
       tft.print("Venceu");
       delay(2000);
    }
//---------------------------------------------------------------------------------------------------
//caso o jogador vermelho ganhe
  void endfinalplayer2Score(){
        tft.fillScreen(BLACK);
        tft.drawRect(68,93,12,35, YELLOW1);
        tft.drawRect(69,94,11,35, YELLOW1);
        tft.drawRect(70,95,10,35, YELLOW1);
        tft.drawRect(158,93,13,35, YELLOW1);
        tft.drawRect(158,93,14,35, YELLOW1);
        tft.drawRect(159,94,12,35, YELLOW1);
        tft.drawRect(160,95,11,35, YELLOW1);

        tft.fillRect(80,80,80,60, YELLOW1);
        tft.fillRect(90,140,60,10, YELLOW1);
        tft.fillRect(100,150,40,10, YELLOW2);
        tft.fillRect(110,160,20,30, YELLOW2);
        tft.fillRect(100,190,40,10, LARANJA);
        tft.fillRect(90,200,60,10, LARANJA);
        tft.fillRect(79,97,82,10, BLUE);
        tft.fillRect(79,117,82,10, BLUE);
        delay(200000);
        delay(200000);
  }
//nome
void nome()
{
      int i = 0;
      int y = 0;
      char letras[]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};    
      int j;
      for(j=0;j<10;j++)
      {
        nome1[j] = '\0';
      }
      nome1[y] = letras[0];
      int oldi;
      int oldy;
      nome1[y] = letras[i];
      delay(500);
      

            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.fillRect(0,0,240,30,BLUE4);
   tft.fillRect(0,30,240,60,BLUE3);
   tft.fillRect(0,60,240,90,BLUE2);

   tft.fillRect(0,150,240,180,BLUE2);
   tft.fillRect(0,180,240,210,BLUE3);
   tft.fillRect(0,210,240,240,BLUE4);
   //PILAR1
   tft.fillRect(0,0,240,5,WHITE);
   tft.fillRect(0,235,240,5,WHITE);
   tft.fillRect(0,175,240,5,WHITE);
   tft.fillRect(0,115,240,5,WHITE);
   tft.fillRect(0,55,240,5,WHITE);

   tft.fillRect(20,0,5,55,WHITE);
   tft.fillRect(120,0,5,55,WHITE);
   tft.fillRect(220,0,5,55,WHITE);
   
   tft.fillRect(70,60,5,55,WHITE);
   tft.fillRect(170,60,5,55,WHITE);

   tft.fillRect(10,180,5,55,WHITE);
   tft.fillRect(110,180,5,55,WHITE);
   tft.fillRect(210,180,5,55,WHITE);

   tft.fillRect(40,120,5,55,WHITE);
   tft.fillRect(140,120,5,55,WHITE);
   tft.fillRect(235,120,5,55,WHITE);


            //ESCREVA
            tft.fillRect(40,10,160,45,WHITE);
            tft.fillRect(45,15,150,35,BLACK);

            //NOME
            tft.fillRect(60,50,120,45,WHITE);
            tft.fillRect(65,55,110,35,BLACK);
            //BARRA
            tft.fillRect(65,50,110,10,BLACK);

            //NOME JOGADOR
            tft.fillRect(35,155,170,50,WHITE);
            tft.fillRect(40,160,160,40,BLACK);
            
            
   
            tft.setTextSize(3);
            tft.setCursor(60,20);
            tft.print("Escreva");
            tft.setCursor(85,55);
            tft.print("Nome");
            nome1[6] = '\0';

            tft.setTextSize(2);
            tft.setCursor(60,170);
            tft.print("nome: ");
            tft.print(nome1[o]);
            delay(500);     
      do
          {
            if(digitalRead(2) == LOW)
              {
                tft.fillScreen(BLACK);
                delay(100);
                return;
              }  
            if(y==5)
            {
              break;
              
            }
            oldi = i;
            oldy = y;
            if(i > 26)
            {
              i=0;
            }
            if(i<0)
            {
              i=25;
            }
          if(digitalRead(5) == LOW)
                {
                   i = i - 1;
                   delay(200);
                }
                
          if(digitalRead(4) == LOW)
            {
              i = i + 1; 
              delay(200);
            }
          if(digitalRead(3) == LOW)
          {
            y++;
            i = 0;
            delay(200);
          }
          if(oldi != i || oldy != y)
          {
  
            tft.setTextSize(2);
            tft.setTextColor(WHITE);

            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            

            tft.fillRect(40,160,160,40,BLACK);


            nome1[y] = letras[i];
            
            
            tft.setCursor(60,170);
            tft.print("Nome: ");
            nome1[5] = '\0';
            tft.print(nome1);
            
           
          }
          
          
      }while(true);
      
      if(o==0)
      {
        strcpy(jogador1,nome1);
        eeprom_write_block(&jogador1, 0, 6);
      }
      if(o==1)
      {
        strcpy(jogador2,nome1);
        eeprom_write_block(&jogador2, 20, 6);
      }
      if(o==2)
      {
        strcpy(jogador3,nome1);
        eeprom_write_block(&jogador3, 500, 6);
      }
      

      return;
}
//-------------------------------------------------------------------------------------------
void ranking()
{
   tft.fillScreen(BLACK);


   tft.setTextColor(WHITE);
   tft.fillRect(0,0,240,60,BLUE4);
   tft.fillRect(0,60,240,120,BLUE3);
   tft.fillRect(0,120,240,180,BLUE2);
   tft.fillRect(0,180,240,240,BLUE1);

   //RANKING
   tft.fillRect(40,10,160,45,WHITE);
   tft.fillRect(45,15,150,35,BLACK);

   //JOGADOR 1
   tft.fillRect(10,70,220,40,WHITE);
   tft.fillRect(15,75,210,30,BLACK);

   //JOGADOR2
   tft.fillRect(10,130,220,40,WHITE);
   tft.fillRect(15,135,210,30,BLACK);

   //JOGADOR3
   tft.fillRect(10,190,220,40,WHITE);
   tft.fillRect(15,195,210,30,BLACK);
   
    struct teste registro[3];
    struct teste x;
    int i;
    for(i=0;i<10;i++)
    {
      registro[0].nome[i] = '\0';
      registro[1].nome[i] = '\0';
      registro[2].nome[i] = '\0';
    }
    registro[0].ponto = 0;
    registro[1].ponto = 0;
    registro[2].ponto = 0;
    registro[0].ponto = rank[0];
    registro[1].ponto = rank[1];
    registro[2].ponto = rank[2];
    strcat(registro[0].nome,jogador1);
    strcat(registro[1].nome,jogador2);
    strcat(registro[2].nome,jogador3);
  
    int j;
    for(i=0;i<2;i++)
    {
      for(j=i+1;j<3;j++)
      {
        if(registro[i].ponto < registro[j].ponto)
        {
          x = registro[i];
          registro[i] = registro[j];
          registro[j] = x;
        }
        
      }
    }
            tft.setTextSize(3); 
            tft.setCursor(60,20);
            tft.print("RANKING");
            
            tft.setTextSize(2);
            tft.setCursor(20,80);
            tft.print(registro[0].nome);
            tft.setCursor(80,80);
            tft.print(registro[0].ponto);
            
            tft.setCursor(20,140);
            tft.print(registro[1].nome);
            tft.setCursor(80,140);
            tft.print(registro[1].ponto);
            
            tft.setCursor(20,200);
            tft.print(registro[2].nome);
            tft.setCursor(80,200);
            tft.print(registro[2].ponto);
           
            
            do
            {
              if(digitalRead(2) == LOW)
              {
                tft.fillScreen(BLACK);
                delay(100);
                return;
              }  
          }while(true);
}
void loading() {
  tft.setTextSize(3);
  tft.fillScreen(BLACK);

  tft.fillRect(60, 45, 125, 50, WHITE);
  tft.fillRect(65, 50, 115, 40, BLACK);
  tft.setTextSize(4);
  tft.setTextColor(WHITE);
  tft.setCursor(78, 55);
  tft.print("PonG");

  tft.fillRect(20, 160, 200, 40, WHITE);
  tft.setTextSize(3);
  tft.setCursor(40, 120);
  tft.print ("Loading...");
  delay(600);
  tft.fillRect(30, 165, 20, 30, BLUE);
  delay(600);
  tft.fillRect(60, 165, 20, 30, BLUE3);
  delay(200);
  tft.fillRect(90, 165, 20, 30, BLUE2);
  delay(400);
  tft.fillRect(120, 165, 20, 30, BLUE1);
  delay(600);
  tft.fillRect(150, 165, 20, 30, BLUE1);
  delay(1000);
  tft.fillRect(180, 165, 20, 30, CYAN);
  delay(1000);
}

  
void player2(){
      tft.fillRect(0,0,240,240,WHITE);
      tft.fillRect(5,40,230,195,BLUE4);

      int player1Score = 0;
      int player2Score = 0;
      int posicaoraquetex = 180;
      int posicaoraquetey = 120;
      desenharScore(player1Score, player2Score);
      do
      {
                 if(digitalRead(2) == LOW)
                  {
                          delay(200);
                          voltar = 1;
                          return;
                  }
                 tft.drawLine(120,40,120,240,WHITE);
                 static int direcaoball = 3;
                 static int direcaobally = 3;
                 static int posicaox = 120;
                 static int posicaoy = 120;
                 static int posicaoraquetex = 220;
                 static int posicaoraquetey = 120;
                 static int posicaoraquete2x= 15;
                 static int posicaoraquete2y= 120;
                 int oldposicaoraquetex;
                 int oldposicaoraquetey;
                 oldposicaoraquetex = posicaoraquetex;
                 oldposicaoraquetey = posicaoraquetey;
                 int oldposicaoraquete2x;
                 int oldposicaoraquete2y;
                 oldposicaoraquete2x = posicaoraquete2x;
                 oldposicaoraquete2y = posicaoraquete2y;
                 
                 int oldposicaox;
                 int oldposicaoy;
                 int oldplayer1Score = player1Score;
                 int oldplayer2Score = player2Score;
                 int habilidade = 3 + nivel;
                 
                 if(digitalRead(5) == LOW)
                 {
                    posicaoraquetey = posicaoraquetey - 7;
                 }
                 else if(digitalRead(4) == LOW)
                 {
                    posicaoraquetey = posicaoraquetey + 7;
                 }
                 
                 if(digitalRead(A0) == LOW)
                 {
                  posicaoraquete2y = posicaoraquete2y - 7;
                 }
                 else if(digitalRead(A1) == LOW)
                 {
                  posicaoraquete2y = posicaoraquete2y + 7;
                 }
                 
                  if(posicaoraquetey > 195)
                   {
                    posicaoraquetey = 195;
                   }
                   if(posicaoraquetey < 45)
                   {
                    posicaoraquetey = 45;
                   }
                   
                   if(posicaoraquete2y > 195)
                   {
                    posicaoraquete2y = 195;
                   }
                   if(posicaoraquete2y < 45)
                   {
                    posicaoraquete2y = 45;
                   }
                 
                 if(oldposicaoraquetex != posicaoraquetex || oldposicaoraquetey != posicaoraquetey )
                   {
                    tft.fillRect(oldposicaoraquetex,oldposicaoraquetey,5,40,BLUE4);
                   }  
                       
                  
                 
                 if(oldposicaoraquete2x != posicaoraquete2x || oldposicaoraquete2y != posicaoraquete2y )
                   {
                    tft.fillRect(oldposicaoraquete2x,oldposicaoraquete2y,5,40,BLUE4);
                   } 
                   
                 oldposicaox =  posicaox;
                 oldposicaoy = posicaoy;
                 posicaox = posicaox + direcaoball;
                 posicaoy = posicaoy + direcaobally;
                 
                 if(oldposicaox != posicaox || oldposicaoy != posicaoy)
                   {
                    tft.fillRect(oldposicaox,oldposicaoy,5,5,BLUE4);
                   }
                   tft.fillRect(posicaoraquetex, posicaoraquetey,5,40,BLACK);

                   tft.fillRect(posicaoraquete2x, posicaoraquete2y, 5,40, BLACK);

                 
                 tft.fillRect(posicaox, posicaoy,5,5, YELLOW);
                 delay(25);
                 if(posicaox >= posicaoraquetex -5 && posicaoy >= posicaoraquetey && posicaoy <= posicaoraquetey + 50)
                 {
                    direcaoball = -direcaoball;
                 }
                 if(posicaox <= posicaoraquete2x +5 && posicaoy >= posicaoraquete2y && posicaoy <= posicaoraquete2y + 50)
                 {
                    direcaoball = -direcaoball;
                 }

                 if(posicaox >= 230)
                 {
                        direcaoball = -direcaoball;
                        player1Score = player1Score + 1;

                        posicaoraquetey = 120;
                        posicaox = 180;
                        posicaoy = 180;
                        posicaoraquetey = 120;
                        posicaoraquete2y = 120;
                             tft.fillScreen(BLACK);   
                      tft.fillRect(55,105,130,50,WHITE);
                      tft.fillRect(60,110,120,40,BLUE);
                      
                            
                      tft.setCursor(80,120);
                      tft.setTextColor(WHITE);
                      tft.setTextSize(3);
                      tft.print("PONTO");
                        delay(2000);
                        

                        tft.fillRect(0,0,240,240,WHITE);
                        tft.fillRect(5,40,230,195,BLUE4);

                        desenharScore(player1Score, player2Score);
                       //break;
                 }
               
                  if(posicaox <= 5)
                   {
                       if(player2Score >= 10)
                       {
                          endfinalplayer2Score();
                          delay(100);
                          return;
                       }
                            
                      direcaoball = -direcaoball;
                      player2Score = player2Score + 1;
                      desenharScore(player1Score, player2Score);

                      posicaoraquetey = 120;
                      posicaox = 60;
                      posicaoy = 60;
                      posicaoraquetey = 120;
                      posicaoraquete2y = 120;
                      
                     
                      tft.fillScreen(BLACK);
                      tft.fillRect(55,105,130,50,WHITE);
                      tft.fillRect(60,110,120,40,RED);
                      
                     
                      tft.setCursor(80,120);
                      tft.setTextColor(WHITE);
                      tft.setTextSize(3);
                      tft.print("PONTO");
                      delay(2000);

                      tft.fillRect(0,0,240,240,WHITE);
                      tft.fillRect(5,40,230,195,BLUE4);
                     
                      desenharScore(player1Score, player2Score);
                  }
                  
                 if(posicaoy >=227)
                   {
                    
                    direcaobally = -direcaobally;
                   }
                 if(posicaoy <= 45)
                   {
                    
                    direcaobally = -direcaobally;
                   }
               
               if(player1Score >= 10)
               {
                  endfinalplayer1Score();
                  delay(100);
                  return;
               }
               if(player2Score >= 10)
               {
                  endfinalplayer2Score();
                  delay(100);
                  return;
               }
      }while(true);
    }
void freemode(){
      tft.fillRect(0,0,240,240,WHITE);
      tft.fillRect(5,5,230,230,BLUE4);
      int player1Score = 0;
      int player2Score = 0;
      int posicaoraquetex = 200;
      int posicaoraquetey = 120;
      do
      {
                 if(digitalRead(2) == LOW)
                  {
                          tft.fillScreen(BLACK);
                          voltar =1;
                          delay(200);
                          
                          return;
                  }
                 tft.drawLine(120,0,120,240,WHITE);
                 static int direcaoball = 3 + nivel;
                 static int direcaobally = 3 + nivel;
                 static int posicaox = 120;
                 static int posicaoy = 120;
                 static int posicaoraquetex = 210;
                 static int posicaoraquetey = 120;
                 
                 int oldposicaoraquetex;
                 int oldposicaoraquetey;
                 oldposicaoraquetex = posicaoraquetex;
                 oldposicaoraquetey = posicaoraquetey;
                 
                 
                 int oldposicaox;
                 int oldposicaoy;
                 int oldplayer1Score = player1Score;
                 int oldplayer2Score = player2Score;
                 
                 
                 if(digitalRead(5) == LOW)
                 {
                    posicaoraquetey = posicaoraquetey - 7;
                    
                 }
                 else if(digitalRead(4) == LOW)
                 {
                    posicaoraquetey = posicaoraquetey + 7;
                 }
                 
                 
                  if(posicaoraquetey > 195)
                   {
                    posicaoraquetey = 195;
                   }
                   if(posicaoraquetey < 5)
                   {
                    posicaoraquetey = 5;
                   }
                 
                 if(oldposicaoraquetex != posicaoraquetex || oldposicaoraquetey != posicaoraquetey )
                   {
                    tft.fillRect(oldposicaoraquetex,oldposicaoraquetey,5,40,BLUE4);
                   }  
                       
                  
                 
                 
                   
                 oldposicaox =  posicaox;
                 oldposicaoy = posicaoy;
                 posicaox = posicaox + direcaoball;
                 posicaoy = posicaoy + direcaobally;
                 
                 if(oldposicaox != posicaox || oldposicaoy != posicaoy)
                   {
                    tft.fillRect(oldposicaox,oldposicaoy,5,5,BLUE4);
                   }
                   
                 tft.fillRect(posicaoraquetex, posicaoraquetey,5,40,BLACK);
                 tft.fillRect(posicaox, posicaoy,5,5, YELLOW);
                 delay(25);
                 
                 if(posicaox >= posicaoraquetex -5 && posicaoy >= posicaoraquetey && posicaoy <= posicaoraquetey + 50)
                 {
                    direcaoball = -direcaoball;
                 }
                 
                 if(posicaox >= 225)
                 {
                   direcaoball = -direcaoball; 

                 }

                  if(posicaox <= 10)
                   {
                      direcaoball = -direcaoball; 
                   }

                 if(posicaoy >=225)
                   {
                    direcaobally = -direcaobally;
                   }
                 if(posicaoy <= 10)
                   {
                    direcaobally = -direcaobally;
                   }
                   
                
               
      }while(true);
    }
