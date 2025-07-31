// _

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemRefTwo.generated.h"

UCLASS()
class PLAYGROUNG_API AItemRefTwo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemRefTwo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// T is a template parameter that allows the function to be used with different types.
	// T is a traditional name for a template parameter, but you can use any valid identifier.
	template<typename T>
	T Avg(T First, T Second); //Whenever we call Avg we have to specify the type we want to use, like int, float, etc.


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};


// template<typename T> has to be defined for the compiler to know that this is a template function as well.
template<typename T>
// inline means that the function wherever it is called, the compiler will replace the function call with the actual code of the function.
// That means that the function body will be called directly just like a macro, but it is still a function.
inline T AItemRefTwo::Avg(T First, T Second)
{
	return T(First + Second) / 2;
}
