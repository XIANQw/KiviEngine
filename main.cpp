#include "GfxWindow.h"
#include <iostream>

int main() 
{
	GfxWindow gfxWindow(640, 480, "KiviEngine");
	if (!gfxWindow.Init()) return -1;
	
	std::vector<Renderer*> rdrs = gfxWindow.PrepareData();
	while (!gfxWindow.ShouldBeClosed())
	{
		gfxWindow.RenderLoop(rdrs);
	}
	
	for (Renderer* rdr : rdrs)
	{
		delete rdr;
	}
}