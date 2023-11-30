#include "keyboard.hpp"

namespace ESS
{
	Keyboard::Keyboard() = default;
	Keyboard::~Keyboard()
	{}

	void Keyboard::addCommand(const std::string& key, const std::string& cmd)
	{

		_commands.insert({ key, cmd });
		_keys += key;
	}
	void Keyboard::pressKey(const std::string& key)
	{

		std::cout << _commands[key] << std::endl;
	}

	void Keyboard::workflow(const std::string& strKey)
	{
		setlocale(LC_ALL, "Rus");
		std::cout << "workflow начало работы" << std::endl;

		parse(strKey);

		for (const auto& i : _keysV)
		{
			std::cout << _commands[i] << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds{ 1000 });
		}

		std::cout << "workflow завершение работы" << std::endl;
		std::cout << "-----------------------------" << std::endl;
	}


	void Keyboard::undo()
	{
		setlocale(LC_ALL, "Rus");
		std::cout << "undo начало работы" << std::endl;

		_keysV.erase(_keysV.end() - 1);
		for (const auto& i : _keysV)
		{
			std::cout << _commands[i] << std::endl; 
			std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
		}

		std::cout << "undo завершение работы" << std::endl;
		std::cout << "----------------------" << std::endl;
	}


	void Keyboard::parse(std::string keys)
	{
		std::stringstream keyssStringstream(keys);
		std::string str;
		
		for (int i = 0; i < keys.length(); i++)
		{

			if (getline(keyssStringstream, str, ' '))
			{
				_keysV.push_back(str);
			}
		}

	}

}