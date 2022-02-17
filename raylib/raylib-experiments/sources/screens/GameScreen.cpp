#include <iostream>

#include <Constants.hpp>
#include "GameScreen.hpp"
#include "Screens.hpp"

GameScreen::GameScreen()
{
    ldtkWorld = new ldtk::World();
    ldtkWorld->loadFromFile(AppConstants::GetAssetPath("world.ldtk"));

    current_level = 0;
    currentLdtkLevel = &ldtkWorld->getLevel(current_level);

    using namespace std;
    cout << "----------------------------------------------" << endl;
    cout << "Loaded LDTK map with " << ldtkWorld->allLevels().size() << " levels in it" << endl;
    cout << "The loaded level is " << current_level << " and it has " << currentLdtkLevel->allLayers().size() << " layers" << endl;
    auto tileLayerTileset = currentLdtkLevel->getLayer("Tiles").getTileset();
    cout << "The path to the tile layer tileset is: " << tileLayerTileset.path << endl;
    cout << "----------------------------------------------" << endl;

    player = new Player();
}

GameScreen::~GameScreen()
{
    delete ldtkWorld;
    delete player;
}

void GameScreen::draw()
{
    player->draw();
}

Screens GameScreen::update(float dt)
{
    player->update(dt);

    return NONE;
}
