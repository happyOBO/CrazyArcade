#ifndef WATER_BALLOON_H_INCLUDED
#define WATER_BALLOON_H_INCLUDED

#include "basic_setting.h"

class One_balloon
{
private:
    GLfloat ball_x;
    GLfloat ball_y;
public:
    int time;
    int pop_time;
    One_balloon(GLfloat x,GLfloat y);
    pair<GLfloat, GLfloat> get_ball_idx();
};

class Water_balloon
{
private:
    int balloon_color;
    int max_balloons;
    int water_steams;
    vector< One_balloon> ball_vector;
    vector< One_balloon> pop_ball_vector;
public:
    Water_balloon();
    void Init(int color);
    void Pop_balloon();
    void Draw_balloon();
    void add_balloon(GLfloat idx_x, GLfloat idx_y);
};

#endif // WATER_BALLOON_H_INCLUDED
