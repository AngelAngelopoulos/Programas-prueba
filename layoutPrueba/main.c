#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define SIZEM 60

typedef struct
{
    int nFil;  //Guarda el numero de filas
    int nCol; //Guarda el numero de columnas
    int ix;  //Variable que guarda el valor de la coordenada X
    int iy;  //Variable que guarda el valor de la coordenada Y
    int iColor;  //Variable que guarda el color de la coordenada (X, Y)
}PIX;  //Estructura del pixel

void generarteGrid(PIX **ptrPix, int, int);
int asignaMem(PIX ***ptrArr, int n, int m);
void impMini(PIX **ptrArr, int n, int m, int x1, int aux);
void liberaMem(PIX **ptrArr, int n, int m);
void leerArch(PIX **ptrPixel, int n, int m, char Name[]);
void save_screen(void *buf[1], int maxx, int maxy);
void restore_screen(void *buf[1], int maxx, int maxy, int ix);
void generarteBackG(PIX **ptrPix, int numcol, int numfil);




int main()
{
    initwindow(800, 600, "Layout");

    PIX **ptrPix;
    PIX **texture;
    int res;
    void *ptr[4], *ptr2[4];
    char iletra;
    int ix = 0;
    //initwindow(800, 600, "");
    res = asignaMem(&texture, 12, 12);
    leerArch(texture, 12, 12, "tierra.dat");
    res = asignaMem(&ptrPix, 16, 16);
    leerArch(ptrPix, 16, 16, "mario.dat");
    outtextxy(200, 300, "Cargando...");
    setactivepage(1);
    setvisualpage(0);
    generarteBackG(texture, 9, 12);
    save_screen(ptr2, 800, 600);
    generarteGrid(ptrPix, 1 ,1);
    setvisualpage(1);
    //setactivepage(0);
    //setvisualpage(1);
    //impMini(ptrPix, 24, 24);
    liberaMem(ptrPix, 16, 16);
    save_screen(ptr, 72, 72);
    /*getch();
    restore_screen(ptr, 72, 72, 100);
    getch();
    cleardevice();
    restore_screen(ptr, 72, 72, 50);
    //getch();*/
    ix = 20;
    do {
        if (kbhit()){
            iletra = getch();
            switch (iletra)
            {
                case 77:
                    cleardevice();
                    restore_screen(ptr2, 800, 600, 0);

                    restore_screen(ptr, 72, 72, ix);
                    ix += 20;
                    break;

                case 75:
                    cleardevice();
                    restore_screen(ptr2, 800, 600, 0);

                    restore_screen(ptr, 72, 72, ix);
                    ix -= 20;
                    break;
            }
        }
        //restore_screen(ptr, 72, 72, ix);
    }while(1);
    //generarteGrid(NULL, 36, 10);

getch();
}


