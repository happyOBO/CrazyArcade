#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "basic_setting.h"
#include "user.h"

class NPC {
private :
    int color;
    GLfloat npc_x;
    GLfloat npc_y;
    int move_term;
    Water_balloon balloon;
public :
    NPC(GLfloat x, GLfloat y);
    void draw_NPC();
    void Auto_Move(User usr);
    void Draw_My_balloon();
    void Pop_My_balloon();
    void Auto_balloon();
};
#endif // NPC_H_INCLUDED
