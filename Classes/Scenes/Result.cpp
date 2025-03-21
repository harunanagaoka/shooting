//
// Result.cpp
//

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SceneFactory.h"

#ifdef _DEBUG
#pragma warning(disable : 4189)
#endif

using namespace SimpleMath;

// Initialize member variables.
Result::Result()
{

}

// Start is called after the scene is created.
void Result::Start()
{
	LoadAssets();
	Initialize();
	InputSystem.Mouse.SetMode(Mouse::MODE_ABSOLUTE);
}

// Load resources.
//void Result::LoadAssets()
//{
//	CreateDeviceDependentResources();
//	CreateResources();
//}

// Allocate memory the Direct3D and Direct2D resources.
// These are the resources that depend on the device.
void Result::CreateDeviceDependentResources()
{
	auto&& device      = DXTK->Device;
	auto&& commandList = DXTK->CommandList;

	m_descriptor_heap_ = DirectXTK::CreateDescriptorHeap(
		DXTK->Device, SpriteName::DescriptorCount + FontName::FontsCount
	);

	ResourceUploadBatch resourceUpload(device);
	resourceUpload.Begin();

	RenderTargetState rtState(DXTK->SwapChain.Format, DXTK->SwapChain.DepthFormat);

	SpriteBatchPipelineStateDescription pd(rtState, &CommonStates::NonPremultiplied);

	SpriteManager::GetInstance().CreatSpriteInfo(resourceUpload, m_descriptor_heap_);

	m_sprite_batch_ = DirectXTK::CreateSpriteBatch(device, resourceUpload, pd);
	auto&& viewport = DXTK->SwapChain.Viewport;
	m_sprite_batch_->SetViewport(viewport);

	auto&& uploadResourcesFinished = resourceUpload.End(DXTK->CommandQueue);
	uploadResourcesFinished.wait();

}

// Create independent resources.
void Result::CreateResources()
{

}

// Initialize a variable and audio resources.
void Result::Initialize()
{

}

// Releasing resources required for termination.
void Result::Terminate()
{
	// TODO: Add a sound instance reset.
	DXTK->Audio.Engine->Suspend();


	DXTK->Audio.ResetEngine();
	DXTK->WaitForGpu();

	// TODO: Add your Termination logic here.

}

// Direct3D resource cleanup.
void Result::OnDeviceLost()
{

}

// Restart any looped sounds here
void Result::OnRestartSound()
{

}

// Updates the scene.
NextScene Result::Update(const float deltaTime)
{

	if (InputSystem.Keyboard.wasPressedThisFrame.A || InputSystem.Mouse.was.leftButton == true)
	{
		return NextScene::TitleScene;
	}
	// TODO: Add your game logic here.



	return NextScene::Continue;
}

// Draws the scene.
void Result::Render()
{
	DXTK->BeginScene();
	DXTK->ClearRenderTarget(Colors::CornflowerBlue);

	auto&& device      = DXTK->Device;
	auto&& commandList = DXTK->CommandList;


	auto&& heap = m_descriptor_heap_->Heap();
	commandList->SetDescriptorHeaps(1, &heap);

	m_sprite_batch_->Begin(commandList);

	SpriteManager::GetInstance().SetSpriteBatch(m_sprite_batch_.get());
	SpriteManager::GetInstance().Render(SpriteName::Result_, SimpleMath::Vector2(640, 360));

	m_sprite_batch_->End();





	DXTK->EndScene();
}
