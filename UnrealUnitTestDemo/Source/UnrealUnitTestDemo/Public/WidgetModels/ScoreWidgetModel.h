// // Copyright 2024 Sherwin Espela. All rights reserved..

#pragma once

#include "CoreMinimal.h"

/**
 * Model class that represent a User Widget component
 * which is similar to the View Model class in an
 * MVVM design pattern
 */

class ScoreManager;

class UNREALUNITTESTDEMO_API ScoreWidgetModel
{
public:
	ScoreWidgetModel();
	~ScoreWidgetModel();

public:
	FString GetFullPlayerName() const;
	FString GetPlayerRank() const;
	FString GetLevel();
	FString GetTotalScore();
	FString GetStars();
	FString GetRewardPoints();
	bool PlayerIsHighestScore() const;

public:
	FORCEINLINE void SetPlayerFirstName(FString Value) { PlayerFirstName = Value; }
	FORCEINLINE void SetPlayerLastName(FString Value) { PlayerLastName = Value; }
	FORCEINLINE void SetPlayerRank(int Value) { Rank = Value; }
	FORCEINLINE void SetLevel(int Value) { Level = Value; }
	FORCEINLINE void SetScoreManager(ScoreManager* Value) { SM = Value; }

protected:
	ScoreManager* SM;

	FString PlayerFirstName;
	FString PlayerLastName;
	FString LevelStatus;
	bool bCanDisplayNextButton;
	bool bCanShareToSocialMedia;
	int Level;
	int Rank;
};
