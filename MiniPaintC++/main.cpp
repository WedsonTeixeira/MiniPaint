#include <iostream>
#include <conio.h>
#include <conio2.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

void grafico(int* material);
void graficoselect(int *material);
void escolha(int *material, int *cor, int *planodefun);
void desenhar(int *material, int *cor, int *planodefun);

int main()
{
    textbackground(15);
    clrscr();

    int *material=0;
    int *cor=0;
    int *planodefun=0;

    material=new int();
    cor=new int();
    planodefun=new int();

    grafico(cor);
    escolha(material, cor, planodefun);
    desenhar(material, cor, planodefun);
}

void grafico(int* material)
{
   textbackground(10);
   for(int x=1; x<121; x++)
    {
        for(int y=1; y<4; y++)
        {
            textcolor(10);
            gotoxy(x,y);
            putchar(219);
        }
    }
    textbackground(2);
    for(int x=1; x<121; x++)
    {
        for(int y=4; y<7; y++)
        {
            textcolor(2);
            gotoxy(x,y);
            putchar(219);
            gotoxy(x,29);
            putchar(219);
            gotoxy(x,30);
            putchar(219);
            if(x>=7 && x<=30)
            {
                textcolor(2);
                gotoxy(1,x);
                putchar(219);
                putchar(219);
                gotoxy(119,x);
                putchar(219);
                putchar(219);
            }
        }
    }
    textbackground(10);
    textcolor(0);
    gotoxy(55,2);
    cout << "PAINT C++";

    textbackground(2);

    *material=='1'?textcolor(15):textcolor(0);
     gotoxy(10,5);
     cout << "1 LAPIS";

     *material=='2'?textcolor(15):textcolor(0);
     gotoxy(37,5);
     cout << "2 BORRACHA";

     *material=='3'?textcolor(15):textcolor(0);
     gotoxy(65,5);
     cout << "3 BALDE DE TINTA";

     *material=='4'?textcolor(15):textcolor(0);
     gotoxy(96,5);
     cout << "4 PLANO DE FUNDO";

     textcolor(0);

     gotoxy(36,30);
     cout << "POSICIONAR - ENTER";

     gotoxy(60,30);
     cout << "MUDAR MATERIAL - ESPACO";

     gotoxy(109,30);
     cout << "SAIR - Esc";
     gotoxy(1,1);
}

void escolha(int *material, int *cor, int *planodefun)
{
   char tecla;
   textbackground(2);
   textcolor(0);
   gotoxy(49,29);
   cout << "ESCOLHA O MATERIAL:";

   gotoxy(69,29);

   _setcursortype(_NORMALCURSOR);

   *material=getche();

   if(*material==27)
   {
       textbackground(WHITE);
       clrscr();
       textcolor(BLACK);
       gotoxy(40,13);
       cout << "Professor: Alcides Xavier Benicasa";
       gotoxy(48,15);
       cout << "Developer: Wedson";
       gotoxy(1,27);
       exit(0);
   }

   while(*material<'1' || *material>'4')
   {
       textcolor(2);
       printf("\b");
       Sleep(100);
       gotoxy(69,29);
       putchar(219);
       gotoxy(69,29);
       textcolor(0);
       *material=getche();
       if(*material==27)
       {
          textbackground(WHITE);
           clrscr();
           textcolor(BLACK);
           gotoxy(40,13);
           cout << "Professor: Alcides Xavier Benicasa";
           gotoxy(48,15);
           cout << "Developer: Wedson";
           gotoxy(1,27);
           exit(0);
       }
   }
   graficoselect(material);

   if(*material!='2')
   {
       textbackground(2);
       textcolor(0);
       gotoxy(49,29);
       cout << "ESCOLHA A COR:";

       while(tecla!=13)
       {
            textbackground(2);
            _setcursortype(_NOCURSOR);

            textcolor(0);
            gotoxy(64,29);
            putchar(174);
            textcolor(0);
            gotoxy(69,29);
            putchar(175);

            while(!kbhit())
            {
                textcolor(*cor);
                gotoxy(66,29);
                putchar(219);
                putchar(219);
                Sleep(200);

                textcolor(2);
                gotoxy(66,29);
                putchar(219);
                putchar(219);
                Sleep(100);
            }

            tecla=getch();

            if(tecla==27)
            {
               textbackground(WHITE);
               clrscr();
               textcolor(BLACK);
               gotoxy(40,13);
               cout << "Professor: Alcides Xavier Benicasa";
               gotoxy(48,15);
               cout << "Developer: Wedson";
               gotoxy(1,27);
               exit(0);
            }

            switch(tecla)
            {
                case 77:
                    if(*cor==15)
                    {
                        *cor=0;
                        break;
                     }
                    *cor=(*cor)+1;
                    break;

                case 75:
                    if(*cor==0)
                    {
                        *cor=15;
                        break;
                    }
                    *cor=(*cor)-1;
                    break;
            }

        }
   }
    graficoselect(material);
}

void graficoselect(int *material)
{
    textbackground(2);
    textcolor(2);
    for(int x=1; x<121; x++)
    {
        for(int y=4; y<7; y++)
        {
            gotoxy(x,y);
            putchar(219);
        }
    }

    for(int x=1; x<121; x++)
    {
        gotoxy(x,29);
        putchar(219);
    }

    textbackground(2);
    *material=='1'?textcolor(15):textcolor(0);
     gotoxy(10,5);
     cout << "1 LAPIS";

     *material=='2'?textcolor(15):textcolor(0);
     gotoxy(37,5);
     cout << "2 BORRACHA";

     *material=='3'?textcolor(15):textcolor(0);
     gotoxy(65,5);
     cout << "3 BALDE DE TINTA";

     *material=='4'?textcolor(15):textcolor(0);
     gotoxy(96,5);
     cout << "4 PLANO DE FUNDO";

     textcolor(0);
     gotoxy(109,30);
     cout << "SAIR - Esc";
     gotoxy(1,1);

}

