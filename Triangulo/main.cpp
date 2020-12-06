#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ax,ay,bx,by,cx,cy;

void inicio(){
    glClearColor(0,0,0,0);
}
void desenha(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gluOrtho2D(-1,1,-1,1);
        glBegin(GL_TRIANGLES);
            //A RED
            glColor3f(1.0,0.0,0.0);
            glVertex2f(ax,ay);
            //B GREEN
            glColor3f(0.0,1.0,0.0);
            glVertex2f(bx,by);
            //C BLUE
            glColor3f(0.0,0.0,1.0);
            glVertex2f(cx,cy);
        glEnd();
        glFlush();
}

int main(int argc, char** argv){

    float abx, aby, acx, acy, bcx, bcy;
    float ladoab, ladoac, ladobc;


    printf("Insira os valores nos vertices: \n");
    printf("ax,ay: ");
    scanf("%f %f",&ax, &ay);
    printf("bx,by: ");
    scanf("%f %f",&bx,&by);
    printf("cx,cy: ");
    scanf("%f %f",&cx,&cy);

    abx = ax - bx;
    aby = ay - by;
    ladoab = sqrt( abx*abx + aby*aby);
    printf("%f\n", ladoab);

    acx = ax - cx;
    acy = ay - cy;
    ladoac = sqrt(acx*acx + acy*acy);
    printf("%f\n", ladoac);

    bcx = bx - cx;
    bcy = by - cy;
    ladobc = sqrt(bcx*bcx + bcy*bcy);
    printf("%f\n", ladobc);

    if (ladoab + ladoac > ladobc && ladoab + ladobc > ladoac && ladoac + ladobc > ladoab){
        if (ladoab == ladoac && ladoac == ladobc){
            glutInit(&argc,argv);
            glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
            glutInitWindowPosition(100,100);
            glutInitWindowSize(640,480);
            glutCreateWindow("TRIANGULO EQUILATERO");

        }else if (ladoab == ladoac || ladoac == ladobc || ladobc == ladoab){
            glutInit(&argc,argv);
            glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
            glutInitWindowPosition(100,100);
            glutInitWindowSize(640,480);
            glutCreateWindow("TRIANGULO ISOSCELES");

        }else /*if (ladoab != ladoac && ladoac != ladobc && ladobc != ladoab)*/{
            glutInit(&argc,argv);
            glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
            glutInitWindowPosition(100,100);
            glutInitWindowSize(640,480);
            glutCreateWindow("TRIANGULO ESCALENO");
        }
    }else
        printf ("Valores invalidos para formar um triangulo");

    inicio();
    glutDisplayFunc(desenha);
    glutMainLoop();
}
