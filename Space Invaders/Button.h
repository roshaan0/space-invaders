#pragma once
class Button
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Text text;

public:
	Button() {};
	Button(const std::string& t, const std::string& textureLocation, int charSize, float size, sf::Color textColor, sf::Color buttonColor);
	void SetTheFont(sf::Font& font);
	void ChangeBackTextColor(sf::Color color);
	void ChangeTextColor(sf::Color color);
	void ChangeTheText(const std::string& t);
	void SetPosition(float x, float y);
	void SetTextPosition(float x, float y);
	void Draw(sf::RenderWindow& window);
	bool IsMouseOver(sf::RenderWindow& window);
};