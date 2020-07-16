#include "olcPixelGameEngine.h"

class Actor
{
public:
    Actor()
    {
    }

    void DrawSelf(olc::PixelGameEngine* pge, int offset);
    void Move(std::string direction);

public:
    olc::vf2d position;

};
