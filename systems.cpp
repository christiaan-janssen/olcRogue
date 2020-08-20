//
// Created by christiaan on 20-08-20.
//
#include "vendor/entt/include/entt.hpp"
#include "vendor/olc/include/olcPixelGameEngine.h"
#include "components.h"
#include "systems.h"

void move(entt::registry &registry) {
    registry.view<position, playerChar>().each([] (auto &pos) {
        pos.x += 1;
    });
}

void render(olc::PixelGameEngine *pge, entt::registry &registry) {
    registry.view<position, renderable>().each([pge] (auto &pos) {
        pge->DrawString(pos.x, pos.y, "@", olc::WHITE);
        if (pos.x > 256) {
            pos.x = 0;
        }
    });
}