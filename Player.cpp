#include "Player.h"
#include <stdio.h>


Player::~Player()
{

}

void Player::Initialize()
{
	//�v���C���[
	player =
	{
		{64,64},
		{0,0},
		16
	};

	//�U���ŉ���u���b�N
	block =
	{
		{0,500},
		800,
		32,
	};


	//�e���X�̏�����(�X�s�[�h�A���a)
	for (int  i = 0; i < 20; i++)
	{
		bulletspeed[i] = 15;
		bulletradius[i] = 16;
	}
	
}

void Player::Update(char* keys, char* prekeys)
{

#pragma region �v���C���[�̓���
	//�E�ɓ���
	if (keys[DIK_A])
	{
		player.velocity.X = -5;
	}
	if (keys[DIK_A] == 0 && prekeys[DIK_A])
	{
		player.velocity.X = 0;
	}

	//���ɓ���
	if (keys[DIK_D])
	{
		player.velocity.X = 5;
	}

	if (keys[DIK_D] == 0 && prekeys[DIK_D])
	{
		player.velocity.X = 0;
	}

	//�d��
	player.velocity.Y += gravity;
	
	//�e����(�����e)
	if (keys[DIK_SPACE] && prekeys[DIK_SPACE] == 0)
	{
		//�A�ł��Ă鎞�͕��V���ė������Ȃ�
		player.velocity.Y -= 10.0f;


		for (int i = 0; i < 20; i++)
		{
			if (isbulletFlag[i] == false)
			{
				bulletposX[i] = player.position.X - 5;
				bulletposY[i] = player.position.Y;

				isbulletFlag[i] = true;

				break;
			}
		}
	}

	//�e�̃t���O�ƃJ�E���g��0�ɂ���
	for (int i = 0; i < bulletnum; i++)
	{
		//�e����(������)
		if (isbulletFlag[i] == true)
		{
			bulletposY[i] += bulletspeed[i];

			bulletAliveCount[i] += 1;

			//�e�Ə���������Ɖ��锻��


			//Novice::ScreenPrintf(100, 100, "atari");

		}

		//�J�E���g��i�߂�250�ɂȂ�Ə����e�������ă��Z�b�g
		if (bulletAliveCount[i] >= 200 && isbulletFlag[i] == true)
		{
			bulletAliveCount[i] = 0;
			isbulletFlag[i] = false;
		}
	}

	

	//�e�ƓG�Ƃ̔���


#pragma endregion

#pragma region �}�b�v�`�b�v����(�v���C���[)
	//4���_�̍��W
	float top = player.position.Y - player.radius;
	float down = player.position.Y + player.radius - 1;
	float right = player.position.X + player.radius - 1;
	float left = player.position.X - player.radius;

	//���E�̔���
	if (map[(int)(top / 32)][(int)((left + player.velocity.X) / 32)] == 1 ||
		map[(int)(top / 32)][(int)((right + player.velocity.X) / 32)] == 1 ||
		map[(int)(down / 32)][(int)((left + player.velocity.X) / 32)] == 1 ||
		map[(int)(down / 32)][(int)((right + player.velocity.X) / 32)] == 1)
	{
		if (player.velocity.X > 0)
		{
			while (map[(int)(top / 32)][(int)((left + 1) / 32)] == 0 &&
				map[(int)(top / 32)][(int)((right + 1) / 32)] == 0 &&
				map[(int)(down / 32)][(int)((left + 1) / 32)] == 0 &&
				map[(int)(down / 32)][(int)((right + 1) / 32)] == 0)
			{
				player.position.Y += 1;
				left += 1;
				right += 1;
			}

			while (map[(int)(top / 32)][(int)((left + 1) / 32)] == 2 &&
				map[(int)(top / 32)][(int)((right + 1) / 32)] == 2 &&
				map[(int)(down / 32)][(int)((left + 1) / 32)] == 2 &&
				map[(int)(down / 32)][(int)((right + 1) / 32)] == 2)
			{
				player.position.Y += 1;
				left += 1;
				right += 1;
			}
		}


		if (player.velocity.X < 0)
		{
			while (map[(int)(top / 32)][(int)((left - 1) / 32)] == 0 &&
				map[(int)(top / 32)][(int)((right - 1) / 32)] == 0 &&
				map[(int)(down / 32)][(int)((left - 1) / 32)] == 0 &&
				map[(int)(down / 32)][(int)((right - 1) / 32)] == 0)
			{
				player.position.X -= 1;
				left -= 1;
				right -= 1;
			}

			while (map[(int)(top / 32)][(int)((left - 1) / 32)] == 2 &&
				map[(int)(top / 32)][(int)((right - 1) / 32)] == 2 &&
				map[(int)(down / 32)][(int)((left - 1) / 32)] == 2 &&
				map[(int)(down / 32)][(int)((right - 1) / 32)] == 2)
			{
				player.position.X -= 1;
				left -= 1;
				right -= 1;
			}
		}

		player.velocity.X = 0;
	}

	//�㉺�̔���
	top = player.position.Y - player.radius;
	down = player.position.Y + player.radius - 1;
	right = player.position.X + player.radius - 1;
	left = player.position.X - player.radius;

	//�u���b��0�ȊO�̎��ɔ�������
	//�u���b�N��0�ȊO�̎��ɔ�������
	if (map[(int)((top + player.velocity.Y) / 32)][(int)((left) / 32)] == 1 ||
		map[(int)((top + player.velocity.Y) / 32)][(int)((right) / 32)] == 1 ||
		map[(int)((down + player.velocity.Y) / 32)][(int)((left) / 32)] == 1 ||
		map[(int)((down + player.velocity.Y) / 32)][(int)((right) / 32)] == 1)
	{

		if (player.velocity.Y > 0)
		{
			while (map[(int)((top + 1) / 32)][(int)((left) / 32)] == 0 &&
				map[(int)((top + 1) / 32)][(int)((right) / 32)] == 0 &&
				map[(int)((down + 1) / 32)][(int)((left) / 32)] == 0 &&
				map[(int)((down + 1) / 32)][(int)((right) / 32)] == 0)
			{
				player.position.Y += 1;
				top += 1;
				down += 1;
			}

			while (map[(int)((top + 1) / 32)][(int)((left) / 32)] == 2 &&
				map[(int)((top + 1) / 32)][(int)((right) / 32)] == 2 &&
				map[(int)((down + 1) / 32)][(int)((left) / 32)] == 2 &&
				map[(int)((down + 1) / 32)][(int)((right) / 32)] == 2)
			{
				player.position.Y += 1;
				top += 1;
				down += 1;
			}

		}


		//1�񂵂��W�����v���Ȃ���
		if (map[(int)((down + 1) / 32)][(int)((left) / 32)] == 2 ||
			map[(int)((down + 1) / 32)][(int)((right) / 32)] == 2)
		{
			//jampFlag = false;//���߃W�����v
			//wallflag = false;//�ǃL�b�N
			
		}
		//1�񂵂��W�����v���Ȃ���


		if (player.velocity.Y < 0)
		{
			while (map[(int)((top - 1) / 32)][(int)((left) / 32)] == 0 &&
				map[(int)((top - 1) / 32)][(int)((right) / 32)] == 0 &&
				map[(int)((down - 1) / 32)][(int)((left) / 32)] == 0 &&
				map[(int)((down - 1) / 32)][(int)((right) / 32)] == 0)
			{
				player.position.Y -= 1;
				top -= 1;
				down -= 1;
			}

			while (map[(int)((top - 1) / 32)][(int)((left) / 32)] == 2 &&
				map[(int)((top - 1) / 32)][(int)((right) / 32)] == 2 &&
				map[(int)((down - 1) / 32)][(int)((left) / 32)] == 2 &&
				map[(int)((down - 1) / 32)][(int)((right) / 32)] == 2)
			{
				player.position.Y -= 1;
				top -= 1;
				down -= 1;
			}

		}

		player.velocity.Y = 0;
	}

	player.position.X += player.velocity.X;
	player.position.Y += player.velocity.Y;

	

#pragma endregion

}

