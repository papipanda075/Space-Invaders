#pragma one
#include<SFML/Graphics.hpp>
#include"PlayerModel.h"
#include"PlayerView.h"

class PlayerController {

private:

	PlayerModel* model;
	PlayerView* view;


	void processinput();
	void processmoveleft();
	void processmoveright();
public:
	PlayerController();
	~PlayerController();
	void intialize();
	void update();
	void render();

	


	sf::Vector2f getPlayerPosition();

};
