#pragma once
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

enum BLOCKinfo
{
	None,  //�Ȃɂ��Ȃ�
	BLOCK, //�u���b�N
	BLOCK2, //(��)����s
};

class Player
{
public:

	//������
	void Initialize();

	//�A�b�v�f�[�g
	void Update(char* keys, char* prekeys);

	//�`��
	void Draw();

	//�f�X�g���N�^
	~Player();


private:

	//�v���C���[�p�\����
	typedef struct vector
	{
		float X;
		float Y;
	}vector;

	typedef struct object
	{
		vector position;
		vector velocity;
		float radius;
	}object;

	//�u���b�N�p�\����
	typedef struct Vector_
	{
		float X;
		float Y;
	}Vector_;

	typedef struct Block
	{
		Vector_ center;
		float raX;
		float raY;
	}Block;


	//�v���C���[
	object player;

	//����u���b�N
	Block block;
	Block block2;
	Block block3;
	Block block4;
	Block block5;
	Block block6;
	Block block7;
	Block block8;

	//���ɓ�����ƃQ�[���I�[�o�[�ɂȂ�t���O
	bool blockflag = false;
	bool blockflag2 = false;
	bool blockflag3 = false;
	bool blockflag4 = false;
	bool blockflag5 = false;
	bool blockflag6 = false;
	bool blockflag7 = false;
	bool blockflag8 = false;

	
	//�e
	const int bulletnum = 20;
	int bulletposX[20] = { 0 };
	int bulletposY[20] = { 0 };
	int bulletspeed[20] = { 0 };
	int bulletradius[20];
	
	int isbulletFlag[20] = { false };

	int bulletAliveCount[20];
	

	//�d��
	float gravity = 1.0f;

	//�X�N���[��
	int scrolY = 0;

	//�C���X�g�֌W
	int irasuto = Novice::LoadTexture("./player3.png");

	int BLOCKirasuto = Novice::LoadTexture("./BLOCK.png");

	//�}�b�v�`�b�v�֌W
	int BLOCKsize = 32;

	int map[25][25]
	{
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

};

