// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	//OpenDoor();
	
}

void UOpenDoor::OpenDoor()
{
	Super::BeginPlay();
	//find ownder and set Z rotation(door opening and closing in 3D space)
	AActor* Owner = GetOwner();
	//rotation based on pitch, yaw and roll. 
	FRotator NewRotation = FRotator(0.0f, 60.0f, 0.0f);

	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Check Each frame to see if the conditions have been met for the door to open
		//If ActorThatOpens is in the Trigger volume
		//Replace this polling conditional with an EventSystem Eventually
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) {
		OpenDoor();
	}
}

