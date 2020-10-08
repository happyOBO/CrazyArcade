#include "water_balloon.h"

One_balloon::One_balloon(GLfloat x,GLfloat y) : ball_x(x), ball_y(y)
{
    time = 1500;
    pop_time = 500;
}

pair<GLfloat, GLfloat> One_balloon::get_ball_idx()
{
    return make_pair(ball_x,ball_y);
}

Water_balloon::Water_balloon()
{
    max_balloons = 3;
    water_steams = 2;
}
void Water_balloon::Init(int color)
{
    balloon_color = color;
}
void Water_balloon::Draw_balloon()
{
    for(int i = 0; i<ball_vector.size(); i++)
    {
        if( ball_vector.front().time < 0 )
        {
            pop_ball_vector.push_back(ball_vector.front());
            ball_vector.erase(ball_vector.begin());
        }
        else break;
    }

    for(int i = 0; i<ball_vector.size(); i++)
    {
        pair<GLfloat,GLfloat> ball_idx = ball_vector[i].get_ball_idx();
        ball_vector[i].time -= 1;
        GLfloat ball_x = ball_idx.first;
        GLfloat ball_y = ball_idx.second;
        glPushMatrix(); //push orgin view
        glTranslatef(ball_x,ball_y,0.0); //translate as much as keyboard callback
        float ColorArray[4] = {0,};
        ColorArray[balloon_color] = 0.8;
        //draw balloon
        glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        glScalef(1.0,1.0,1.0);
        glColor3f(ColorArray[0],ColorArray[1],ColorArray[2]);
        glutSolidSphere(x * 1.4,100,30);
        glPopMatrix();
        glPopMatrix(); // Eliminate translate view

    }


}

void Water_balloon::Pop_balloon()
{
    for(int i = 0; i<pop_ball_vector.size(); i++)
    {
        if( pop_ball_vector.front().pop_time < 0 )
        {
            pop_ball_vector.erase(pop_ball_vector.begin());
        }
        else break;
    }

    for(int i = 0; i<pop_ball_vector.size(); i++)
    {
        pair<GLfloat,GLfloat> ball_idx = pop_ball_vector[i].get_ball_idx();
        pop_ball_vector[i].pop_time -= 1;
        GLfloat idx_x = ball_idx.first;
        GLfloat idx_y = ball_idx.second;
        float ColorArray[4] = {0.5,0.5,0.5};
        ColorArray[balloon_color] = 0.9;
        //draw balloon
        glPushMatrix();
            glTranslatef(idx_x,idx_y,0.0);
            glPushMatrix();
                glColor3f(ColorArray[0],ColorArray[1],ColorArray[2]);
                glutSolidCube(2.5 * x);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(1.0,0.0,0.0);
                glColor3f(ColorArray[0],ColorArray[1],ColorArray[2]);
                glutSolidCube(2.5 * x);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-1.0,0.0,0.0);
                glColor3f(ColorArray[0],ColorArray[1],ColorArray[2]);
                glutSolidCube(2.5 * x);
            glPopMatrix();
                    glPushMatrix();
                glTranslatef(0.0,1.0,0.0);
                glColor3f(ColorArray[0],ColorArray[1],ColorArray[2]);
                glutSolidCube(2.5 * x);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,-1.0,0.0);
                glColor3f(ColorArray[0],ColorArray[1],ColorArray[2]);
                glutSolidCube(2.5 * x);
            glPopMatrix();
        glPopMatrix();

    }

}

void Water_balloon::add_balloon(GLfloat idx_x, GLfloat idx_y)
{
    if(max_balloons > ball_vector.size())
    {
        One_balloon new_ball = One_balloon(idx_x, idx_y);
        ball_vector.push_back( new_ball);
    }
}

void Water_balloon::Auto_balloon(GLfloat idx_x, GLfloat idx_y)
{
    if(max_balloons > ball_vector.size())
    {
        for(int i = 0; i < ball_vector.size(); i++)
        {
            pair<GLfloat,GLfloat> ball_idx = ball_vector[i].get_ball_idx();
            if(ball_idx.first == idx_x || ball_idx.second == idx_y)
            {
                return;
            }
        }
        One_balloon new_ball = One_balloon(idx_x, idx_y);
        ball_vector.push_back( new_ball);
    }
}
