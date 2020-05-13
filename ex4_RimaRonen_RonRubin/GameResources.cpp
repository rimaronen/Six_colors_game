#include "GameResources.h"



GameResources::GameResources()
{

	if (!m_greenTexture->loadFromFile("green.png"))
		exit(EXIT_FAILURE);

	if (!m_blueTexture->loadFromFile("blue.png"))
		exit(EXIT_FAILURE);

	if (!m_yellowTexture->loadFromFile("yellow.png"))
		exit(EXIT_FAILURE);

	if (!m_orangeTexture->loadFromFile("orange.png"))
		exit(EXIT_FAILURE);

	if (!m_redTexture->loadFromFile("red.png"))
		exit(EXIT_FAILURE);

	if (!m_purpleTexture->loadFromFile("purple.png"))
		exit(EXIT_FAILURE);

	if (!m_exitTexture->loadFromFile("exit.png"))
		exit(EXIT_FAILURE);

	if (!m_restartTexture->loadFromFile("reset1.png"))
		exit(EXIT_FAILURE);

	if (!m_cbFont->loadFromFile("realpolitik.ttf"))
		exit(EXIT_FAILURE);

	if (!m_xTexture->loadFromFile("x.png"))
		exit(EXIT_FAILURE);
}

GameResources::~GameResources()
{
}

GameResources & GameResources::instance()
{
	static GameResources instance;
	return instance;
}

sf::Texture & GameResources::getBlueTexture()
{
	return *m_blueTexture;
}

sf::Texture & GameResources::getGreenTexture()
{
	return *m_greenTexture;
}

sf::Texture & GameResources::getYellowTexture()
{
	return *m_yellowTexture;
}

sf::Texture & GameResources::getRedexture()
{
	return *m_redTexture;
}

sf::Texture & GameResources::getOrangeTexture()
{
	return *m_orangeTexture;
}

sf::Texture & GameResources::getPurpuleTexture()
{
	return *m_purpleTexture;
}

sf::Texture & GameResources::getExitTexture()
{
	return *m_exitTexture;
}
sf::Texture & GameResources::getRestartTexture()
{
	return *m_restartTexture;
}

sf::Font& GameResources::getCbFont()
{
	return *m_cbFont;
}
sf::Texture & GameResources::getXTexture()
{
	return *m_xTexture;
}