#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "3042_おちうど";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 800);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player_ = new Player();
	Enemy* enemy_ = new Enemy();

	player_->Initialize();
	enemy_->Initialize();

	int scene = 0;

	int title = Novice::LoadTexture("./OP.png");
	int setumei = Novice::LoadTexture("./setumei.png");
	int setumei2 = Novice::LoadTexture("./setumei2.png");
	int zanpai = Novice::LoadTexture("./zanpai.png");
	int seiha = Novice::LoadTexture("./seiha.png");


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene)
		{
		case 0://タイトル

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				scene = 1;
			}

			break;

		case 1: //説明

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				scene = 2;

				//変数などリセット
				player_->Reset();
				player_->Initialize();

				enemy_->Initialize();
			}

			break;

		case 2: //説明
			
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				scene = 3;
			}

			break;

		case 3: //ゲーム画面

			player_->Update(keys, preKeys);

			//enemy_->Update();
			//クリア画面へ
			if (player_->gameClear == true)
			{
				scene = 4;
			}

			//ゲームオーバー画面へ
			if (player_->gameOver == true)
			{
				scene = 5;
			}

			break;

		case 4://クリア画面

			//ボタンを押すと戻る
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				//タイトルに戻る
				scene = 0;
			}

			break;

		case 5://ゲームオーバー画面

			//ボタンを押すと戻る
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				//タイトルに戻る
				scene = 0;
			}

			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene)
		{
		case 0:

			//タイトル
			Novice::DrawSprite(0, 0, title, 1, 1, 0.0f, WHITE);

			break;
			
		case 1:

			//説明
			Novice::DrawSprite(0, 0, setumei, 1, 1, 0.0f, WHITE);

			break;

		case 2:

			//説明
			Novice::DrawSprite(0, 0, setumei2, 1, 1, 0.0f, WHITE);

			break;

		case 3:

			//ゲーム画面
			player_->Draw();

			//enemy_->Draw(enemy_->y);

			break;

		case 4:

			//クリア画面
			Novice::DrawSprite(0, 0, seiha, 1, 1, 0.0f, WHITE);
			
			break;

		case 5:

			//ゲームオーバー画面
			Novice::DrawSprite(0, 0, zanpai, 1, 1, 0.0f, WHITE);

			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
