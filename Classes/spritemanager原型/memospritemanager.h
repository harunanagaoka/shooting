//
// SpriteManager.h
//

#pragma once
#include <unordered_map>
#include<vector>
#include "..\Base\pch.h"
#include "..\Base\dxtk.h"

using namespace DirectX;
using namespace std;

class SpriteManager {

protected:
	//enum Descriptors {
	//	BG,
	//	Pl,
	//	Ene,
	//	DescriptorCount
	//};

public:
	enum Descriptors {
		BG,
		Pl,
		Ene,
		DescriptorCount
	};

	void CreatSpriteInfo(ResourceUploadBatch& resourceUpload,
		std::unique_ptr<DirectX::DescriptorHeap>& resourceDescriptors);

	void Render(Descriptors ImageName, DirectX::SpriteBatch* spritebatch);

protected:


	unordered_map<Descriptors, string> m_spriteFilePath = {
		{Descriptors::BG, "..\\Assets\\BG.png"},
		{Descriptors::Ene, "..\\Assets\\slime.png"},
		{Descriptors::Pl, "..\\Assets\\Player2.png"}
	};
	struct SpriteInfo {
		DirectXTK::Sprite m_sprite;
	};

	std::vector<SpriteInfo> spriteArray;

	SimpleMath::Vector2 position_;

};