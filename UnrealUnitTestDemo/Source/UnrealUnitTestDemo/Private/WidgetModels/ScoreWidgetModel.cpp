// // Copyright 2024 Sherwin Espela. All rights reserved..


#include "WidgetModels/ScoreWidgetModel.h"
#include "Managers/ScoreManager.h"

ScoreWidgetModel::ScoreWidgetModel()
{
	SM = new ScoreManager();
}

ScoreWidgetModel::~ScoreWidgetModel()
{
}

FString ScoreWidgetModel::GetFullPlayerName() const
{
	FString FullName = FString::Printf(TEXT("%s %s"), *PlayerFirstName, *PlayerLastName);
	return FullName;
}

FString ScoreWidgetModel::GetPlayerRank() const
{
	// Player rank can be provided by a Service class
	FString PlayerRank = FString::Printf(TEXT("Rank %i"), Rank);
	return PlayerRank;
}

FString ScoreWidgetModel::GetLevel()
{
	// Level number can be provided by a Service class
	if (Level == 0) ++Level;
	FString TextLevel = FString::Printf(TEXT("Level: %i"), Level);
	return TextLevel;
}

FString ScoreWidgetModel::GetTotalScore()
{
	check(SM);
	FString TotalScore = FString::Printf(TEXT("Total Score: %i"), SM->GetTotalScore());
	return TotalScore;
}

FString ScoreWidgetModel::GetStars()
{
	check(SM);
	FString TotalStars = FString::Printf(TEXT("Total Stars: %i"), SM->GetNumberOfStars());
	return TotalStars;
}

FString ScoreWidgetModel::GetRewardPoints()
{
	check(SM);
	FString RewardPoints = FString::Printf(TEXT("Total Reward Points: %i"), SM->GetRewardPoints());
	return RewardPoints;
}
