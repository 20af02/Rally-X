#include "TileMap.h"

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}


bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, sf::Rect<int> bounds)
{
	int tileNum = 0,
		tu, tv,
		width = bounds.width,
		height = bounds.height;

	//Load tileset
	if (!m_tileset.loadFromFile(tileset,bounds))
		return 0;

	//Resize vertex array to fit level size
	m_verticies.setPrimitiveType(sf::Quads);
	m_verticies.resize(width*height* 4);


	//Populate vertex array, one quad per tile
	for(unsigned int i = 0; i < width; i++)
		for (unsigned int j = 0; j < height; j++)
		{
			//Current tile num
			tileNum = tiles[i + j * width];
			
			//Find position in texture
			tu = tileNum % (m_tileset.getSize().x / tileSize.x);
			tv = tileNum / (m_tileset.getSize().x / tileSize.x);

			//get pointer to current tile quad
			sf::Vertex* quad = &m_verticies[(i + j * width) * 4];


			//Define 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i+1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i+1) * tileSize.x, (j+1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j+1) * tileSize.y);

			//Define 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	return 1;
}


void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Apply transform
	states.transform *= getTransform();

	//apply tileset texture
	states.texture = &m_tileset;

	//Draw vertex array
	target.draw(m_verticies, states);
}
