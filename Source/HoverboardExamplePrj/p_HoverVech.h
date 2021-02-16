// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "p_HoverVech.generated.h"

UCLASS()
class HOVERBOARDEXAMPLEPRJ_API Ap_HoverVech : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Ap_HoverVech();
	float X;
	float Y;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void MoveForward(float value);
	virtual void MoveHorizontal(float value);
};
