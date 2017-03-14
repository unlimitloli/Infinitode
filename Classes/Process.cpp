#include "Process.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

Process *process = nullptr;

const char * Process::GRAY = "gray";

const char * Process::RECOVERY = GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP;

Process * Process::getInstance()
{
	if (process == nullptr)
	{
		process = new Process();
		if (process && process->init())
		{
			return process;
		}
		else
		{
			CC_SAFE_DELETE(process);
			return nullptr;
		}
	}
	return process;
}

void Process::setProcess(cocos2d::Sprite *sprite, const char * key)
{
	GLProgram * p = ShaderCache::sharedShaderCache()->getGLProgram(key);
	sprite->setGLProgram(p);
}

bool Process::init()
{
	do
	{
		CC_BREAK_IF(!loadShader());
		return true;
	} while (false);

	return false;
}

bool Process::loadShader()
{
	do
	{
		CC_BREAK_IF(!loadShaderWithFile(Process::GRAY));
		return true;
	} while (false);

	return false;
}

bool Process::loadShaderWithFile(const char * filename)
{
	string vsh_file = StringUtils::format("shader/%s.vsh", filename);
	string fsh_file = StringUtils::format("shader/%s.fsh", filename);
	GLProgram *p = GLProgram::createWithFilenames(vsh_file, fsh_file);
	CHECK_GL_ERROR_DEBUG();
	if (p == nullptr)
		return false;
	ShaderCache::sharedShaderCache()->getInstance()->addGLProgram(p, filename);
	CHECK_GL_ERROR_DEBUG();
	return false;
}
