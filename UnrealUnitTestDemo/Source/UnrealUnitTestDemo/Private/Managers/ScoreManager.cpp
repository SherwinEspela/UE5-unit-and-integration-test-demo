// Copyright 2024 Sherwin Espela. All rights reserved.

#include "Managers/ScoreManager.h"
#include "Containers/Array.h"

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

int ScoreManager::GetNumberOfStars()
{
	if (TotalScore >= 90)
	{
		TotalStars = 3;
	}
	else if (TotalScore >= 50 && TotalScore < 90)
	{
		TotalStars = 2;
	}
	else if (TotalScore >= 20 && TotalScore < 50)
	{
		TotalStars = 1;
	}

	return TotalStars;
}

int ScoreManager::GetRewardPoints()
{
	switch (TotalStars)
	{
	case 3:
		return 30;

	case 2:
		return 20;

	case 1:
		return 10;

	default:
		return 0;
	}
}

bool ScoreManager::IsHighestScore(int PlayerScore)
{
	if (PlayerScores.IsEmpty()) return true;
	AddPlayerScore(PlayerScore);
	int TopScore = PlayerScores.Top();
	if (TopScore == PlayerScore) return true;
	return false;
}

void ScoreManager::AddPlayerScore(int Value)
{
	PlayerScores.AddUnique(Value);
	PlayerScores.Sort();
}
