#pragma once
#include "Screen.h"
#include <vector>

class HighScoreScene : public Screen
{
private:
    bool isPlaying;
    std::vector<int> highScores;

    void LoadHighScores();
    void SaveHighScores();

public:
    virtual int Run(sf::RenderWindow& window);
};
