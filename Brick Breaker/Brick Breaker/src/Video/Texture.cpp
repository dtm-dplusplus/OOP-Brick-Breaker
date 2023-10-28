#include "Texture.h"

#include "Renderer.h"

Texture::Texture(): m_Texture{nullptr}
{
}

Texture::Texture(const std::string& _path): m_Texture{nullptr}
{
	LoadTexture();
}

bool Texture::LoadTexture()
{
	// Load image to SDL surface
	SDL_Surface* loadedSurface = IMG_Load(m_Path.c_str());
	if (!loadedSurface)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", m_Path.c_str(), IMG_GetError());
		return false;
	}

	// Create texture from surface
	m_Texture = SDL_CreateTextureFromSurface(Renderer::GetSDLRenderer(), loadedSurface);
	if (!m_Texture)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", m_Path.c_str(), SDL_GetError());
		return false;
	}

	// Free loaded surface
	SDL_FreeSurface(loadedSurface);

	return true;
}

void Texture::DestroyTexture() const
{
	SDL_DestroyTexture(m_Texture);
}

std::string Texture::GetTexurePath() const
{
	return m_Path;
}

void Texture::SetTexturePath(const std::string& _path)
{
	m_Path = _path;
}

SDL_Texture* Texture::GetTexture() const
{
	return m_Texture;
}

void Texture::SetTexture(SDL_Texture*& _texture)
{
	m_Texture = _texture;
} 