void Player::Draw()
{
	//�w�i
	Novice::DrawBox(0, 0, 800, 800, 0.0f, BLACK, kFillModeSolid);

	//�e�̕`��
	for (int  i = 0; i < bulletnum; i++)
	{
		if (isbulletFlag[i] == true) 
		{
			Novice::DrawBox(bulletposX[i] - 3, bulletposY[i], bulletradius[i], bulletradius[i], 0.0f, RED, kFillModeSolid);
		}
	}

	//�e�̍��W�Ȃ�(�f�o�b�O�p�ϐ��̐����������悤��)
	for (int i = 0; i < bulletnum; i++)
	{
		if (isbulletFlag[i] == true)
		{
			Novice::ScreenPrintf(10, i * 20, "bullet%d: x:%d,     y:%d,    isShot:%d", i, bulletposX[i], bulletposY[i], isbulletFlag[i]);
		}

		if (isbulletFlag[i] == true)
		{
			Novice::ScreenPrintf(500, i * 20, "Count %d",bulletAliveCount[i]);
			//Novice::ScreenPrintf(500, i * 20, "Count %d", ak);
		}
	}

	//����
	Novice::DrawSprite(player.position.X - player.radius, player.position.Y - player.radius, irasuto, 1, 1, 0.0f, WHITE);
	
	//���̔�����(�e�𓖂Ă�Ɖ���)
	Novice::DrawBox(block.center.X, block.center.Y, block.raX, block.raY, 0.0f, WHITE, kFillModeSolid);
	

	//�u���b�N�`��
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			if (map[y][x] == BLOCK)//���ʂ̃u���b�N
			{
				Novice::DrawSprite(x * BLOCKsize, y * BLOCKsize, BLOCKirasuto, 1, 1, 0.0f, WHITE);
			}


			if (map[y][x] == BLOCK2)//�U���ŉ���u���b�N
			{

				//Novice::DrawSprite(k = x * BLOCKsize, o = y * BLOCKsize, BLOCKirasuto, 1, 1, 0.0f, WHITE);
				//Novice::DrawSprite(x * BLOCKsize, y * BLOCKsize, BLOCKirasuto, 1, 1, 0.0f, WHITE);
			}
			
		}
	}
}


