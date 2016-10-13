#include "stdafx.h"
#include "Project.h"

namespace basecross {

	//���\�[�X�쐬
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

	//�r���[�ƃ��C�g�̍쐬
	void EditorStage::CreateViewLight() {
		auto PtrView = CreateView<SingleView>();
		//�r���[�̃J�����̐ݒ�
		auto PtrLookAtCamera = ObjectFactory::Create<LookAtCamera>();
		PtrView->SetCamera(PtrLookAtCamera);
		PtrLookAtCamera->SetEye(Vector3(0.0f, 5.0f, -5.0f));
		PtrLookAtCamera->SetAt(Vector3(0.0f, 0.0f, 0.0f));
		//�V���O�����C�g�̍쐬
		auto PtrSingleLight = CreateLight<SingleLight>();
		//���C�g�̐ݒ�
		PtrSingleLight->GetLight().SetPositionToDirectional(-0.25f, 1.0f, -0.25f);
	}

	//�v���[�g
	void EditorStage::CreatePlate() {
		//�X�e�[�W�ւ̃Q�[���I�u�W�F�N�g�̒ǉ�
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

		//�`��R���|�[�l���g�̒ǉ�
		auto DrawComp = Ptr->AddComponent<PNTStaticDraw>();
		//�`��R���|�[�l���g�Ɍ`��i���b�V���j��ݒ�
		DrawComp->SetMeshResource(L"DEFAULT_SQUARE");
		//�����ɉe���f�肱�ނ悤�ɂ���
		DrawComp->SetOwnShadowActive(true);

		//�`��R���|�[�l���g�e�N�X�`���̐ݒ�
		DrawComp->SetTextureResource(L"SKY_TX");
	}

	//�Œ�{�b�N�X�쐬
	void EditorStage::CreateFixedBox() {
		//�z��̏�����
		vector< vector<Vector3> > Vec = {


		};
	//�I�u�W�F�N�g�̍쐬
	for (auto v : Vec) {
		AddGameObject<FixedBox>(v[0], v[1], v[2]);
	}

   }

	//�������̃X�v���C�g�쐬
	void EditorStage::CreateTraceSprite() {
		
	}


	//�ǖ͗l�̃X�v���C�g�쐬
	void EditorStage::CreateWallSprite() {
		
	}

	//�摜��UI�\��
	void EditorStage::CreateSprite() {

	}

	void EditorStage::OnCreate() {
		try {
			//���\�[�X�̍쐬
			CreateResourses();
			//�r���[�ƃ��C�g�̍쐬
			CreateViewLight();
			//�v���[�g�̍쐬
			CreatePlate();
			//�Œ�̃{�b�N�X�̍쐬
			CreateFixedBox();
			//�������̃X�v���C�g�쐬
			CreateTraceSprite();
			//�ǖ͗l�̃X�v���C�g�쐬
			CreateWallSprite();
			//�X�v���C�g�쐬
			CreateSprite();
		}
		catch (...) {
			throw;
		}
	}

}
