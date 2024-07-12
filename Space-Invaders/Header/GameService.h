#pragma once

class GameService {

private:
	void initlaize();
	void destroy();

public:

	GameService();
	~GameService();
	

	void ignite();
	void update();
	void render();
	bool isRunning();
};