void generarteGrid(PIX **ptrPix, int numfil, int numcol)
{
    int cont = 0;
    char scont[5];
    int x1 = 0, x2 = 72, y1 = 0, y2 = 72, carry = 0;
    setcolor(15);
    for (int i = 0; i < numcol; i++)
    {

        for (int j = 0; j < numfil; j++)
        {
            //delay(100);
            //setvisualpage(1);
            impMini(ptrPix, 16 , 16, x1, y1);
            //setactivepage(0);

            //setvisualpage(0);
            //impMini(ptrPix, 24 , 24, x1, y1);
            //delay(100);
            //impMini(ptrPix, 24 , 24, x1, y1);
            //setvisualpage(1);
            //setactivepage(0);
            //rectangle(x1, y1, x2, y2);
            //itoa(cont, scont, 10)
            //sprintf(scont, "%d", cont);
            //outtextxy(x1 + 20, y1+20, scont);
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


void generarteBackG(PIX **ptrPix, int numcol, int numfil)
{
    int cont = 0;
    char scont[5];
    int x1 = 0, x2 = 72, y1 = 0, y2 = 72, carry = 0;
    setcolor(15);
    for (int i = 0; i < numfil; i++)
    {

        for (int j = 0; j < numcol; j++)
        {
            //delay(100);
            //setvisualpage(1);
            impMini(ptrPix, 12 , 12, x1, y1);
            //setactivepage(0);

            //setvisualpage(0);
            //impMini(ptrPix, 24 , 24, x1, y1);
            //delay(100);
            //impMini(ptrPix, 24 , 24, x1, y1);
            //setvisualpage(1);
            //setactivepage(0);
            //rectangle(x1, y1, x2, y2);
            //itoa(cont, scont, 10)
            //sprintf(scont, "%d", cont);
            //outtextxy(x1 + 20, y1+20, scont);
            //atoi(scont);
            y1 = y2;
            y2 += 72;
            cont ++;
        }
        y1 = 0;
        y2 = 72;
        x1 = x2;
        x2 += 72;
    }
}

void impMini(PIX **ptrArr, int n, int m, int x1, int aux)
{
    int tamDispx = 72;
    int tamDispy = 72, cont = 0;
    //int x1, x2, y1, y2,
    int i, j, x2 = 0, y2 = 0, y1 = 0;
    //int x1 = 0;
    x2 = x1 + (tamDispx/n) , y2 = y1 + (tamDispy/m)+aux;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            y1 = y2;
            y2 = y1+(tamDispy/m);
            if ((*(ptrArr+i)+j)->iColor != 0){
            //setcolor(15);
            setfillstyle(1,(*(ptrArr+i)+j)->iColor);
            if (x1 == 0)
                printf("%d \n", (*(ptrArr+i)+j)->iColor);
            //setactivepage(cont)
            bar(x1, y1, x2, y2);
            //floodfill(x1+1, y1+1, 15);
            }
        }
        x1 = x2;
        x2 = x1+ (tamDispx/n);
        y1 = aux;
        y2 = y1 +(tamDispy/m);
    }
}

int asignaMem(PIX ***ptrArr, int n, int m)
{
    int res = 0, i = 0;

    *ptrArr = (PIX**)malloc(sizeof(PIX*)*m);

    if (*ptrArr != NULL)
    {
        res = 1;

        for (i = 0; i < n; i++)
        {
            *(*ptrArr+i) = (PIX*)malloc(sizeof(PIX)*m);

            if (*(*ptrArr+i) == NULL)
            {
                while (--i > 0)
                {
                    free(*(*ptrArr+i));
                }
                free(*ptrArr);
                res = 0;
            }
        }
    }
    return(res);
}

void liberaMem(PIX **ptrArr, int n, int m)
{
    int i;
    for(i = m; i > m; i--)
    {
        free((*ptrArr+i));
    }
    free(*ptrArr);
}

void leerArch(PIX **ptrPixel, int n, int m, char Name[])
{
    FILE *arch;
    arch = fopen(Name, "rb+");

    if (arch)
    {
        for (int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j++)
            {
                fread(&(*(ptrPixel+i)+j)->nFil, sizeof(int), 1, arch);
                fread(&(*(ptrPixel+i)+j)->nCol, sizeof(int), 1, arch);
                fread(&(*(ptrPixel+i)+j)->ix, sizeof(int), 1, arch);
                printf("X: %d ", (*(ptrPixel+i)+j)->ix);
                fread(&(*(ptrPixel+i)+j)->iy, sizeof(int), 1, arch);
                printf("Y: %d ", (*(ptrPixel+i)+j)->iy);
                fread(&(*(ptrPixel+i)+j)->iColor, sizeof(int), 1, arch);
                printf("Color: %d \n", (*(ptrPixel+i)+j)->iColor);
            }
        }
    }
    fclose(arch);
}



void save_screen(void *buf[4], int maxx, int maxy)

{

   unsigned size;

   int ystart=0, yend, yincr, block;

   yincr = (maxy+1) / 4;

   yend = yincr;



   /* get byte size of image */

   size = imagesize(0, ystart, maxx, yend);

   for (block=0; block<=4; block++) {

      if ((buf[block] = malloc(size)) == NULL) {

         closegraph();

         printf("Error: not enough heap space in save_screen().\n");

         exit(1);

      }

     getimage(0, ystart, maxx, yend, buf[block]);



     ystart = yend + 1;

     yend += yincr + 1;

   }

}



void restore_screen(void *buf[4], int maxx, int maxy, int ix)

{

   int ystart=0, yend, yincr, block;

   yincr = (maxy+1) / 4;

   yend = yincr;

   for (block=0; block<=4; block++) {

      putimage(ix, ystart, buf[block], COPY_PUT);

      //free(buf[block]);

      ystart = yend + 1;



      yend += yincr + 1;

   }

}
