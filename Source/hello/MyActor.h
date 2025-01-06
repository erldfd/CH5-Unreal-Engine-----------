// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HELLO_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	void Move();
	int Step();

	float Distance(const FVector2D& First, const FVector2D& Second);

	int CreateEvent();

private:

	FVector2D Start;
	int EvCnt;
	int TotDist;
};

