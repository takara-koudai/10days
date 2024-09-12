#include "Player.h"
#include <stdio.h>

Player::~Player()
{

}

void Player::Initialize()
{
	//プレイヤー
	player =
	{
		{64,64},
		{0,0},
		16
	};

	//攻撃で壊れるブロック
	block =
	{
		{0,500},
		800,
		32,
	};
	
	//上から２つ目のブロック
	block2 =
	{
		{0,700},
		800,
		32,
	};

	//上から3つ目のブロック
	block3 =
	{
		{0,1000},
		800,
		32
	};

	//上から4つ目のブロック
	block4 =
	{
		{0,1200},
		800,
		32
	};

	//上から5つ目のブロック
	block5 =
	{
		{0,1500},
		800,
		32,
	};

	//上から6つ目のブロック
	block6 =
	{
		{0,1600},
		800,
		32,
	};

	//上から7つ目のブロック
	block7 =
	{
		{0,1800},
		800,
		32,
	};

	//上から8つ目のブロック
	block8 =
	{
		{0,2200},
		800,
		32,
	};


	//ゴール
	Goal =
	{
		{500,2335},
		32,
		32,
	};

	//弾諸々の初期化(スピード、半径)
	for (int  i = 0; i < 20; i++)
	{
		bulletspeed[i] = 15;
		bulletradius[i] = 16;
	}

	//敵の初期化
	enemy.Initialize();

}

