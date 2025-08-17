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

	// Create a default subobject of type UStaticMeshComponent and assign it to ItemMesh
	// ItemMesh is a UStaticMeshComponent, wich derives from scene component, which is a base class for all components that can be attached to an actor in Unreal Engine.
	// Which means we can take our actors and attach them to other actors or components in the game world, which includes the root component of the actor "RootComponent".
	// So our actors inherited root component variable "RootComponent" can be reassigned to a new component, like ItemMesh, and it will be the root component of our actor.
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	
	// Just like in Blueprints, that default scene root that our root component pointer variable stored the address of, is going to be deleted automatically.
	// And that's because the garbage collection system will see that RootComponent no longer points to it. And since it is not referenced anywhere else, it will be garbage collected and deleted.
	// So now the RootComponent pointer variable will point to ItemMesh SubObject, which is a UStaticMeshComponent that we created in the constructor.
	RootComponent = ItemMesh; // Set the root component of the actor to ItemMesh

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

	
	AddActorWorldRotation(FRotator(0.f, .3f * DeltaTime, 0.f));

	UPDATE_ACTOR_ROTATION_YAW(RunningTime, RotationRate); // Rotate the actor around the Yaw axis at a rate of 50 degrees per second
}

