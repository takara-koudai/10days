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
	/*block3 =
	{
		{0,1000},
		800,
		32
	};*/


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

}

void Player::Update(char* keys, char* prekeys)
{

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

#pragma region ２つ目
			//２つ目
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
			//２つ目のブロック
			if (blockflag2 == true)
			{
				isbulletFlag[i] = true;
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
			Novice::ScreenPrintf(100, 70, "sinu");
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
			Novice::ScreenPrintf(100, 70, "sinu");
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
		Novice::ScreenPrintf(300, 300, "atari");
	}
#pragma endregion

	//時間制限処理
	timer++;

	Novice::ScreenPrintf(50, 350, "%d", timer);

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
	//Novice::DrawSprite(player.position.X - player.radius, player.position.Y - player.radius - scrolY, irasuto, 1, 1, 0.0f, WHITE);
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
		//上から２つ目のブロック
		Novice::DrawBox(block2.center.X, block2.center.Y - scrolY, block2.raX, block2.raY, 0.0f, WHITE, kFillModeSolid);
	}

#pragma endregion
	
	//ブロック描画
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


	//弾
	const int bulletnum = 20;
	int bulletposX[20] = { 0 };
	int bulletposY[20] = { 0 };
	int bulletspeed[20] = { 0 };
	int bulletradius[20];

	int isbulletFlag[20] = { false };

	int bulletAliveCount[20];
}


