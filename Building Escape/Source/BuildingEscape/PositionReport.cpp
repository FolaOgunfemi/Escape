																				// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"

#include "Gameframework/Actor.h"


//NOTE: If project was built with UE older than 4.17, try include-what-you-use(IWYU) to slow down compile times and include only what is necessary //https://docs.unrealengine.com/en-us/Programming/UnrealBuildSystem/IWYUReferenceGuide
	//Current versions already use this

// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

		//GetOwner returns pointer to actor that this script is attatched to
	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjectName, *ObjectPos);	//the TEXT Macro wants us to dereference ObjectName and ObjectPos. It involves overloading of * Operator. Basically, the macro is expecting a TCHAR Array as an input. An array is essentially a pointer to the first element of the array, so in that way, this syntax satisfies conditions
							
	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

