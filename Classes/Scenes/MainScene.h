//
// MainScene.h
//

#pragma once

#include "Scene.h"
#include "..\Classes\Timer.h"
#include "..\Classes\Collider.h"
#include "Classes/SpriteManager.h"
#include "Classes/Gamemanager.h"
#include "Classes/FontManager.h"
#include "Classes/GameStateController.h"
#include "Classes/PlayFlowController.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class MainScene final : public Scene {
private:
	
public:
	MainScene(){}
	virtual ~MainScene() { Terminate(); }

	MainScene(MainScene&&) = default;
	MainScene& operator= (MainScene&&) = default;

	MainScene(MainScene const&) = delete;
	MainScene& operator= (MainScene const&) = delete;

	// These are the functions you will implement.
	void Start() override;

	//void LoadAssets() override;
	void CreateDeviceDependentResources() override;
	void CreateResources() override;

	void Initialize() override;
	void Terminate() override;

	void OnDeviceLost() override;
	void OnRestartSound() override;

	NextScene Update(const float deltaTime) override;
	void Render() override;

private:

	DirectXTK::DescriptorHeap descriptor_heap_;

	DirectXTK::SpriteBatch sprite_batch_;

	DirectXTK::Sprite sprite_;
	SimpleMath::Vector2       bg_position_;
	DirectXTK::SpriteFont sprite_font_;

};