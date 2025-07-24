// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class PLAYGROUNG_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters (Custom C++)")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters (Custom C++)")
	float TimeConstant;

private:
	// To access a private property, we use meta modifier. Allows the property to be visible in the editor and read-only in Blueprints but we can still access with meta AllowPrivateAccess.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

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