void desenhar(int *material, int *cor, int *planodefun)
{
    int coluna=60, linha=18, cont=0;
    char tecla=13, outra;

        while(tecla!=27)
        {
            cont=0;

            if(tecla==13)
            {
                _setcursortype(_SOLIDCURSOR);
                outra=tecla;

                while(outra==13 && *material!='4')
                {
                    cont=1;
                    gotoxy(coluna,linha);
                    tecla=getch();
                    if(tecla==27)
                    {
                       textbackground(WHITE);
                       clrscr();
                       textcolor(BLACK);
                       gotoxy(40,13);
                       cout << "Professor: Alcides Xavier Benicasa";
                       gotoxy(48,15);
                       cout << "Developer: Wedson";
                       gotoxy(1,27);
                       exit(0);
                    }

                    switch(tecla)
                    {
                       case 72:
                           if(linha>7)
                           {
                               linha--;
                           }
                           break;

                        case 80:
                            if(linha<28)
                            {
                                linha++;
                            }
                            break;
                        case 77:
                           if(coluna<118)
                           {
                               coluna++;
                           }
                           break;

                        case 75:
                            if(coluna>3)
                            {
                                coluna--;
                            }
                            break;
                    }
                    if(tecla==32)
                    {
                       *material=0;
                        graficoselect(material);
                       escolha(material, cor, planodefun);
                       tecla=13;
                       _setcursortype(_SOLIDCURSOR);
                    }
                    if(tecla==13)
                    {
                        outra=0;
                    }

                }
            }

            if(*material=='1')
            {
               textbackground(*cor);
               textcolor(*cor);
            }
            if(*material=='2')
            {
               textbackground(15);
               textcolor(15);
            }

            if(*material=='1' || *material=='2' )
            {
                gotoxy(coluna,linha);
                putchar(219);
                gotoxy(coluna,linha);
                tecla=getch();
                if(tecla==27)
                {
                   textbackground(WHITE);
                   clrscr();
                   textcolor(BLACK);
                   gotoxy(40,13);
                   cout << "Professor: Alcides Xavier Benicasa";
                   gotoxy(48,15);
                   cout << "Developer: Wedson";
                   gotoxy(1,27);
                   exit(0);
                }

                switch(tecla)
                {
                    case 72:
                        if(linha>7)
                        {
                            linha--;
                        }
                        break;

                    case 80:
                        if(linha<28)
                        {
                            linha++;
                        }
                        break;
                    case 77:
                        if(coluna<118)
                        {
                            coluna++;
                        }
                        break;

                    case 75:
                        if(coluna>3)
                        {
                            coluna--;
                        }
                        break;
                }
                if(tecla==32)
                {
                    *material=0;
                    graficoselect(material);
                    escolha(material,cor,planodefun);
                    tecla=13;
                    _setcursortype(_SOLIDCURSOR);
                }
            }
            if(*material=='3')
            {
                tecla=13;
                outra=tecla;
                if(cont==0)
                {
                    while(outra==13)
                    {
                        _setcursortype(_SOLIDCURSOR);
                        gotoxy(coluna,linha);
                        tecla=getch();

                        if(tecla==27)
                        {
                           textbackground(WHITE);
                           clrscr();
                           textcolor(BLACK);
                           gotoxy(40,13);
                           cout << "Professor: Alcides Xavier Benicasa";
                           gotoxy(48,15);
                           cout << "Developer: Wedson";
                           gotoxy(1,27);
                           exit(0);
                        }

                        switch(tecla)
                        {
                            case 72:
                                if(linha>7)
                                {
                                    linha--;
                                }
                                break;

                            case 80:
                                if(linha<28)
                                {
                                    linha++;
                                }
                                break;
                            case 77:
                                if(coluna<118)
                                {
                                    coluna++;
                                }
                                break;

                            case 75:
                                if(coluna>3)
                                {
                                    coluna--;
                                }
                                break;
                            }

                            if(tecla==32)
                            {
                                *material=0;
                                graficoselect(material);
                                escolha(material,cor, planodefun);
                                tecla=13;
                                _setcursortype(_SOLIDCURSOR);
                            }
                            if(tecla==13)
                            {
                                outra=0;
                            }
                        }
                }

                for(int x=coluna-5; x<coluna+6; x++)
                {
                    if(x>118)
                    {
                        break;
                    }
                    if(x<3)
                    {
                        x=3;
                    }
                    for(int y=linha-2; y<linha+3; y++)
                    {
                        if(y>28)
                        {
                            break;
                        }
                        if(y<7)
                        {
                            y=7;
                        }

                        textbackground(*cor);
                        textcolor(*cor);
                        gotoxy(x,y);
                        putchar(219);

                    }
                }

                if(tecla==32)
                {
                    *material=0;
                    graficoselect(material);
                    escolha(material,cor,planodefun);
                    tecla=13;
                    _setcursortype(_SOLIDCURSOR);
                }

           }
           if(*material=='4')
           {
               *material=0;
               graficoselect(material);
               for(int z=3; z<119; z++)
               {
                   for(int p=7; p<29; p++)
                   {
                       gotoxy(z,p);
                       textbackground(*cor);
                       textcolor(*cor);
                       putchar(219);
                   }
               }
               escolha(material, cor, planodefun);
           }
     }
}
