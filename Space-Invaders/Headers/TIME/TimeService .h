#pragma once
//Capture the current time at the beginning of a frame
//Capture the current time again at the beginning of the next frame
//Calculate the delta time by subtracting the previous frame's start time from the current frame's start time.
//Update the current frame's start time to become the previous frame's start time so as to prepare for the next frame.
#include<chrono>

class  TimeService {
private:
	std::chrono::time_point<std::chrono::steady_clock> previous_time;

	float delta_time;//to store the value of delta time
	float calculate_delta_time();//calculate time by subtracting the previous time from the current time
	void updatePreviousTime(); // finally update the current time to be previous time
	void updateDeltaTime();
public:
	void update();
	void intialize();
	float getdeltatime();



};
