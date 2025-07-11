// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Item BeginPlay called!"));

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
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

