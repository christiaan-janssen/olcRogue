#include "olcPixelGameEngine.h"
#include "Actor.h"


olc::vf2d position = {1, 1};

void Actor::DrawSelf(olc::PixelGameEngine* pge, int offset)
{
  pge->DrawString(position.x*offset, position.y*offset, "@", olc::WHITE);
}

void Actor::Move(std::string direction) {
  if (direction == "right" ) position.x += 1;
  if (direction == "left" ) position.x -= 1;
  if (direction == "down" ) position.y += 1;
  if (direction == "up" ) position.y -= 1;
}
