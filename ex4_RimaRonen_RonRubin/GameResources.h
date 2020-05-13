#pragma once
#include <SFML/Graphics.hpp>

const int SCREEN_SIZE_X = 600;
const int SCREEN_SIZE_Y = 800;

class GameResources
{
public:
	
	~GameResources();
	static GameResources& instance(); // provide instance via a special function that will always provide the same instance
	sf::Texture & getBlueTexture(); //return blue button texture
	sf::Texture & getGreenTexture(); //return green button texture
	sf::Texture & getYellowTexture(); //return yellow button texture
	sf::Texture & getRedexture(); //return red button texture
	sf::Texture & getOrangeTexture(); //return orange button texture
	sf::Texture & getPurpuleTexture(); //return purple button texture
	sf::Texture & getExitTexture(); //return exit button texture
	sf::Texture & getRestartTexture(); //return exit button texture
	sf::Texture & getXTexture();
	sf::Font& getCbFont(); // return font

private:
	GameResources();
	GameResources(const GameResources& other);// prevent instantiation by copying
	GameResources& operator=(const GameResources& other); // prevent instantiation by assignment

	std::unique_ptr <sf::Texture> m_restartTexture = std::make_unique<sf::Texture>();
	std::unique_ptr <sf::Texture> m_exitTexture = std::make_unique<sf::Texture>();
	std::unique_ptr <sf::Texture> m_greenTexture = std::make_unique<sf::Texture>();
	std::unique_ptr <sf::Texture> m_blueTexture = std::make_unique<sf::Texture>();
	std::unique_ptr <sf::Texture> m_yellowTexture = std::make_unique<sf::Texture>();
	std::unique_ptr <sf::Texture> m_orangeTexture = std::make_unique<sf::Texture>();
	std::unique_ptr <sf::Texture> m_redTexture = std::make_unique<sf::Texture>();
	std::unique_ptr <sf::Texture> m_purpleTexture = std::make_unique<sf::Texture>();
	std::unique_ptr <sf::Texture> m_xTexture = std::make_unique<sf::Texture>();
	std::unique_ptr <sf::Font> m_cbFont = std::make_unique<sf::Font>();


};

