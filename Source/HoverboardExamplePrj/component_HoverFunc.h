// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "p_HoverVech.h"
#include "Engine/World.h"
#include "Math/Vector.h"
#include "DrawDebugHelpers.h"
#include "Components/PrimitiveComponent.h"
#include "component_HoverFunc.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOVERBOARDEXAMPLEPRJ_API Ucomponent_HoverFunc : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Ucomponent_HoverFunc();
	Ap_HoverVech* Parent;
	bool bisRdy;
	float HoverDistance = 164;
	float springCoff=400;
	float Dampening=80;
	float PreviousHoverDelta;
	float HoverDelta;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
