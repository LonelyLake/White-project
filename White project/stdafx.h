#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>


#include "Game.h"
#include "Menu.h"
#include "Player.h"
#include "Level.h"
#include "Map.h"
#include "Tile.h"
#include "Item.h"
#include "Coin.h"
#include "Heart.h"

using namespace sf;
using namespace std;

class stdafx
{
};

template <typename T>
constexpr T clamp(T value, T min, T max) {
    return std::max(min, std::min(value, max));
}

