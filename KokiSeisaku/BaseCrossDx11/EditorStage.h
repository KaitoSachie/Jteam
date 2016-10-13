/*!
@file EditorStage.h
@brief �G�f�B�^�[�X�e�[�W
*/
#pragma once
#include "stdafx.h"

namespace basecross {

	//-----------------------------------------------------------------------------
   //�G�f�B�^�[�X�e�[�W�N���X
  //-----------------------------------------------------------------------------
	class EditorStage : public Stage {
		//���\�[�X�̍쐬
		void CreateResourses();
		//�r���[�̍쐬
		void CreateViewLight();
		//�v���[�g�̍쐬
		void CreatePlate();
		//�Œ�̃{�b�N�X�̍쐬
		void CreateFixedBox();
		//�������̃X�v���C�g�쐬
		void CreateTraceSprite();
		//�ǖ͗l�̃X�v���C�g�쐬
		void CreateWallSprite();
		//UI�Ƃ��摜�Ƃ�
		void CreateSprite();
		
	public:
		//�\�z�Ɣj��
		EditorStage() :Stage() {}
		virtual ~EditorStage() {}
		//������
		virtual void OnCreate()override;

	};
}