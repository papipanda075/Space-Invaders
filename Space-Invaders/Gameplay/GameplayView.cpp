#include "GameplayView.H"
#include"../../Headers/Global/ServiceLocator.h"
#include"../../Headers/Graphic/GraphicService.h";

namespace Gameplay {

	using namespace Global;
	using namespace Graphic;
	Gameplay::GameplayView::GameplayView()
	{
	}

	Gameplay::GameplayView::~GameplayView()
	{
	}

	void GameplayView::initalizebackgroundsprite()
	{
		if (background_texture.loadFromFile(background_texture_path)) {
			background_sprite.setTexture(background_texture);
			scaleBackgroundSprite();
		}
	}

	void GameplayView::scaleBackgroundSprite()
	{

		background_sprite.setScale(static_cast<float> (game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float> (game_window->getSize().y) / background_sprite.getTexture()->getSize().y);



	}

	void Gameplay::GameplayView::initialize()
	{

		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initalizebackgroundsprite();
	}

	void Gameplay::GameplayView::update()
	{
	}

	void Gameplay::GameplayView::render()
	{
		game_window->draw(background_sprite);
	}
}