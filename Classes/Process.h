#pragma once
#include "cocos2d.h"

#define _process		Process::getInstance()

class Process
{
public:
	static Process * getInstance();

public:
	static const char * GRAY;					// �һ�
	static const char * RECOVERY;				// ��ԭ

	void setProcess(cocos2d::Sprite *sprite, const char * key);

protected:
	bool init();
	bool loadShader();

	bool loadShaderWithFile(const char * filename);
};