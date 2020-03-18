#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	~TileMap();

	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, const int* rotations, unsigned int width, unsigned int height, int x, int y);

	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;


private:
	void setRotation(sf::Vertex* quad, int rot, int tu, int tv,
	sf::Vector2u tileSize, int tileNumber);
	sf::VertexArray m_verticies;
	sf::Texture m_tileset;
	std::vector<sf::Texture> textures;
};
#endif // !TILEMAP_H