////////////////////////////////////////////////////////////////////////////////
// Filename: textureclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TEXTURECLASS_H_
#define _TEXTURECLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <stdio.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: TextureClass
////////////////////////////////////////////////////////////////////////////////
class TextureClass
{
private:
	// ���� .tag ��ʽ�ļ���ͷ�ṹ���Ա�����ɵض�ȡ����
	struct TargaHeader
	{
		unsigned char data1[12];
		unsigned short width;
		unsigned short height;
		unsigned char bpp;  // bit per pixel
		unsigned char data2;
	};

public:
	TextureClass();
	TextureClass(const TextureClass&);
	~TextureClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*);
	void Shutdown();

	ID3D11ShaderResourceView* GetTexture();

	int GetWidth();
	int GetHeight();

private:
	/** 
	 * Targa ͼ��Ĭ�������ϵģ�ʹ��ǰ��Ҫ��ת
	 * ��ע�⣬���ǹ���ֻ������� Alpha ͨ���� 32 λ Targa �ļ�
	 * �˺������ܾ�����Ϊ 24 λ�� Targa �ļ�
	 */
	bool LoadTarga32Bit(char*);

private:
	unsigned char* m_targaData;
	ID3D11Texture2D* m_texture;
	ID3D11ShaderResourceView* m_textureView;
	int m_width, m_height;
};

#endif