#include "olcPixelGameEngine.h"
#include "Actor.h"


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class RogueLike : public olc::PixelGameEngine
{
  public:
    RogueLike()
    {
      sAppName = "Roguelike Tutorial";
    }
  public:
    bool OnUserCreate() override
    {
      // Called once at the start, so create things here
      return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {

      if (GetKey(olc::Key::RIGHT).bReleased) player.Move("right");
      if (GetKey(olc::Key::LEFT).bReleased) player.Move("left");
      if (GetKey(olc::Key::UP).bReleased) player.Move("up");
      if (GetKey(olc::Key::DOWN).bReleased) player.Move("down");

      Clear(olc::BLACK);

      // Draw the  player
      player.DrawSelf(this, OFFSET);
      return true;
    }
  public:
    int OFFSET = 8;
  protected:
    Actor player;
};

int main()
{
  RogueLike rogue;
  if (rogue.Construct(SCREEN_WIDTH, SCREEN_HEIGHT, 4, 4))
    rogue.Start();
  return 0;
}
