#pragma once  

#include "DrawDebugHelpers.h" 

// DRAW_DEBUG_SPHERE is a macro that simplifies the process of drawing a debug sphere in the game world.  
// 2 verstions : Normal and SingleFrame.
// Normal version draws the sphere continuously, while SingleFrame version draws it only for one frame.

#define DRAW_DEBUG_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 24, FColor::Red, true);
#define DRAW_DEBUG_SPHERE_SingleFrame(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 24, FColor::Red, false, -1.f);
#define DRAW_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Cyan, true, -1.f, 0, 1.f);  
#define DRAW_DEBUG_LINE_SingleFrame(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Cyan, false, -1.f, 0, 1.f);
#define DRAW_DEBUG_POINT(Location) if (GetWorld()) DrawDebugPoint(World, Location, 15.f, FColor::Red, true);  
#define DRAW_DEBUG_POINT_SingleFrame(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, false, -1.f);
#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld()) { \
			DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Magenta, true, -1.f, 0, 1.f); \
			DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Magenta, true); \
	}
#define DRAW_DEBUG_VECTOR_SingleFrame(StartLocation, EndLocation) if (GetWorld()) { \
			DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Magenta, false, -1.f, 0, 1.f); \
			DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Magenta, false, -1.f); \
	}