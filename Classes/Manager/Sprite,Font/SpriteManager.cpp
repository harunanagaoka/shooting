//
// SpriteManager.cpp
//

#include "SpriteManager.h"

using namespace SimpleMath;

//SpriteInfo.defのデータを使い、読み込みを一括で行う関数。
void SpriteManager::CreatSpriteInfo(ResourceUploadBatch& resourceUpload,
	std::unique_ptr<DirectX::DescriptorHeap>& resourceDescriptors)
{
	for (int i = 0; i < SpriteName::DescriptorCount; i++)
	{
		//ファイルパスの文字形式を変換しています
		string FilePath = m_spritePath[i];
		wstring wstringPath(FilePath.begin(), FilePath.end());
		const wchar_t* spriteFilePath = wstringPath.c_str();

		SpriteData spriteData;

		spriteData.m_sprite = DirectXTK::CreateSpriteSRV(
			DXTK->Device,
			spriteFilePath,
			resourceUpload,
			resourceDescriptors,
			static_cast<int>(static_cast<SpriteName>(i)));

		//描画用データをspriteArrayにまとめて格納しています。
			spriteArray.push_back(std::move(spriteData));
	}
}

//enumを引数に設定すると、該当のスプライトデータを返します。
struct SpriteData SpriteManager::GetSprite(int SpriteNum)//SpriteNameで受け取る
{
	return spriteArray[SpriteNum];
}

//旧関数　スプライトデータの呼び出しを外部クラスに任せていたが、廃止予定
void SpriteManager::Render(struct SpriteData spriteData, SimpleMath::Vector2 position, DirectX::SpriteBatch* spritebatch)
{
	spritebatch->Draw(
		spriteData.m_sprite.handle,
		spriteData.m_sprite.size,
		position
	);
}

//Renderはすべてこちらに変更予定。
void SpriteManager::Render(SpriteName spriteName, SimpleMath::Vector2 position)
{
	SpriteData spd = GetSprite(spriteName);
	m_spriteBatch->Draw(
		spd.m_sprite.handle,
		spd.m_sprite.size,
		SimpleMath::Vector2(position.x - spd.m_sprite.size.x / 2,position.y - spd.m_sprite.size.y / 2)
	);
}



