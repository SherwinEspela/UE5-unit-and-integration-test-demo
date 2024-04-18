// // Copyright 2024 Sherwin Espela. All rights reserved..

#pragma once

#include "CoreMinimal.h"

/**
 * Model class that represent a User Widget component
 * which is similar to the View Model class in an
 * MVVM design pattern
 */
class UNREALUNITTESTDEMO_API ScoreWidgetModel
{
public:
	ScoreWidgetModel();
	~ScoreWidgetModel();

public:
	FString GetFullPlayerName() const;
	FString GetPlayerRank() const;
	FString GetLevel();

public:
	FORCEINLINE void SetPlayerFirstName(FString Value) { PlayerFirstName = Value; }
	FORCEINLINE void SetPlayerLastName(FString Value) { PlayerLastName = Value; }
	FORCEINLINE void SetPlayerRank(int Value) { Rank = Value; }
	FORCEINLINE void SetLevel(int Value) { Level = Value; }

protected:
	FString PlayerFirstName;
	FString PlayerLastName;
	FString PlayerScore;
	FString PlayerReward;
	FString LevelStatus;
	int NumberOfStars;
	bool bIsHighScore;
	bool bCanDisplayNextButton;
	bool bCanShareToSocialMedia;
	int Level;
	int Rank;
};
