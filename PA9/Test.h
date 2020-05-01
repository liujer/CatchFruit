#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include "utilityFunction.h"
#include "LoseScreen.h"
#include "Player.h"
#include "TopBar.h"
#include "Fruit.h"
#include "Apple.h"
#include "Galaxian.h"
#include "Strawberry.h"
#include "Melon.h"
#include "Key.h"
#include "Orange.h"
#include "Bananna.h"
#include "Bell.h"
#include <vector>

class TestBerry: public Fruit
{

public:
	TestBerry();
	void setSprite();
	void move();

};

void test_game();

void test_double_collision();

void test_double_miss();

void test_game_over();

void test_difficulty();

#endif // !TEST_H