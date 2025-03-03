//
// SpriteManager.h
//
//画像読み込み用のクラスです

#pragma once

#include<vector>
#include <string>
#include "..\Base\pch.h"
#include "..\Base\dxtk.h"

using namespace DirectX;
using namespace std;

enum  SpriteName {//画像呼び出し用のenum
#define ITEM(name,adress)name,
#include "defineFile/SpriteInfo.def"
#undef ITEM
};

struct SpriteData {//画像読み込み後に保存しておく構造体
	DirectXTK::Sprite m_sprite; 
};

class SpriteManager  {
private:
	SpriteManager(){}
	
	std::vector<string> m_spritePath = {//SpriteInfo.defから画像のファイルパス取得
	#define ITEM(name,adress)adress,
	#include "defineFile/SpriteInfo.def"
	#undef ITEM
	};

	std::vector<SpriteData> spriteArray; //全SpriteDataを管理しています。

	DirectX::SpriteBatch* m_spriteBatch = nullptr;
public:
	//外部から取得できるようにしています
	static SpriteManager& GetInstance() {
		static SpriteManager instance; 
		return instance;
	}

	//コピー禁止
	SpriteManager(const SpriteManager&) = delete;
	SpriteManager& operator=(const SpriteManager&) = delete;


	void CreatSpriteInfo(ResourceUploadBatch& resourceUpload,
						 std::unique_ptr<DirectX::DescriptorHeap>& resourceDescriptors);

	struct SpriteData GetSprite(int SpriteNum);

	void Render(SpriteName spriteName, SimpleMath::Vector2 position);

	void SetSpriteBatch(DirectX::SpriteBatch* sp) {
		m_spriteBatch = sp; 
	}

	DirectX::SpriteBatch* GetSpriteBatch() {
		return m_spriteBatch; 
	}

	//削除予定
	void Render(struct SpriteData spriteData,SimpleMath::Vector2 position, DirectX::SpriteBatch* spritebatch);
};