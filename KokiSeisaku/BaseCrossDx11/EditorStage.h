/*!
@file EditorStage.h
@brief エディターステージ
*/
#pragma once
#include "stdafx.h"

namespace basecross {

	//-----------------------------------------------------------------------------
   //エディターステージクラス
  //-----------------------------------------------------------------------------
	class EditorStage : public Stage {
		//リソースの作成
		void CreateResourses();
		//ビューの作成
		void CreateViewLight();
		//プレートの作成
		void CreatePlate();
		//固定のボックスの作成
		void CreateFixedBox();
		//半透明のスプライト作成
		void CreateTraceSprite();
		//壁模様のスプライト作成
		void CreateWallSprite();
		//UIとか画像とか
		void CreateSprite();
		
	public:
		//構築と破棄
		EditorStage() :Stage() {}
		virtual ~EditorStage() {}
		//初期化
		virtual void OnCreate()override;

	};
}