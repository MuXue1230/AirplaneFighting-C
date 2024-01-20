#include "Config.h"

Config::Config(std::string config_name, std::string assets_path) {
	this->config_name = config_name;
	this->assets_path = assets_path;
}

bool Config::init()
{
	std::string config_str;
	std::string temp;
	std::string key_temp;
	std::stringstream buffer;
	char        chartemp;
	bool        is_key = true;
	bool        is_string = false;
	this->config_file.open(this->config_name,std::ios::in);
	buffer << this->config_file.rdbuf();
	this->config_file.close();
	this->config_str = buffer.str();
	for (int i = 0; i < this->config_str.length(); i++) {
		chartemp = this->config_str[i];
		if (chartemp == ':') {
			is_key = false;
		}
		else if (chartemp == ',') {
			is_key = true;
		}
		else if (chartemp == '"') {
			if (is_string && is_key) {
				key_temp = temp;
				temp = "";
			}
			else if (is_string && !(is_key)) {
				this->set_config(key_temp, temp);
				temp = "";
			}
			is_string = !(is_string);
		}
		else {
			if (is_string) {
				temp += chartemp;
			}
		}
	}
	/* Test
	std::cout << this->config[0][0] << ':' << this->config[0][1] << std::endl
		      << this->config[1][0] << ':' << this->config[1][1] << std::endl
		      << this->config[2][0] << ':' << this->config[2][1] << std::endl
		      << this->config[3][0] << ':' << this->config[3][1] << std::endl
		      << this->config[4][0] << ':' << this->config[4][1] << std::endl
		      << this->config[5][0] << ':' << this->config[5][1] << std::endl
		      << this->config[6][0] << ':' << this->config[6][1] << std::endl
		      << this->config[7][0] << ':' << this->config[7][1] << std::endl;
	*/
	return false;
}

bool Config::reload()
{
	this->last[0][1] = this->config[0][1];
	this->last[1][1] = this->config[1][1];
	this->last[2][1] = this->config[2][1];
	this->last[3][1] = this->config[3][1];
	this->last[4][1] = this->config[4][1];
	this->last[5][1] = this->config[5][1];
	this->last[6][1] = this->config[6][1];
	std::string config_str;
	std::string temp;
	std::string key_temp;
	std::stringstream buffer;
	char        chartemp;
	bool        is_key = true;
	bool        is_string = false;
	this->config_file.open(this->config_name, std::ios::in);
	buffer << this->config_file.rdbuf();
	this->config_file.close();
	this->config_str = buffer.str();
	for (int i = 0; i < this->config_str.length(); i++) {
		chartemp = this->config_str[i];
		if (chartemp == ':') {
			is_key = false;
		}
		else if (chartemp == ',') {
			is_key = true;
		}
		else if (chartemp == '"') {
			if (is_string && is_key) {
				key_temp = temp;
				temp = "";
			}
			else if (is_string && !(is_key)) {
				this->set_config(key_temp, temp);
				temp = "";
			}
			is_string = !(is_string);
		}
		else {
			if (is_string) {
				temp += chartemp;
			}
		}
	}
	/* Test
	std::cout << this->config[0][0] << ':' << this->config[0][1] << std::endl
			  << this->config[1][0] << ':' << this->config[1][1] << std::endl
			  << this->config[2][0] << ':' << this->config[2][1] << std::endl
			  << this->config[3][0] << ':' << this->config[3][1] << std::endl
			  << this->config[4][0] << ':' << this->config[4][1] << std::endl
			  << this->config[5][0] << ':' << this->config[5][1] << std::endl
			  << this->config[6][0] << ':' << this->config[6][1] << std::endl
			  << this->config[7][0] << ':' << this->config[7][1] << std::endl;
	*/
	return false;
}

bool Config::write()
{
	this->config_str = "{\n    \"";
	for (const auto &item : this->config) {
		this->config_str += item[0] + "\": \"" + item[1] + "\",\n    ";
	}
	this->config_str += "\b\b\b\b}";
	return false;
}

void Config::get_screen_size(SDL_DisplayMode* inMode)
{
	if (this->get_config("screen_width") == "0") {
		SDL_DisplayMode mode;
		SDL_GetDisplayMode(0, 0, &mode);
		if (mode.w < 1920) {
			inMode->w = 1050;
			inMode->h = 720;
		}
		else if (1920 <= mode.w < 3840) {
			inMode->w = 1400;
			inMode->h = 960;
		}
		else if (mode.w >= 3840) {
			inMode->w = 1750;
			inMode->h = 1200;
		}
	}
	else {
		if (this->get_config("screen_width") == "1050") {
			inMode->w = 1050;
			inMode->h = 720;
		}
		else if (this->get_config("screen_width") == "1400") {
			inMode->w = 1400;
			inMode->h = 960;
		}
		else if (this->get_config("screen_width") == "1750") {
			inMode->w = 1750;
			inMode->h = 1200;
		}
	}
}

void Config::set_config(std::string key, std::string value)
{
	for (int i = 0;i < 10;i++) {
		if (this->config[i][0] == key) {
			this->config[i][1] = value;
			break;
		}
	}
}

std::string Config::get_config(std::string key)
{
	for (int i = 0;i < 10;i++) {
		if (this->config[i][0] == key) {
			return this->config[i][1];
		}
	}
}
