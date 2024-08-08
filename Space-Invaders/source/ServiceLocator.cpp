
#include"../Headers/Global/ServiceLocator.h"
#include"../Headers/EVENT/EventService.h"
#include"../Headers/player/PlayerService.h"
#include"../Headers/TIME/TimeService .h"
#include"../Headers//Graphic/GraphicService.h"
#include"../Headers/main/GameService.h"
#include"../../Gameplay/GameplayService.H"


namespace Global {
	using namespace Main;
	using namespace Graphic;
	using namespace event;
	using namespace Gameplay;

	// Constructor: Initializes the graphic_service pointer to null and creates services.
	ServiceLocator::ServiceLocator() {
		graphic_service = nullptr;// Initialize graphic_service to null
		event_service = nullptr;
		player_service = nullptr;
		time_Service = nullptr;
		ui_service = nullptr;
		enemy_service =nullptr;
		game_play = nullptr;
		
		createServices(); // Call createServices to instantiate services
	}

	// Destructor: Cleans up resources by clearing all services.
	ServiceLocator::~ServiceLocator() {
		clearAllServices(); // Call clearAllServices to delete any allocated services	
	}

	// Creates service instances, specifically the graphic service in this case.
	void ServiceLocator::createServices() {
		graphic_service = new GraphicService(); // Dynamically create a GraphicService instance
		event_service = new EventService();

		player_service = new PlayerService();
		time_Service = new TimeService();
		ui_service = new UiService();
		enemy_service = new EnemyService();
		game_play = new GameplayService();
	}

	// Deletes allocated services to prevent memory leaks, specifically the graphic service.
	void ServiceLocator::clearAllServices() {
		delete(graphic_service); // Delete the graphic_service instance
		delete(event_service);
		delete(player_service);
		delete(time_Service);
		delete(ui_service);
		delete(enemy_service);
		delete(game_play);
		
	}

	// Returns a pointer to ServiceLocator.
	ServiceLocator* ServiceLocator::getInstance() {
		static ServiceLocator instance; 
		return &instance; // Return address of the instance
	}

	// Calls initialize on the graphic service, readying it for use.
	void ServiceLocator::initialize() {
		graphic_service->initialize(); // Initialize graphic service
		event_service->initialize();
		player_service->initialize();
		time_Service->intialize();
		ui_service->intialize();
		enemy_service->initialize();
		game_play->initialize();
	}

	// Updates the state of the graphic service.
	void ServiceLocator::update() {
		graphic_service->update(); // Update graphic service
		event_service->update();
		time_Service->update();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			game_play->update();
			player_service->update();
			enemy_service->update();
		
		}
		
		   ui_service->update();

	
		
	}


	// Renders using the graphic service.
	void ServiceLocator::render() {



		graphic_service->render(); // Render graphic service

		// Render graphic service

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			game_play->render();
			player_service->render();
			enemy_service->render();
			
		}  

		

		ui_service->render();
		
		
	}

	// Returns a pointer to the currently set graphic service.
	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	EventService* ServiceLocator::getEventService() {
		return event_service;
	}

	PlayerService* ServiceLocator::getplayerservice() {
		return player_service;
	}

	TimeService* ServiceLocator::gettimeservice()
	{
		return time_Service;
	}

	UiService* ServiceLocator::getUiservice()
	{
		return ui_service;
	}

	EnemyService* ServiceLocator::getenemyservice()
	{
		return enemy_service;
	}

	GameplayService* ServiceLocator::getgameplayservice()
	{
		return game_play;
	}

	

}

