// Fill out your copyright notice in the Description page of Project Settings.


#include "component_HoverFunc.h"

// Sets default values for this component's properties
Ucomponent_HoverFunc::Ucomponent_HoverFunc()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Ucomponent_HoverFunc::BeginPlay()
{
	Super::BeginPlay();
	
	Ap_HoverVech* Vech = Cast<Ap_HoverVech>(this->GetOwner());
	if (Vech != nullptr) { // Check cast to see if valid
		Parent = Vech;
		bisRdy = true;
	}


	
}


// Called every frame
void Ucomponent_HoverFunc::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bisRdy)
	{

		FHitResult hit(ForceInit);
		FVector end = this->GetUpVector();
		end *= -1 * HoverDistance;
		FCollisionQueryParams CollisionParams;
		GetWorld()->LineTraceSingleByChannel(
			hit,        //result
			GetComponentLocation(),    //start
			GetComponentLocation() + end, //end
			ECC_Pawn, //collision channel
			CollisionParams
		);

		DrawDebugLine(
			GetWorld(),
			GetComponentLocation(),
			hit.Location,
			FColor(255, 0, 0),
			false, -1, 0,
			12.333
		);

		if (hit.bBlockingHit) {
			HoverDelta = HoverDistance - hit.Distance;
			float force = (HoverDelta * springCoff) + (((HoverDelta - PreviousHoverDelta) / DeltaTime) * Dampening);
			FVector fForc = this->GetUpVector() * force;

			UPrimitiveComponent* Vech = Cast<UPrimitiveComponent>(Parent->GetRootComponent());
			if (Vech != nullptr) { // Check cast to see if valid
				Vech->AddForceAtLocation(fForc, GetComponentLocation());
				PreviousHoverDelta = HoverDelta;
			}

		}

	}

}

