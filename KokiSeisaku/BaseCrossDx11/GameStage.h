/*!
@file GameStage.h
@brief ゲームステージ
*/

#pragma once
#include "stdafx.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	ゲームステージクラス
	//--------------------------------------------------------------------------------------
	class GameStage : public Stage {
		//リソースの作成
		void CreateResourses();
		//ビューの作成
		void CreateViewLight();
		//プレートの作成
		void CreatePlate();
		//追いかけるオブジェクトの作成
		void CreateSeekObject();
		//固定のボックスの作成
		void CreateFixedBox();
		//上下移動しているボックスの作成
		void CreateMoveBox();
		//ヒットする球体の作成
		void CreateSphere();
		//半透明のスプライト作成
		void CreateTraceSprite();
		//壁模様のスプライト作成
		void CreateWallSprite();
		//スクロールするスプライト作成
		void CreateScrollSprite();
		//左上で回転する立方体
		void CreateRollingCube();
		//形状が変わる球体
		void CreateTransSphere();
		//スパークの作成
		void CreateSpark();
		//プレイヤーの作成
		void CreatePlayer();
	public:
		//構築と破棄
		GameStage() :Stage() {}
		virtual ~GameStage() {}
		//初期化
		virtual void OnCreate()override;
	};


}
//end basecross

