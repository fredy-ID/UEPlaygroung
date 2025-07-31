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

	// This is a parameter that controls the amplitude of the sine wave.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters (Custom C++)")
	float Amplitude = 0.25f;

	// TimeConstant is a parameter that controls the frequency of the sine wave.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters (Custom C++)")
	float TimeConstant;

	// This is a function that can be called from Blueprints or C++ code to get the transformed sine value based on the Amplitude and TimeConstant.
	/**
	* @brief Transforms the input value using a sine function based on the Amplitude and TimeConstant. (Custom C++)
	* @return The transformed sine value.
	*/
	UFUNCTION(BlueprintPure, Category = "Custom pure Functions (Custom C++)")
	float TransformedSin();

	/**
	* @brief Transforms the input value using a cosine function based on the Amplitude and TimeConstant. (Custom C++)
	* @return The transformed cosine value.
	*/
	UFUNCTION(BlueprintPure, Category = "Custom pure Functions (Custom C++)")
	float TransformedCos();

	// see ItemRefTwo for def
	template<typename T>
	T Avg(T First, T Second);

private:
	// To access a private property, we use meta modifier. Allows the property to be visible in the editor and read-only in Blueprints but we can still access with meta AllowPrivateAccess.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// see ItemRefTwo for def
template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return T(First + Second) / 2;
}
