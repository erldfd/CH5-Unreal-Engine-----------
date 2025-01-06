// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor() : Start(FVector2D(0, 0)), EvCnt(0), TotDist(0)
{
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	Move();
}
	
void AMyActor::Move()
{
	int TotalMoveCount = 10;

	FVector2D PreviousPosition = Start;

	for (int i = 0; i < TotalMoveCount; ++i)
	{
		Start.X += Step();
		Start.Y += Step();

		UE_LOG(LogTemp, Warning, TEXT("Current Position : %s"), *Start.ToString());

		if (CreateEvent())
		{
			UE_LOG(LogTemp, Warning, TEXT("목이 말라 물 좀 마셨다."), *Start.ToString());
			EvCnt++;
		}

		TotDist += Distance(PreviousPosition, Start);
		PreviousPosition = Start;
	}

	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %d, Event Count : %d"), TotDist, EvCnt, *Start.ToString());
}

int AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::Distance(const FVector2D& First, const FVector2D& Second)
{
	return FMath::Sqrt((First.X - Second.X) * (First.X - Second.X) + (First.Y - Second.Y) * (First.Y - Second.Y));
}

int AMyActor::CreateEvent()
{
	return FMath::RandRange(0, 1);
}


