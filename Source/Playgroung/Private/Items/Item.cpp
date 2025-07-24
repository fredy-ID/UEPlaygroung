// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
// has a number of debug helper functions, including a function for drawing debug spheres, lines, and other shapes in the game world.

#include "Playgroung/DebugMacros.h"

//#define is a preprocessor directive that defines a macro, which is a symbolic name for a value or expression.
// here we define a macro called THIRTY_SECONDS with a value of 30.f (30 seconds).
// we can use this macro throughout our code to represent the value 30 seconds without having to type it out each time.
// the diference between using a macro and a constant variable is that macros are replaced by the preprocessor before compilation, while constant variables are defined at runtime.
#define THIRTY 30
#define TWENTY_FOUR 24



// Sets default values
// A in AItem stands for "Actor," which is a base class for all objects that can be placed in the world.

//Constructors in Unreal Engine are special functions that are called when an object of a class is created.
AItem::AItem() : TimeConstant(5.f) // : Amplitude(0.25f) -> Initializing Amplitude in Constructor initialization list. This is one of the 3 ways to initialize a variable in C++ : constructor initialization list, constructor body, or in the class declaration
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// This is another way to initialize a variable in C++. but it is better to initialize variables in the constructor initialization list or in the class declaration.
	//Amplitude = 0.25f; 
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	// UE_LOG is a macro used for logging messages in Unreal Engine.
	UE_LOG(LogTemp, Warning, TEXT("Item BeginPlay called! with C++"));

	// F in FString stands for "FString," which is a class in Unreal Engine that represents a string of characters.
	FString Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Item name, with C++ : %s"), *Name);

	// Check if GEngine is valid before using it because it may not be available in some contexts (e.g., during construction)
	// GEngine is a global pointer to the engine instance, which provides access to various engine functionalities, including logging and displaying messages on the screen.
	// It is defined in the Unreal Engine source code, typically in the Engine module.
	// GEngine can be a null pointer (0) so we should check if it is valid before using it to avoid dereferencing a null pointer.
	// Good practices include checking our pointer before using it, especially in contexts where the engine might not be fully initialized or available.
	
	if (GEngine) {
		// Display a message on the screen
		GEngine->AddOnScreenDebugMessage(4, 60.f, FColor::Red, TEXT("Item BeginPlay called with C++, using TEXT()"));
		GEngine->AddOnScreenDebugMessage(5, 60.f, FColor::Green, FString("Item on screen message with C++ ! Using FString()"));
	}	
	
	// Draw a debug sphere at the actor's location
	// UWorld is a class that represents the game world in Unreal Engine.
	// It is responsible for managing all actors, components, and other game elements within the world.
	// UWorld* is a pointer to the UWorld instance, which allows us to interact with the game world and perform various operations, such as spawning actors, drawing debug shapes, and more.
	// U in UWorld stands for "Unreal," indicating that it is part of the Unreal Engine framework.
	// The GetWorld() function is a member function of the AActor class, which returns a pointer to the UWorld instance that this actor belongs to.

	UWorld* World = GetWorld();

	// Get the actor's location in the world
	// GetActorLocation() is a member function of the AActor class, which returns the current location of the actor in the game world.
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();

	if (World) 
	{
		

		// My personal macro to draw a debug sphere and a line in the game world, defined in Playgroung.h
		DRAW_DEBUG_SPHERE(Location);
		DRAW_LINE(Location, Location + Forward * -100.f);
		DRAW_DEBUG_POINT(Location + Forward * -100.f);
		DRAW_VECTOR(Location, FVector(Location.X + 10.f, Location.Y + 10.f, Location.Z + 10.f) + Forward * -100.f);

		// DrawDebugSphere is a function that draws a sphere in the game world for debugging purposes.
		DrawDebugSphere(
			World,
			FVector(Location.X + 10.f, Location.Y + 10.f, Location.Z + 10.f),
			25.f, // Radius of the sphere
			THIRTY, // Number of segments
			FColor::Blue, // Color of the sphere
			false, // Whether to persist the sphere in the world
			30.f // Duration for which the sphere will be visible
		);


		DrawDebugLine(
			World,
			FVector(Location.X + 10.f, Location.Y + 10.f, Location.Z + 10.f),
			FVector(Location.X + 100.f, Location.Y + 100.f, Location.Z + 100.f),
			FColor::Blue,
			false,
			30.f,
			0,
			5.f
		);

		DrawDebugPoint(
			World,
			FVector(Location.X + 10.f, Location.Y + 10.f, Location.Z + 10.f),
			10.f, // Size of the point
			FColor::Cyan, // Color of the point
			false, // Whether to persist the point in the world
			30.f // Duration for which the point will be visible
		);

		// Ces deux lignes sont retirés car je test AddActorWorldOffset
		/*SetActorLocation(FVector(Location.X + 100.f, Location.Y + 100.f, Location.Z + 100.f));
		SetActorRotation(FRotator(60.f, 45.f, 120.f));*/
	}

}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* // This code is commented out, but it shows how to move and rotate the actor based on DeltaTime.
	// Movement rate in units of centimeters per second (cm/s)
	float MovementRate = 100.f;
	float RotationRate = 50.f;

	// AddActorWorldOffset is a function that moves the actor by a specified offset in the world space.
	// //DeltaTime is the time elapsed since the last frame, which is used to ensure smooth movement regardless of frame rate.
	// MovementRate * DeltaTime (cm/s) * (s/frame) = cm/frame
	AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	*/

	RunningTime += DeltaTime;

	// This line shows how to use FMath::Sin to calculate a sine wave value.
	// 0.25f is a multiplier to control the amplitude of the sine wave wich is the height of the wave*
	// Sin function takes an angle in radians, so we use RunningTime as the input to create a smooth oscillation over time.
	float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant); // period = 2* PI / K where K is the frequency of the sine wave (all the way up and all the way down). In this case, K = 5.f, so the period is 2*PI/5.f
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	DRAW_DEBUG_SPHERE_SingleFrame(GetActorLocation());
	DRAW_DEBUG_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	if (GEngine) {
		// Display a message on the screen
		GEngine->AddOnScreenDebugMessage(4, 60.f, FColor::Red, TEXT("Debug custom message with C++"));
		

		// Using FString::Printf to format the message with DeltaTime
		FString Message = FString::Printf(TEXT("Item Tick called with C++, DeltaTime: %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(5, 60.f, FColor::Green, Message);

		// Get the name of the item
		FString Name = GetName();

		// the * means we are dereferencing the FString to get the underlying string value. 
		// Meaning the FString type has custom string formatting capabilities.
		// We pass in a C style string format specifier %s to insert the name of the item into the message.
		FString NameMessage = FString::Printf(TEXT("Item Name called with C++, Name : %s"), *Name);
		GEngine->AddOnScreenDebugMessage(5, 60.f, FColor::Green, NameMessage);

	}
}

