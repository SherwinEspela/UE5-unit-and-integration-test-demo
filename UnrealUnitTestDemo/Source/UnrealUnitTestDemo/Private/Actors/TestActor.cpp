// Copyright 2024 Sherwin Espela. All rights reserved.

#include "Actors/TestActor.h"

ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
