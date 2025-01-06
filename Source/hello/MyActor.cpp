// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// 필수 기능 구현
	FVector2D Position(0, 0);
	Move(Position);
}
	
void AMyActor::Move(FVector2D& OutPosition)
{
	int TotalMoveCount = 10;

	for (int i = 0; i < TotalMoveCount; ++i)
	{
		OutPosition.X += Step();
		OutPosition.Y += Step();

		UE_LOG(LogTemp, Warning, TEXT("Current Position : %s"), *OutPosition.ToString());
	}
}

int AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}


