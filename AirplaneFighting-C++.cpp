#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

#include "Logger.h"
#include "Config.h"

int main(int argc, char** argv)
{
	// Create Logger
	Logger *logger = new Logger("log");

	// Load configure
	//logger->log("Load configure");
	logger->debug("Create configure class");
	Config* config = new Config("config.json","assets/");
	logger->debug("Init configure class");
	config->init();
	return 0;
}