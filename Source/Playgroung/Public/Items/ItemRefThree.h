#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemRefThree.generated.h"

UCLASS()
class PLAYGROUNG_API AItemRefThree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemRefThree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Can only be edited in the game instance, not in the editor.
	//UPROPERTY(EditInstanceOnly)


	// Amplitude initialization in the class declaration. This is one of the 3 ways to initialize a variable in C++ : constructor initialization list, constructor body, or in the class declaration

	// This is a property that can be edited in the Unreal Engine editor and is accessible in Blueprints.
	// EditAnywhere allows the property to be edited in the editor, BlueprintReadWrite allows it to be read and written in Blueprints.
	// EditDefaultsOnly would restrict editing to the defaults only, and BlueprintReadOnly would make it read-only in Blueprints.
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))

	// Can only be edited in the editor, not in the game instance.
	//UPROPERTY(EditDefaultsOnly)

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
