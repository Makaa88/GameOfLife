#include "FPSManagement.h"

FPSManagement::FPSManagement()
{
}

float FPSManagement::GetFPS() const
{
	return _fps_per_second;
}

void FPSManagement::SetFPS(const float fps)
{
	_fps_per_second = fps;

}
