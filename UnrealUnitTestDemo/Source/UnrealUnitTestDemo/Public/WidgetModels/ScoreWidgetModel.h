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

public:
	FORCEINLINE void SetPlayerFirstName(FString Value) { PlayerFirstName = Value; }
	FORCEINLINE void SetPlayerLastName(FString Value) { PlayerLastName = Value; }

protected:
	FString PlayerFirstName;
	FString PlayerLastName;
	FString PlayerRank;
	FString PlayerScore;
	FString PlayerReward;
	FString LevelName;
	FString LevelStatus;
	int NumberOfStars;
	bool bIsHighScore;
	bool bCanDisplayNextButton;
	bool bCanShareToSocialMedia;
};
