#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

float ax,ay,bx,by,cx,cy;
float tx,ty,tz;
float sx,sy,sz;
float angulo,rx,ry,rz;

float cisalha,vertice;
float shearingX, shearingY;

void inicio(){
    glClearColor(0,0,0,0);
}
void desenha(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
            //A RED
            glColor3f(1.0,0.0,.0);
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

void desenhaTranslada(){
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0f, 0.0f, 0.0f);
     //glTranslatef(0.4f, 0.7f, 1.0f);
     glTranslatef(tx, ty, tz);

     glBegin(GL_TRIANGLES);
               glVertex2f(ax,ay);
               glVertex2f(bx,by);
               glVertex2f(cx,cy);
     glEnd();
     glFlush();
}

void desenhaEscalado(){
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0f, 0.0f, 0.0f);
     //glScalef(1.7f, 1.7f, 1.7f);
     glScalef(sx, sy, sz);

     glBegin(GL_TRIANGLES);
               glVertex2f(ax,ay);
               glVertex2f(bx,by);
               glVertex2f(cx,cy);
     glEnd();
     glFlush();
}

void desenhaRotacionado(){
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0f, 0.0f, 0.0f);
     //glRotatef(45.0f,1.0f,0.0f,0.0f);
     glRotatef(angulo,rx,ry,rz);
     glBegin(GL_TRIANGLES);
               glVertex2f(ax,ay);
               glVertex2f(bx,by);
               glVertex2f(cx,cy);
     glEnd();
     glFlush();
}

