#include "Enemy.h"

void Enemy::Initialize()
{
	enemy_[1] =
	{
		{100,600},
		{3,0},
		32
	};
	enemy_[2] =
	{
		{300,750},
		{3,0},
		32
	};

	enemy_[3] =
	{
		{200,1000},
		{4,0},
		32
	};

	enemy_[4] =
	{
		{500,1300},
		{2.5,0},
		32
	};

	enemy_[5] =
	{
		{150,1200},
		{3.5,0},
		32
	};

	enemy_[6] =
	{
		{250,1400},
		{3.5,0},
		32
	};

	enemy_[7] =
	{
		{360,1700},
		{3.5,0},
		32
	};

	enemy_[8] =
	{
		{200,2000},
		{3.5,0},
		32
	};

}

void Enemy::Update()
{

	//Še“G‚ðŽ©“®‚Å“®‚©‚µ‚Ä•Ç‚É“–‚½‚é‚Æ”½ŽË‚·‚é
	enemy_[1].position.X += enemy_[1].velocity.X;

	if (enemy_[1].position.X >= 500)
	{
		enemy_[1].velocity.X *= -1;
	}
	if (enemy_[1].position.X <= 100)
	{
		enemy_[1].velocity.X *= -1;
	}
	//gG2
	enemy_[2].position.X += enemy_[2].velocity.X;

	if (enemy_[2].position.X >= 500)
	{
		enemy_[2].velocity.X *= -1;
	}
	if (enemy_[2].position.X <= 100)
	{
		enemy_[2].velocity.X *= -1;
	}
	//gG3
	enemy_[3].position.X += enemy_[3].velocity.X;

	if (enemy_[3].position.X >= 500)
	{
		enemy_[3].velocity.X *= -1;
	}
	if (enemy_[3].position.X <= 100)
	{
		enemy_[3].velocity.X *= -1;
	}
	//gG4
	enemy_[4].position.X += enemy_[4].velocity.X;

	if (enemy_[4].position.X >= 500)
	{
		enemy_[4].velocity.X *= -1;
	}
	if (enemy_[4].position.X <= 100)
	{
		enemy_[4].velocity.X *= -1;
	}
	//gG5
	enemy_[5].position.X += enemy_[5].velocity.X;

	if (enemy_[5].position.X >= 500)
	{
		enemy_[5].velocity.X *= -1;
	}
	if (enemy_[5].position.X <= 100)
	{
		enemy_[5].velocity.X *= -1;
	}

	//6
	enemy_[6].position.X += enemy_[6].velocity.X;

	if (enemy_[6].position.X >= 500)
	{
		enemy_[6].velocity.X *= -1;
	}
	if (enemy_[6].position.X <= 100)
	{
		enemy_[6].velocity.X *= -1;
	}

	//7
	enemy_[7].position.X += enemy_[7].velocity.X;

	if (enemy_[7].position.X >= 500)
	{
		enemy_[7].velocity.X *= -1;
	}
	if (enemy_[7].position.X <= 100)
	{
		enemy_[7].velocity.X *= -1;
	}

	//8
	enemy_[8].position.X += enemy_[8].velocity.X;

	if (enemy_[8].position.X >= 500)
	{
		enemy_[8].velocity.X *= -1;
	}
	if (enemy_[8].position.X <= 100)
	{
		enemy_[8].velocity.X *= -1;
	}

}

void Enemy::Draw(int y)
{
	if (isenemyFlag == false)
	{
		Novice::DrawBox(enemy_[1].position.X, enemy_[1].position.Y, enemy_[1].radius, enemy_[1].radius, 0.0f, BLUE, kFillModeSolid);

	}
	if (isenemyFlag2 == false)
	{
		Novice::DrawBox(enemy_[2].position.X, enemy_[2].position.Y, enemy_[2].radius, enemy_[2].radius, 0.0f, BLUE, kFillModeSolid);

	}
	if (isenemyFlag3 == false)
	{

		Novice::DrawBox(enemy_[3].position.X, enemy_[3].position.Y, enemy_[3].radius, enemy_[3].radius, 0.0f, BLUE, kFillModeSolid);
	}
	if (isenemyFlag4 == false)
	{

		Novice::DrawBox(enemy_[4].position.X, enemy_[4].position.Y, enemy_[4].radius, enemy_[4].radius, 0.0f, BLUE, kFillModeSolid);
	}
	if (isenemyFlag5 == false)
	{

		Novice::DrawBox(enemy_[5].position.X, enemy_[5].position.Y, enemy_[5].radius, enemy_[5].radius, 0.0f, BLUE, kFillModeSolid);
	}
	if (isenemyFlag6 == false)
	{

		Novice::DrawBox(enemy_[6].position.X, enemy_[6].position.Y, enemy_[6].radius, enemy_[6].radius, 0.0f, BLUE, kFillModeSolid);
	}
	if (isenemyFlag7 == false)
	{

		Novice::DrawBox(enemy_[7].position.X, enemy_[7].position.Y, enemy_[7].radius, enemy_[7].radius, 0.0f, BLUE, kFillModeSolid);
	}
	if (isenemyFlag8 == false)
	{

		Novice::DrawBox(enemy_[8].position.X, enemy_[8].position.Y, enemy_[8].radius, enemy_[8].radius, 0.0f, BLUE, kFillModeSolid);
	}
}