void Player::Update(char* keys, char* prekeys)
{

	enemy.Update();

#pragma region プレイヤーの動き
	//右に動く
	if (keys[DIK_A])
	{
		player.velocity.X = -5;
	}
	if (keys[DIK_A] == 0 && prekeys[DIK_A])
	{
		player.velocity.X = 0;
	}

	//左に動く
	if (keys[DIK_D])
	{
		player.velocity.X = 5;
	}

	if (keys[DIK_D] == 0 && prekeys[DIK_D])
	{
		player.velocity.X = 0;
	}

	//重力
	player.velocity.Y += gravity;

	//スクロール(落下について行く)
	if (player.position.Y >= 300 && player.position.Y <= 2000)
	{
		scrolY += 2.0f;
	}
	
	//弾発射(複数弾)
	if (keys[DIK_SPACE] && prekeys[DIK_SPACE] == 0)
	{
		//連打してる時は浮遊して落下しない
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

	//弾のフラグとカウントを0にする
	for (int i = 0; i < bulletnum; i++)
	{
		//弾発射(動かす)
		if (isbulletFlag[i] == true)
		{
			bulletposY[i] += bulletspeed[i];

			bulletAliveCount[i] += 1;

#pragma region 消えるブロック一つ目
			//弾と床が当たると壊れる判定(一番上の白い床)
			if (bulletposX[i] <= block.center.X + block.raX &&
				block.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block.center.Y + block.raY &&
				block.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//当たるとカウントを増やして
				//一定のカウントまで行くと消える
				count += 1;
				if (count >= 10)
				{
					//ブロックが消える
					blockflag = true;
				}
				
				//弾を消す
				isbulletFlag[i] = false;
			}

			//一度消えたブロックに再び弾を当てても消えない
			//一番上のブロック
			if (blockflag == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 2つ目
			//2つ目
			if (bulletposX[i] <= block2.center.X + block2.raX &&
				block2.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block2.center.Y + block2.raY &&
				block2.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//当たるとカウントを増やして
				//一定のカウントまで行くと消える
				count2 += 1;
				if (count2 >= 10)
				{
					//ブロックが消える
					blockflag2 = true;
				}

				//弾を消す
				isbulletFlag[i] = false;
			}

			//一度消えたブロックに再び弾を当てても消えない
			//2つ目のブロック
			if (blockflag2 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region ３つ目
			if (bulletposX[i] <= block3.center.X + block3.raX &&
				block3.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block3.center.Y + block3.raY &&
				block3.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//当たるとカウントを増やして
				//一定のカウントまで行くと消える
				count3 += 1;
				if (count3 >= 10)
				{
					//ブロックが消える
					blockflag3 = true;
				}

				//弾を消す
				isbulletFlag[i] = false;
			}

			//一度消えたブロックに再び弾を当てても消えない
			//3つ目のブロック
			if (blockflag3 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 4つ目

			if (bulletposX[i] <= block4.center.X + block4.raX &&
				block4.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block4.center.Y + block4.raY &&
				block4.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//当たるとカウントを増やして
				//一定のカウントまで行くと消える
				count4 += 1;
				if (count4 >= 10)
				{
					//ブロックが消える
					blockflag4 = true;
				}

				//弾を消す
				isbulletFlag[i] = false;
			}

			//一度消えたブロックに再び弾を当てても消えない
			//3つ目のブロック
			if (blockflag4 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 5つ目

			if (bulletposX[i] <= block5.center.X + block5.raX &&
				block5.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block5.center.Y + block5.raY &&
				block5.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//当たるとカウントを増やして
				//一定のカウントまで行くと消える
				count5 += 1;
				if (count5 >= 10)
				{
					//ブロックが消える
					blockflag5 = true;
				}

				//弾を消す
				isbulletFlag[i] = false;
			}

			//一度消えたブロックに再び弾を当てても消えない
			//3つ目のブロック
			if (blockflag5 == true)
			{
				isbulletFlag[i] = true;
			}

#pragma endregion

#pragma region 6つ目

			if (bulletposX[i] <= block6.center.X + block6.raX &&
				block6.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block6.center.Y + block6.raY &&
				block6.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//当たるとカウントを増やして
				//一定のカウントまで行くと消える
				count6 += 1;
				if (count6 >= 10)
				{
					//ブロックが消える
					blockflag6 = true;
				}

				//弾を消す
				isbulletFlag[i] = false;
			}

			//一度消えたブロックに再び弾を当てても消えない
			//3つ目のブロック
			if (blockflag6 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 7つ目

			if (bulletposX[i] <= block7.center.X + block7.raX &&
				block7.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block7.center.Y + block7.raY &&
				block7.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//当たるとカウントを増やして
				//一定のカウントまで行くと消える
				count7 += 1;
				if (count7 >= 10)
				{
					//ブロックが消える
					blockflag7 = true;
				}

				//弾を消す
				isbulletFlag[i] = false;
			}

			//一度消えたブロックに再び弾を当てても消えない
			//3つ目のブロック
			if (blockflag7 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 8つ目

			if (bulletposX[i] <= block8.center.X + block8.raX &&
				block8.center.X <= bulletposX[i] + bulletradius[i] &&
				bulletposY[i] <= block8.center.Y + block8.raY &&
				block8.center.Y <= bulletposY[i] + bulletradius[i])
			{
				//当たるとカウントを増やして
				//一定のカウントまで行くと消える
				count8 += 1;
				if (count8 >= 10)
				{
					//ブロックが消える
					blockflag8 = true;
				}

				//弾を消す
				isbulletFlag[i] = false;
			}

			//一度消えたブロックに再び弾を当てても消えない
			//3つ目のブロック
			if (blockflag8 == true)
			{
				isbulletFlag[i] = true;
			}
#pragma endregion

#pragma region 敵と弾の判定

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

		//カウントを進めて250になると順次弾を消してリセット
		if (bulletAliveCount[i] >= 200 && isbulletFlag[i] == true)
		{
			bulletAliveCount[i] = 0;
			isbulletFlag[i] = false;
		}
	}

#pragma region 消えてるブロックに当たっても死なない一つ目
	//ブロックが消えてる時に
	//プレイヤーがブロックに当たっても死なない
	if (blockflag == false)
	{
		//自分と消える床の判定
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

#pragma region ２つ目
	if (blockflag2 == false)
	{
		//自分と消える床の判定
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

#pragma region ３つ目

	if (blockflag3 == false)
	{
		//自分と消える床の判定
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

#pragma region 4つ目

	if (blockflag4 == false)
	{
		//自分と消える床の判定
		if (player.position.X <= block4.center.X + block4.raX &&
			block4.center.X <= player.position.X + player.radius &&
			player.position.Y <= block4.center.Y + block4.raY &&
			block4.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region 5つ目

	if (blockflag5 == false)
	{
		//自分と消える床の判定
		if (player.position.X <= block5.center.X + block5.raX &&
			block5.center.X <= player.position.X + player.radius &&
			player.position.Y <= block5.center.Y + block5.raY &&
			block5.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region 6つ目

	if (blockflag6 == false)
	{
		//自分と消える床の判定
		if (player.position.X <= block6.center.X + block6.raX &&
			block6.center.X <= player.position.X + player.radius &&
			player.position.Y <= block6.center.Y + block6.raY &&
			block6.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region 7つ目

	if (blockflag7 == false)
	{
		//自分と消える床の判定
		if (player.position.X <= block7.center.X + block7.raX &&
			block7.center.X <= player.position.X + player.radius &&
			player.position.Y <= block7.center.Y + block7.raY &&
			block7.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region 8つ目

	if (blockflag8 == false)
	{
		//自分と消える床の判定
		if (player.position.X <= block8.center.X + block8.raX &&
			block8.center.X <= player.position.X + player.radius &&
			player.position.Y <= block8.center.Y + block8.raY &&
			block8.center.Y <= player.position.Y + player.radius)
		{
			gameOver = true;
		}
	}

#pragma endregion

#pragma region 自分と敵の判定

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


#pragma region ゴールとの判定

	//ゴールと自分の当たり判定
	if (player.position.X <= Goal.center.X + Goal.raX &&
		Goal.center.X <= player.position.X + player.radius &&
		player.position.Y <= Goal.center.Y + Goal.raY &&
		Goal.center.Y <= player.position.Y + player.radius)
	{
		//クリア
		gameClear = true;
	}
#pragma endregion

#pragma region 時間制限
	//時間制限処理
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

	//30秒を越えるとゲームオーバーになる
	if (timer >= 1800)
	{
		//ゲームオーバー
		gameOver = true;
	}

#pragma endregion


#pragma endregion

#pragma region マップチップ判定(プレイヤー)
	//4頂点の座標
	float top = player.position.Y - player.radius;
	float down = player.position.Y + player.radius - 1;
	float right = player.position.X + player.radius - 1;
	float left = player.position.X - player.radius;

	//左右の判定
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

	//上下の判定
	top = player.position.Y - player.radius;
	down = player.position.Y + player.radius - 1;
	right = player.position.X + player.radius - 1;
	left = player.position.X - player.radius;

	//ブロッが0以外の時に判定を取る
	//ブロックが0以外の時に判定を取る
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
	//背景
	Novice::DrawBox(0, 0, 800, 800, 0.0f, BLACK, kFillModeSolid);

#pragma region 敵の描画

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


	//残り時間(合計30秒)
	if (timerflag == false) //30秒
	{
		Novice::DrawSprite(500, 30, timerirasuto3, 1, 1, 0.0f, WHITE);
	}
	if (timerflag2 == true) //20秒
	{
		Novice::DrawSprite(500, 30, timerirasuto2, 1, 1, 0.0f, WHITE);
	}
	if (timerflag3 == true) //10秒
	{
		Novice::DrawSprite(500, 30, timerirasuto, 1, 1, 0.0f, WHITE);
	}


	//弾の描画
	for (int  i = 0; i < bulletnum; i++)
	{
		if (isbulletFlag[i] == true) 
		{
			Novice::DrawBox(bulletposX[i] - 3, bulletposY[i] - scrolY, bulletradius[i], bulletradius[i], 0.0f, RED, kFillModeSolid);
		}
	}

	//自分
	Novice::DrawSprite(player.position.X - player.radius, player.position.Y - player.radius - scrolY, plirasuto, 1, 1, 0.0f, WHITE);

	//ゴール
	Novice::DrawBox(Goal.center.X, Goal.center.Y - scrolY, Goal.raX, Goal.raY, 0.0f, BLUE, kFillModeSolid);


#pragma region 壊れるブロック

	if (blockflag == false)
	{
		//一番上
		//下の白い線(弾を当てると壊れる)
		Novice::DrawBox(block.center.X, block.center.Y - scrolY, block.raX, block.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag2 == false)
	{
		//上から2つ目のブロック
		Novice::DrawBox(block2.center.X, block2.center.Y - scrolY, block2.raX, block2.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag3 == false)
	{
		//上から3つ目のブロック
		Novice::DrawBox(block3.center.X, block3.center.Y - scrolY, block3.raX, block3.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag4 == false)
	{
		//上から4つ目のブロック
		Novice::DrawBox(block4.center.X, block4.center.Y - scrolY, block4.raX, block4.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag5 == false)
	{
		//上から5つ目のブロック
		Novice::DrawBox(block5.center.X, block5.center.Y - scrolY, block5.raX, block5.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag6 == false)
	{
		//上から6つ目のブロック
		Novice::DrawBox(block6.center.X, block6.center.Y - scrolY, block6.raX, block6.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag7 == false)
	{
		//上から6つ目のブロック
		Novice::DrawBox(block7.center.X, block7.center.Y - scrolY, block7.raX, block7.raY, 0.0f, WHITE, kFillModeSolid);
	}

	if (blockflag8 == false)
	{
		//上から6つ目のブロック
		Novice::DrawBox(block8.center.X, block8.center.Y - scrolY, block8.raX, block8.raY, 0.0f, WHITE, kFillModeSolid);
	}


#pragma endregion
	
	//ブロック描画(壁と一番下の床)
	for (int y = 0; y < 75; y++)
	{
		for (int x = 0; x < 60; x++)
		{
			if (map[y][x] == BLOCK)//普通のブロック
			{
				Novice::DrawSprite(x * BLOCKsize, y * BLOCKsize - scrolY, BLOCKirasuto, 1, 1, 0.0f, WHITE);
			}
		}
	}
}

//関数リセット(フラグやタイマーなど、細かいところ)
void Player::Reset()
{
	timer = 0;
	scrolY = 0;

	gameClear = false;
	gameOver = false;

	//タイマー
	timerflag = false;
	timerflag2 = false;
	timerflag3 = false;

	//線に当たるとゲームオーバーになるフラグ
	blockflag = false;
	blockflag2 = false;
	blockflag3 = false;
	blockflag4 = false;
	blockflag5 = false;
	blockflag6 = false;
	blockflag7 = false;
	blockflag8 = false;

	//カウント
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

	//弾
	const int bulletnum = 20;
	int bulletposX[20] = { 0 };
	int bulletposY[20] = { 0 };
	int bulletspeed[20] = { 0 };
	int bulletradius[20];

	int isbulletFlag[20] = { false };

	int bulletAliveCount[20];
}


