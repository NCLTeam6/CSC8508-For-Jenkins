#pragma once
#include "GameObject.h"
#include "Window.h"
#include "GameWorld.h"

namespace NCL {
	namespace CSC8503 {
		class Player :public GameObject
		{
		public:
			Player( const std::string& objectname = "");
			~Player();
			float  GetHealth()
			{
				return health;
			}
			void SetHealth(float inHealth)
			{
				health = inHealth;
			}
			int  GetCollectibles()
			{
				return collectibles;
			}
			float  GetTimer()
			{
				return timer;
			}
			void  ResetPlayerValues(float intimer)
			{
				health = 60;
				timer = 60 * intimer;
			}
			void SetCollectibles(int incollectibles)
			{
				collectibles = incollectibles;
			}
			int  GetIsDead()
			{
				return isDead;
			}
			void SetIsDead(bool inIsDead)
			{
				isDead = inIsDead;
			}
			bool  GetCanJump()
			{
				return canJump;
			}
			void SetCanJump(bool inCanJump)
			{ 
				canJump = inCanJump;
			}
			bool updateJumpTimer(float dt);
			float updateTimer(float dt);
			float updateHealth(float inhealth);
			float updateCollectibles(int collected);
			virtual void OnCollisionBegin(GameObject* otherObject) override;
			bool changeLevel = false;
		protected:
			int health;
			int collectibles;
			float timer;
			float jumpTimer = 0;
			bool isDead = false;
			bool canJump = false;
			//add�timer
		};
	}
}