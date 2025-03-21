//
// Result.h
//

#pragma once

#include "Scene.h"

using Microsoft::WRL::ComPtr;
using std::unique_ptr;
using std::make_unique;
using namespace DirectX;

class Result final : public Scene {
public:
	Result();
	virtual ~Result() { Terminate(); }

	Result(Result&&) = default;
	Result& operator= (Result&&) = default;

	Result(Result const&) = delete;
	Result& operator= (Result const&) = delete;

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