void desenhaCisalhando(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	if (cisalha == 8){
            if(vertice == 1){
                glVertex2f(ax + shearingX, ay);
                glVertex2f(bx, by);
                glVertex2f(cx, cy);
            }else if(vertice == 2){
                glVertex2f(ax, ay);
                glVertex2f(bx + shearingX, by);
                glVertex2f(cx, cy);
            }else if(vertice ==3){
                glVertex2f(ax, ay);
                glVertex2f(bx, by);
                glVertex2f(cx + shearingX, cy);
            }
	}else if (cisalha == 7){
	    if(vertice == 1){
            glVertex2f(ax, ay + shearingY);
            glVertex2f(bx, by);
            glVertex2f(cx, cy);
	    }else if(vertice == 2){
	        glVertex2f(ax, ay);
            glVertex2f(bx, by + shearingY);
            glVertex2f(cx, cy);
	    }else if(vertice ==3){
	        glVertex2f(ax, ay);
            glVertex2f(bx, by);
            glVertex2f(cx, cy + shearingY);
	    }
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv){

    float abx, aby, acx, acy, bcx, bcy;
    float ladoab, ladoac, ladobc;
    float ac, bc;

    printf("Insira os valores nos vertices: \n");
    printf("ax: ");
    scanf("%f",&ax);
    printf("ay: ");
    scanf("%f",&ay);
    printf("bx: ");
    scanf("%f",&bx);
    printf("by: ");
    scanf("%f",&by);
    printf("cx: ");
    scanf("%f",&cx);
    printf("cy: ");
    scanf("%f",&cy);

    abx = ax - bx;
    aby = ay - by;
    ladoab = sqrt(abx*abx + aby*aby);
    printf(" LADO AB %f\n", ladoab);

    acx = ax - cx;
    acy = ay - cy;
    ac = sqrt(acx*acx + acy*acy);
    //ladoac = floor(ac * 10.0f) / 10.0f;
    ladoac = ceil(ac * 10.0f)/10.0f;
    printf(" LADO AC %f\n", ladoac);

    bcx = bx - cx;
    bcy = by - cy;
    bc = sqrt(bcx*bcx + bcy*bcy);
    //ladobc = floor(bc * 10.0f) / 10.0f;
    ladobc = ceil(bc * 10.0f)/10.0f;
    printf(" LADO BC %f\n", ladobc);

    int efeito = 0;
        printf("1 - Normal\n");
        printf("2 - Transladar\n");
        printf("3 - Rotacionar\n");
        printf("4 - Escalar\n");
        printf("5 - Cisalhamento\n");
        printf("0 - Sair\n");
        printf("Digite o numero do efeito desejado: ");
        scanf("%d", &efeito);

        switch (efeito){
            case 1:
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

                    }else if (ladoab != ladoac && ladoac != ladobc && ladobc != ladoab){
                        glutInit(&argc,argv);
                        glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
                        glutInitWindowPosition(100,100);
                        glutInitWindowSize(640,480);
                        glutCreateWindow("TRIANGULO ESCALENO");
                    }else
                        printf ("Valores invalidos para formar um triangulo");
                }
                inicio();
                glutDisplayFunc(desenha);
                glutMainLoop();


            case 2:
                printf("Insira os valores nos eixos: \n");
                printf("tx: ");
                scanf("%f",&tx);
                printf("ty: ");
                scanf("%f",&ty);
                printf("tz: ");
                scanf("%f",&tz);
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

                    }else if (ladoab != ladoac && ladoac != ladobc && ladobc != ladoab){
                        glutInit(&argc,argv);
                        glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
                        glutInitWindowPosition(100,100);
                        glutInitWindowSize(640,480);
                        glutCreateWindow("TRIANGULO ESCALENO");
                    }else
                        printf ("Valores invalidos para formar um triangulo");
                }
                inicio();
                glutDisplayFunc(desenhaTranslada);
                glutMainLoop();
                break;


            case 3:
                printf("Insira os valores no angulo e nos eixos: \n");
                printf("angulo: ");
                scanf("%f",&angulo);
                printf("rx: ");
                scanf("%f",&rx);
                printf("ry: ");
                scanf("%f",&ry);
                printf("rz: ");
                scanf("%f",&rz);
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

                    }else if (ladoab != ladoac && ladoac != ladobc && ladobc != ladoab){
                        glutInit(&argc,argv);
                        glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
                        glutInitWindowPosition(100,100);
                        glutInitWindowSize(640,480);
                        glutCreateWindow("TRIANGULO ESCALENO");
                    }else
                        printf ("Valores invalidos para formar um triangulo");
                }
                inicio();
                glutDisplayFunc(desenhaRotacionado);
                glutMainLoop();
                break;


            case 4:
                printf("Insira os valores nos eixos: \n");
                printf("sx: ");
                scanf("%f",&sx);
                printf("sy: ");
                scanf("%f",&sy);
                printf("sz: ");
                scanf("%f",&sz);
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

                    }else if (ladoab != ladoac && ladoac != ladobc && ladobc != ladoab){
                        glutInit(&argc,argv);
                        glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
                        glutInitWindowPosition(100,100);
                        glutInitWindowSize(640,480);
                        glutCreateWindow("TRIANGULO ESCALENO");
                    }else
                        printf ("Valores invalidos para formar um triangulo");
                }
                inicio();
                glutDisplayFunc(desenhaEscalado);
                glutMainLoop();
                break;


            case 5:
                printf("Informe o eixo de cisalhamento 8(x) ou 7(y): \n");
                scanf("%f", &cisalha);
                printf("Qual vertice do triangulo deve ser cisalhado: 1(a), 2(b) ou 3(c)? \n");
                scanf("%f", &vertice);
                if (cisalha == 8){
                        printf("Insira o valor do cisalhamento x: \n");
                        scanf("%f", &shearingX);
                }else{
                        printf("Insira o valor do cisalhamento Y: \n");
                        scanf("%f", &shearingY);
                }
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

                    }else if (ladoab != ladoac && ladoac != ladobc && ladobc != ladoab){
                        glutInit(&argc,argv);
                        glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
                        glutInitWindowPosition(100,100);
                        glutInitWindowSize(640,480);
                        glutCreateWindow("TRIANGULO ESCALENO");
                    }else
                        printf ("Valores invalidos para formar um triangulo");
                }
                inicio();
                glutDisplayFunc(desenhaCisalhando);
                glutMainLoop();
                break;

            case 0:
                printf("Nenhum efeito aplicado!");
                break;
        }
}
