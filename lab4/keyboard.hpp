#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <thread>
#include <chrono>

namespace ESS
{
    class Keyboard
    {

    public:
        
        Keyboard();

        ~Keyboard();

        void addCommand(const std::string& key, const std::string& cmd);

        void pressKey(const std::string& key);

        void workflow(const std::string& strKey);

        void undo();

    private:

        std::string _keys, _pressedKey;
        std::vector<std::string> _keysV;
        std::unordered_map<std::string, std::string> _commands;

        void parse(std::string keys);
    };
    

}