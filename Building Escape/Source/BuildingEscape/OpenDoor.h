// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h" //must be included last


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere) //Set OpenAngle to 90 as a constant property. MACRO MAKES IT VISIBLE IN INSPECTOR EVEN THOUGH IT IS PRIVATE do not use semicolon
	float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere) //Allows this property below to be edited anywhere despite t being private
		ATriggerVolume* PressurePlate; //an invisible space(volume) object that acts as a trigger

	UPROPERTY(EditAnywhere) 
		AActor* ActorThatOpens; //Thje player Actor in this game is a pawn,
	
};
