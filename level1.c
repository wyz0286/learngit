#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Level1.h"
#include "AEEngine.h"
#include "AEInput.h"
#include "GameObjectManager.h"

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

static GameObj* pHero;
Vector2D zero = { 0.0f, 0.0f };

void Load1(void)
{
	GameObjBase* pObjBase;
	theBaseList = NULL;
	// ��ʼ����Ϸ��������ʵ���б�
	InitialGameObjBaseList(&theBaseList);

	// ��ʼ����Ϸ�������ʵ���б�

	// ���������ʵ��	

	// =======================
	// ����(ƽ̨)���ߴ��С���򻯳������ζ���
	// =======================

	AEGfxMeshStart();
	AEGfxTriAdd(
		-2.0f, 0.1f, COLOR_BACKGROUND, 0.0f, 0.0f,
		-2.0f, -0.1f, COLOR_BACKGROUND, 0.0f, 0.0f,
		2.0f, 0.1f, COLOR_BACKGROUND, 0.0f, 0.0f);
	AEGfxTriAdd(
		2.0f, -0.1f, COLOR_BACKGROUND, 0.0f, 0.0f,
		-2.0f, -0.1f, COLOR_BACKGROUND, 0.0f, 0.0f,
		2.0f, 0.1f, COLOR_BACKGROUND, 0.0f, 0.0f);

	CreateGameObjBase(TYPE_BACKGROUND, AEGfxMeshEnd(), theBaseList);

	// =========================
	// ���ǣ���12��������ƴ��һ����Բ�Ρ�
	// =========================

	AEGfxMeshStart();
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		1.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		0.866f, 0.5f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		0.866f, 0.5f, COLOR_PLAYER, 0.0f, 0.0f,
		0.5f, 0.866f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		0.5f, 0.866f, COLOR_PLAYER, 0.0f, 0.0f,
		0.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		0.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f,
		-0.5f, 0.866f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		-0.5f, 0.866f, COLOR_PLAYER, 0.0f, 0.0f,
		-0.866f, 0.5f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		-0.866f, 0.5f, COLOR_PLAYER, 0.0f, 0.0f,
		-1.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		-1.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		-0.866f, -0.5f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		-0.866f, -0.5f, COLOR_PLAYER, 0.0f, 0.0f,
		-0.5f, -0.866f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		-0.5f, -0.866f, COLOR_PLAYER, 0.0f, 0.0f,
		0.0f, -1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		0.0f, -1.0f, COLOR_PLAYER, 0.0f, 0.0f,
		0.5f, -0.866f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		0.5f, -0.866f, COLOR_PLAYER, 0.0f, 0.0f,
		0.866f, -0.5f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		0.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f,
		0.866f, -0.5f, COLOR_PLAYER, 0.0f, 0.0f,
		1.0f, 0.0f, COLOR_PLAYER, 0.0f, 0.0f);

	CreateGameObjBase(TYPE_PLAYER, AEGfxMeshEnd(), theBaseList);

	// ========================
	// �ϰ��3��������ƴ�ӵ������
	// ========================

	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.7f, -0.1f, 0xFFFFFF00, 0.0f, 0.0f,
		0.0f, 0.5f, 0xFFFFFF00, 0.0f, 0.0f,
		0.6f, 0.4f, 0xFFFFFF00, 0.0f, 0.0f);
	AEGfxTriAdd(
		-0.7f, -0.1f, 0xFFFFFF00, 0.0f, 0.0f,
		0.6f, 0.4f, 0xFFFFFF00, 0.0f, 0.0f,
		0.25f, -0.15f, 0xFFFFFF00, 0.0f, 0.0f);
	AEGfxTriAdd(
		-0.7f, -0.1f, 0xFFFFFF00, 0.0f, 0.0f,
		-0.2f, -0.5f, 0xFFFFFF00, 0.0f, 0.0f,
		0.25f, -0.15f, 0xFFFFFF00, 0.0f, 0.0f);
	CreateGameObjBase(TYPE_BLOCK, AEGfxMeshEnd(), theBaseList);

}

