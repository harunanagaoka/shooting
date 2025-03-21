//
// TitleScene.h
//

#pragma once

#include "Scene.h"
#include "Classes/TitleManager.h"
#include "Classes/SpriteManager.h"
#include "Classes/FontManager.h"
#include "Classes/GameStateController.h"
#include "Classes/PlayFlowController.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class TitleScene final : public Scene {
public:
	TitleScene();
	virtual ~TitleScene() { Terminate(); }

	TitleScene(TitleScene&&) = default;
	TitleScene& operator= (TitleScene&&) = default;

	TitleScene(TitleScene const&) = delete;
	TitleScene& operator= (TitleScene const&) = delete;

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

	DirectXTK::DescriptorHeap m_descriptor_heap_;

	DirectXTK::SpriteBatch m_sprite_batch_;
};