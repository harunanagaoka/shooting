//
// BGTexture.cpp
//

#include "BGTexture.h"


using namespace SimpleMath;

void BGTexture::Initialize()
{
	
}

// Updates the scene.
void BGTexture::Update()
{
	
}

//void BGTexture::CreatSpriteInfo(ResourceUploadBatch& resourceUpload, std::unique_ptr<DirectX::DescriptorHeap>& resourceDescriptors)
//{
//	for (int i = 0; i < Descriptors::DescriptorCount; i++)
//		{
//			string FilePath = m_spriteFilePath[static_cast<TextureName>(i)];
//			wstring wstringPath(FilePath.begin(), FilePath.end());
//			const wchar_t* spriteFilePath = wstringPath.c_str();
//
//			SpriteData spriteinfo;
//			//srv”­“®
//			spriteinfo.m_sprite = DirectXTK::CreateSpriteSRV(
//				DXTK->Device,
//				spriteFilePath,
//				resourceUpload,
//				resourceDescriptors,
//				static_cast<int>(static_cast<TextureName>(i)));
//				spriteArray.push_back(std::move(spriteinfo));
//		}
//}

//void BGTexture::Render(DirectXTK::Sprite sprite,DirectX::SpriteBatch* spritebatch)
//{
//	spritebatch->Draw(
//		sprite.handle,
//		sprite.size,
//		position_
//	);
//}

//void BGTexture::Load(DirectXTK::Sprite& sprite)
//{
//
//}
//
//void BGTexture::Render(DirectX::SpriteBatch* sprite_batch)
//{
//}
