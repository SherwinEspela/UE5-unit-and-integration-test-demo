// Copyright 2024 Sherwin Espela. All rights reserved.

#include "Managers/ScoreManager.h"

ScoreManager::ScoreManager()
{
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::AddScore(int Value)
{
	TotalScore += Value;
}

void ScoreManager::RemoveScore(int Value)
{
	TotalScore -= Value;
}
