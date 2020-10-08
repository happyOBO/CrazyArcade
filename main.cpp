/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include "water_balloon.h"
#include "user.h"
#include "npc.h"


User usr(0.0,0.0);
NPC np1(5.0, 5.0); // call class npc


void Draw_Wallpaper()
{

}

void Draw_grid()
{
    for(float i = - width ; i< width ;i += 1.0)
    {
        glPushMatrix();
            glBegin(GL_LINES);
            glColor3f(1.0,1.0,0.5);
            glVertex3f(0.5 + i,10.0,0.0);
            glVertex3f(0.5 + i,-10.0,0.0);
            glEnd();
        glPopMatrix();
    }
    for(float i = - width ; i< width ;i += 1.0)
    {
        glPushMatrix();
            glBegin(GL_LINES);
            glColor3f(1.0,1.0,0.5);
            glVertex3f(10.0,0.5 + i,0.0);
            glVertex3f(-10.0,0.5 + i,0.0);
            glEnd();
        glPopMatrix();
    }
}
void changeColor()
{
    srand((unsigned int)time(0));
    for(int i = 2;i<10;i++)
    {
        for(int j = 0; j< 3; j++)
            pallet[i][j] = (float)(rand()%256)/256;
    }
}

void Idlefunc()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Draw_grid();
    np1.Auto_Move(usr);
    np1.Draw_My_balloon();
    np1.Pop_My_balloon();
    np1.Auto_balloon();
    usr.Draw_My_balloon();
    usr.Pop_My_balloon();
    np1.draw_NPC();
    usr.DrawChar();
    glFlush();

    glutPostRedisplay();
}


void MyKeyboard(unsigned char key, int p, int k) {
    pair<GLfloat,GLfloat> loc = usr.Return_loc();
    GLfloat x_location = loc.first;
    GLfloat y_location = loc.second;
 switch (key) {
 case 'd':
     if(x_location < width - x)
        usr.move_user(1,0);
    break;
 case 'a':
     if(x_location > -1.0 * width + x)
         usr.move_user(-1,0);
    break;
 case 'w':
     if(y_location < width - x)
        usr.move_user(0,1);
    break;
 case 's':
     if(y_location > -1.0 * width + x)
         usr.move_user(0,-1);
     break;
 case 32 :
     usr.add_balloon();
//     np1.touch_NPC(usr);
//    np2.touch_NPC();
//    np3.touch_NPC();
    break;
 default:
     break;

 }
 glutPostRedisplay();
}



int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Crazy Arcade");
    srand((unsigned int)time(0));
    for(int i = 0;i<10;i++)
    {
        for(int j = 0; j< 3; j++)
            pallet[i][j] = (float)(rand()%256)/256;
    }

    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-8.0,8.0,-8.0,8.0,-5.0,5.0);
    glutDisplayFunc(Draw_Wallpaper);
    glutIdleFunc(Idlefunc);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}
