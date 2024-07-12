#include<SFML/Graphics.hpp>
#include<iostream>
#include"Header/GameService.h"
using namespace std;
int main() {

	GameService gameservice;
	gameservice.ignite();
	gameservice.update();
	gameservice.render();
}