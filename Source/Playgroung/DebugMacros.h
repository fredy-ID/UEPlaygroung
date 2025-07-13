#pragma once  

#include "DrawDebugHelpers.h" 


// DRAW_DEBUG_SPHERE is a macro that simplifies the process of drawing a debug sphere in the game world.  
#define DRAW_DEBUG_SPHERE(Location) if (GetWorld()) \  
	DrawDebugSphere(GetWorld(), Location, 25.f, TWENTY_FOUR, FColor::Red, false, 30.f)  
#define DRAW_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Cyan, true, -1.f, 0, 1.f)  
#define DRAW_DEBUG_POINT(Location) if (GetWorld()) DrawDebugPoint(World, Location, 15.f, FColor::Red, true);  
#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld()) \  
	{ \  
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Magenta, true, -1.f, 0, 1.f); \  
		DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Magenta, true); \  
	}