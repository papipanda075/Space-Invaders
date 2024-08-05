#include "MainMenuUIController.h"
#include"../../Headers/main/GameService.h"
#include"../../Headers/Global/ServiceLocator.h"
#include"../../Headers/Graphic/GraphicService.h"
namespace UI {

	namespace MainMenu {

		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace event;

		void MainMenuUI::initializeBackgroundImage()
		{
			if (background_texture.loadFromFile(background_texture_path))
			{
				background_sprite.setTexture(background_texture);
				scaleBackgroundImage();
			}
		}

		void MainMenuUI::scaleBackgroundImage()
		{
			background_sprite.setScale(

				static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
				static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
			);
		}

		void MainMenuUI::initializeButtons()
		{
			if (loadButtonTexturesFromFile())
			{
				// order of function calls matter
				setButtonSprites();
				scaleAllButttons();
				positionButtons();
			}
		}

		bool MainMenuUI::loadButtonTexturesFromFile()
		{
			return play_button_texture.loadFromFile(play_button_texture_path)
				&& instructions_button_texture.loadFromFile(instructions_button_texture_path)
				&& quit_button_texture.loadFromFile(quit_button_texture_path);
		}

		void MainMenuUI::setButtonSprites()
		{
			play_button_sprite.setTexture(play_button_texture);
			instructions_button_sprite.setTexture(instructions_button_texture);
			quit_button_sprite.setTexture(quit_button_texture);
		}

		void MainMenuUI::scaleAllButttons()
		{
			scaleButton(&play_button_sprite);
			scaleButton(&instructions_button_sprite);
			scaleButton(&quit_button_sprite);
		}

		void MainMenuUI::scaleButton(sf::Sprite* button_to_scale)
		{
			button_to_scale->setScale(
				button_width / button_to_scale->getTexture()->getSize().x,
				button_height / button_to_scale->getTexture()->getSize().y

			);
		}

		void MainMenuUI::positionButtons()
		{
			float xposition = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
			play_button_sprite.setPosition(xposition, 500);
			instructions_button_sprite.setPosition(xposition,700);
			quit_button_sprite.setPosition(xposition, 900);
		}

		UI::MainMenu::MainMenuUI::MainMenuUI()
		{
			game_window = nullptr;
		}

		UI::MainMenu::MainMenuUI::~MainMenuUI()
		{

		}

		void UI::MainMenu::MainMenuUI::intialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeButtons();
			initializeBackgroundImage();

		}

		void UI::MainMenu::MainMenuUI::update()
		{
			processButtonInteractions();

		}

		void UI::MainMenu::MainMenuUI::render()
		{

			game_window->draw(background_sprite);
			game_window->draw(play_button_sprite);
			game_window->draw(instructions_button_sprite);
			game_window->draw(quit_button_sprite);
		}
		void MainMenuUI::processButtonInteractions()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));
			if (clickedButton(&play_button_sprite, mouse_position)) {
				GameService::setGameState(GameState::GAMEPLAY);
			}

			if (clickedButton(&instructions_button_sprite, mouse_position))
			{
				printf("Clicked Instruction Button \\n");
			}
			if (clickedButton(&quit_button_sprite, mouse_position))
				game_window->close();

		}
		bool MainMenuUI::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
		{

			EventService* event_service = ServiceLocator::getInstance()->getEventService();
			return  event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
		}
	}
}