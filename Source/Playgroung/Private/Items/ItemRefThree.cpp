#include "Items/ItemRefThree.h"
#include "Playgroung/DebugMacros.h"

// Sets default values
AItemRefThree::AItemRefThree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemRefThree::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemRefThree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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


