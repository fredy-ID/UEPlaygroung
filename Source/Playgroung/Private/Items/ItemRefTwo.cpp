#include "Items/ItemRefTwo.h"
#include "Playgroung/DebugMacros.h"


// Sets default values
AItemRefTwo::AItemRefTwo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemRefTwo::BeginPlay()
{
	Super::BeginPlay();

	Avg<int32>(1, 3); // Example of using the Avg function with int32 type
	Avg<float>(1.f, 2.f); // Example of using the Avg function with float type
	Avg(1, 2); // Example of using the Avg function with int type

	int32 AvgInt = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg<int32>(1, 3) = %d"), AvgInt);

	float AvgFloat = Avg<float>(3.45f, 7.86f);
	UE_LOG(LogTemp, Warning, TEXT("Avg<float>(3.45f, 7.86f) = %f"), AvgFloat);
	
}

// Called every frame
void AItemRefTwo::Tick(float DeltaTime)
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


	/* // This line shows how to use FMath::Sin to calculate a sine wave value.
	// 0.25f is a multiplier to control the amplitude of the sine wave wich is the height of the wave*
	// Sin function takes an angle in radians, so we use RunningTime as the input to create a smooth oscillation over time.
	float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant); // period = 2* PI / K where K is the frequency of the sine wave (all the way up and all the way down). In this case, K = 5.f, so the period is 2*PI/5.f
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ)); */

	DRAW_DEBUG_SPHERE_SingleFrame(GetActorLocation());
	DRAW_DEBUG_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector); // Average distance between origin and actor location
	DRAW_DEBUG_POINT_SingleFrame(AvgVector);

}


