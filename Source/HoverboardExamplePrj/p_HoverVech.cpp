// Fill out your copyright notice in the Description page of Project Settings.


#include "p_HoverVech.h"
#define DEBUGMESSAGE(x, ...) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT(x), __VA_ARGS__));}
// Sets default values
Ap_HoverVech::Ap_HoverVech()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Ap_HoverVech::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Ap_HoverVech::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	DEBUGMESSAGE("FLOAT %f", InputComponent->GetAxisValue(TEXT("MoveForward")));

	UPrimitiveComponent* Vech = Cast<UPrimitiveComponent>(this->GetRootComponent());
	if (Vech != nullptr) { // Check cast to see if valid
		Vech->AddForce(GetActorForwardVector() * X * 50000);
		Vech->AddTorqueInDegrees(GetActorUpVector() * 10000000 * Y);
	}

}


void Ap_HoverVech::MoveForward(float v)
{
	X = v;
}

void Ap_HoverVech::MoveHorizontal(float v)
{
	Y = v;
}

// Called to bind functionality to input
void Ap_HoverVech::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	InputComponent->BindAxis("MoveForward",this,&Ap_HoverVech::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &Ap_HoverVech::MoveHorizontal);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

