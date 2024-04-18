// // Copyright 2024 Sherwin Espela. All rights reserved..


#include "WidgetModels/ScoreWidgetModel.h"

ScoreWidgetModel::ScoreWidgetModel()
{
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
