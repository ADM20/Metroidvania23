// Fill out your copyright notice in the Description page of Project Settings.


#include "Metroidvania23_Enemy.h"

// Sets default values
AMetroidvania23_Enemy::AMetroidvania23_Enemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMetroidvania23_Enemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMetroidvania23_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMetroidvania23_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

