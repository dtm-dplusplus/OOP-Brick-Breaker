#pragma once

#include "Core.h"

class Texture
{
public:
	Texture();
	explicit Texture(const std::string& _path);

	bool LoadTexture();
	void DestroyTexture() const;

	std::string GetTexurePath() const;
	void SetTexturePath(const std::string& _path);

	SDL_Texture* GetTexture() const;
	void SetTexture(SDL_Texture*& _texture);

private:
	SDL_Texture* m_Texture;
	std::string m_Path;
};