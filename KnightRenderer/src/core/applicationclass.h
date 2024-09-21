////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "core/render/d3dclass.h"
#include "core/camera/cameraclass.h"
#include "core/render/3d/modelclass.h"
#include "core/render/3d/lightshaderclass.h"
#include "core/render/3d/lightclass.h"
#include "core/render/2d/textureshaderclass.h"
#include "core/render/2d/spriteclass.h"
#include "core/timerclass.h"
#include "core/render/2d/fontshaderclass.h"
#include "core/render/2d/fontclass.h"
#include "core/render/2d/textclass.h"
#include "core/fpsclass.h"


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.3f;


////////////////////////////////////////////////////////////////////////////////
// Class name: ApplicationClass
////////////////////////////////////////////////////////////////////////////////
class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass& other);
	~ApplicationClass();

	bool Initialize(int screenWidth, int screenHeight, HWND hwnd);
	void Shutdown();
	bool Frame();

private:
	bool Render();
	bool UpdateFps();

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	ModelClass* m_Model;
	LightShaderClass* m_LightShader;
	LightClass* m_Lights;
	int m_numLights;

	// ******
	// sprite
	// ******
	TextureShaderClass* m_TextureShader;
	SpriteClass* m_Sprite;
	TimerClass* m_Timer;

	// ****
	// font
	// ****
	FontShaderClass* m_FontShader;
	FontClass* m_Font;
	TextClass* m_AuthorTextString;

	// ***
	// Fps
	// ***
	FpsClass* m_Fps;
	TextClass* m_FpsString;
	int m_previousFps;
};

#endif