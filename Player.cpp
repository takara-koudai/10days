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
	
	//�ォ��Q�ڂ̃u���b�N
	block2 =
	{
		{0,700},
		800,
		32,
	};

	//�ォ��3�ڂ̃u���b�N
	block3 =
	{
		{0,1000},
		800,
		32
	};

	//�ォ��4�ڂ̃u���b�N
	block4 =
	{
		{0,1200},
		800,
		32
	};

	//�ォ��5�ڂ̃u���b�N
	block5 =
	{
		{0,1500},
		800,
		32,
	};

	//�ォ��6�ڂ̃u���b�N
	block6 =
	{
		{0,1600},
		800,
		32,
	};

	//�ォ��7�ڂ̃u���b�N
	block7 =
	{
		{0,1800},
		800,
		32,
	};

	//�ォ��8�ڂ̃u���b�N
	block8 =
	{
		{0,2200},
		800,
		32,
	};


	//�S�[��
	Goal =
	{
		{500,2335},
		32,
		32,
	};

	//�e���X�̏�����(�X�s�[�h�A���a)
	for (int  i = 0; i < 20; i++)
	{
		bulletspeed[i] = 15;
		bulletradius[i] = 16;
	}

	//�G�̏�����
	enemy.Initialize();

}

void Player::Update(char* keys, char* prekeys)
{

	enemy.Update();

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

	//�X�N���[��(�����ɂ��čs��)
	if (player.position.Y >= 300 && player.position.Y <= 2000)
	{
		scrolY += 2.0f;
	}
	
	//�e����(�����e)
	if (keys[DIK_SPACE] && prekeys[DIK_SPACE] == 0)
	{
		//�A�ł��Ă鎞�͕��V���ė������Ȃ�
		player.velocity.Y -= 8.0f;


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

#pragma region ������u���b�N���
			//�e�Ə���������Ɖ��锻��(��ԏ�̔�����)
			if (bulletposX[i] <= block.center.X + block.raX &&
				block.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block.center.Y + block.raY &&
				block.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//������ƃJ�E���g�𑝂₵��
				//���̃J�E���g�܂ōs���Ə�����
				count += 1;
				if (count >= 10)
				{
					//�u���b�N��������
					blockflag = true;
				}
				
				//�e������
				isbulletFlag[i] = false;
			}

			//��x�������u���b�N�ɍĂђe�𓖂ĂĂ������Ȃ�
			//��ԏ�̃u���b�N
			if (blockflag == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 2��
			//2��
			if (bulletposX[i] <= block2.center.X + block2.raX &&
				block2.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block2.center.Y + block2.raY &&
				block2.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//������ƃJ�E���g�𑝂₵��
				//���̃J�E���g�܂ōs���Ə�����
				count2 += 1;
				if (count2 >= 10)
				{
					//�u���b�N��������
					blockflag2 = true;
				}

				//�e������
				isbulletFlag[i] = false;
			}

			//��x�������u���b�N�ɍĂђe�𓖂ĂĂ������Ȃ�
			//2�ڂ̃u���b�N
			if (blockflag2 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region �R��
			if (bulletposX[i] <= block3.center.X + block3.raX &&
				block3.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block3.center.Y + block3.raY &&
				block3.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//������ƃJ�E���g�𑝂₵��
				//���̃J�E���g�܂ōs���Ə�����
				count3 += 1;
				if (count3 >= 10)
				{
					//�u���b�N��������
					blockflag3 = true;
				}

				//�e������
				isbulletFlag[i] = false;
			}

			//��x�������u���b�N�ɍĂђe�𓖂ĂĂ������Ȃ�
			//3�ڂ̃u���b�N
			if (blockflag3 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 4��

			if (bulletposX[i] <= block4.center.X + block4.raX &&
				block4.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block4.center.Y + block4.raY &&
				block4.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//������ƃJ�E���g�𑝂₵��
				//���̃J�E���g�܂ōs���Ə�����
				count4 += 1;
				if (count4 >= 10)
				{
					//�u���b�N��������
					blockflag4 = true;
				}

				//�e������
				isbulletFlag[i] = false;
			}

			//��x�������u���b�N�ɍĂђe�𓖂ĂĂ������Ȃ�
			//3�ڂ̃u���b�N
			if (blockflag4 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 5��

			if (bulletposX[i] <= block5.center.X + block5.raX &&
				block5.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block5.center.Y + block5.raY &&
				block5.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//������ƃJ�E���g�𑝂₵��
				//���̃J�E���g�܂ōs���Ə�����
				count5 += 1;
				if (count5 >= 10)
				{
					//�u���b�N��������
					blockflag5 = true;
				}

				//�e������
				isbulletFlag[i] = false;
			}

			//��x�������u���b�N�ɍĂђe�𓖂ĂĂ������Ȃ�
			//3�ڂ̃u���b�N
			if (blockflag5 == true)
			{
				isbulletFlag[i] = true;
			}

#pragma endregion

#pragma region 6��

			if (bulletposX[i] <= block6.center.X + block6.raX &&
				block6.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block6.center.Y + block6.raY &&
				block6.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//������ƃJ�E���g�𑝂₵��
				//���̃J�E���g�܂ōs���Ə�����
				count6 += 1;
				if (count6 >= 10)
				{
					//�u���b�N��������
					blockflag6 = true;
				}

				//�e������
				isbulletFlag[i] = false;
			}

			//��x�������u���b�N�ɍĂђe�𓖂ĂĂ������Ȃ�
			//3�ڂ̃u���b�N
			if (blockflag6 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 7��

			if (bulletposX[i] <= block7.center.X + block7.raX &&
				block7.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block7.center.Y + block7.raY &&
				block7.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//������ƃJ�E���g�𑝂₵��
				//���̃J�E���g�܂ōs���Ə�����
				count7 += 1;
				if (count7 >= 10)
				{
					//�u���b�N��������
					blockflag7 = true;
				}

				//�e������
				isbulletFlag[i] = false;
			}

			//��x�������u���b�N�ɍĂђe�𓖂ĂĂ������Ȃ�
			//3�ڂ̃u���b�N
			if (blockflag7 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 8��

			if (bulletposX[i] <= block8.center.X + block8.raX &&
				block8.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block8.center.Y + block8.raY &&
				block8.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//������ƃJ�E���g�𑝂₵��
				//���̃J�E���g�܂ōs���Ə�����
				count8 += 1;
				if (count8 >= 10)
				{
					//�u���b�N��������
					blockflag8 = true;
				}

				//�e������
				isbulletFlag[i] = false;
			}

			//��x�������u���b�N�ɍĂђe�𓖂ĂĂ������Ȃ�
			//3�ڂ̃u���b�N
			if (blockflag8 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region �G�ƒe�̔���

			if (enemy.enemy_[1].position.X <= bulletposX[i] + bulletradius[i] &&
				bulletposX[i] <= enemy.enemy_[1].position.X + enemy.enemy_[1].radius &&
				enemy.enemy_[1].position.Y <= bulletposY[i] + bulletradius[i] &&
				bulletposY[i] <= enemy.enemy_[1].position.Y + enemy.enemy_[1].radius)

			{
				enemy.isenemyFlag = true;
			}

			if (enemy.enemy_[2].position.X <= bulletposX[i] + bulletradius[i] &&
				bulletposX[i] <= enemy.enemy_[2].position.X + enemy.enemy_[2].radius &&
				enemy.enemy_[2].position.Y <= bulletposY[i] + bulletradius[i] &&
				bulletposY[i] <= enemy.enemy_[2].position.Y + enemy.enemy_[2].radius)

			{
				enemy.isenemyFlag2 = true;
			}

			if (enemy.enemy_[3].position.X <= bulletposX[i] + bulletradius[i] &&
				bulletposX[i] <= enemy.enemy_[3].position.X + enemy.enemy_[3].radius &&
				enemy.enemy_[3].position.Y <= bulletposY[i] + bulletradius[i] &&
				bulletposY[i] <= enemy.enemy_[3].position.Y + enemy.enemy_[3].radius)

			{
				enemy.isenemyFlag3 = true;
			}

			if (enemy.enemy_[4].position.X <= bulletposX[i] + bulletradius[i] &&
				bulletposX[i] <= enemy.enemy_[4].position.X + enemy.enemy_[4].radius &&
				enemy.enemy_[4].position.Y <= bulletposY[i] + bulletradius[i] &&
				bulletposY[i] <= enemy.enemy_[4].position.Y + enemy.enemy_[4].radius)

			{
				enemy.isenemyFlag4 = true;
			}

			if (enemy.enemy_[5].position.X <= bulletposX[i] + bulletradius[i] &&
				bulletposX[i] <= enemy.enemy_[5].position.X + enemy.enemy_[5].radius &&
				enemy.enemy_[5].position.Y <= bulletposY[i] + bulletradius[i] &&
				bulletposY[i] <= enemy.enemy_[5].position.Y + enemy.enemy_[5].radius)

			{
				enemy.isenemyFlag5 = true;
			}

			if (enemy.enemy_[6].position.X <= bulletposX[i] + bulletradius[i] &&
				bulletposX[i] <= enemy.enemy_[6].position.X + enemy.enemy_[6].radius &&
				enemy.enemy_[6].position.Y <= bulletposY[i] + bulletradius[i] &&
				bulletposY[i] <= enemy.enemy_[6].position.Y + enemy.enemy_[6].radius)

			{
				enemy.isenemyFlag6 = true;
			}

			if (enemy.enemy_[7].position.X <= bulletposX[i] + bulletradius[i] &&
				bulletposX[i] <= enemy.enemy_[7].position.X + enemy.enemy_[7].radius &&
				enemy.enemy_[7].position.Y <= bulletposY[i] + bulletradius[i] &&
				bulletposY[i] <= enemy.enemy_[7].position.Y + enemy.enemy_[7].radius)

			{
				enemy.isenemyFlag7 = true;
			}

			if (enemy.enemy_[8].position.X <= bulletposX[i] + bulletradius[i] &&
				bulletposX[i] <= enemy.enemy_[8].position.X + enemy.enemy_[8].radius &&
				enemy.enemy_[8].position.Y <= bulletposY[i] + bulletradius[i] &&
				bulletposY[i] <= enemy.enemy_[8].position.Y + enemy.enemy_[8].radius)

			{
				enemy.isenemyFlag8 = true;
			}


#pragma endregion
			
		}

		//�J�E���g��i�߂�250�ɂȂ�Ə����e�������ă��Z�b�g
		if (bulletAliveCount[i] >= 200 && isbulletFlag[i] == true)
		{
			bulletAliveCount[i] = 0;
			isbulletFlag[i] = false;
		}
	}

#pragma region �����Ă�u���b�N�ɓ������Ă����ȂȂ����
	//�u���b�N�������Ă鎞��
	//�v���C���[���u���b�N�ɓ������Ă����ȂȂ�
	if (blockflag == false)
	{
		//�����Ə����鏰�̔���
		if (player.position.X <= block.center.X + block.raX &&
			block.center.X <= player.position.X + player.radius &&
			player.position.Y <= block.center.Y + block.raY &&
			block.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
			//Novice::ScreenPrintf(100, 70, "sinu");
		}
	}
#pragma endregion

#pragma region �Q��
	if (blockflag2 == false)
	{
		//�����Ə����鏰�̔���
		if (player.position.X <= block2.center.X + block2.raX &&
			block2.center.X <= player.position.X + player.radius &&
			player.position.Y <= block2.center.Y + block2.raY &&
			block2.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
			//Novice::ScreenPrintf(100, 70, "sinu");
		}
	}
#pragma endregion

#pragma region �R��

	if (blockflag3 == false)
	{
		//�����Ə����鏰�̔���
		if (player.position.X <= block3.center.X + block3.raX &&
			block3.center.X <= player.position.X + player.radius &&
			player.position.Y <= block3.center.Y + block3.raY &&
			block3.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
			//Novice::ScreenPrintf(100, 70, "sinu");
		}
	}

#pragma endregion

#pragma region 4��

	if (blockflag4 == false)
	{
		//�����Ə����鏰�̔���
		if (player.position.X <= block4.center.X + block4.raX &&
			block4.center.X <= player.position.X + player.radius &&
			player.position.Y <= block4.center.Y + block4.raY &&
			block4.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region 5��

	if (blockflag5 == false)
	{
		//�����Ə����鏰�̔���
		if (player.position.X <= block5.center.X + block5.raX &&
			block5.center.X <= player.position.X + player.radius &&
			player.position.Y <= block5.center.Y + block5.raY &&
			block5.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region 6��

	if (blockflag6 == false)
	{
		//�����Ə����鏰�̔���
		if (player.position.X <= block6.center.X + block6.raX &&
			block6.center.X <= player.position.X + player.radius &&
			player.position.Y <= block6.center.Y + block6.raY &&
			block6.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region 7��

	if (blockflag7 == false)
	{
		//�����Ə����鏰�̔���
		if (player.position.X <= block7.center.X + block7.raX &&
			block7.center.X <= player.position.X + player.radius &&
			player.position.Y <= block7.center.Y + block7.raY &&
			block7.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region 8��

	if (blockflag8 == false)
	{
		//�����Ə����鏰�̔���
		if (player.position.X <= block8.center.X + block8.raX &&
			block8.center.X <= player.position.X + player.radius &&
			player.position.Y <= block8.center.Y + block8.raY &&
			block8.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region �����ƓG�̔���

	if (enemy.isenemyFlag == false)
	{
		if (player.position.X <= enemy.enemy_[1].position.X + enemy.enemy_[1].radius &&
			enemy.enemy_[1].position.X <= player.position.X + player.radius &&
			player.position.Y <= enemy.enemy_[1].position.Y + enemy.enemy_[1].radius &&
			enemy.enemy_[1].position.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}
	
	if (enemy.isenemyFlag2 == false)
	{
		if (player.position.X <= enemy.enemy_[2].position.X + enemy.enemy_[2].radius &&
			enemy.enemy_[2].position.X <= player.position.X + player.radius &&
			player.position.Y <= enemy.enemy_[2].position.Y + enemy.enemy_[2].radius &&
			enemy.enemy_[2].position.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

	if (enemy.isenemyFlag3 == false)
	{
		if (player.position.X <= enemy.enemy_[3].position.X + enemy.enemy_[3].radius &&
			enemy.enemy_[3].position.X <= player.position.X + player.radius &&
			player.position.Y <= enemy.enemy_[3].position.Y + enemy.enemy_[3].radius &&
			enemy.enemy_[3].position.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

	if (enemy.isenemyFlag4 == false)
	{
		if (player.position.X <= enemy.enemy_[4].position.X + enemy.enemy_[4].radius &&
			enemy.enemy_[4].position.X <= player.position.X + player.radius &&
			player.position.Y <= enemy.enemy_[4].position.Y + enemy.enemy_[4].radius &&
			enemy.enemy_[4].position.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

	if (enemy.isenemyFlag5 == false)
	{
		if (player.position.X <= enemy.enemy_[5].position.X + enemy.enemy_[5].radius &&
			enemy.enemy_[5].position.X <= player.position.X + player.radius &&
			player.position.Y <= enemy.enemy_[5].position.Y + enemy.enemy_[5].radius &&
			enemy.enemy_[5].position.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

	if (enemy.isenemyFlag6 == false)
	{
		if (player.position.X <= enemy.enemy_[6].position.X + enemy.enemy_[6].radius &&
			enemy.enemy_[6].position.X <= player.position.X + player.radius &&
			player.position.Y <= enemy.enemy_[6].position.Y + enemy.enemy_[6].radius &&
			enemy.enemy_[6].position.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

	if (enemy.isenemyFlag7 == false)
	{
		if (player.position.X <= enemy.enemy_[7].position.X + enemy.enemy_[7].radius &&
			enemy.enemy_[7].position.X <= player.position.X + player.radius &&
			player.position.Y <= enemy.enemy_[7].position.Y + enemy.enemy_[7].radius &&
			enemy.enemy_[7].position.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}
	
	if (enemy.isenemyFlag8 == false)
	{
		if (player.position.X <= enemy.enemy_[8].position.X + enemy.enemy_[8].radius &&
			enemy.enemy_[8].position.X <= player.position.X + player.radius &&
			player.position.Y <= enemy.enemy_[8].position.Y + enemy.enemy_[8].radius &&
			enemy.enemy_[8].position.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion


#pragma region �S�[���Ƃ̔���

	//�S�[���Ǝ����̓����蔻��
	if (player.position.X <= Goal.center.X + Goal.raX &&
		Goal.center.X <= player.position.X + player.radius &&
		player.position.Y <= Goal.center.Y + Goal.raY &&
		Goal.center.Y <= player.position.Y + player.radius)
	{
		//�N���A
		gameClear = true;
	}
#pragma endregion

#pragma region ���Ԑ���
	//���Ԑ�������
	timer++;

	if (timer == 1800)
	{
		gameoverflag = true;
	}
	if (timer == 600)
	{
		timerflag = true;
		timerflag2 = true;
	}
	if (timer == 1200)
	{
		timerflag2 = false;
		timerflag3 = true;
	}

	//30�b���z����ƃQ�[���I�[�o�[�ɂȂ�
	if (timer >= 1800)
	{
		//�Q�[���I�[�o�[
		gameOver = true;
	}

#pragma endregion


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

#pragma region �G�̕`��

	if (enemy.isenemyFlag == false)
	{
		Novice::DrawSprite(enemy.enemy_[1].position.X, enemy.enemy_[1].position.Y - scrolY, enemyirasuto, 1, 1, 0.0f, WHITE);
	}

	if (enemy.isenemyFlag2 == false)
	{
		Novice::DrawSprite(enemy.enemy_[2].position.X, enemy.enemy_[2].position.Y - scrolY, enemyirasuto2, 1, 1, 0.0f, WHITE);
	}

	if (enemy.isenemyFlag3 == false)
	{
		Novice::DrawSprite(enemy.enemy_[3].position.X, enemy.enemy_[3].position.Y - scrolY, enemyirasuto3, 1, 1, 0.0f, WHITE);
	}

	if (enemy.isenemyFlag4 == false)
	{
		Novice::DrawSprite(enemy.enemy_[4].position.X, enemy.enemy_[4].position.Y - scrolY, enemyirasuto2, 1, 1, 0.0f, WHITE);
	}

	if (enemy.isenemyFlag5 == false)
	{
		Novice::DrawSprite(enemy.enemy_[5].position.X, enemy.enemy_[5].position.Y - scrolY, enemyirasuto3, 1, 1, 0.0f, WHITE);
	}

	if (enemy.isenemyFlag6 == false)
	{
		Novice::DrawSprite(enemy.enemy_[6].position.X, enemy.enemy_[6].position.Y - scrolY, enemyirasuto, 1, 1, 0.0f, WHITE);
	}

	if (enemy.isenemyFlag7 == false)
	{
		Novice::DrawSprite(enemy.enemy_[7].position.X, enemy.enemy_[7].position.Y - scrolY, enemyirasuto2, 1, 1, 0.0f, WHITE);
	}

	if (enemy.isenemyFlag8 == false)
	{
		Novice::DrawSprite(enemy.enemy_[8].position.X, enemy.enemy_[8].position.Y - scrolY, enemyirasuto3, 1, 1, 0.0f, WHITE);
	}



#pragma endregion


	//�c�莞��(���v30�b)
	if (timerflag == false) //30�b
	{
		Novice::DrawSprite(500, 30, timerirasuto3, 1, 1, 0.0f, WHITE);
	}
	if (timerflag2 == true) //20�b
	{
		Novice::DrawSprite(500, 30, timerirasuto2, 1, 1, 0.0f, WHITE);
	}
	if (timerflag3 == true) //10�b
	{
		Novice::DrawSprite(500, 30, timerirasuto, 1, 1, 0.0f, WHITE);
	}


	//�e�̕`��
	for (int  i = 0; i < bulletnum; i++)
	{
		if (isbulletFlag[i] == true) 
		{
			Novice::DrawBox(bulletposX[i] - 3, bulletposY[i] - scrolY, bulletradius[i], bulletradius[i], 0.0f, RED, kFillModeSolid);
		}
	}

	//����
	Novice::DrawSprite(player.position.X - player.radius, player.position.Y - player.radius - scrolY, plirasuto, 1, 1, 0.0f, WHITE);

	//�S�[��
	Novice::DrawBox(Goal.center.X, Goal.center.Y - scrolY, Goal.raX, Goal.raY, 0.0f, BLUE, kFillModeSolid);


#pragma region ����u���b�N

	if (blockflag == false)
	{
		//��ԏ�
		//���̔�����(�e�𓖂Ă�Ɖ���)
		Novice::DrawBox(block.center.X, block.center.Y - scrolY, block.raX, block.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag2 == false)
	{
		//�ォ��2�ڂ̃u���b�N
		Novice::DrawBox(block2.center.X, block2.center.Y - scrolY, block2.raX, block2.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag3 == false)
	{
		//�ォ��3�ڂ̃u���b�N
		Novice::DrawBox(block3.center.X, block3.center.Y - scrolY, block3.raX, block3.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag4 == false)
	{
		//�ォ��4�ڂ̃u���b�N
		Novice::DrawBox(block4.center.X, block4.center.Y - scrolY, block4.raX, block4.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag5 == false)
	{
		//�ォ��5�ڂ̃u���b�N
		Novice::DrawBox(block5.center.X, block5.center.Y - scrolY, block5.raX, block5.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag6 == false)
	{
		//�ォ��6�ڂ̃u���b�N
		Novice::DrawBox(block6.center.X, block6.center.Y - scrolY, block6.raX, block6.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag7 == false)
	{
		//�ォ��6�ڂ̃u���b�N
		Novice::DrawBox(block7.center.X, block7.center.Y - scrolY, block7.raX, block7.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag8 == false)
	{
		//�ォ��6�ڂ̃u���b�N
		Novice::DrawBox(block8.center.X, block8.center.Y - scrolY, block8.raX, block8.raY, 0.0f, WHITE, kFillModeSolid);
	}


#pragma endregion
	
	//�u���b�N�`��(�ǂƈ�ԉ��̏�)
	for (int y = 0; y < 75; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			if (map[y][x] == BLOCK)//���ʂ̃u���b�N
			{
				Novice::DrawSprite(x * BLOCKsize, y * BLOCKsize - scrolY, BLOCKirasuto, 1, 1, 0.0f, WHITE);
			}
		}
	}
}

//�֐����Z�b�g(�t���O��^�C�}�[�ȂǁA�ׂ����Ƃ���)
void Player::Reset()
{
	timer = 0;
	scrolY = 0;

	gameClear = false;
	gameOver = false;

	//�^�C�}�[
	timerflag = false;
	timerflag2 = false;
	timerflag3 = false;

	//���ɓ�����ƃQ�[���I�[�o�[�ɂȂ�t���O
	blockflag = false;
	blockflag2 = false;
	blockflag3 = false;
	blockflag4 = false;
	blockflag5 = false;
	blockflag6 = false;
	blockflag7 = false;
	blockflag8 = false;

	//�J�E���g
	count = 0;
	count2 = 0;
	count3 = 0;
	count4 = 0;
	count5 = 0;
	count6 = 0;
	count7 = 0;
	count8 = 0;

	enemy.isenemyFlag = false;
	enemy.isenemyFlag2 = false;
	enemy.isenemyFlag3 = false;
	enemy.isenemyFlag4 = false;
	enemy.isenemyFlag5 = false;
	enemy.isenemyFlag6 = false;
	enemy.isenemyFlag7 = false;
	enemy.isenemyFlag8 = false;

	//�e
	const int bulletnum = 20;
	int bulletposX[20] = { 0 };
	int bulletposY[20] = { 0 };
	int bulletspeed[20] = { 0 };
	int bulletradius[20];

	int isbulletFlag[20] = { false };

	int bulletAliveCount[20];
}


