//
// BattleManager.cpp
//

#include "BattleManager.h"

BattleManager::~BattleManager() {
    for (auto& enemy : m_enemytest) {
        enemy.reset(); //ƒƒ‚ƒŠ‚ğ‰ğ•ú
    }
}

void BattleManager::Initialize()
{
    m_destroiedEnemy = 0;
    InitEnemyInfo();
}

void BattleManager::Update()
{

    if (InputSystem.Mouse.was.leftButton == InputSystem.Mouse.was.PRESSED)
    {
        OccurrenceATK();
    }

    UpdateEnemy();
    UpdateAtk();

    DeleteisDeadEnemy();
    DeleteFinishAtk();
    EraseNullVector();

    if (m_initEnemyNum <= m_destroiedEnemy && m_initEnemyNum > 0)
    {
       AllEnemyDestroied();
    }
}

void BattleManager::OccurrenceATK()
{
     PlayerAttack* atk = new PlayerAttack(InputSystem.Mouse.position);
     atk->Initialize();
     m_attack.push_back(atk);
}

void BattleManager::UpdateEnemy()
{
    for (int i = 0; i < m_enemytest.size(); i++)
    {
        if (m_enemytest[i] == nullptr)
        {
            continue;
        }

        m_enemytest[i]->Update();
    }
}

void BattleManager::UpdateAtk()
{
    for (int i = 0; i < m_attack.size(); i++)
    {
        if (m_attack[i] == nullptr)
        {
            continue;
        }

        CheckHit(m_attack[i]);
        
        m_attack[i]->Update();
    }
}

void BattleManager::CheckHit(PlayerAttack* atk)
{
    for (int i = 0; i < m_enemytest.size(); i++)
    {
        atk->CheckHit(m_enemytest[i].get());
    }
    
}

bool BattleManager::CheckTitleHit(Collider::ColliderRect other)
{
    for (int i = 0; i < m_attack.size(); i++)
    {
        if (m_attack[i] == nullptr)
        {
            continue;
        }

        if (m_attack[i]->CheckHit(other))
        {
            return true;
            break;
        }
    }
    return false;
}

void BattleManager::Render(DirectX::SpriteBatch* sprite_batch)
{
    SpriteManager& sm = SpriteManager::GetInstance();
    for (int i = 0; i < m_enemytest.size(); i++)
    {
        m_enemytest[i]->Render();
    }

    if (m_attack.size() > 0)
    {
        for (int i = 0; i < m_attack.size(); i++)
        {
            m_attack[i]->Render(sprite_batch, sm);
        }

    }
}

void BattleManager::SpawnEnemy(int count) 
{
    //for (int i = 0; i < count; ++i) {
    //    EnemyBase* enemy = nullptr;
    //        enemy = new Tri_Orange();
    //        
    //    if (enemy) {
    //        enemy->Initialize();
    //        m_enemytest.push_back(enemy);
    //    }
    //}

    PlayStateController::GetInstance().ChangeState(PlayState::Battle);
}

void BattleManager::SpawnEnemies(EnemyName enemy, int count)
{
    vector<unique_ptr<EnemyBase>> enemies = EnemyFactory::SpawnEnemy(enemy, count);


    for (auto& ene : enemies) {
        m_enemytest.push_back(std::move(ene)); //“G‚ÌŠÇ—Œ ‚ğ‚»‚ê‚¼‚ê“n‚·
    }
    //Š—LŒ ‚ğ“n‚·¨vector‚ÌŒã‚ë‚É’Ç‰Á‚·‚é
 /*   if (enemy == EnemyName::ShiroMaru_)
    {
        for (int i = 0; i < count; ++i) {
            EnemyBase* enemy = nullptr;
            enemy = new ShiroMaru();

            if (enemy) {
                enemy->Initialize();
                m_enemytest.push_back(enemy);
            }
        }
    }

    if (enemy == EnemyName::MiyabiMaru_)
    {
        for (int i = 0; i < count; ++i) {
            EnemyBase* enemy = nullptr;
            enemy = new MiyabiMaru();

            if (enemy) {
                enemy->Initialize();
                m_enemytest.push_back(enemy);
            }
        }
    }

    if (enemy == EnemyName::TriOrange_)
    {
        for (int i = 0; i < count; ++i) {
            EnemyBase* enemy = nullptr;
            enemy = new Tri_Orange();

            if (enemy) {
                enemy->Initialize();
                m_enemytest.push_back(enemy);
            }
        }
    }*/
}

void BattleManager::DeleteisDeadEnemy()
{
    if (m_enemytest.size() <= 0)
    {
        return;
    }

    for (auto& enemy : m_enemytest) {
        if (enemy->IsDead()) {
            enemy.reset();
            m_destroiedEnemy += 1;
        }
    }
}

void BattleManager::DeleteAllEnemy()
{
    if (m_enemytest.size() <= 0)
    {
        return;
    }

    for (int i = 0; i < m_enemytest.size();i++)
    {
        m_enemytest[i].reset();
            //delete  m_enemytest[i];
            //m_enemytest[i] = nullptr;
    }
}


void BattleManager::DeleteAllATK()
{
    if (m_attack.size() <= 0)
    {
        return;
    }

    for (int i = 0; i < m_attack.size(); i++)
    {
        delete  m_attack[i];
        m_attack[i] = nullptr;
    }
}


void BattleManager::DeleteFinishAtk()
{
    if (m_attack.size() <= 0)
    {
        return;
    }

    for (auto& atk : m_attack) {
        if (atk->IsFinish()) {
            delete atk;
            atk = nullptr;
        }
    }
}

void BattleManager::EraseNullVector()
{
    auto nullvector = std::find(m_enemytest.begin(), m_enemytest.end(), nullptr);
    if (nullvector != m_enemytest.end())
    {
        auto new_end = std::remove(m_enemytest.begin(), m_enemytest.end(), nullptr);
        m_enemytest.erase(new_end, m_enemytest.end());
    }

    auto findnull = std::find(m_attack.begin(), m_attack.end(), nullptr);
    if (findnull != m_attack.end())
    {
        auto new_end = std::remove(m_attack.begin(), m_attack.end(), nullptr);
        m_attack.erase(new_end, m_attack.end());
    }
}

void BattleManager::AllEnemyDestroied()
{
        isAllEnemyDestroied = true;
        DeleteAllEnemy();
        DeleteAllATK();
        EraseNullVector();

       StageManager::GetInstance().AddStage();
       PlayStateController::GetInstance().ChangeState(PlayState::Transition);
       isAllEnemyDestroied = false;
}

void BattleManager::InitEnemyInfo()
{
    m_initEnemyNum = StageManager::GetInstance().GetStageData().enemyCount;
}