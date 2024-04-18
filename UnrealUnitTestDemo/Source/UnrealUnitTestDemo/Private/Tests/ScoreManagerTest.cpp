// Copyright 2024 Sherwin Espela. All rights reserved.

#include "Managers/ScoreManager.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreManagerAddScoreTest, "ScoreManager.Add Score",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreManagerAddScoreTest::RunTest(const FString& Parameters)
{
	ScoreManager* SM = new ScoreManager();
	SM->AddScore(10);
	int TotalScore = SM->GetTotalScore();
	TestEqual(TEXT("Expected to have 10 points"), TotalScore, 10);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreManagerRemoveScoreTest, "ScoreManager.Remove Score",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreManagerRemoveScoreTest::RunTest(const FString& Parameters)
{
	ScoreManager* SM = new ScoreManager();
	SM->AddScore(20);
	SM->RemoveScore(5);
	int TotalScore = SM->GetTotalScore();
	TestEqual(TEXT("Expected to have 15 points"), TotalScore, 15);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreManagerStressTest, "ScoreManager.Stress Test",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreManagerStressTest::RunTest(const FString& Parameters)
{
	ScoreManager* SM = new ScoreManager();
	SM->AddScore(25); // 25
	SM->RemoveScore(5); // 25 - 5 = 20
	SM->AddScore(30); // 20 + 30 = 50
	SM->RemoveScore(10); // 50 - 10 = 40
	SM->RemoveScore(20); // 40 - 20 = 20
	SM->AddScore(80); // 20 + 80 = 100
	int TotalScore = SM->GetTotalScore();
	TestEqual(TEXT("Expected total score should be 100 points"), TotalScore, 100);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreManagerGetStarsTest, "ScoreManager.Get Number of Stars",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreManagerGetStarsTest::RunTest(const FString& Parameters)
{
	ScoreManager SM;

	SM.AddScore(10); // Total Score = 10
	TestTrue(TEXT("Expected to have zero stars"), SM.GetNumberOfStars() == 0);

	SM.AddScore(20); // Total Score = 30
	TestTrue(TEXT("Expected to have 1 star"), SM.GetNumberOfStars() == 1);

	SM.AddScore(40); // Total Score = 70
	TestTrue(TEXT("Expected to have 2 stars"), SM.GetNumberOfStars() == 2);

	SM.AddScore(25); // Total Score = 95
	TestTrue(TEXT("Expected to have 3 stars"), SM.GetNumberOfStars() == 3);
	
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreManagerGetRewardsTest, "ScoreManager.Get Reward Points",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreManagerGetRewardsTest::RunTest(const FString& Parameters)
{
	ScoreManager SM;

	SM.AddScore(10); // Total Score = 10
	TestTrue(TEXT("Expected to have zero stars"), SM.GetNumberOfStars() == 0);
	TestTrue(TEXT("Expected to have 0 reward points"), SM.GetRewardPoints() == 0);

	SM.AddScore(20); // Total Score = 30
	TestTrue(TEXT("Expected to have 1 star"), SM.GetNumberOfStars() == 1);
	TestTrue(TEXT("Expected to have 10 reward points"), SM.GetRewardPoints() == 10);

	SM.AddScore(40); // Total Score = 70
	TestTrue(TEXT("Expected to have 2 stars"), SM.GetNumberOfStars() == 2);
	TestTrue(TEXT("Expected to have 20 reward points"), SM.GetRewardPoints() == 20);

	SM.AddScore(25); // Total Score = 95
	TestTrue(TEXT("Expected to have 3 stars"), SM.GetNumberOfStars() == 3);
	TestTrue(TEXT("Expected to have 20 reward points"), SM.GetRewardPoints() == 30);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FScoreManagerCheckIfHighestScoresTest, "ScoreManager.Check if Player has the Highest Score",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FScoreManagerCheckIfHighestScoresTest::RunTest(const FString& Parameters)
{
	ScoreManager SM;
	SM.AddPlayerScore(10);
	SM.AddPlayerScore(20);
	SM.AddPlayerScore(30);

	bool bIsHighestScore = SM.IsHighestScore(100);
	TestTrue(TEXT("Player should be the highest score"), bIsHighestScore == true);

	return true;
}
