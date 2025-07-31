// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
// has a number of debug helper functions, including a function for drawing debug spheres, lines, and other shapes in the game world.

#include "Playgroung/DebugMacros.h"


// Sets default values
// A in AItem stands for "Actor," which is a base class for all objects that can be placed in the world.

//Constructors in Unreal Engine are special functions that are called when an object of a class is created.
AItem::AItem() : TimeConstant(5.f) // : TimeConstant(5.f) -> Initializing TimeConstant in Constructor initialization list. This is one of the 3 ways to initialize a variable in C++ : constructor initialization list, constructor body, or in the class declaration
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// This is another way to initialize a variable in C++. but it is better to initialize variables in the constructor initialization list or in the class declaration.
	// TimeConstant = 5.f; 
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();


	
}

// la fonction est une fonction membre (::) de la classe AItem qui prend un paramètre de type float et retourne un float.
// On dit que TransformedSin est fully quilified, meaning it is fully qualified with the class name AItem.
// "::" c'est l'opérateur de résolution de portée en C++ (scope resolution operator), qui est utilisé pour accéder aux membres d'une classe ou d'un espace de noms.
float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	DRAW_DEBUG_SPHERE_SingleFrame(GetActorLocation());
	DRAW_DEBUG_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
	
	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector); // Average distance between origin and actor location
	DRAW_DEBUG_POINT_SingleFrame(AvgVector);


	
}

