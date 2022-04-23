#pragma once

#include "Gameplay/Components/IComponent.h"
#include "Gameplay/Physics/RigidBody.h"
#include "Gameplay/GameObject.h"

// Utils
#include "Utils/GUID.hpp"

// GLM
#define GLM_ENABLE_EXPERIMENTAL
#include "GLM/gtx/common.hpp"

// Others
#include "Gameplay/Components/IComponent.h"
#include "Gameplay/Components/ComponentManager.h"

class EnemyControl : public Gameplay::IComponent
{
public:

	typedef std::shared_ptr<EnemyControl> Sptr;

	EnemyControl();
	virtual ~EnemyControl();
	void Update(float deltaTime);

	std::weak_ptr<Gameplay::IComponent> golem1;
public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(EnemyControl);
	virtual nlohmann::json ToJson() const override;
	static EnemyControl::Sptr FromJson(const nlohmann::json& blob);
	float m_segmentTravelTime = 8.0f;

private:
	size_t m_segmentIndex = 0;

protected:
	float _impulse;
	float _timer = 0.0f;

	float _playbackSpeed;
};

