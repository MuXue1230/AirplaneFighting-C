#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SDL.h>

class Config {
public:
	Config(std::string config_name, std::string assets_path);
	bool init();
	bool reload();
	bool write();
	void get_screen_size(SDL_DisplayMode*);
	void set_config(std::string key, std::string value);
	std::string get_config(std::string key);
private:
	std::string config_name;
	std::string assets_path;
	std::string config_str;
	std::string config[7][2] = {
		{"version","1.0.0"},
		{"language","zh_cn"},
		{"music","1"},
		{"mix","1"},
		{"screen_width","0"},
		{"screen_height","0"},
		{"record","0"},
	};
	std::ifstream config_file;
	std::string last[7][2] = {
		{"version","1.0.0"},
		{"language","zh_cn"},
		{"music","1"},
		{"mix","1"},
		{"screen_width","0"},
		{"screen_height","0"},
		{"record","0"},
	};
};
