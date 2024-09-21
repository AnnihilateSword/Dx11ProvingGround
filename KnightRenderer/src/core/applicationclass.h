////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "core/render/d3dclass.h"
#include "core/input/inputclass.h"
#include "core/camera/cameraclass.h"
#include "core/render/3d/modelclass.h"
#include "core/render/3d/lightshaderclass.h"
#include "core/render/3d/lightmapshaderclass.h"
#include "core/render/3d/lightclass.h"
#include "core/render/2d/textureshaderclass.h"
#include "core/render/2d/spriteclass.h"
#include "core/timerclass.h"
#include "core/render/2d/fontshaderclass.h"
#include "core/render/2d/fontclass.h"
#include "core/render/2d/textclass.h"
#include "core/fpsclass.h"
#include "core/render/2d/multitextureshaderclass.h"


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
	bool Frame(InputClass* Input);

private:
	bool Render();
	bool UpdateMouseStrings(int mouseX, int mouseY, bool mouseDown);
	bool UpdateFps();

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	LightMapShaderClass* m_LightMapShader;
	ModelClass* m_Model;


	
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

	// Mouse String
	TextClass* m_MouseStrings;
};

#endif