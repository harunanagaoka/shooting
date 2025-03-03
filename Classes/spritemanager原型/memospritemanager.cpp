//
// SpriteManager.cpp
//

#include "SpriteManager.h"

using namespace SimpleMath;

void SpriteManager::CreatSpriteInfo(ResourceUploadBatch& resourceUpload,
	std::unique_ptr<DirectX::DescriptorHeap>& resourceDescriptors)
{
	for (int i = 0; i < Descriptors::DescriptorCount; i++)
	{
		string FilePath = m_spriteFilePath[static_cast<Descriptors>(i)];
		wstring wstringPath(FilePath.begin(), FilePath.end());
		const wchar_t* spriteFilePath = wstringPath.c_str();

		SpriteInfo spriteinfo;
		//srv”­“®
		spriteinfo.m_sprite = DirectXTK::CreateSpriteSRV(
			DXTK->Device,
			spriteFilePath,
			resourceUpload,
			resourceDescriptors,
			static_cast<int>(static_cast<Descriptors>(i)));
		spriteArray.push_back(std::move(spriteinfo));
	}
}

void SpriteManager::Render(Descriptors ImageName, DirectX::SpriteBatch* spritebatch)
{
	//string sprite = m_spriteFilePath[ImageName];

	spritebatch->Draw(
		spriteArray[ImageName].m_sprite.handle,
		spriteArray[ImageName].m_sprite.size,
		position_
	);
}





