// Copyright 2017 Brian Walsh

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

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

	///Removed due to lack of need
//	void OpenDoor();
//	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

private:
	///Blueprint replaced
//	UPROPERTY(VisibleAnywhere)
//	float OpenAngle = -90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.f;

	///Blueprint replaced
//	UPROPERTY(EditAnywhere)
//	float DoorCloseDelay = 0.6f;

	///Blueprint replaced
//	float LastDoorOpenTime;

	//The owning door
	AActor* Owner = nullptr; 

	// Mass is in kg
	float GetTotalMassOfActorsOnPlate();
};