void Ini1(void)
{

	GameObj* pObj;
	int i;

	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// ����ʵ������
	// ��Ҷ���ʵ����
	pHero = CreateGameObj(TYPE_PLAYER, SIZE_HERO, zero, zero, 0, theBaseList, 0, NULL);
	AE_ASSERT(pHero);
	// ��������ʵ����
	pObj = CreateGameObj(TYPE_BACKGROUND, SIZE_BACKGROUND, zero, zero, 0, theBaseList, 0, NULL);
	AE_ASSERT(pHero);
	// С���Ƕ���ʵ���� �� ��ʼ��
	for (i = 0; i < BLOCK_NUM; i++)
	{
		// ʵ����
		pObj = CreateGameObj(TYPE_BLOCK, SIZE_BLOCK, zero, zero, 0, theBaseList, 0, NULL);
		AE_ASSERT(pObj);

		// ��ʼ��: ����λ�� ����ͳߴ��С
		switch (i)
		{
		case 0:
			pObj->posCurr.x = AEGfxGetWinMaxX();
			pObj->posCurr.y = 100.0f;
			break;
		case 1:
			pObj->posCurr.x = 100.0f;
			pObj->posCurr.y = AEGfxGetWinMaxY();
			break;
		case 2:
			pObj->posCurr.x = AEGfxGetWinMinX();
			pObj->posCurr.y = 100.0f;
			break;
		}
		// ����
		pObj->dirCurr = acosf(pObj->posCurr.x / ((float)sqrt(pObj->posCurr.x*pObj->posCurr.x + pObj->posCurr.y * pObj->posCurr.y))) - PI;

		pObj->scale = (i + 1) * 10.0f;
	}

}

void Free1(void)
{
	baseNode* pbaseNode = theBaseList->head;
	insNode* pinsNode;
	while (pbaseNode != theBaseList->tail) {
		pinsNode = pbaseNode->gameobj_list->head->next;
		while (pinsNode != pbaseNode->gameobj_list->tail){
			GameObjDelete(&(pinsNode->gameobj));
			pinsNode = pinsNode->next;
		}
		pbaseNode = pbaseNode->next;
	}
}

void Draw1(void)
{
	char strBuffer[1024];
	unsigned long i;
	double frameTime;

	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);

	// ������ƶ����б��е����ж���
	baseNode* pbaseNode = theBaseList->head;
	insNode* pinsNode;
	while (pbaseNode != theBaseList->tail)
	{
		pinsNode = pbaseNode->gameobj_list->head->next;
		while (pinsNode != pbaseNode->gameobj_list->tail){
			
			// �����ǻ����
			if ((pinsNode->gameobj->flag & FLAG_ACTIVE) == 0)
				continue;

			// ���û���ģʽ(Color or texture)
			AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
			// �������в���(Color blend, textures, etc..)
			AEGfxSetBlendMode(AE_GFX_RM_COLOR);
			// ���ö����2D�任����ʹ�ú�����AEGfxSetTransform
			AEGfxSetTransform(pinsNode->gameobj->transform.m);
			// ���Ƶ�ǰ����ʹ�ú�����AEGfxMeshDraw
			AEGfxMeshDraw(pbaseNode->gameobj_base.pMesh, AE_GFX_MDM_TRIANGLES);
			
			
			pinsNode = pinsNode->next;
		}
		
		pbaseNode = pbaseNode->next;
	
	}
}

void Unload1(void)
{
	baseNode* pbaseNode = theBaseList->head;
	insNode* pinsNode;
	while (pbaseNode != theBaseList->tail) {
		DestroyGameObjList(&(pbaseNode->gameobj_list));
		AEGfxMeshFree(pbaseNode->gameobj_base.pMesh);
		pbaseNode = pbaseNode->next;
	}
	DestroyGameObjBaseList(theBaseList);

}
