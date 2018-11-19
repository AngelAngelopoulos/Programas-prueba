#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

/* Ejemplo de scroll con paginacion*/
void generarteGrid(int numfil, int numcol, int  inicio);


int main()
{
    initwindow(800, 600, "prueba");
    char iletra;
    const int limiteizq = -300, limiteder = 300;
    int ix1 = 20, iy1 = 20, ix2 = 780, iy2 = 580;
    //setactivepage(0);
    setfillstyle(1, 15);
    bar(ix1, iy1, ix2, iy2);
    do
    {

        //setvisualpage(1);
        if (kbhit())
        {
            iletra = getch();

            if (iletra == 77)
            {
                cleardevice();
                setactivepage(0);
                setfillstyle(1, 15);
                bar(ix1, iy1, ix2, iy2);
                setfillstyle(1, 8);
                bar(ix1, iy1+200, ix2, iy2-200);
                setfillstyle(1, 9);
                rectangle(ix1, iy1+5, ix2, iy2+40);
                //generarteGrid(36, 10, ix1);
                setvisualpage(0);
                if (ix2 < 800+limiteder)
                {
                    ix1 += 10;
                    ix2 += 10;
                }
            }
            if (iletra == 75)
            {
                cleardevice();
                setactivepage(1);
                setfillstyle(1, 15);
                bar(ix1, iy1, ix2, iy2);
                setfillstyle(1, 6);
                bar(ix1, iy1+200, ix2, iy2-200);
                //generarteGrid(36, 10, ix1);
                setvisualpage(1);
                if (ix1 > 0+limiteizq)
                {
                    ix1 -= 10;
                    ix2 -= 10;
                }
            }
        }
        //setvisualpage(1);
        //setvisualpage(0);
    }while(1);
}

void generarteGrid(int numfil, int numcol, int inicio)
{
    int cont = 0;
    char scont[5];
    int x1 = inicio, x2 = 72 + inicio, y1 = 0, y2 = 72, carry = 0;
    setcolor(15);
    for (int i = 0; i < numcol; i++)
    {

        for (int j = 0; j < numfil; j++)
        {
            //delay(100);
            //setvisualpage(1);
            //impMini(ptrPix, 16 , 16, x1, y1);
            //setactivepage(0);

            //setvisualpage(0);
            //impMini(ptrPix, 24 , 24, x1, y1);
            //delay(100);
            //impMini(ptrPix, 24 , 24, x1, y1);
            //setvisualpage(1);
            //setactivepage(0);
            rectangle(x1, y1, x2, y2);
            //itoa(cont, scont, 10)
            sprintf(scont, "%d", cont);
            outtextxy(x1 + 20, y1+20, scont);
            //atoi(scont);
            x1 = x2;
            x2 += 72;
            cont ++;
        }
        x1 = 0;
        x2 = 72;
        y1 = y2;
        y2 += 72;
    }
}


