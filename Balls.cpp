#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

//#define PI 3.14159265
#define PI 3.14159265358979323846

using namespace std;

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void setcolor (int fg, int bg) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),bg*16+fg);
}

struct ponto {
    float m;
    float px;
    float py;
    float vx;
    float vy;
    float ax;
    float ay;
};

ponto b1;
ponto b2;

int sleep = 100;
int vel = 500;

//cout<<"entre com angulo \n\n";
//cin>> g;

//yv = sin (( g * PI / 180.0 ) * v)*(-1);
//xv = cos (( g * PI / 180.0 ) * v)*(-1);

int main () {

        b1.m = 10;
        b2.m = 10;

        b1.px = 29;
        b1.py = 1;
        b1.vx = 5;
        b1.vy = 5;
        b1.ax = 0;
        b1.ay = 0;

        b2.px = 51;
        b2.py = 23;
        b2.vx = -5;
        b2.vy = -5;
        b2.ax = 0;
        b2.ay = 0;

        //pintar_mapa();
        //gotoxy(x+70,y+24); cout<<" ";
        //y= yI+yv*t+ya*(t*t)/2; //calcula y
        //x= x0+Sxv*t; //Calcula x

        while (true) {

            gotoxy(b1.px, b1.py);
            cout << " ";

            gotoxy(b2.px, b2.py);
            cout << " ";

            b1.vx += b1.ax * sleep / vel;
            b1.vy += b1.ay * sleep / vel;
            b1.px += b1.vx * sleep / vel;
            b1.py += b1.vy * sleep / vel;

            b2.vx += b2.ax * sleep / vel;
            b2.vy += b2.ay * sleep / vel;
            b2.px += b2.vx * sleep / vel;
            b2.py += b2.vy * sleep / vel;

            if (sqrt((b2.px-b1.px)*(b2.px-b1.px)+(b2.py-b1.py)*(b2.py-b1.py)) < 1.2) {
                float u1 = sqrt((b1.vx*b1.vx) + (b1.vy*b1.vy));
                float u2 = sqrt((b2.vx*b2.vx) + (b2.vy*b2.vy));
                float m1 = b1.m;
                float m2 = b2.m;
                float a1 = atan2(b1.vy, b1.vx);
                float a2 = atan2(b2.vy, b2.vx);
                //float v1 = (u1*(m1-m2) + (2*m2*u2))/(m1+m2);
                //float v2 = (u2*(m2-m1) + (2*m1*u1))/(m1+m2);
                float fi = atan2(b2.py - b1.py, b2.px - b1.px);

                b1.vx = (u1*cos(a1-fi)*(m1-m2)+2*m2*u2*cos(a2-fi))/
                    (m1+m2)*cos(fi)+u1*sin(a1-fi)*cos(fi+(PI/2));
                b1.vy = (u1*cos(a1-fi)*(m1-m2)+2*m2*u2*cos(a2-fi))/
                    (m1+m2)*sin(fi)+u1*sin(a1-fi)*sin(fi+(PI/2));
                b2.vx = (u2*cos(a2-fi)*(m2-m1)+2*m1*u1*cos(a1-fi))/
                    (m1+m2)*cos(fi)+u2*sin(a2-fi)*cos(fi+(PI/2));
                b2.vy = (u2*cos(a2-fi)*(m2-m1)+2*m1*u1*cos(a1-fi))/
                    (m1+m2)*sin(fi)+u2*sin(a2-fi)*sin(fi+(PI/2));
            }

            if (b1.px <= 0) {
                b1.vx = fabs(b1.vx);
            }
            if (b1.py <= 0) {
                b1.vy = fabs(b1.vy);
            }
            if (b1.px >= 80) {
                b1.vx = -fabs(b1.vx);
            }
            if (b1.py >= 25) {
                b1.vy = -fabs(b1.vy);
            }

            if (b2.px <= 0) {
                b2.vx = fabs(b2.vx);
            }
            if (b2.py <= 0) {
                b2.vy = fabs(b2.vy);
            }
            if (b2.px >= 80) {
                b2.vx = -fabs(b2.vx);
            }
            if (b2.py >= 25) {
                b2.vy = -fabs(b2.vy);
            }


            gotoxy(b1.px, b1.py);
            cout << (char)219;

            gotoxy(b2.px, b2.py);
            cout << (char)177;

            Sleep(sleep);
        }


        //t+=0.3; //Aumenta o tempo
        //gotoxy(x+7,y+24); //Vai para as cordenadas
        //setCColor(color[2]);
        //printf("%c",254); //Imprime o asterisco

//x = vx . cos
// y = yv . sen


    return 0;
}
