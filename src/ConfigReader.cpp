#include "ConfigReader.h"

ConfigReader::ConfigReader(std::string path) {
	this->path = path;
}

void ConfigReader::Read() {
	std::fstream configFile;
	configFile.open(this->path, std::ios::in);
	if (configFile.is_open()) {
		std::string line;
		while (std::getline(configFile, line)) {
			HandleLine(line);
		}
		configFile.close();
	}
}

std::string ConfigReader::GetValue(std::string key) {
	return readValues[key];
}

void ConfigReader::HandleLine(std::string line) {
	// If comment or empty line
	if (line.length() == 0 || line[0] == '#')
		return;

	std::string key = "";
	std::string value = "";
	int i = 0;
	bool foundEq = false;
	while (i < line.length()) {
		if (line[i] == '=')
			foundEq = true;
		else if (!foundEq)
			key += line[i];
		else
			value += line[i];
		i++;
	}
	readValues.emplace(key, value);
}