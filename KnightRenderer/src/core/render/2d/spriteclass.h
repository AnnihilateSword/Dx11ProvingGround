////////////////////////////////////////////////////////////////////////////////
// Filename: spriteclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SPRITECLASS_H_
#define _SPRITECLASS_H_


//////////////
// INCLUDES //
//////////////
#include <directxmath.h>
#include <fstream>
using namespace DirectX;


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "core/render/textureclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: SpriteClass
////////////////////////////////////////////////////////////////////////////////
class SpriteClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	SpriteClass();
	SpriteClass(const SpriteClass& other);
	~SpriteClass();

	bool Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, int screenWidth, int screenHeight, char* spriteFilename, int renderX, int renderY);
	void Shutdown();
	bool Render(ID3D11DeviceContext* deviceContext);

	void Update(float);

	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();

	void SetRenderLocation(int, int);
	void SetRenderScale(float, float);

private:
	bool InitializeBuffers(ID3D11Device* device);
	void ShutdownBuffers();
	bool UpdateBuffers(ID3D11DeviceContext* deviceContext);
	void RenderBuffers(ID3D11DeviceContext* deviceContext);

	bool LoadTextures(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* filename);
	void ReleaseTextures();

private:
	ID3D11Buffer* m_vertexBuffer, * m_indexBuffer;
	int m_vertexCount, m_indexCount, m_screenWidth, m_screenHeight, m_bitmapWidth, m_bitmapHeight, m_renderX, m_renderY, m_prevPosX, m_prevPosY;
	TextureClass* m_Textures;
	float m_frameTime, m_cycleTime;
	int m_currentTexture, m_textureCount;
};

#endif