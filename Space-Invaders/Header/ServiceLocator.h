#pragma once
class ServiceLocator
{
private:
    // Private Attributes:
    // - event_service: Manages event-related functionalities.
    // - graphic_service: Handles graphics-related tasks.
    // ..........................
    // ..........................

    // Private Constructor and Destructor:

    // Constructor for initializing the ServiceLocator.
    ServiceLocator();

    // Destructor for cleaning up resources upon object deletion.
    ~ServiceLocator();

    // Private Methods:
    void createServices(); 			// Creates instances of all services.
    void clearAllServices(); 		//	Deletes and deallocates memory for all services.

public:
    // Public Methods:
    static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

    void initialize(); 			//	Initializes the ServiceLocator.
    void update(); 				//	Updates all services.
    void render(); 				//	Renders using the services.

    // Methods to Get Specific Services: 
    //EventService* getEventService();   // Retrieve the EventService instance
    //GraphicService* getGraphicService();   // Retrieve the GraphicService instance

};
