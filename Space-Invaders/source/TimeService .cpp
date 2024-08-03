#include"../Headers/TIME/TimeService .h"

float TimeService::calculate_delta_time()
{
	// Calculate time difference in microseconds between the current and previous frame.
	int delta = std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::steady_clock::now() - previous_time).count();

	// The cast is used to convert delta time from microseconds into seconds.
	// We will learn aboit how this works in detail later.
	return static_cast<float>(delta) / static_cast<float>(1000000);
}

void TimeService::updatePreviousTime()
{

	previous_time = std::chrono::steady_clock::now();
}

void TimeService::updateDeltaTime()
{
    delta_time = calculate_delta_time();
	updatePreviousTime();
    
}

void TimeService::update()
{
	updateDeltaTime();
}

void TimeService::intialize()
{
    previous_time = std::chrono::steady_clock::now();
	delta_time = 0;
}

float TimeService::getdeltatime()
{
    return delta_time;
}

