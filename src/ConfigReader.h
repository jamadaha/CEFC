#ifndef CONFIG_READER
#define CONFIG_READER

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class ConfigReader {
	public:
	ConfigReader(std::string path);
	void Read();
	std::string GetString(std::string key);
	bool GetBool(std::string key);

	private:
	std::string path;
	std::unordered_map<std::string, std::string> readValues;

	void HandleLine(std::string line);

};

#endif