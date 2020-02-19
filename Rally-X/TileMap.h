#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	~TileMap();

	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, sf::Rect<int> bounds);
	void draw(sf::RenderTarget& target, sf::RenderStates) const;


private:
	sf::VertexArray m_verticies;
	sf::Texture m_tileset;
	std::vector<sf::Texture> textures;
};
#endif // !TILEMAP_H