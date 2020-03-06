#include "TileMap.h"

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}


//Returns true if a tilemap is loaded given a filename, tilesize, tileArray of inputs, rotations of array, and bounds
bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, const int* rotations, unsigned int width, unsigned int height, int x, int y)
{
	int tileNum = 0,
		tu, tv,
		rot;

	//Load tileset
	if (!m_tileset.loadFromFile(tileset, sf::IntRect(0 + x * 24 * 7, 112 + y * 4 * 24, 7 * 24, 4 * 24)))
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
			rot = rotations[i + j * width];
			
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
			setRotation(quad, rot, tu, tv, tileSize, tileNum);
			//quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			//quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			//quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			//quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	return 1;
}


//Draws a Tilemap to a rendertarget
void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const

{
	//Apply transform
	states.transform *= getTransform();

	//apply tileset texture
	states.texture = &m_tileset;

	//Draw vertex array
	target.draw(m_verticies, states);
}


//Rotates q quad given a rotation count, index, tilesize, and tile num
void TileMap::setRotation(sf::Vertex* quad, int rot, int tu, int tv, sf::Vector2u tileSize, int tileNumber)
{
	sf::Vector2f topLeft(tu * tileSize.x, tv * tileSize.y);
	sf::Vector2f topRight((tu + 1) * tileSize.x, tv * tileSize.y);
	sf::Vector2f bottomRight((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
	sf::Vector2f bottomLeft(tu * tileSize.x, (tv + 1) * tileSize.y);
	switch (rot) {
		//Unrotated.
	case 0:
		quad[0].texCoords = topLeft;//0
		quad[1].texCoords = topRight;//1
		quad[2].texCoords = bottomRight;//2
		quad[3].texCoords = bottomLeft;//3
		break;
		//Rotated 90 degrees clockwise.
	case 1:
		quad[0].texCoords = bottomLeft;//3
		quad[1].texCoords = topLeft;//0
		quad[2].texCoords = topRight;//1
		quad[3].texCoords = bottomRight;//2
		break;
		//Rotated 180 degreese clockwise.
	case 2:
		quad[0].texCoords = bottomRight;//2
		quad[1].texCoords = bottomLeft;//3
		quad[2].texCoords = topLeft;//0
		quad[3].texCoords = topRight;//1   
		break;
		//Rotated 270 degrees clockwise.
	case 3: // Horizontal + Vertical Flip
		quad[0].texCoords = topRight;//1
		quad[1].texCoords = bottomRight;//2
		quad[2].texCoords = bottomLeft;//3
		quad[3].texCoords = topLeft;//0
		break;
	}
}
