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
