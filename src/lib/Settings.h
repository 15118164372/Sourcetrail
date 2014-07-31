#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <memory>

#include "utility/ConfigManager.h"

class Settings
{
public:
	Settings();
	virtual ~Settings();

	bool load(const std::string& filePath);
	void save(const std::string& filePath);
	void clear();

protected:
	template<typename T>
	T getValue(const std::string& key, T defaultValue) const;

	template<typename T>
	bool setValue(const std::string& key, T value);

private:
	std::shared_ptr<ConfigManager> m_config;
};

template<typename T>
T Settings::getValue(const std::string& key, T defaultValue) const
{
	if (m_config)
	{
		T value;
		if (m_config->getValue(key, value))
		{
			return value;
		}
	}
	return defaultValue;
}

template<typename T>
bool Settings::setValue(const std::string& key, T value)
{
	if (m_config)
	{
		m_config->setValue(key, value);
		return true;
	}
	return false;
}

#endif // SETTINGS_H
