#define OLC_PGE_APPLICATION

#include "vendor/olc/include/olcPixelGameEngine.h"
#include "vendor/entt/include/entt.hpp"
#include "components.h"
#include "systems.h"

class RogueLike : public olc::PixelGameEngine
{
public:
    RogueLike()
    {
        sAppName = "RogueLike";
    }

public:
    bool OnUserCreate() override
    {
        auto player = registry.create();
        registry.emplace<position>(player, 10, 10);
        registry.emplace<renderable>(player);
        registry.emplace<playerChar>(player);

        auto npc = registry.create();
        registry.emplace<position>(npc, 20, 20);
        registry.emplace<renderable>(npc);

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        // called once per frame
        Clear(olc::BLACK);
        move(registry);
        render(this, registry);
        return true;
    }

public:
    entt::registry registry;
};

int main() {
    RogueLike rogue;
    if (rogue.Construct(256, 240, 4, 4))
        rogue.Start();

    return 0;
}
