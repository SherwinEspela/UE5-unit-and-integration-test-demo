// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"

class UNREALUNITTESTDEMO_API ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();

	void AddScore(int Value);
	void RemoveScore(int Value);
	int GetNumberOfStars();
	int GetRewardPoints();

public:
	FORCEINLINE int GetTotalScore() const { return TotalScore; }

private:
	int TotalScore = 0;
	int TotalStars = 0;
};
