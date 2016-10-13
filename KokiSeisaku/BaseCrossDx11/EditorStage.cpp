#include "stdafx.h"
#include "Project.h"

namespace basecross {

	//リソース作成
	void basecross::EditorStage::CreateResourses()
	{
		wstring DataDir;
		App::GetApp()->GetDataDirectory(DataDir);
		wstring strTexture = DataDir + L"trace.png";
		App::GetApp()->RegisterTexture(L"TRACE_TX", strTexture);
		strTexture = DataDir + L"sky.jpg";
		App::GetApp()->RegisterTexture(L"SKY_TX", strTexture);
		strTexture = DataDir + L"wall.jpg";
		App::GetApp()->RegisterTexture(L"WALL_TX", strTexture);
		strTexture = DataDir + L"spark.png";
		App::GetApp()->RegisterTexture(L"SPARK_TX", strTexture);
		strTexture = DataDir + L"number.png";
		App::GetApp()->RegisterTexture(L"NUMBER_TX", strTexture);
	}

	//ビューとライトの作成
	void EditorStage::CreateViewLight() {
		auto PtrView = CreateView<SingleView>();
		//ビューのカメラの設定
		auto PtrLookAtCamera = ObjectFactory::Create<LookAtCamera>();
		PtrView->SetCamera(PtrLookAtCamera);
		PtrLookAtCamera->SetEye(Vector3(0.0f, 5.0f, -5.0f));
		PtrLookAtCamera->SetAt(Vector3(0.0f, 0.0f, 0.0f));
		//シングルライトの作成
		auto PtrSingleLight = CreateLight<SingleLight>();
		//ライトの設定
		PtrSingleLight->GetLight().SetPositionToDirectional(-0.25f, 1.0f, -0.25f);
	}

	//プレート
	void EditorStage::CreatePlate() {
		//ステージへのゲームオブジェクトの追加
		auto Ptr = AddGameObject<GameObject>();
		auto PtrTrans = Ptr->GetComponent<Transform>();
		Quaternion Qt;
		Qt.RotationRollPitchYawFromVector(Vector3(XM_PIDIV2, 0, 0));
		Matrix4X4 WorldMat;
		WorldMat.DefTransformation(
			Vector3(200.0f, 200.0f, 1.0f),
			Qt,
			Vector3(0.0f, 0.0f, 0.0f)
		);
		PtrTrans->SetScale(200.0f, 200.0f, 1.0f);
		PtrTrans->SetQuaternion(Qt);
		PtrTrans->SetPosition(0.0f, 0.0f, 0.0f);

		//描画コンポーネントの追加
		auto DrawComp = Ptr->AddComponent<PNTStaticDraw>();
		//描画コンポーネントに形状（メッシュ）を設定
		DrawComp->SetMeshResource(L"DEFAULT_SQUARE");
		//自分に影が映りこむようにする
		DrawComp->SetOwnShadowActive(true);

		//描画コンポーネントテクスチャの設定
		DrawComp->SetTextureResource(L"SKY_TX");
	}

	//固定ボックス作成
	void EditorStage::CreateFixedBox() {
		//配列の初期化
		vector< vector<Vector3> > Vec = {


		};
	//オブジェクトの作成
	for (auto v : Vec) {
		AddGameObject<FixedBox>(v[0], v[1], v[2]);
	}

   }

	//半透明のスプライト作成
	void EditorStage::CreateTraceSprite() {
		
	}


	//壁模様のスプライト作成
	void EditorStage::CreateWallSprite() {
		
	}

	//画像とUI表示
	void EditorStage::CreateSprite() {

	}

	void EditorStage::OnCreate() {
		try {
			//リソースの作成
			CreateResourses();
			//ビューとライトの作成
			CreateViewLight();
			//プレートの作成
			CreatePlate();
			//固定のボックスの作成
			CreateFixedBox();
			//半透明のスプライト作成
			CreateTraceSprite();
			//壁模様のスプライト作成
			CreateWallSprite();
			//スプライト作成
			CreateSprite();
		}
		catch (...) {
			throw;
		}
	}

}
