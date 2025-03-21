//
// TitleScene.cpp
//

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SceneFactory.h"

#ifdef _DEBUG
#pragma warning(disable : 4189)
#endif

using namespace SimpleMath;

// Initialize member variables.
TitleScene::TitleScene()
{

}

// Start is called after the scene is created.
void TitleScene::Start()
{
	LoadAssets();
	Initialize();
	InputSystem.Mouse.SetMode(Mouse::MODE_ABSOLUTE);
}

// Load resources.
//void TitleScene::LoadAssets()
//{
//	CreateDeviceDependentResources();
//	CreateResources();
//}

// Allocate memory the Direct3D and Direct2D resources.
// These are the resources that depend on the device.
void TitleScene::CreateDeviceDependentResources()
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

	FontManager::GetInstance().CreatFontsInfo(resourceUpload, m_descriptor_heap_);

	m_sprite_batch_ = DirectXTK::CreateSpriteBatch(device, resourceUpload, pd);
	auto&& viewport = DXTK->SwapChain.Viewport;
	m_sprite_batch_->SetViewport(viewport);

	auto&& uploadResourcesFinished = resourceUpload.End(DXTK->CommandQueue);
	uploadResourcesFinished.wait();

	// TODO: Add your device-dependent creation code here.

}

// Create independent resources.
void TitleScene::CreateResources()
{

}

// Initialize a variable and audio resources.
void TitleScene::Initialize()
{

}

// Releasing resources required for termination.
void TitleScene::Terminate()
{
	// TODO: Add a sound instance reset.
	DXTK->Audio.Engine->Suspend();


	DXTK->Audio.ResetEngine();
	DXTK->WaitForGpu();

	// TODO: Add your Termination logic here.

}

// Direct3D resource cleanup.
void TitleScene::OnDeviceLost()
{

}

// Restart any looped sounds here
void TitleScene::OnRestartSound()
{

}

// Updates the scene.
NextScene TitleScene::Update(const float deltaTime)
{
	//UNREFERENCED_PARAMETER(deltaTime);


	if (TitleManager::GetInstance().GetPushStart())
	{
		GameStateController::GetInstance().ChangeState(GameState::MainGame);
	}

	GameState state = GameStateController::GetInstance().GetState();
	switch (state)
	{
	case GameState::Title:
		TitleManager::GetInstance().Update();
		return NextScene::Continue;
		break;

	case GameState::MainGame:
		return NextScene::MainScene;
		break;

	default:
		return NextScene::Continue;
		break;
	}


}

// Draws the scene.
void TitleScene::Render()
{
	DXTK->BeginScene();
	DXTK->ClearRenderTarget(Colors::CornflowerBlue);

	auto&& device      = DXTK->Device;
	auto&& commandList = DXTK->CommandList;

	auto&& heap = m_descriptor_heap_->Heap();
	commandList->SetDescriptorHeaps(1, &heap);

	m_sprite_batch_->Begin(commandList);

	SpriteManager::GetInstance().SetSpriteBatch(m_sprite_batch_.get());
	FontManager::GetInstance().SetSpriteBatch(m_sprite_batch_.get());

	TitleManager::GetInstance().Render();

	m_sprite_batch_->End();


	DXTK->EndScene();
}
