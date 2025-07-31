#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemRefOne.generated.h"

UCLASS()
class PLAYGROUNG_API AItemRefOne : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemRefOne();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	
};
