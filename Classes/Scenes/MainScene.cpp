//
// MainScene.cpp
//

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SceneFactory.h"

#ifdef _DEBUG
#pragma warning(disable : 4189)
#endif

using namespace SimpleMath;

// Start is called after the scene is created.
void MainScene::Start()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	LoadAssets();
	Initialize();
	InputSystem.Mouse.SetMode(Mouse::MODE_ABSOLUTE);
}

// Allocate memory the Direct3D and Direct2D resources.
// These are the resources that depend on the device.
void MainScene::CreateDeviceDependentResources()
{
	auto&& device      = DXTK->Device;
	auto&& commandList = DXTK->CommandList;

	descriptor_heap_ = DirectXTK::CreateDescriptorHeap(
		DXTK->Device, SpriteName::DescriptorCount + FontName::FontsCount
	);

	ResourceUploadBatch resourceUpload(device);
	resourceUpload.Begin();

	RenderTargetState rtState(DXTK->SwapChain.Format, DXTK->SwapChain.DepthFormat);

	SpriteBatchPipelineStateDescription pd(rtState, &CommonStates::NonPremultiplied);

	SpriteManager::GetInstance().CreatSpriteInfo(resourceUpload, descriptor_heap_);

	FontManager::GetInstance().CreatFontsInfo(resourceUpload, descriptor_heap_);


	sprite_batch_ = DirectXTK::CreateSpriteBatch(device, resourceUpload, pd);
	auto&& viewport = DXTK->SwapChain.Viewport;
	sprite_batch_->SetViewport(viewport);

	auto&& uploadResourcesFinished = resourceUpload.End(DXTK->CommandQueue);
	uploadResourcesFinished.wait();
}

// Create independent resources.
void MainScene::CreateResources()
{

}

// Initialize a variable and audio resources.
void MainScene::Initialize()
{
	PlayFlowController::GetInstance().Initialize();
}

// Releasing resources required for termination.
void MainScene::Terminate()
{
	// TODO: Add a sound instance reset.
	DXTK->Audio.Engine->Suspend();


	DXTK->Audio.ResetEngine();
	DXTK->WaitForGpu();

	// TODO: Add your Termination logic here.

}

// Direct3D resource cleanup.
void MainScene::OnDeviceLost()
{

}

// Restart any looped sounds here
void MainScene::OnRestartSound()
{

}

// Updates the scene.
NextScene MainScene::Update(const float deltaTime)
{
	// デルタタイム使う場合は消してOK
	//UNREFERENCED_PARAMETER(deltaTime);


	GameState state = GameStateController::GetInstance().GetState();

	switch (state)
	{
	case GameState::Title :
		return NextScene::TitleScene;
		break;

	case GameState::MainGame :
		PlayFlowController::GetInstance().Update();
		break;

	case GameState::GameOver :
		//return NextScene::GameOver
		break;

	case GameState::Result:
		return NextScene::Result;
		break;

	default :
		return NextScene::Continue;
		break;
	}

	return NextScene::Continue;
}

// Draws the scene.
void MainScene::Render()
{
	DXTK->BeginScene();
	DXTK->ClearRenderTarget(Colors::CornflowerBlue);

	auto&& device      = DXTK->Device;
	auto&& commandList = DXTK->CommandList;

	auto&& heap = descriptor_heap_->Heap();
	commandList->SetDescriptorHeaps(1, &heap);

	sprite_batch_->Begin(commandList);

	SpriteManager::GetInstance().SetSpriteBatch(sprite_batch_.get());
	FontManager::GetInstance().SetSpriteBatch(sprite_batch_.get());
	PlayFlowController::GetInstance().Render();

	sprite_batch_->End();
	DXTK->EndScene();
}
